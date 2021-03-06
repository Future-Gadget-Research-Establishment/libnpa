#include <cstring>
#include "nsscompiler.hpp"
#include "scriptfile.hpp"
#include "flex.hpp"
#include "parser.hpp"
#include "buffer.hpp"
using namespace Npa;

class Program;
extern Program* pRoot;

// TODO: if/while/select have separate counters
static uint32_t SymCounter;
static uint32_t Counter;
static Buffer* Output;
static Buffer* MapOutput;

const char* ArgumentTypes[] =
{
    "INT",
    "STRING",
    "FLOAT"
};

Call* MakeCall(string Name, uint16_t Magic)
{
    ExpressionList Args;
    Args.push_back(new Argument(Name, ARG_STRING));
    Argument* Arg = new Argument(Nsb::StringifyMagic(Magic), ARG_FUNCTION);
    return new Call(Arg, Args, Magic);
}

void WriteSymbol(const string& Symbol)
{
    MapOutput->Write<uint32_t>(Output->GetSize());
    MapOutput->WriteStr16(Symbol);
}

void Node::Compile(uint16_t Magic, uint16_t NumParams)
{
    Output->Write<uint32_t>(Counter);
    Output->Write<uint16_t>(Magic);
    Output->Write<uint16_t>(NumParams);
    ++Counter;
}

void Argument::Compile()
{
    if (Type == ARG_VARIABLE)
        Node::Compile(MAGIC_VARIABLE, 1);
    else
    {
        Node::Compile(MAGIC_LITERAL, 2);
        Output->WriteStr32(NpaFile::FromUtf8(ArgumentTypes[Type]));
    }
    CompileRaw();
}

void Argument::CompileRaw()
{
    Output->WriteStr32(Data);
}

void Array::Compile()
{
    for (auto i = Arguments.begin(); i != Arguments.end(); ++i)
        (*i)->Compile();

    Node::Compile(MAGIC_SUB_SCRIPT, 2);
    Argument Arg1(ArrayData, ARG_STRING);
    Arg1.CompileRaw();
    Argument Arg2(to_string(Arguments.size()), ARG_INT);
    Arg2.CompileRaw();
}

void Expression::CompileRaw()
{
    Output->WriteStr32("@");
}

void Call::Compile()
{
    uint16_t NumParams = Arguments.size();
    uint32_t BuiltinMagic = Nsb::MagicifyString(Name->Data.c_str());

    // Parameters
    if (BuiltinMagic != MAGIC_PARSE_TEXT &&
        BuiltinMagic != MAGIC_CALL_SCENE &&
        BuiltinMagic != MAGIC_CALL_CHAPTER)
        for (auto i = Arguments.begin(); i != Arguments.end(); ++i)
            (*i)->Compile();

    // Builtin function
    if (BuiltinMagic != 0)
        Node::Compile(BuiltinMagic, NumParams);
    // Script function
    else
    {
        NumParams += 1;
        Node::Compile(Magic, NumParams);
        Name->CompileRaw();
    }
    // Arguments
    for (auto i = Arguments.begin(); i != Arguments.end(); ++i)
        (*i)->CompileRaw();
}

void CallStatement::Compile()
{
    Call::Compile();
    Node::Compile(MAGIC_CLEAR_PARAMS, 0);
}

void Block::Compile()
{
    Node::Compile(MAGIC_SCOPE_BEGIN, 0);
    for (auto i = Statements.begin(); i != Statements.end(); ++i)
        (*i)->Compile();
    Node::Compile(MAGIC_SCOPE_END, 0);
}

void Subroutine::CompilePrototype(uint16_t BeginMagic, uint32_t NumBeginParams)
{
    WriteSymbol(Name->Data);
    Node::Compile(BeginMagic, NumBeginParams);
    Name->CompileRaw();
}

void Subroutine::Compile()
{
    SubroutineBlock->Compile();
}

void Subroutine::CompileReturn(uint16_t EndMagic)
{
    Node::Compile(EndMagic, NumEndParams);
}

void Program::Compile()
{
    for (auto i = Subroutines.begin(); i != Subroutines.end(); ++i)
        (*i)->Compile();
}

void Function::Compile()
{
    CompilePrototype(MAGIC_FUNCTION_DECLARATION, Arguments.size() + 1);
    for (auto i = Arguments.begin(); i != Arguments.end(); ++i)
        (*i)->CompileRaw();
    Subroutine::Compile();
    CompileReturn(MAGIC_END_FUNCTION);
}

void Chapter::Compile()
{
    CompilePrototype(MAGIC_CHAPTER_DECLARATION, 1);
    Subroutine::Compile();
    CompileReturn(MAGIC_END_CHAPTER);
}

void Scene::Compile()
{
    CompilePrototype(MAGIC_SCENE_DECLARATION, 1);
    Subroutine::Compile();
    CompileReturn(MAGIC_END_SCENE);
}

void Assignment::Compile()
{
    if (Name->Type == ARG_ARRAY)
        Name->Compile();
    Rhs->Compile();
    Node::Compile(Magic, 1);
    Name->CompileRaw();
    Node::Compile(MAGIC_CLEAR_PARAMS, 0);
}

void BinaryOperator::Compile()
{
    Lhs->Compile();
    Rhs->Compile();
    Node::Compile(Magic, 0);
}

void UnaryOperator::Compile()
{
    Rhs->Compile();
    Node::Compile(Magic, 0);
}

void UnaryStatement::Compile()
{
    UnaryOperator::Compile();
    Node::Compile(MAGIC_CLEAR_PARAMS, 0);
}

void Condition::_Compile(Argument& EndSym)
{
    Expr->Compile();
    Node::Compile(Magic, 1);
    EndSym.CompileRaw();
    ConditionBlock->Compile();
}

void If::Compile()
{
    Argument ElseSym("label.if." + to_string(SymCounter++), ARG_STRING);
    Argument EndSym("label.if.end." + to_string(SymCounter++), ARG_STRING);
    Condition::_Compile(ElseSym);
    Node::Compile(MAGIC_JUMP, 1);
    EndSym.CompileRaw();
    WriteSymbol(ElseSym.Data);
    if (ElseBlock) ElseBlock->Compile();
    if (ElseIf) ElseIf->Compile();
    WriteSymbol(EndSym.Data);
}

void While::Compile()
{
    Argument BeginSym("label.while.begin." + to_string(SymCounter), ARG_STRING);
    Argument EndSym("label.while.end." + to_string(SymCounter++), ARG_STRING);
    WriteSymbol(BeginSym.Data);
    Condition::_Compile(EndSym);
    Node::Compile(MAGIC_WHILE_END, 0);
    Node::Compile(MAGIC_JUMP, 1);
    BeginSym.CompileRaw();
    WriteSymbol(EndSym.Data);
}

// ugly hack
static Argument SelEndSym;

void Select::Compile()
{
    Argument BeginSym("label.select.begin." + to_string(SymCounter), ARG_STRING);
    Argument EndSym("label.select.end." + to_string(SymCounter++), ARG_STRING);
    Node::Compile(MAGIC_SELECT, 1);
    EndSym.CompileRaw();
    WriteSymbol(BeginSym.Data);

    // pass the end symbol down the tree to case
    Argument Old = SelEndSym;
    SelEndSym = EndSym;
    SelectBlock->Compile();
    SelEndSym = Old;

    Node::Compile(MAGIC_SELECT_END, 0);
    Node::Compile(MAGIC_JUMP, 1);
    BeginSym.CompileRaw();
    WriteSymbol(EndSym.Data);
    Node::Compile(MAGIC_SELECT_BREAK_END, 0);
}

void Case::Compile()
{
    Argument Label(Name, ARG_STRING);
    Argument StartSym("label.case.start." + to_string(SymCounter), ARG_STRING);
    Argument EndSym("label.case.end." + to_string(SymCounter++), ARG_STRING);
    Node::Compile(MAGIC_CASE, 3);
    Label.CompileRaw();
    EndSym.CompileRaw();
    StartSym.CompileRaw();
    WriteSymbol(StartSym.Data);
    CaseBlock->Compile();
    Node::Compile(MAGIC_CASE_END, 1);
    Label.CompileRaw();
    Node::Compile(MAGIC_JUMP, 1);
    SelEndSym.CompileRaw();
    WriteSymbol(EndSym.Data);
}

void Label::Compile()
{
    // TODO
}

namespace Nss
{

void Compile(const char* pBuffer, uint32_t Length, Buffer* NsbBuffer, Buffer* MapBuffer)
{
    Counter = 1;
    SymCounter = 1;
    Output = NsbBuffer;
    MapOutput = MapBuffer;
    YY_BUFFER_STATE buffer = yy_scan_bytes(pBuffer, Length);
    yyparse();
    pRoot->Compile();
    yy_delete_buffer(buffer);
    delete pRoot;
}

}

#include "nsbmagic.hpp"
#include <boost/assign/list_of.hpp>
#include <boost/bimap.hpp>

typedef boost::bimap<uint16_t, std::string> LookupTable;

static const LookupTable MagicStrings = boost::assign::list_of<LookupTable::value_type>
    (MAGIC_FWN_UNK, "FUWANOVEL")

    (MAGIC_PARSE_TEXT, "ParseText")
    (MAGIC_SET_PARAM, "SetParam")
    (MAGIC_CHAPTER_BEGIN, "ChapterBegin")
    (MAGIC_IF, "If")
    (MAGIC_JUMP, "Jump")
    (MAGIC_CALL_FUNCTION, "CallFunction")
    (MAGIC_LOGICAL_AND, "LogicalAnd")
    (MAGIC_LOGICAL_OR, "LogicalOr")
    (MAGIC_SCOPE_BEGIN, "ScopeBegin")
    (MAGIC_SCOPE_END, "ScopeEnd")
    (MAGIC_GET_SCRIPT_NAME, "GetScriptName")
    (MAGIC_CLEAR_PARAMS, "ClearParams")
    (MAGIC_RESET, "Reset")
    (MAGIC_LOGICAL_NOT_EQUAL, "LogicalNotEqual")
    (MAGIC_ADD, "Add")
    (MAGIC_SET, "Set")
    (MAGIC_GET, "Get")
    (MAGIC_CHAPTER_END, "ChapterEnd")
    (MAGIC_SCENE_BEGIN, "SceneBegin")
    (MAGIC_CALL_SCENE, "CallScene")
    (MAGIC_SCENE_END, "SceneEnd")
    (MAGIC_MOVE, "Move")
    (MAGIC_REQUEST, "Request")
    (MAGIC_DELETE, "Delete")
    (MAGIC_FADE, "Fade")
    (MAGIC_UNK20, "UNK20")
    (MAGIC_WAIT, "Wait")
    (MAGIC_PLACEHOLDER_PARAM, "PlaceholderParam")
    (MAGIC_NEGATIVE, "Negative")
    (MAGIC_SET_VOLUME, "SetVolume")
    (MAGIC_SHAKE, "Shake")
    (MAGIC_ARRAY_READ, "ArrayRead")
    (MAGIC_UNK27, "UNK27")
    (MAGIC_CREATE_WINDOW, "CreateWindow")
    (MAGIC_SET_ALIAS, "SetAlias")
    (MAGIC_CREATE_MOVIE, "CreateMovie")
    (MAGIC_SET_VERTEX, "SetVertex")
    (MAGIC_APPLY_BLUR, "ApplyBlur")
    (MAGIC_CREATE_RENDER_TEXTURE, "CreateRenderTexture")
    (MAGIC_DRAW_TO_TEXTURE, "DrawToTexture")
    (MAGIC_LOGICAL_EQUAL, "LogicalEqual")
    (MAGIC_FUNCTION_BEGIN, "FunctionBegin")
    (MAGIC_FUNCTION_END, "FunctionEnd")
    (MAGIC_UNK38, "UNK38")
    (MAGIC_UNK39, "UNK39")
    (MAGIC_STRING_TO_VARIABLE, "StringToVariable")
    (MAGIC_CREATE_TEXTURE, "CreateTexture")
    (MAGIC_TEXTURE_WIDTH, "TextureWidth")
    (MAGIC_DIVIDE, "Divide")
    (MAGIC_MULTIPLY, "Multiply")
    (MAGIC_LOGICAL_NOT, "LogicalNot")
    (MAGIC_WHILE, "While")
    (MAGIC_GET_MOVIE_TIME, "GetMovieTime")
    (MAGIC_BREAK, "Break")
    (MAGIC_LOGICAL_LESS_EQUAL, "LogicalLessEqual")
    (MAGIC_UNK50, "UNK50")
    (MAGIC_UNK51, "UNK51")
    (MAGIC_UNK52, "UNK52")
    (MAGIC_ALLOW_PHONE_CALL, "AllowPhoneCall")
    (MAGIC_INCREMENT, "Increment")
    (MAGIC_LOGICAL_GREATER, "LogicalGreater")
    (MAGIC_DRAW_TRANSITION, "DrawTransition")
    (MAGIC_LOGICAL_GREATER_EQUAL, "LogicalGreaterEqual")
    (MAGIC_SUBSTRACT, "Substract")
    (MAGIC_UNK59, "UNK59")
    (MAGIC_UNK60, "UNK60")
    (MAGIC_UNK61, "UNK61")
    (MAGIC_UNK62, "UNK62")
    (MAGIC_UNK63, "UNK63")
    (MAGIC_LOGICAL_LESS, "LogicalLess")
    (MAGIC_WHILE_END, "WhileEnd")
    (MAGIC_UNK66, "UNK66")
    (MAGIC_LOAD_FONT, "LoadFont")
    (MAGIC_LOAD_IMAGE, "LoadImage")
    (MAGIC_CREATE_ARRAY, "CreateArray")
    (MAGIC_BIND_IDENTIFIER, "BindIdentifier")
    (MAGIC_CREATE_CHOICE, "CreateChoice")
    (MAGIC_TEXTURE_HEIGHT, "TextureHeight")
    (MAGIC_COUNT, "Count")
    (MAGIC_SET_FONT, "SetFont")
    (MAGIC_CREATE_TEXT, "CreateText")
    (MAGIC_CREATE_COLOR, "CreateColor")
    (MAGIC_UNK77, "UNK77")
    (MAGIC_CREATE_SCROLLBAR, "CreateScrollbar")
    (MAGIC_UNK79, "UNK79")
    (MAGIC_UNK80, "UNK80")
    (MAGIC_UNK81, "UNK81")
    (MAGIC_UNK82, "UNK82")
    (MAGIC_FORMAT, "Format")
    (MAGIC_UNK84, "UNK84")
    (MAGIC_SELECT, "Select")
    (MAGIC_CALL_CHAPTER, "CallChapter")
    (MAGIC_CASE_BEGIN, "CaseBegin")
    (MAGIC_CASE_END, "CaseEnd")
    (MAGIC_SELECT_END, "SelectEnd")
    (MAGIC_UNK90, "UNK90")
    (MAGIC_UNK91, "UNK91")
    (MAGIC_UNK92, "UNK92")
    (MAGIC_SCROLLBAR_VALUE, "ScrollbarValue")
    (MAGIC_UNK94, "UNK94")
    (MAGIC_CREATE_PROCESS, "CreateProcess")
    (MAGIC_ZOOM, "Zoom")
    (MAGIC_TIME, "Time")
    (MAGIC_SET_NEXT_FOCUS, "SetNextFocus")
    (MAGIC_RETURN, "Return")
    (MAGIC_UNK100, "UNK100")
    (MAGIC_UNK101, "UNK101")
    (MAGIC_SET_SHORTCUT, "SetShortcut")
    (MAGIC_SAVE, "Save")
    (MAGIC_DELETE_SAVE_FILE, "DeleteSaveFile")
    (MAGIC_UNK105, "UNK105")
    (MAGIC_CLEAR_SCORE, "ClearScore")
    (MAGIC_CLEAR_BACKLOG, "ClearBacklog")
    (MAGIC_EXIST_SAVE, "ExistSave")
    (MAGIC_WAIT_ACTION, "WaitAction")
    (MAGIC_UNK110, "UNK110")
    (MAGIC_MOVIE_PLAY, "MoviePlay")
    (MAGIC_UNK112, "UNK112")
    (MAGIC_UNK113, "UNK113")
    (MAGIC_SYSTEM, "System")
    (MAGIC_UNK115, "UNK115")
    (MAGIC_UNK116, "UNK116")
    (MAGIC_UNK117, "UNK117")
    (MAGIC_UNK118, "UNK118")
    (MAGIC_UNK119, "UNK119")
    (MAGIC_UNK120, "UNK120")
    (MAGIC_UNK121, "UNK121")
    (MAGIC_UNK122, "UNK122")
    (MAGIC_UNK123, "UNK123")
    (MAGIC_UNK124, "UNK124")
    (MAGIC_UNK125, "UNK125")
    (MAGIC_UNK126, "UNK126")
    (MAGIC_UNK127, "UNK127")
    (MAGIC_UNK128, "UNK128")
    (MAGIC_UNK129, "UNK129")
    (MAGIC_SEND_MAIL_EDIT, "SendMailEdit")
    (MAGIC_UNK131, "UNK131")
    (MAGIC_UNK132, "UNK132")
    (MAGIC_UNK133, "UNK133")
    (MAGIC_UNK134, "UNK134")
    (MAGIC_UNK135, "UNK135")
    (MAGIC_UNK136, "UNK136")
    (MAGIC_UNK137, "UNK137")
    (MAGIC_UNK138, "UNK138")
    (MAGIC_UNK139, "UNK139")
    (MAGIC_UNK140, "UNK140")
    (MAGIC_UNK141, "UNK141")
    (MAGIC_UNK142, "UNK142")
    (MAGIC_UNK143, "UNK143")
    (MAGIC_UNK144, "UNK144")
    (MAGIC_UNK145, "UNK145")
    (MAGIC_UNK146, "UNK146")
    (MAGIC_UNK147, "UNK147")
    (MAGIC_UNK148, "UNK148")
    (MAGIC_UNK149, "UNK149")
    (MAGIC_UNK150, "UNK150")
    (MAGIC_LOAD_TEXTURE_CLIP, "LoadTextureClip")
    (MAGIC_CREATE_STENCIL, "CreateStencil")
    (MAGIC_UNK153, "UNK153")
    (MAGIC_UNK154, "UNK154")
    (MAGIC_CREATE_SOUND, "CreateSound")
    (MAGIC_SET_LOOP_POINT, "SetLoopPoint")
    (MAGIC_SET_FREQUENCY, "SetFrequency")
    (MAGIC_SET_PAN, "SetPan")
    (MAGIC_SET_LOOP, "SetLoop")
    (MAGIC_UNK160, "UNK160")
    (MAGIC_CONQUEST, "Conquest")
    (MAGIC_STR_STR, "StrStr")
    (MAGIC_SET_TEXTBOX_ATTRIBUTES, "SetTextboxAttributes")
    (MAGIC_LOAD_TEXT, "LoadText")
    (MAGIC_WAIT_TEXT, "WaitText")
    (MAGIC_UNK166, "UNK166")
    (MAGIC_UNK167, "UNK167")
    (MAGIC_UNK168, "UNK168")
    (MAGIC_UNK169, "UNK169")
    (MAGIC_UNK170, "UNK170")
    (MAGIC_UNK171, "UNK171")
    (MAGIC_UNK172, "UNK172")
    (MAGIC_READ_FILE, "ReadFile")
    (MAGIC_SOUND_AMPLITUDE, "SoundAmplitude")
    (MAGIC_WRITE_FILE, "WriteFile")
    (MAGIC_LOAD, "Load")
    (MAGIC_MESSAGE_BOX, "MessageBox")
    (MAGIC_UNK178, "UNK178")
    (MAGIC_UNK179, "UNK179")
    (MAGIC_UNK180, "UNK180")
    (MAGIC_UNK181, "UNK181")
    (MAGIC_UNK182, "UNK182")
    (MAGIC_UNK183, "UNK183")
    (MAGIC_UNK184, "UNK184")
    (MAGIC_UNK185, "UNK185")
    (MAGIC_EXIT, "Exit")
    (MAGIC_UNK187, "UNK187")
    (MAGIC_UNK188, "UNK188")
    (MAGIC_UNK189, "UNK189")
    (MAGIC_UNK190, "UNK190")
    (MAGIC_UNK191, "UNK191")
    (MAGIC_UNK192, "UNK192")
    (MAGIC_UNK193, "UNK193")
    (MAGIC_UNK194, "UNK194");

namespace Nsb
{
    bool IsValidMagic(uint16_t Magic)
    {
        return MagicStrings.left.find(Magic) != MagicStrings.left.end();
    }

    const char* StringifyMagic(uint16_t Magic)
    {
        auto iter = MagicStrings.left.find(Magic);
        if (iter != MagicStrings.left.end())
            return iter->second.c_str();
        return nullptr;
    }

    uint16_t MagicifyString(const char* String)
    {
        auto iter = MagicStrings.right.find(String);
        if (iter != MagicStrings.right.end())
            return iter->second;
        return 0;
    }
}

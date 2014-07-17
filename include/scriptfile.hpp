#ifndef SCRIPT_FILE_HPP
#define SCRIPT_FILE_HPP

#include <vector>
#include <string>
#include <map>
#include <cstdint>
#define NSB_INVALIDE_LINE ~(uint32_t)0

namespace NpaPrivate
{
    class Buffer;
}

struct Line
{
    uint16_t Magic;
    std::vector<std::string> Params;
};

class ScriptFile
{
public:
    enum FileType
    {
        NSB,
        NSS
    };

    ScriptFile(const std::string& Name, char* NssData, uint32_t NssSize);
    ScriptFile(const std::string& Name, char* NsbData, uint32_t NsbSize, char* MapData, uint32_t MapSize);
    ScriptFile(const std::string& Name, FileType Type);

    uint32_t GetSymbol(const std::string& Symbol);
    const std::string& GetName() const { return Name; }
    Line* GetLine(uint32_t Entry) { return Entry < Source.size() ? &Source[Entry] : nullptr; }

private:
    void OpenNss(const std::string& Name);
    void OpenNsb(std::string Name);
    void ReadNss(char* NssData, uint32_t NssSize);
    void ReadNsb(char* NsbData, uint32_t NsbSize, char* MapData, uint32_t MapSize);
    void Read(char** Src, void* Dest, uint32_t Size);

    std::map<std::string, uint32_t> Symbols;
    std::vector<Line> Source;
    const std::string Name;
};

namespace Nss
{
    void Compile(char* pBuffer, uint32_t Length, NpaPrivate::Buffer* NsbBuffer, NpaPrivate::Buffer* MapBuffer);
}

#endif

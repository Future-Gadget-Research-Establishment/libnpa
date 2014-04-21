#ifndef I_NPA_FILE_HPP
#define I_NPA_FILE_HPP

#include "npafile.hpp"
#include <map>

// GStreamer requires g_malloc instead of ::operator new because it deallocates memory with g_free
void* DefaultAlloc(uint64_t Size)
{
    char* pMem = new char[Size];
    return pMem;
}

class INpaFile : NpaFile
{
public:
    struct Entry
    {
        uint32_t Size;
        uint32_t Offset;
        uint32_t Unk;
    };
    typedef std::map<std::string, Entry>::iterator NpaIterator;
public:
    INpaFile(const std::string& Filename);
    ~INpaFile();

    char* ReadFile(const std::string& Filename, uint32_t& Size);
    char* ReadFile(NpaIterator iter);
    char* ReadFile(NpaIterator iter, uint32_t Offset, uint32_t Size, void *(*Alloc)(uint64_t) = DefaultAlloc);
    NpaIterator Begin() { return Registry.begin(); }
    NpaIterator End() { return Registry.end(); }
    NpaIterator FindFile(const std::string& Filename) { return Registry.find(Filename); }
private:
    void ReadHeader();
    char* ReadData(uint32_t GlobalOffset, uint32_t LocalOffset, uint32_t Size, void *(*Alloc)(uint64_t));

    std::map<std::string, Entry> Registry;
};

#endif

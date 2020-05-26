#pragma once
#include <streambuf>

//Simple wrapper around std::streambuf representing a memory buffer.
//Used by BinaryReader and BinaryWriter
struct MemoryBuffer : std::streambuf
{
    MemoryBuffer(char* begin, char* end)
    {
        this->setg(begin, begin, end);
    }
    MemoryBuffer(char* begin, uint32_t sizeInBytes)
    {
        this->setg(begin, begin, begin + sizeInBytes);
    }
};
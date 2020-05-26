#pragma once
#include <string>
#include <fstream>

class MemoryBuffer;

//Class that can read binary data either from a file or from a fixed size buffer 
//depending on the constructor used.
class BinaryReader
{
public:
    //Reads binary data from file at path
    BinaryReader(const std::string& inputPath);
    //Reads binary data from fixed size memory buffer
    BinaryReader(char* buffer, uint32_t sizeInBytes);
    ~BinaryReader();

    [[nodiscard]] uint8_t ReadUint8();
    [[nodiscard]] uint16_t ReadUint16();
    [[nodiscard]] uint32_t ReadUint32();
    [[nodiscard]] uint64_t ReadUint64();

    [[nodiscard]] int8_t ReadInt8();
    [[nodiscard]] int16_t ReadInt16();
    [[nodiscard]] int32_t ReadInt32();
    [[nodiscard]] int64_t ReadInt64();

    [[nodiscard]] char ReadChar();
    [[nodiscard]] std::string ReadNullTerminatedString();
    [[nodiscard]] std::string ReadFixedLengthString(int length);
    [[nodiscard]] char NextChar();

    [[nodiscard]] float ReadFloat();
    [[nodiscard]] double ReadDouble();

    void ReadToMemory(void* destination, size_t size);

    void SeekBeg(int absoluteOffset);
    void SeekCur(int relativeOffset);
    void Skip(int bytesToSkip);
    size_t Align(int alignmentValue = 2048);

private:
    std::istream* stream_ = nullptr;
    MemoryBuffer* buffer_ = nullptr;
};


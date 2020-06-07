#pragma once
#include <string>
#include <fstream>

class MemoryBuffer;

//Class that can write binary data either from a file or from a fixed size buffer 
//depending on the constructor used.
class BinaryWriter
{
public:
    //Writes binary data from file at path
    BinaryWriter(const std::string& inputPath);
    //Writes binary data from fixed size memory buffer
    BinaryWriter(char* buffer, uint32_t sizeInBytes);
    ~BinaryWriter();

    void Flush();

    void WriteUint8(uint8_t value);
    void WriteUint16(uint16_t value);
    void WriteUint32(uint32_t value);
    void WriteUint64(uint64_t value);

    void WriteInt8(int8_t value);
    void WriteInt16(int16_t value);
    void WriteInt32(int32_t value);
    void WriteInt64(int64_t value);

    void WriteChar(char value);
    void WriteNullTerminatedString(const std::string& value);

    void WriteFloat(float value);
    void WriteDouble(double value);

    void WriteFromMemory(void* data, size_t size);

    void SeekBeg(int absoluteOffset);
    void SeekCur(int relativeOffset);
    void Skip(int bytesToSkip);
    size_t Align(int alignmentValue = 2048);

    size_t Position() const;

private:
    std::ostream* stream_ = nullptr;
    MemoryBuffer* buffer_ = nullptr;
};


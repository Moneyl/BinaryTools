#pragma once
#include <string>
#include <fstream>

class BinaryWriter
{
public:
    BinaryWriter(const std::string& inputPath);
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

private:
    std::ofstream stream_;
};


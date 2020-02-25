#pragma once
#include <string>
#include <fstream>

class BinaryReader
{
public:
    BinaryReader(std::string inputPath);
    ~BinaryReader();

    uint8_t ReadUint8();
    uint16_t ReadUint16();
    uint32_t ReadUint32();
    uint64_t ReadUint64();

    int8_t ReadInt8();
    int16_t ReadInt16();
    int32_t ReadInt32();
    int64_t ReadInt64();

    char ReadChar();
    std::string ReadNullTerminatedString();
    std::string ReadFixedLengthString(int length);
    char NextChar();

    float ReadFloat();
    double ReadDouble();

    void SeekBeg(int absoluteOffset);
    void SeekCur(int relativeOffset);
    void Skip(int bytesToSkip);
    void Align(int alignmentAmount = 2048);

private:
    std::ifstream _stream;
};


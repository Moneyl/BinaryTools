#include "BinaryWriter.h"
#include "MemoryBuffer.h"

BinaryWriter::BinaryWriter(const std::string& inputPath)
{
    //Todo: Add more open options. For now should remove all data and write from scratch because of std::ofstream::trunc
    stream_ = new std::ofstream(inputPath, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
}

BinaryWriter::BinaryWriter(char* buffer, uint32_t sizeInBytes)
{
    buffer_ = new MemoryBuffer(buffer, sizeInBytes);
    stream_ = new std::ostream(buffer_);
}

BinaryWriter::~BinaryWriter()
{
    delete stream_;
    if (buffer_)
        delete buffer_;
}

void BinaryWriter::Flush()
{
    stream_->flush();
}

void BinaryWriter::WriteUint8(uint8_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 1);
}

void BinaryWriter::WriteUint16(uint16_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 2);
}

void BinaryWriter::WriteUint32(uint32_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 4);
}

void BinaryWriter::WriteUint64(uint64_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 8);
}

void BinaryWriter::WriteInt8(int8_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 1);
}

void BinaryWriter::WriteInt16(int16_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 2);
}

void BinaryWriter::WriteInt32(int32_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 4);
}

void BinaryWriter::WriteInt64(int64_t value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 8);
}

void BinaryWriter::WriteChar(char value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 1);
}

void BinaryWriter::WriteNullTerminatedString(const std::string& value)
{
    stream_->write(value.data(), 1);
}

void BinaryWriter::WriteFloat(float value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 4);
}

void BinaryWriter::WriteDouble(double value)
{
    stream_->write(reinterpret_cast<const char*>(&value), 8);
}

void BinaryWriter::WriteFromMemory(void* data, size_t size)
{
    stream_->write(reinterpret_cast<const char*>(data), size);
}

void BinaryWriter::SeekBeg(int absoluteOffset)
{
    stream_->seekp(absoluteOffset, std::ifstream::beg);
}

void BinaryWriter::SeekCur(int relativeOffset)
{
    stream_->seekp(relativeOffset, std::ifstream::cur);
}

void BinaryWriter::Skip(int bytesToSkip)
{
    stream_->seekp(bytesToSkip, std::ifstream::cur);
}

size_t BinaryWriter::Align(int alignmentValue)
{
    //Todo: Test that this math is working as expected. Had bug here in C# version
    const size_t remainder = stream_->tellp() % alignmentValue;
    size_t paddingSize = remainder > 0 ? alignmentValue - remainder : 0;
    Skip(paddingSize);
    return paddingSize;
}

size_t BinaryWriter::Position() const
{
    return stream_->tellp();
}
# BinaryTools
C++ classes for reading/writing binary data and some helper functions/classes. Based on C#'s `BinaryReader` and `BinaryWriter`.

## BinaryReader & BinaryWriter
Classes which can read/write binary data to/from a file or memory buffer. Both have functions for the most common primitive types. Ex: `uint32_t`, `int32_t`, `uint64_t`, `int64_t`, `float`, `double`, etc. See `BinaryReader.h` and `BinaryWriter.h` for a full list. The constructor used determines whether the class reads from a file (the constructor provides a file path), or a memory region (it provides a memory address and size). They can also read and write entire structs to or from memory using `ReadToMemory` and `WriteFromMemory`, respectively. 

## Other helpers and included classes
- `Span<T>`: A very simple wrapper around a fixed sized memory region used by ReadAllBytes. You must free the memory the span points to if it's heap allocated.
- `MemoryBuffer`: A simple class which inherits std::streambuf. Used by BinaryReader/Writer when interacting with a memory buffer.
- `ReadAllBytes(const std::string& filePath)`: Function that reads all bytes from a file and returns them in a Span<T>. Since it's using a span you must free the memory it returns once you're done with it.

#pragma once

//Simple wrapper around a contiguous area of memory
template<class T>
struct Span
{
public:
    Span(T* ptr, size_t size) : ptr_(ptr), size_(size) {}

    T* Data() { return ptr_; }
    size_t Size() { return size_; }

private:
    T* ptr_ = nullptr;
    size_t size_ = 0;
};
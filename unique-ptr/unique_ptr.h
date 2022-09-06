#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <cstddef>

template<typename T>
class unique_ptr {
public:
    unique_ptr() noexcept;
    unique_ptr(std::nullptr_t) noexcept;
    unique_ptr(T*) noexcept;
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr(unique_ptr&&) noexcept;
    ~unique_ptr();

public:
    unique_ptr& operator=(std::nullptr_t) noexcept;
    unique_ptr& operator=(const unique_ptr&n) = delete;
    unique_ptr& operator=(unique_ptr&& rhs) noexcept;

public:
    T& operator*() const noexcept;
    T* operator->() const noexcept;

public:
    T* get() const noexcept;
    void reset(T* new_ptr = nullptr) noexcept;
    T* release() noexcept;
    void swap(unique_ptr&) noexcept;

private: 
    T* m_ptr;
};

#include "unique_ptr.tpp"
#endif // UNIQUE_PTR_H
template<typename T>
unique_ptr<T>::unique_ptr() noexcept : m_ptr{nullptr} { }

template<typename T>
unique_ptr<T>::unique_ptr(std::nullptr_t) noexcept {
    unique_ptr();
}

template<typename T>
unique_ptr<T>::unique_ptr(T* new_ptr) noexcept {
    this->m_ptr = new_ptr;
}

template<typename T>
unique_ptr<T>::unique_ptr(unique_ptr&& rhs) noexcept : m_ptr{rhs.m_ptr} {
    rhs.m_ptr = nullptr;
}

 template<typename T>
 unique_ptr<T>::~unique_ptr() {
    delete m_ptr;
 }

 template<typename T>
 unique_ptr<T>& unique_ptr<T>::operator=(std::nullptr_t) noexcept {
    this->reset();
    return *this;
 }

template<typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr&& rhs) noexcept {
    this->reset();
    delete m_ptr;
    m_ptr = rhs.m_ptr;
    rhs.m_ptr = nullptr;
    return *this;
}

template<typename T>
T& unique_ptr<T>::operator*() const noexcept {
    return *m_ptr;
}

template<typename T>
T* unique_ptr<T>::operator->() const noexcept {
    return m_ptr;
}

template<typename T>
T* unique_ptr<T>::get() const noexcept {
    return m_ptr;
}

template<typename T>
void unique_ptr<T>::reset(T* new_ptr) noexcept {
    delete m_ptr;
    m_ptr = new_ptr;
}

template<typename T>
T* unique_ptr<T>::release() noexcept {
    T* ptr = m_ptr;
    m_ptr = nullptr;
    return ptr;
}

template<typename T>
void unique_ptr<T>::swap(unique_ptr& other) noexcept {
    std::swap(m_ptr, other.m_ptr);
}
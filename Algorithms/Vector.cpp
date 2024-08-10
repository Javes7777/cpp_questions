#include "Vector.hpp"

template <typename T>
Vector<T>::Vector() : vec(nullptr), capacity_(10), size_(0) {
    vec = new T[capacity_];
}

template <typename T>
Vector<T>::Vector(int initsize) : vec(nullptr), capacity_(2*initsize), size_(initsize) {
    vec = new T[capacity_];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    this->vec = new T[this->capacity_];
    for(int i=0; i < this->size_; i++) {
        this->vec[i] = other[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : vec(other.vec), capacity_(other.capacity_), size_(other.size_) {
    other.vec = nullptr;    
    other.capacity_ = 0;    
    other.size_ = 0;    
}

template <typename T>
Vector<T>::~Vector() {
    delete []vec;
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) {
        return *this;
    }
    delete []vec;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    this->vec = new T[this->capacity_];
    for(int i=0; i < this->size_; i++) {
        this->vec[i] = other[i];
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return vec[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return vec[index]; 
}

template <typename T>
T& Vector<T>::at(int index) {
    return vec[index];
}

template <typename T>
const T& Vector<T>::at(int index) const {
    return vec[index];
}

template <typename T>
void Vector<T>::push_back(const T& element) {
    if (this->size_ >= this->capacity_) {
        this->reserve(2 * this->capacity_);
    }
    this->vec[this->size_++] = element;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    } else {
        throw std::out_of_range("Vector is empty, cannot pop back.");
    }
}

template <typename T>
void Vector<T>::reserve(const int newCapacity) {
    if (newCapacity <= this->capacity_) {
        return; 
    }
    T* newVec = new T[newCapacity];
    try {
        for (int i = 0; i < this->size_; i++) {
            newVec[i] = vec[i];
        }
    } catch (...) {
        delete[] newVec;
        throw;
    }
    delete[] this->vec; 
    this->vec = newVec;
    this->capacity_ = newCapacity;
    return;
}

template <typename T>
int Vector<T>::size() const {
    return this->size_ + 1;
}

template <typename T>
bool Vector<T>::empty() const {
    return this->size_ == 0;
}

template <typename T>
int Vector<T>::capacity() const {
    return this->capacity_;
}

template <typename T>
void Vector<T>::clear() noexcept {
    if (this-> size_ == 0) return;
    this->size_=0;
    delete[] this->vec;
}
template <typename T>
void Vector<T>::shrink_to_fit() {
    T* newVec = new T[this->size_];
    for(int i=0; i < this->size_; i++) {
        newVec[i] = vec[i];
    }
    delete[] this->vec;
    this->vec = newVec;
    this->capacity_ = this->size_;
}

template <typename T>
T* Vector<T>::begin() noexcept {
    return vec;
}
template <typename T>
const T* Vector<T>::begin() const noexcept {
    return vec;
}
template <typename T>
T* Vector<T>::end() noexcept {
    return vec + size_;
}
template <typename T>
const T* Vector<T>::end() const noexcept {
    return vec + size_;
}

template <typename T>
T& Vector<T>::front() {
    if (size_ > 0) {
        return vec[0];
    } else {
        throw std::out_of_range("Vector is empty, no front element.");
    }
}
template <typename T>
const T& Vector<T>::front() const {
    if (size_ > 0) {
        return vec[0];
    } else {
        throw std::out_of_range("Vector is empty, no front element.");
    }
}
template <typename T>
T& Vector<T>::back() {
    if (size_ > 0) {
        return vec[size_ - 1];
    } else {
        throw std::out_of_range("Vector is empty, no back element.");
    }
}
template <typename T>
const T& Vector<T>::back() const {
    if (size_ > 0) {
        return vec[size_ - 1];
    } else {
        throw std::out_of_range("Vector is empty, no back element.");
    }
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    return !(this != other);
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    if ( this->size_ != other.size_ || this->capacity_ != other.capacity_ )
        return true;
    for(int i=0; i < this->size_; i++) {
        if ( this->vec[i] != other[i] ) 
            return true;
    }
    return false;
}

template <typename T>
void Vector<T>::set(const int index, const T element) {
    vec[index] = element;
}
template <typename T>
void Vector<T>::insert(const int index, const T element) {
    vec[index] = element;
}
template <typename T>
void Vector<T>::erase(const int index) {
    if ( index == size_ ) {}
}

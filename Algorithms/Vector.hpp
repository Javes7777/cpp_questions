#include<iostream>

template <typename T>
class Vector {
private: 
    T* vec;
    int capacity_;
    int size_;
public: 
    Vector();
    Vector(int initSize);
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other) noexcept;
    ~Vector();

    Vector<T>& operator=(const Vector<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    T& at(int index);
    const T& at(int index) const;

    void push_back(const T& element);
    void pop_back();

    void clear() noexcept;
    void shrink_to_fit();

    T* begin() noexcept;
    const T* begin() const noexcept;
    T* end() noexcept;
    const T* end() const noexcept;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;

    void reserve(const int newCapacity);

    void set(const int index, const T element);
    void insert(const int index, const T element);
    void erase(const int index);

    int size() const;
    int capacity() const;
    bool empty() const;
};

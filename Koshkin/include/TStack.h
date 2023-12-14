#pragma once
#include <iostream>

#define MAX_STACK_SIZE 1000
#define EXP_COEF 1.5

using namespace std;

template <class T>
class TStack {
private:
    T* pMem;
    size_t size;
    size_t end;

public:
    explicit TStack(size_t _size = 2);
    TStack(const TStack<T>& stack);
    TStack(TStack<T>&& stack) noexcept;

    ~TStack() { delete[] pMem; }

    T& Top();
    const T& Top() const;

    void Pop();
    void Push(const T& elem);

    size_t Size() const noexcept;
    bool IsEmpty() const noexcept;

    TStack& operator= (TStack<T>&& stack) noexcept;
    bool operator== (const TStack<T>& stack) const;
    bool operator!= (const TStack<T>& stack) const;
};

template<class T>
inline TStack<T>::TStack(const TStack<T>& stack) {
    size = stack.end + 1;
    pMem = new T[size];
    end = stack.end;

    for (size_t i = 0; i < end; i++) {
        pMem[i] = stack.pMem[i];
    }
}

template<class T>
inline TStack<T>::TStack(TStack<T>&& stack) noexcept {
    pMem = stack.pMem;
    stack.pMem = nullptr;
    size = stack.size;
    end = stack.end;
}

template<class T>
inline TStack<T>::TStack(size_t _size) {
    size = _size;
    end = 0;
    if ((size < 1) || (size > MAX_STACK_SIZE)) throw length_error("Неверный размер стека");
    pMem = new T[size];
}

template<class T>
inline TStack<T>& TStack<T>::operator=(TStack<T>&& stack) noexcept {
    swap(pMem, stack.pMem);
    size = stack.size;
    end = stack.end;
    return *this;
}

template<class T>
inline void TStack<T>::Push(const T& elem) {
    if (end >= size) {
        T* tmp = new T[size_t(size * EXP_COEF) + 1];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = pMem[i];
        }
        size = size_t(size * EXP_COEF) + 1;
        delete[] pMem;
        pMem = tmp;
    }
    pMem[end] = elem;
    end++;
}

template<class T>
inline bool TStack<T>::operator==(const TStack<T>& stack) const {
    if (end != stack.end) return false;

    for (size_t i = 0; i < end; i++) {
        if (stack.pMem[i] != pMem[i]) return false;
    }

    return true;
}

template<class T>
inline T& TStack<T>::Top() {
    if (end == 0) throw out_of_range("Стек пустой");
    return pMem[end - 1];
}

template<class T>
inline bool TStack<T>::operator!=(const TStack<T>& stack) const {
    return !(*this == stack);
}

template<class T>
inline const T& TStack<T>::Top() const {
    if (end == 0) throw out_of_range("Стек пустой");
    return pMem[end - 1];
}

template<class T>
inline void TStack<T>::Pop() {
    if (end == 0) throw out_of_range("Стек пустой");
    end--;
}

template<class T>
inline bool TStack<T>::IsEmpty() const noexcept {
    return end == 0;
}

template<class T>
inline size_t TStack<T>::Size() const noexcept {
    return size;
}



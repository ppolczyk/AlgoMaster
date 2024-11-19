#pragma once
#include <stdexcept>

template <typename T> 
class Vector {
public:
    Vector() : size_(0), capacity_(1){
        data_ = new T[capacity_];
    }
    
    ~Vector() {
        delete[] data_;
    }

    void push_back(const T& value) {
        if (size_ == capacity_){
            resize();
        }
        data_[size_] = value;
        ++size_; 
    }
    
    void pop_back() {
        if (size_ > 0) {
        --size_;
        }
    }

    T& operator[](int index) const {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("index out of range!");
        }
        return data_[index];
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    void clean() {
        return size_=0;
    }

    T at(int index) const {
        if (index >= size_ || index < 0) {
            throw std::out_of_range("index out of range!");
        }
        return data_[index];
    }
    
    void reserve(int newCapacity) {
        if(newCapacity > capacity_) {
            T* newData = new T[newCapacity];
            for (int i=0; i<size_; i++) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }
    }

    void empty() {
        size_=0;
    }

    T front() const {
        if (size_ == 0) throw std::out_of_range("Vector is empty");
        return data_[0];
    }

    T back () const {
        if (size_ == 0) throw std::out_of_range("Vector is empty");
        return data_[size_ - 1];
    }

    void shrink_to_fit() {
        if (size_ < capacity_) {
            T* newData = new T[size_];
                for (int i=0; i<size_; i++) {
                    newData[i] = data_[i];
                }
            delete[] data_;
            data_ = newData;
            capacity_ = size_;
        }
    }
    
private:
    T* data_;
    int size_=0;
    int capacity_=1;

    void resize() {
        capacity_*=2;
        T* newData = new T[capacity_];
        for (int i=0; i<size_; i++) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
    }
};
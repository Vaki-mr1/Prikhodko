#include <iostream>

class Vector {
private:
    int* data;
    size_t capacity;
    size_t size;

    void resize() {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        int* new_data = new int[new_capacity];
        
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector() : data(nullptr), capacity(0), size(0) {}
    
    Vector(size_t initial_capacity) : capacity(initial_capacity), size(0) {
        if (capacity > 0) {
            data = new int[capacity];
        } else {
            data = nullptr;
        }
    }
    
    Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
        if (capacity > 0) {
            data = new int[capacity];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            
            capacity = other.capacity;
            size = other.size;
            
            if (capacity > 0) {
                data = new int[capacity];
                for (size_t i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }
    
    ~Vector() {
        delete[] data;
    }
    
    void push_back(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }
    
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }
    
    int& operator[](size_t index) {
        return data[index];
    }
    
    const int& operator[](size_t index) const {
        return data[index];
    }
    
    size_t get_size() const {
        return size;
    }
    
    size_t get_capacity() const {
        return capacity;
    }
    
    bool empty() const {
        return size == 0;
    }
    
    void clear() {
        size = 0;
    }
    
    void insert(size_t index, int value) {
        if (index > size) {
            return;
        }
        
        if (size >= capacity) {
            resize();
        }
        
        for (size_t i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        
        data[index] = value;
        size++;
    }
    
    void erase(size_t index) {
        if (index >= size) {
            return;
        }
        
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        
        size--;
    }
    
    int& front() {
        return data[0];
    }
    
    const int& front() const {
        return data[0];
    }
    
    int& back() {
        return data[size - 1];
    }
    
    const int& back() const {
        return data[size - 1];
    }
    
    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity) {
            return;
        }
        
        int* new_data = new int[new_capacity];
        
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    
    void shrink_to_fit() {
        if (size == capacity) {
            return;
        }
        
        if (size == 0) {
            delete[] data;
            data = nullptr;
            capacity = 0;
            return;
        }
        
        capacity = size;
        int* new_data = new int[capacity];
        
        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    
    int* begin() {
        return data;
    }
    
    const int* begin() const {
        return data;
    }
    
    int* end() {
        return data + size;
    }
    
    const int* end() const {
        return data + size;
    }
};
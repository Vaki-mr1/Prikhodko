#include <iostream>

template <typename T>
class Subvector {
private:
    T* dataArr;
    unsigned int sz;
    unsigned int cap;

    void copyFrom(const Subvector& src) {
        dataArr = new T[src.cap];
        for (unsigned int i = 0; i < src.sz; i++) {
            dataArr[i] = src.dataArr[i];
        }
        sz = src.sz;
        cap = src.cap;
    }

public:
    Subvector() : dataArr(nullptr), sz(0), cap(0) {}

    explicit Subvector(unsigned int c) {
        dataArr = new T[c];
        sz = 0;
        cap = c;
    }

    ~Subvector() {
        delete[] dataArr;
    }

    Subvector(const Subvector& other) {
        copyFrom(other);
    }

    Subvector(Subvector&& other) {
        dataArr = other.dataArr;
        sz = other.sz;
        cap = other.cap;

        other.dataArr = nullptr;
        other.sz = 0;
        other.cap = 0;
    }

    Subvector& operator=(const Subvector& other) {
        if (this != &other) {
            delete[] dataArr;
            copyFrom(other);
        }
        return *this;
    }

    Subvector& operator=(Subvector&& other) {
        if (this != &other) {
            delete[] dataArr;
            dataArr = other.dataArr;
            sz = other.sz;
            cap = other.cap;

            other.dataArr = nullptr;
            other.sz = 0;
            other.cap = 0;
        }
        return *this;
    }

    bool push_back(const T& value) {
        if (sz >= cap) {
            unsigned int newCap = (cap == 0 ? 2 : cap * 2);

            T* tmp = new T[newCap];
            for (unsigned int i = 0; i < sz; i++) {
                tmp[i] = dataArr[i];
            }

            delete[] dataArr;
            dataArr = tmp;
            cap = newCap;
        }

        dataArr[sz++] = value;
        return true;
    }

    T pop_back() {
        if (sz == 0)
            return T{};
        sz--;
        return dataArr[sz];
    }

    bool resize(unsigned int newCap) {
        if (newCap == cap)
            return true;

        T* temp = new T[newCap];
        unsigned int m = (sz < newCap ? sz : newCap);

        for (unsigned int i = 0; i < m; i++) {
            temp[i] = dataArr[i];
        }

        delete[] dataArr;
        dataArr = temp;
        cap = newCap;
        sz = m;

        return true;
    }

    void shrink_to_fit() {
        if (sz == cap)
            return;

        if (sz == 0) {
            delete[] dataArr;
            dataArr = nullptr;
            cap = 0;
            return;
        }

        T* tmp = new T[sz];
        for (unsigned int i = 0; i < sz; i++) {
            tmp[i] = dataArr[i];
        }

        delete[] dataArr;
        dataArr = tmp;
        cap = sz;
    }

    void clear() {
        sz = 0;
    }

    T& operator[](unsigned int idx) {
        return dataArr[idx];
    }

    const T& operator[](unsigned int idx) const {
        return dataArr[idx];
    }

    unsigned int size() const {
        return sz;
    }

    unsigned int get_capacity() const {
        return cap;
    }
};
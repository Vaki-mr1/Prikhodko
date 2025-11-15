#include <iostream>

template <class T>
class subforwardlist {
private:
    struct Elem {
        T value;
        Elem* nxt;
        Elem(const T& v) : value(v), nxt(nullptr) {}
    };

    Elem* first;

    void copyFrom(const subforwardlist& other) {
        Elem* p = other.first;
        while (p != nullptr) {
            addBack(p->value);
            p = p->nxt;
        }
    }

public:
    subforwardlist() {
        first = nullptr;
    }

    ~subforwardlist() {
        removeAll();
    }

    subforwardlist(const subforwardlist& other) {
        first = nullptr;
        copyFrom(other);
    }

    subforwardlist(subforwardlist&& other) {
        first = other.first;
        other.first = nullptr;
    }

    subforwardlist& operator=(const subforwardlist& other) {
        if (this != &other) {
            removeAll();
            copyFrom(other);
        }
        return *this;
    }

    subforwardlist& operator=(subforwardlist&& other) {
        if (this != &other) {
            removeAll();
            first = other.first;
            other.first = nullptr;
        }
        return *this;
    }

    void addBack(const T& x) {
        Elem* e = new Elem(x);
        if (first == nullptr) {
            first = e;
        } else {
            Elem* cur = first;
            while (cur->nxt != nullptr)
                cur = cur->nxt;
            cur->nxt = e;
        }
    }

    T removeBack() {
        if (first == nullptr) {
            return T{};
        }
        if (first->nxt == nullptr) {
            T val = first->value;
            delete first;
            first = nullptr;
            return val;
        }

        Elem* cur = first;
        while (cur->nxt->nxt != nullptr)
            cur = cur->nxt;

        T val = cur->nxt->value;
        delete cur->nxt;
        cur->nxt = nullptr;
        return val;
    }

    void addFront(const T& x) {
        Elem* e = new Elem(x);
        e->nxt = first;
        first = e;
    }

    T removeFront() {
        if (first == nullptr) return T{};
        T val = first->value;
        Elem* tmp = first;
        first = first->nxt;
        delete tmp;
        return val;
    }

    void insertAt(unsigned int pos, const T& val) {
        if (pos == 0) {
            addFront(val);
            return;
        }

        Elem* cur = first;
        for (unsigned int i = 1; i < pos && cur != nullptr; i++) {
            cur = cur->nxt;
        }

        if (cur == nullptr) return;

        Elem* e = new Elem(val);
        e->nxt = cur->nxt;
        cur->nxt = e;
    }

    T eraseAt(unsigned int pos) {
        if (pos == 0) {
            return removeFront();
        }

        Elem* cur = first;
        for (unsigned int i = 1; i < pos && cur != nullptr; i++) {
            cur = cur->nxt;
        }

        if (cur == nullptr || cur->nxt == nullptr) {
            return T{};
        }

        Elem* del = cur->nxt;
        T val = del->value;
        cur->nxt = del->nxt;
        delete del;
        return val;
    }

    unsigned int count() const {
        unsigned int c = 0;
        Elem* p = first;
        while (p != nullptr) {
            c++;
            p = p->nxt;
        }
        return c;
    }

    void removeAll() {
        while (first != nullptr) {
            Elem* tmp = first;
            first = first->nxt;
            delete tmp;
        }
    }
};
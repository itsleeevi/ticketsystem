#ifndef RAILWAYSTORE_H_INCLUDED
#define RAILWAYSTORE_H_INCLUDED


template <typename T>
class railwayStore {
    T *data;
    int siz;
public:
    railwayStore() {
        siz = 0;
        data = nullptr;      
    }
    void push_back(const T& rhs) {
        T *temp = new T[siz + 1];
        for (int i = 0; i < siz; ++i)
            temp[i] = data[i];
        temp[siz] = rhs;
        delete[] data;
        data = temp;
        ++siz;
    }
    T operator[](const unsigned int idx) const {
        return data[idx];
    }
    T& operator[](const unsigned int idx) {
        return data[idx];
    }
    int size() {
        return siz;
    }
    void popAll() { 
        siz = 0;
     }
    ~railwayStore() {
        if (data != nullptr)
            delete[] data;
    }
};


#endif
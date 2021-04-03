//
// Created by paolo on 31/03/2021.
//

#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H


template<typename T>
class Vector {
private:
    int size;
    T* arr;
public:
        Vector(){
            size=10;
            arr = new T[size];
        }

        ~Vector(){
            size=0;
            delete[] arr;
            arr = nullptr;
        }

        T& operator[](int i){
            if(i >= size-1)
                resize(size+size/2);
            return arr[i];
        }

        void resize(int new_size){
            T* arrnew = new T[new_size];
            for(int i=0; i<new_size && i<size; i++)
                arrnew[i] = arr[i];
            delete[] arr;
            arr = arrnew;
            size = new_size;
        }

        void print(int i){
            for (int j = 0; j < i; ++j) {
                std::cout << arr[j] << " ";
            }
        }




};



#endif //LAB2_VECTOR_H

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
            size = 0;
            arr = nullptr;
        }

        explicit Vector(int dim){
            size=dim;
            arr = new T[size];
        }

        ~Vector(){
            size=0;
            delete[] arr;
            arr = nullptr;
        }

        Vector(const Vector &v1){
            size = v1.size;
            arr = new T[size];
            for(int i=0; i<size; i++){
                arr[i] = v1.arr[i];
            }
        }

        Vector(Vector &&v1) noexcept {
            size = v1.size;
            arr = v1.arr;
            v1.arr = nullptr;
        }

        Vector& operator=(Vector<int> v1){
            if(arr!=v1.arr){
                if (arr != nullptr){
                    delete[] arr;
                    size = v1.size;
                    v1.size = 0;
                    arr = new T[size];
                    for (int i = 0; i < size; i++){
                        arr[i] = v1[i];
                    }
                }
            }
            return *this;
        }

        Vector& operator=(Vector &&v1) noexcept {
            if(arr!=v1.arr){
                delete[] arr;
                arr = v1.arr;
                size = v1.size;
                v1.arr = nullptr;
                v1.size = 0;
            }
            else{
                v1.arr = nullptr;
                v1.size = 0;
            }
            return *this;
        }

        T& operator[](int i){
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

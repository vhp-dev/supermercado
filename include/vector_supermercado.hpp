#ifndef VECTOR_SUPERMERCADO_HPP
#define VECTOR_SUPERMERCADO_HPP

#include <string>

template <typename T>
class vector_supermercado{
    private:
        size_t capacity;
        size_t size;
        T* elements;
    
    public:
        vector_supermercado(){
            this->capacity = 1;
            this->size = 0;
            this->elements = new T[capacity];         
        }

        void push_back(T element){
            if(size >= capacity){
                resizeCapacity();
            }

            this->elements[size++] = element;
        }

        bool empty(){
            if(size==0){
                return true;
            }else
            {
                return false;
            }
            
        }

        void resizeCapacity(){
            size_t capacity2x;
            capacity2x = capacity*2;

            T* auxiliar = new T[capacity];

            // Passando informações para um vetor auxiliar temporário
            for(size_t i=0; i<capacity; i++){
                auxiliar[i] = this->elements[i];
            }

            delete[] this->elements;
            this->elements = new T[capacity2x];

            // Repassando informações para o vetor original 
            for(size_t i=0; i<capacity; i++){
                this->elements[i] = auxiliar[i];
            }

            capacity = capacity2x;
            delete[] auxiliar;

        }

        T getElement(size_t index){
            if(index < size){
                return this->elements[index];
            }
        }

        size_t getCapacity(){
            return capacity;
        }

        T* begin(){
            return &elements[0];
        }

        T* end(){
            return &elements[size];
        }

        T* clear(){
            delete[] this->elements;
            this->capacity = 1;
            this->size = 0;
            this->elements = new T[capacity]; 
        }


};


#endif // !VECTOR_SUPERMERCADO_HPP
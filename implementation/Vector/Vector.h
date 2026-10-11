#include <stdexcept>
template <class T>
 class Vector{
         int size;
         int capacity;
         T* data;
    public:
        Vector():size(0), capacity(5), data(new T[5]){}
        ~Vector(){
            delete []  data;
        }
        Vector(Vector& other):size(other.size), capacity(other.capacity), data(new T[capacity]){
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
            }
        }
        Vector& operator=(Vector& other){
            if (&other != this ){
                this->capacity = other.capacity;
                this->size = other.size;
                delete [] data;
                this->data = new T[other.capacity];
                for(int i = 0; i < other.size; i++){
                    data[i] = other.data[i];
                }
            }
           return *this;
        }
        void push_back(const T& el){
            if(size >= capacity){
                capacity *= 2;
                T* new_data = new T[capacity];
                for (int i = 0;i < size;i++) {
                    new_data[i] = data[i];
                }
                delete [] data;
                data = new_data;
            }
            data[size] = el;
            size++;
        }
        void pop_back(){
            if(size != 0){
                size--;
            }
            else throw std::runtime_error("nechego udalyat");
        }
        T& operator[](int index){
            if(index >= 0 && index < size){
                return data[index];
            }
            throw std::out_of_range("kuda polez");
        }
        void insert(int pos, T& val){
            if(size >= capacity){
                capacity *= 2;
                T* new_data = new T[capacity];
                for (int i = 0;i < size;i++) {
                    new_data[i] = data[i];
                }
                delete [] data;
                data = new_data;
            }
            if(pos >= 0 && pos <= size){
                for(int i = size - 1; i >= pos; i-- ) data[i + 1] = data[i];
                data[pos] = val;
                size++;
             }
            else{
                throw std::out_of_range("kuda polez");
            }

        }
        void erase(int pos){
            if(pos >=0 && pos < size){
                for(int i = pos; i < size - 1; i++ ) data[i] = data[i + 1];
                size--;
            }
            else{
                throw std::out_of_range("kuda polez");
            }
        }

        void swap(Vector& other){
            int tmp = size;
            size = other.size;
            other.size = tmp;

            tmp = capacity;
            capacity = other.capacity;
            other.capacity = tmp;

            T* tmpd = data;
            data = other.data;
            other.data = tmpd;
        }
        void clear(){
            size = 0;
        }
        void resize(int new_size){
            if(this-> size < new_size){
                capacity = new_size * 2;
                size = new_size;
                
            }
            else{
                throw std::runtime_error("logical size is greater than physical one");
            }
        }
        T& front(){
            if (size)return data[0];
            else throw std::runtime_error("empty arr");
        }
        T& back(){
            if (size)return data[size - 1];
            else throw std::runtime_error("empty arr");
        }
        int get_size(){ return size;}
        int get_capacity(){ return capacity;}
 };

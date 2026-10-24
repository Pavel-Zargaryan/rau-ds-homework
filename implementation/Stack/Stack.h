#ifndef STACK_H
#define STACK_H

#include <stdexcept>
template <typename T>
class Stack {
private:
    T* data;
    int cap;
    int size;
    
    void expand(){
        cap *= 2;
        T* new_data = new T[cap];
       for(int i = 0; i < size ; i++){
           new_data[i] = data[i];
       } 
       delete [] data;
       data = new_data;       
    };

public:
    /// 1. Конструктор по умолчанию
    Stack():cap(10), size(0), data(new T[10]){}
    
    /// 2. Деструктор
    ~Stack(){
        delete [] data;
    }
    
    /// 3. Конструктор копирования
    Stack(const Stack& other): cap(other.cap), size(other.size), data(new T[cap]){
        for(int i = 0; i < size ; i++){
            data[i] = other.data[i];
        } 
    }
    
    /// 4. Оператор присваивания
    Stack& operator=(const Stack& other){
        if (&other == this) return *this;
        cap = other.cap;
        size = other.size;
        delete [] data;
        data = new T[cap];
        for(int i = 0; i < size ; i++){
            data[i] = other.data[i];
        } 
        return *this;        
    }
    
    /// 5. push(const T& x) - добавить в стек
    void push(const T& x){
        if (size == cap) expand();
        data[size] = x;
        size++;
    }
    
    /// 6. pop() - удалить с вершины
    void pop(){
        if(size) size--;
    }
    
    /// 7. top() - вершина стека
    T& top(){
       if (size) return data[size - 1];
       throw  std::runtime_error("empty stack");
    }
    const T& top() const{
      if (size)  return data[size - 1];
      throw  std::runtime_error("empty stack");
    }
    
    /// 8. size() - количество элементов
    int getsize() const{
        return size;
    }
    
    /// 9. capacity() - вместимость
    int capacity() const{
        return cap;
    }
    
    /// 10. is_empty() - пуст ли
    bool is_empty() const{
        return !((bool) size);
    }
    
    /// 11. clear() - очистить
    void clear(){
        size = 0;
    }
    
    /// 12. peek() - посмотреть вершину без удаления
    T& peek(){
       if (size) return data[size - 1];
       throw  std::runtime_error("empty stack");
    }
    const T& peek() const{
      if (size)  return data[size - 1];
      throw  std::runtime_error("empty stack");
    }
    
};

#endif // STACK_H

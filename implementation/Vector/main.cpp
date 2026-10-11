#include "Vector.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <stdexcept>


// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(5);
    assert(v.get_size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.get_size() == 3);
    assert(v.back() == 15);    
    std::cout << "test_push_back passed" << std::endl;
}

// void test_pop_back() { ... }
// void test_operator_bracket() { ... }
// void test_back() { ... }
// void test_front() { ... }
// void test_insert() { ... }
// void test_erase() { ... }
// void test_swap() { ... }
// void test_clear() { ... }
// void test_resize() { ... }
// void test_copy_constructor() { ... }
// void test_assignment_operator() { ... }
void test_copy_constructor() {
    Vector<int> orig;

    orig.push_back(10);
    orig.push_back(20);
    orig.push_back(30);

    Vector<int> cp(orig);
    assert(cp[0] == 10);
    assert(cp[1] == 20);
    assert(cp[2] == 30);
    std::cout << "test_copy_constructor passed" << std::endl;

}

void test_operator_assignment() {
    Vector<int> src;

    src.push_back(10);
    src.push_back(20);
    src.push_back(30);

    Vector<int> dest;
    dest.push_back(99);

    dest = src;

    assert(dest[0] == 10);
    assert(dest[1] == 20);
    assert(dest[2] == 30);

    Vector<int> self;
    self.push_back(4);
    self.push_back(5);

    self = self;
    assert(self[0] == 4);
    assert(self[1] == 5);

    Vector<int> empty;
    dest = empty;
    assert(dest.get_size() == 0);
    std::cout << "test_operator_assignment passed" << std::endl;

}

void test_pop_back() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);

    v.pop_back();
    assert(v.get_size() == 1);
    v.pop_back();
    try{
        v.pop_back();
    }
    catch(std::runtime_error e){
        assert(e.what());
    }
    

    std::cout << "test_pop_back passed" << std::endl;

    }

void test_operator_bracket() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);

    v[1] = 99;
    assert(v[1] == 99);

    try{
        v[90] = 0;
    }
    catch(std::out_of_range e){
        assert(e.what());
    }
    std::cout << "test_operator_bracket passed" << std::endl;

}

void test_insert() {
    Vector<int> v;
    int num = 10;
    v.insert(0, num);

    assert(v[0] == 10);

    int num1 = 5;
    v.insert(0, num1);

    assert(v[0] == 5);
    assert(v[1] == 10);

    int num2 = 7;
    v.insert(1, num2);

    assert(v[0] == 5);
    assert(v[1] == 7);
    assert(v[2] == 10);

    Vector<int> full;

    for (int i = 0; i < 5; ++i) {
        full.push_back(i);
    }
    full.insert(2, num);

    assert(full[0] == 0);
    assert(full[1] == 1);
    assert(full[2] == 10);
    assert(full[3] == 2);
    assert(full[4] == 3);
    assert(full[5] == 4);
    std::cout << "test_insert passed" << std::endl;
}

void test_erase() {
    Vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    v.erase(1);

    assert(v[0] == 10);
    assert(v[1] == 30);
    assert(v[2] == 40);

   try{
       v.erase(99);
   }
   catch(std::out_of_range e){
       assert(e.what());
   }
   std::cout << "test_erase passed" << std::endl;

}

void test_swap() {
    Vector<int> a;
    Vector<int> b;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    b.push_back(99);

    a.swap(b);

    assert(a[0] == 99);

    assert(b[0] == 1);
    assert(b[1] == 2);
    assert(b[2] == 3);

    a.swap(a);

    assert(a[0] == 99);

    Vector<int> empty;
    empty.swap(a);

    assert(empty[0] == 99);
    assert(a.get_size() == 0);
    std::cout << "test_swap passed" << std::endl;

   
}

void test_clear() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.clear();
    
    v.push_back(42);
    assert(v[0] == 42);

    std::cout << "test_clear passed" << std::endl;

}

void test_resize() {
    Vector<int> v;

    v.resize(3);
    assert(v.get_size() == 3);
    std::cout << "test_resize passed" << std::endl;

}

void test_front() {
    Vector<int> v;
    v.push_back(10);

    assert(v.front() == 10);

    v.front() = 99;

    assert(v[0] == 99);
    std::cout << "test_front passed" << std::endl;

}

void test_back() {
    Vector<int> v;
    v.push_back(10);

    assert(v.back() == 10);

    v.push_back(20);
    v.push_back(30);

    assert(v.back() == 30);

    v.back() = 99;

    assert(v[2] == 99);
    std::cout << "test_back passed" << std::endl;
}


int main() {
    std::cout << "Running Vector tests" << std::endl;
    
    test_push_back();
    test_copy_constructor();
    test_operator_assignment();
    test_pop_back();
    test_operator_bracket();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_front();
    test_back();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}

#include "Stack.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

void test_push() {
    Stack<int> s;
    
    s.push(5);
    assert(s.getsize() == 1);
    assert(s.top() == 5);
    
    s.push(10);
    s.push(15);
    assert(s.getsize() == 3);
    assert(s.top() == 15);
    
    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.pop();
    assert(s.getsize() == 1);
    assert(s.top() == 5);

    s.pop();
    s.pop();
    assert(s.getsize() == 0);

    std::cout << "test_pop passed" << std::endl;
}

void test_top() {
    Stack<int> s;

    s.push(10);
    assert(s.top() == 10);

    s.push(20);
    assert(s.top() == 20);

    Stack<int> s1;
    try {
        s1.top();
    } catch (std::runtime_error err) {
        assert(err.what());
    }

    std::cout << "test_top passed" << std::endl;
}

void test_getsize() {
    Stack<int> s;

    assert(s.getsize() == 0);

    s.push(5);
    assert(s.getsize() == 1);

    s.push(10);
    assert(s.getsize() == 2);

    std::cout << "test_getsize passed" << std::endl;
}

void test_capacity() {
    Stack<int> s;

    assert(s.capacity() == 10);

    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    s.push(10);
    assert(s.capacity() == 20);

    std::cout << "test_capacity passed" << std::endl;
}

void test_is_empty() {
    Stack<int> s;

    assert(s.is_empty() == true);

    s.push(5);
    assert(s.is_empty() == false);
    std::cout << "test_is_empty passed" << std::endl;
}

void test_clear() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.clear();
    assert(s.is_empty() == true);
    std::cout << "test_clear passed" << std::endl;
}

void test_peek() {
    Stack<int> s;

    s.push(5);
    s.push(10);

    assert(s.peek() == 10);

    s.peek() = 20;
    assert(s.peek() == 20);
    
    Stack<int> s1;
    try {
        s1.peek();
    } catch (std::runtime_error err) {
        assert(err.what());
    }


    std::cout << "test_peek passed" << std::endl;
}

void test_copy_constructor() {
    Stack<int> s1;

    s1.push(5);
    s1.push(10);
    s1.push(15);

    Stack<int> s2(s1);

    assert(s2.getsize() == 3);
    assert(s2.top() == 15);

    s2.pop();
    assert(s2.top() == 10);
    assert(s1.top() == 15);

    s2.push(20);
    assert(s2.top() == 20);
    assert(s1.top() == 15);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Stack<int> s1;
    Stack<int> s2;

    s1.push(5);
    s1.push(10);
    s1.push(15);

    s2.push(100);

    s2 = s1;

    assert(s2.getsize() == 3);
    assert(s2.top() == 15);

    s2.pop();
    assert(s2.top() == 10);
    assert(s1.top() == 15);

    Stack<int> s;

    s.push(5);
    s.push(10);

    s = s;

    assert(s.getsize() == 2);
    assert(s.top() == 10);

    std::cout << "test_assignment_operator passed" << std::endl;
}

// void test_pop() { ... }
// void test_top() { ... }

int main() {
    std::cout << "Running Stack tests" << std::endl;
    test_push();
    test_push();
    test_pop();
    test_top();
    test_getsize();
    test_capacity();
    test_is_empty();
    test_clear();
    test_peek();
    test_copy_constructor();
    test_assignment_operator();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

/*Move Semantics Exercies*/
#include <iostream>
#include <vector>

class A {

    private: 
        int* _number;

    public: 

    //Constructor
    //Assigns number to pointer _number, new keyword assigns to heap
    A(int number):_number(new int(number)) {
        std::cout << "Class A Constructor: " << number << std::endl;
    }

    //Destructor
    ~A() {
        std::cout << "Class A Destructor: ";
        //If pointer _number doesn't point to int, it should point to nullptr(keyword)
        if(_number != nullptr) {
            std::cout << *_number;
            //Delete pointer
            delete _number;
        } else {
            std::cout << "nullptr";
        } 
        std::cout << std::endl;
    }

    //Copy Construtor
    //Using previous class as input, that copied class' pointer _number to find the value
    A(const A& copyClass):_number(new int(*copyClass._number)) {
        std::cout << "Class A Copy Constructor: " << *_number << std::endl;

    }

    //Move Constructor
    A(A&& moveClass):_number(new int(*moveClass._number)) {
        moveClass._number = nullptr; 
        std::cout << "Class A Move Constructor: " << *_number << std::endl;

    }

    //Copy Assignment Operator
    A& operator=(const A& copyClass) {
        //Set current value to copyClass number
        *_number = *copyClass._number;
        std::cout <<"Class A Copy Assignment Operator: " << *_number << std::endl;
        //return this class from the operator
        return *this;
    }

    //Move Assignment Operator
    A& operator=(A&& copyClass) {
        //Set current value to copyClass number
        _number = copyClass._number;
        //Set previous class value to null
        copyClass._number = nullptr;
        std::cout <<"Class A Move Assignment Operator: " << *_number << std::endl;
        //return this class from the operator
        return *this;
    }


};

int main(int argc, char* argv[]) 
{
{
    std::cout << "Exercise 1:" << std::endl;
    A a1(3);
}
{
    std::cout << "Exercise 2:" << std::endl;
    A a1{3};
    A a2{a1};
    A a3{A{4}};
}
{
    std::cout << "Exercise 3:" << std::endl;
    std::vector<A> v;
    v.push_back(A{5});

}
{
    std::cout << "Exercise 4:" << std::endl;
    A a5{7};
    A a6{8};
    a6 = a5;    
}
{
    std::cout << "Exercise 5:" << std::endl;
    A a7{9};
    a7 = A{10};   
}
{
    std::cout << "Exercise 6:" << std::endl;
    //Create class a8 with value 11
    A a8{11};
    //Create class a9 by moving a8 to its position
    A a9{std::move(a8)};
    //a9 destructs with value 11
    //a8 produces nullptr as a9 took its place
}
return 0;
}
    

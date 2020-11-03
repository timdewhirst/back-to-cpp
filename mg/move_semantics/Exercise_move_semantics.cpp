//move semantics
//Add the following to a new class A:
//A private member _number which is a pointer to an int
//A public constructor that:


#include <iostream>
#include <vector>

class A{
    private:
        int* _number;
    public:
        A(int input); //constructor
        A(const A &obj);  // copy constructor
        A& operator=(const A& obj); //copy assignment operator
        A(A &&obj); //move constructor
        A& operator=(A&& obj); //move assigment operator
        ~A(); //destructor

};

//Define constructor
//Accepts an int as input argument
//Allocates an int on the heap and sets its value according to the input argument
//Points _number to the newly allocated int
//Prints to standard out what int value it has been initialized with
    A::A(int input){
        _number = new int;
        *_number = input;
        std::cout << "class A constructor: "<<*_number<<"\n";    
    }

//A destructor that:
//Prints what value _number points to before it frees the associated memory
//Prints nullptr if _number does not point to an int
//class A shall generate the following output:

    A::~A(){
        if(_number!=nullptr){
            std::cout<<"class A destructor: "<<*_number<<"\n";
        }else{
           std::cout<<"class A destructor: nullptr \n";
        };
        delete _number; 
    }

//copy constructor
    A::A(const A &obj){
        _number = new int;
        *_number = *obj._number;
        std::cout<<"class A copy constructor: "<<*_number<<"\n";
    }

//move constructor
    A::A(A &&obj){
        _number = obj._number;
        obj._number=nullptr;
        std::cout<<"class A move constructor: "<<*_number<<"\n";
    }
    
//copy assignment operator
    A& A::operator=(const A& obj){
        (*this->_number)= (*obj._number);
        std::cout<<"class A copy assignment operator: "<<*_number<<"\n";
        return *this;
    }

//move assignment operator
    A& A::operator=(A&& obj){
        if(this != &obj){
            delete _number;
            _number=obj._number;
            obj._number=nullptr;
            std::cout<<"class A move assignment operator: "<<*_number<<"\n";            
        }
        return *this;
    }

int main() {
    //Exercise 1. constructor+destructor
    //A a1{3}

    //Exercise 2. copy constructor
    /*A a1{3};
    A a2{a1};
    A a3{A{4}};*/

    //Exercise 3. move constructor
    /*vector<A> v;
    v.push_back(A{5});*/

    //Exercise 4. copy assignment operator
    /*A a5{7};
    A a6{8};
    a6 = a5;*/

    //Exercise 5. move assignment operator
    /*A a7{9};
    a7 = A{10};*/

    //Exercise 6. move function
    A a8{11};
    A a9{std::move(a8)};
};

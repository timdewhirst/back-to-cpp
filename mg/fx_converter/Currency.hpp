#pragma once
#include <iostream>
using namespace std;
//## Class __Currency__

//Atttributes:

//- code
//- name
//- numeric code

class Currency{
    private:
        string code;
        string name;
        int numeric_code;
    public:
        Currency();

//Constructor
    Currency(string new_name, string new_code, int new_numeric_code){
            code=new_code;
            name=new_name;
            numeric_code=new_numeric_code;
    }

//getCode to get code attribute
    string getCode (){
        return code;
    }
//setCode to set real part
    void setCode(string new_code){
        code=new_code;
    }

//getCode to get code attribute
    string getName (){
        return name;
    }
//setCode to set real part
    void setName(string new_name){
        name=new_name;
    }

//getCode to get code attribute
    double getNumericCode (){
        return numeric_code;
    }
//setCode to set real part
    void setNumericCode(int new_numeric_code){
        numeric_code=new_numeric_code;
    }

};
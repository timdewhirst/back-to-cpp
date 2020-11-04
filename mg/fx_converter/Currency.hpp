#pragma once

using namespace std;
#include <string>
#include <vector>
//## Class __Currency__

class Currency{
    private:
        string name;
        string code;
        int numeric_code;
        int minor_unit;
    public:
        Currency() {}

//Constructor
    Currency(string new_name, string new_code, int new_numeric_code,int minor_unit){
            name=new_name;
            code=new_code;
            numeric_code=new_numeric_code;
            this->minor_unit=minor_unit;
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

//getCode to get code attribute
    double getMinorUnit (){
        return minor_unit;
    }
//setCode to set real part
    void setMinorUnit(int new_minor_unit){
        minor_unit=new_minor_unit;
    }

};


bool getFileContent(string fileName);
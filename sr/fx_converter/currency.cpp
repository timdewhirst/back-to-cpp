#include "currency.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string Currency::getCode() {
    return code;
}

string Currency::getName() {
    return name;
}

int Currency::getNumerice_code() {
    return numeric_code;
}

void Currency::setCode(string value) {
    code = value;
}

void Currency::setName(string value) {
    name = value;
}

void Currency::setNumerice_code(int value) {
    numeric_code = value;
}

void readCurrenciesFromFile(string fileName, vector<Currency> &currencies) 
{
    ifstream file(fileName.c_str());
    if(!file) 
    {
        cout << "Cannot read from this file: " << fileName << endl;
    }
        
    string line;
    const char delim = ',';
    while(getline(file,line))
    {
        istringstream ss(line);
        Currency currency;
        string currName, currCode;
        int currNum;
        getline(ss, currName, delim);
        currency.setName(currName);
        getline(ss, currCode, delim);
        currency.setCode(currCode);
        ss >> currNum; ss.ignore(256, delim);
        currency.setNumerice_code(currNum);
        if (ss)
            currencies.push_back(currency); 
    }
    file.close();
}

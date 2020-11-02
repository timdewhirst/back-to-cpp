#include "currency.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


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
        getline(ss, currency.name, delim);
        getline(ss, currency.code, delim);
        ss >> currency.numeric_code; ss.ignore(256, delim);
        if (ss)
            currencies.push_back(currency); 
    }
    file.close();
}

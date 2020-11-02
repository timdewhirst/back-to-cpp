#include "exchangeRate.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void readExchangeRatesFromFile(string fileName, vector<ExchangeRate> &exchangeRates)
{
    ifstream file(fileName.c_str());
    if (!file)
    {
        cout << "Cannot read from this file: " << fileName << endl;
    }

    string line;
    const char delim = ',';
    while(getline(file, line))
    {
        istringstream ss(line);
        ExchangeRate exchangeRate;
        ss.ignore(256, delim);
        getline(ss, exchangeRate.base, delim);
        getline(ss, exchangeRate.quote, delim);
        ss >> exchangeRate.bid; ss.ignore(256, delim);
        ss >> exchangeRate.ask; ss.ignore(256, delim);

        if(ss)
            exchangeRates.push_back(exchangeRate);
    }
    file.close();
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "exchangeRate.hpp"

using namespace std;

string ExchangeRate::getBase() const{
    return base;
}

string ExchangeRate::getQuote() const{
    return quote;
}

double ExchangeRate::getBid() const{
    return bid;
}

double ExchangeRate::getAsk() const{
    return ask;
}

void ExchangeRate::setBase(string value) {
    base = value;
}

void ExchangeRate::setQuote(string value) {
    quote = value;
}

void ExchangeRate::setBid(double value) {
    bid = value;
}

void ExchangeRate::setAsk(double value) {
    ask = value;
}

void readExchangeRatesFromFile(const string fileName, vector<ExchangeRate> &exchangeRates)
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
        string exchangeBase, exchangeQuote;
        double exchangeBid, exchangeAsk;
        getline(ss, exchangeBase, delim);
        exchangeRate.setBase(exchangeBase);
        getline(ss, exchangeQuote, delim);
        exchangeRate.setQuote(exchangeQuote);
        ss >> exchangeBid; ss.ignore(256, delim);
        exchangeRate.setBid(exchangeBid);
        ss >> exchangeAsk; ss.ignore(256, delim);
        exchangeRate.setAsk(exchangeAsk);
        if(ss)
            exchangeRates.push_back(exchangeRate);
    }
    file.close();
}
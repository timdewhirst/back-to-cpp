#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

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

double ExchangeRate::getLast() const{
    return last;
}


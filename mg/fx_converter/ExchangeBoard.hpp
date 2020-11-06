#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "ExchangeRate.hpp"

//## Class __ExchangeBoard__

//- list of ExchangeRates
//- does the exchange

class ExchangeBoard{
    private:
        unordered_map<string, unordered_map<string,double>> exchangeRates;   
    public:
        bool didExchange=false;
        ExchangeBoard() {}

};
bool const corr_mon(unordered_map<string, unordered_map<string,double>> &bid,unordered_map<string, unordered_map<string,double>> &ask,const string &curr_from, const string &curr_to, const double &mon);

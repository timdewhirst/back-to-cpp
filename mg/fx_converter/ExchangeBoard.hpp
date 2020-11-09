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
double const corr_mon(unordered_map<string, unordered_map<string,double>> &ubid,unordered_map<string, unordered_map<string,double>> &uask,const string &curr_from, const string &curr_to, const double &amount);

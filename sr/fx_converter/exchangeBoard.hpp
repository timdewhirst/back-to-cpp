#include <string>
#include <vector>
#include <unordered_map>

#include "exchangeRate.hpp"

#pragma once

using namespace std;

class ExchangeBoard
{
    private: 
        unordered_map<string, unordered_map<string, const ExchangeRate*>> exchangeRates;

    public:
        double convertToIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary);
        double convertFromIntermediary(const unordered_map<string, ExchangeRate> &rates, const string & base, const string &quote, double amount, const string &intermediary);

};
    double exchange(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary);
    string findIntermediary(const unordered_map<string, ExchangeRate> &rates, const string &base, const string &quote);
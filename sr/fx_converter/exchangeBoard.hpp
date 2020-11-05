#include <string>
#include <vector>

#include "exchangeRate.hpp"

#pragma once

using namespace std;

class ExchangeBoard
{
    public:
        double convertToIntermediary(const vector<ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary);
        double convertFromIntermediary(const vector<ExchangeRate> &rates, const string & base, const string &quote, double amount, const string &intermediary);

};
    void displayRates(const vector<ExchangeRate> &exchangeRates);
    double exchange(const vector<ExchangeRate> &rates, const string &base, const string &quote, double amount, const string &intermediary);
#include <string>
#include <vector>

#include "exchangeRate.hpp"

#pragma once

using namespace std;

class ExchangeBoard
{
    public:
        double convertToUSD(vector<ExchangeRate> &rates, string &base, string &quote, double amount);
        double convertFromUSD(vector<ExchangeRate> &rates, string &quote, double amount);

};
    void displayRates(vector<ExchangeRate> &exchangeRates);
    double exchange(vector<ExchangeRate> &rates, string &base, string &quote, double amount);
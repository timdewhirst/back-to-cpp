#include <string>
#include <vector>
#include "exchangeRate.hpp"
#pragma once

using namespace std;

class ExchangeBoard
{
    public:

    void displayRates(vector<ExchangeRate> &exchangeRates);

    double convertToUSD(string base, string quote, double amount);
    double convertFromUSD(string quote, double amount);
    double exchange(string base, string quote, double amount);
};
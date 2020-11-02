#include <string>
#include <vector>
#pragma once

using namespace std;

class ExchangeRate
{
    public:

        string base;
        string quote;
        double bid;
        double ask;

        ExchangeRate() : base {""}, quote {""}, bid{0}, ask{0} {};
        ~ExchangeRate() {};

        void readExchangeRatesFromFile(string fileName, vector<ExchangeRate> &exchangeRates);
};
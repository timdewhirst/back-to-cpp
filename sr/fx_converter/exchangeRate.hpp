#include <string>
#include <vector>
#pragma once

using namespace std;

class ExchangeRate
{
    private:
        string base;
        string quote;
        double bid;
        double ask;

    public:
        ExchangeRate() : base {""}, quote {""}, bid{0}, ask{0} {};
        ~ExchangeRate() {};

        string getBase();
        string getQuote();
        double getBid();
        double getAsk();

        void setBase(string value);
        void setQuote(string value);
        void setBid(double value);
        void setAsk(double value);

        void readExchangeRatesFromFile(string fileName, vector<ExchangeRate> &exchangeRates);
};
#include <string>
#include <vector>
#include <unordered_map>

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

        string getBase() const;
        string getQuote() const;
        double getBid() const;
        double getAsk() const;

        void setBase(string value);
        void setQuote(string value);
        void setBid(double value);
        void setAsk(double value);
};

        void readExchangeRatesFromFile(const string fileName, unordered_map<string, ExchangeRate> &exchangeRates);
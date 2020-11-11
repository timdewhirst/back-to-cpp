/*ExchangeRate class allows for the creation of ExchangeRate objects
via the readFromFile method in ExchangeBoard*/

#include <string>
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
        double last;

    public:
        ExchangeRate() {}
        ExchangeRate(const string& new_base, const string& new_quote, double new_bid, double new_ask, double new_last):
            base{new_base}, quote{new_quote}, bid{new_bid}, ask{new_ask}, last{new_last} {}
        ~ExchangeRate() {}

        string getBase() const;
        string getQuote() const;
        double getBid() const;
        double getAsk() const;
        double getLast() const;

};
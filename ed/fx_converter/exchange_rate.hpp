#ifndef EXCHANGE_RATE_HPP
#define EXCHANGE_RATE_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ExchangeRate
{
private:
    string m_base;
    string m_quote;
    double m_bid;
    double m_ask;

public:
    ExchangeRate() {}
    ExchangeRate(const string& base, const string& quote) : m_base{base}, m_quote{quote} {}
    ExchangeRate(const string& base, const string& quote, double bid, double ask);
    ~ExchangeRate() {}

    const string& base() const { return m_base; }
    const string& quote() const { return m_quote; }
    string pair_name() const;
    
    double get_bid() const { return m_bid; }
    double get_ask() const { return m_ask; }

    double buy(double amount);
    double sell(double amount);

    // If -1 is passed, then the corresponding quote is not updated
    void update(double bid = -1, double ask = -1);
};


vector<ExchangeRate> load_rates(const string& fname);

#endif
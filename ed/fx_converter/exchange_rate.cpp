#include "exchange_rate.hpp"

ExchangeRate::ExchangeRate(const string& base, const string& quote, double bid, double ask) :
    m_base(base), m_quote(quote), m_bid(bid), m_ask(ask) {}

double ExchangeRate::buy(double amount)
{
    return amount * m_ask;
}
    
double ExchangeRate::sell(double amount)
{
    return amount * m_bid;
}

void ExchangeRate::update(double bid, double ask)
{
    if (bid != -1) m_bid = bid;
    if (ask != -1) m_ask = ask;
}

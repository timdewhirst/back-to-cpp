#include "exchange_rate.hpp"

ExchangeRate::ExchangeRate(const Currency& base, const Currency& quote, double rate)
{
    m_base = &base;
    m_quote = &quote;
    m_rate = rate;
}


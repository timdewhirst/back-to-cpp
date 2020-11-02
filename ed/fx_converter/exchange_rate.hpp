#include "currency.hpp"

class ExchangeRate
{
private:
    const Currency* m_base;
    const Currency* m_quote;
    double m_rate;

public:
    ExchangeRate(const Currency& base, const Currency& quote, double rate);
    ~ExchangeRate() {}

    double get_rate();
};

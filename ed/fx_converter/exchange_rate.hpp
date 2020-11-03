#include <string>

using namespace std;

class ExchangeRate
{
private:
    string m_base;
    string m_quote;
    double m_bid;
    double m_ask;

public:
    ExchangeRate(const string& base, const string& quote) : m_base{base}, m_quote{quote} {}
    ExchangeRate(const string& base, const string& quote, double bid, double ask);
    ~ExchangeRate() {}

    const string& base() { return m_base; }
    const string& quote() { return m_quote; }
    
    double get_bid() { return m_bid; }
    double get_ask() { return m_ask; }

    double buy(double amount);
    double sell(double amount);

    // If -1 is passed, then the corresponding quote is not updated
    void update(double bid = -1, double ask = -1);
};

#include <iostream>
#include "exchange_board.hpp"

using namespace std;

void ExchangeBoard::add_rates(const unordered_map<string, ExchangeRate>& rates)
{
    for (auto r : rates)
    {
        m_board[r.second.base()][r.second.quote()] = &rates.at(r.first);
        m_board[r.second.quote()][r.second.base()] = &rates.at(r.first);
    }
}

double ExchangeBoard::convert(const string& from, const string& to, double amount)
{
    auto i1 = m_board.find(from);

    // Check if a conversion from source ccy can be done
    if (i1 == m_board.end())
        return -1;

    cout << "First: " << i1->first << endl;

    auto i2 = i1->second.find(to);
    if (i2 == i1->second.end())
        return -1;
    
    cout << "Second: " << i2->first << endl;

    cout << "Currency: " << i2->second->pair_name() << endl;
    cout << "Bid: " << i2->second->get_bid() << endl;

    return 0;
}

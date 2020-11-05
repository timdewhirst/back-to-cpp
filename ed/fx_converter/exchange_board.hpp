#ifndef EXCHANGE_BOARD_HPP
#define EXCHANGE_BOARD_HPP

#include <string>
#include <unordered_map>
#include "exchange_rate.hpp"

using namespace std;

class ExchangeBoard
{
private:
    unordered_map<string, unordered_map<string, const ExchangeRate*>> m_board;
    
public:
    void add_rates(const unordered_map<string, ExchangeRate>& rates);
    
    double convert(const string& from, const string& to, double amount);
};

#endif
#ifndef EXCHANGE_BOARD_HPP
#define EXCHANGE_BOARD_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include "exchange_rate.hpp"

class ExchangeBoard
{
private:
    std::unordered_map<std::string, std::shared_ptr<ExchangeRate>> m_rates;
    std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<ExchangeRate>>> m_board;
    
public:
    
    double convert(const string& from, const string& to, double amount);

    bool load_rates(const string &fname);

    shared_ptr<ExchangeRate> get_rate(const string &ccy_pair);
};

#endif
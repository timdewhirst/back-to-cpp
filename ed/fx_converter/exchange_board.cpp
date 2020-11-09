#include <iostream>
#include <fstream>
#include <sstream>
#include "exchange_board.hpp"

using namespace std;

vector<string> split(const string &s, char delim);


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
    cout << "Ask: " << i2->second->get_ask() << endl;

    return 0;
}

shared_ptr<ExchangeRate> ExchangeBoard::get_rate(const string &ccy_pair)
{
    if (m_rates.find(ccy_pair) == m_rates.end())
        return nullptr;

    return m_rates[ccy_pair];
}

bool ExchangeBoard::load_rates(const string& fname)
{
    ifstream file;
    string line;
    vector<string> tokens;
    shared_ptr<ExchangeRate> p_rate;

    file.open(fname);

    if ((file.rdstate() & ifstream::failbit) != 0)
        return false;   

    // Skip the heading
    getline(file, line);

    while (getline(file, line))
    {
        tokens = split(line, ',');

        auto sp = make_shared<ExchangeRate>(tokens[0], tokens[1],
            stod(tokens[2]), stod(tokens[3]), stod(tokens[4]));
        m_rates[sp->pair_name()] = sp;

        m_board[sp->base()][sp->quote()] = sp;
        m_board[sp->quote()][sp->base()] = sp;
    }

    return true;
}

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;
    
    while (getline(ss, item, delim))
        result.push_back(item);

    return result;
}

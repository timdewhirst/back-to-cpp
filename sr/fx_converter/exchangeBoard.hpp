/*ExchangeBoard class reads data from a CSV file, creating Exchange Rate objects
and storing them in two vectors which are used to perform a currency exchange
with or without an intermediary value*/

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "exchangeRate.hpp"

using namespace std;

class ExchangeBoard
{
    private: 
        unordered_map<string, shared_ptr<ExchangeRate>> exchangeRates;
        unordered_map<string, unordered_map<string, shared_ptr<ExchangeRate>>> exchangeBoard;

    public:
        double convertToIntermediary(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote, double amount, const string &intermediary);
        double convertFromIntermediary(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string & base, const string &quote, double amount, const string &intermediary);
        void readExchangeRatesFromFile(const string &fileNames);

};
    double exchange(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote, double amount, const string &intermediary);
    string findIntermediary(const unordered_map<string, shared_ptr<ExchangeRate>> &rates, const string &base, const string &quote);
    
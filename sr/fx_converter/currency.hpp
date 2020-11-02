#include <string>
#include <vector>
#pragma once

using namespace std;

class Currency
{
    public:

        string code;
        string name;
        int numeric_code;

        Currency() : code{""}, name{""}, numeric_code{0} {};
        ~Currency() {};

        void readCurrenciesFromFile(string fileName, vector<Currency> &currencies);
};

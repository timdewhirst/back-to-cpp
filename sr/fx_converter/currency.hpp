#include <string>
#include <vector>
#pragma once

using namespace std;

class Currency
{
    private:
        string code;
        string name;
        int numeric_code;

    public:
        Currency() : code{""}, name{""}, numeric_code{0} {};
        ~Currency() {};

        string getCode() const;
        string getName() const;
        int getNumerice_code() const;
        void setCode(string value);
        void setName(string value);
        void setNumerice_code(int value);
};

        void readCurrenciesFromFile(const string fileName, vector<Currency> &currencies);

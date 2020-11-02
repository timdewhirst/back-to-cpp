#include <string>

using namespace std;

class Currency
{
private:
    string m_name;
    string m_code;
    int m_numeric_code;

public:
    Currency(const string& name, const string& code, const int numeric_code);
    ~Currency();

    const string& get_name();
    const string& get_code();
    int get_numeric_code();
};

#include "currency.hpp"

Currency::Currency(const string& name, const string& code, const int numeric_code)
{
    m_name = name;
    m_code = code;
    m_numeric_code = numeric_code;
}

Currency::~Currency()
{

}

const string& Currency::get_name()
{
    return m_name;
}

const string& Currency::get_code()
{
    return m_code;
}

int Currency::get_numeric_code()
{
    return m_numeric_code;
}

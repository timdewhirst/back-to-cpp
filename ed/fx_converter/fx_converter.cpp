#include <fstream>
#include <memory>
#include <iostream>
#include "exchange_board.hpp"

using namespace std;

int main()
{
    ExchangeBoard board;

    board.convert("EUR", "USD", 1000);
}

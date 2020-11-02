#include <fstream>

using namespace std;

int main()
{
    fstream fin;

    fin.open("./datasets/currencies.csv", ios::in);

    
    fin.close();
}
#include "globals.hpp"

using namespace std;

mutex g_mutex_cout;
atomic<double> g_last_quote;

# FX Converter Application

## Class __Currency__

Atttributes:

- code
- name
- numeric code

## Class __ExchangeRate__

Attributes:

- base
- quote
- bid
- ask

## Class __ExchangeBoard__

- list of ExchangeRates
- does the exchange

## Main application

Main application is __Converter app__, which is a console application with the following functionality:

- loads information about currencies from currencies.csv file
- loads exchange rates from exchange_rates.csv file
- asks for amount and currency to exchange from
- asks for currency to exchange to
- outputs exchanged amount
- if there is no way to make a currency exchange, outputs a message

## Threading and simulation of random walk

- Thread #1. The thread at random time intervals updates EUR/JPY using a random walk. Price change is caculated using the following formula:
  
  $new\_price = last\_price \times e^x$

  $x=\frac{0.10}{\sqrt{24\times60\times60}}\times{(rand() - 0.5)\times{4}}$

  $price\_change=new\_price - last\_price$

  $new\_bid=last\_bid + price\_change$

  $new\_ask=last\_ask + price\_change$

  > - $0.10\ (10\%)$ - daily EUR/JPY volatility. The volatility is exaggerated in order to get more volatile price movements.
  > - $rand()$ - a function that returns a random value from a uniform distribution between [0, 1]. At this stage, due to simpler implementation, a uniform distribution is used for stochastic component of the random walk. $(rand() - 0.5) \times 2$ generates a value that is between [-1, 1], which is subsequently scaled by 2 (and hence, multiplication by 4).

  Price updates are done at random time steps. The length of each time step is between 2-5 seconds.

  This thread will simulate a quote change captured from the market.

- Thread #2. The thread is "listening" for EUR/JPY quote change, and then updates EUR/JPY, as well as other currencies that have JPY in FX pair.

  This thread is responsible for updating all currency pairs that have JPY. This is done to simulate no arbitrage opportunity.

- Thread #3. Main thread is running main fx conversion program. Remember, that by the time user inputs all conversion details, the rate could be different.

  This is the main thread, that starts threads #1 and #2 and then runs the main program logic - currency conversion. It asks for currency to convert from, currency convert to, amount, then displays the following line (considering EUR, JPY, 100 was inputted, and EUR/JPY rate is 140.00) and asks for Y/N input.

  100 EUR -> 14000 JPY @ EUR/JPY 140.00. Do you confirm? (Y/N)

  If the rate changes while program is waiting for user input, the line above must be updated accordingly, e.g.:

  100 EUR -> 14010 JPY @ EUR/JPY 140.10. Do you confirm? (Y/N)

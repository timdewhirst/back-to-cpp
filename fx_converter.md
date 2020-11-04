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

A new thread at random time intervals updates EUR/USD using a random walk. 
A new thread is "listening" for EUR/JPY quote change, and then updates EUR/JPY, as well as other currencies that have JPY in FX pair.
Main thread is running main fx conversion program. Remember, that by the time user inputs all conversion details, the rate could be different.
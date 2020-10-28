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

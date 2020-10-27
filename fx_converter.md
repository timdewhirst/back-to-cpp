# FX Converter Application

## Class __Currency__

Atttributes:

- code
- name
- numeric code

## Class __ExchangeRate__

Attributes:

- from currency
- to currency
- rate

## Class __ExchangeBoard__

- list of ExchangeRates
- does the exchange

## Main application

Main application is __Converter app__, which is a console application with the following functionality.

- loads currencies information from a CSV file
- loads exchange rates from a CSV file
- asks for amount and currency to exchange from
- asks for currency to exchange to
- outputs exchanged amount

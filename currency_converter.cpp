#include <iostream>
using namespace std;

class CurrencyConverter
{
public:
    CurrencyConverter()
    {
        
        currencies[0] = ("USD", "usd");
        exchangeRates[0] = 119.48; 
        currencies[1] = ("EUR", "eur");
        exchangeRates[1] = 110; 
        currencies[2] = ("GBP", "gbp");
        exchangeRates[2] = 120; 
        currencies[3] = ("JPY", "jpy");
        exchangeRates[3] = 90; 
        currencies[4] = ("AUD", "aud");
        exchangeRates[4] = 85; 
        currencies[5] = ("CAD", "cad");
        exchangeRates[5] = 95; 
        currencies[6] = ("CHF", "chf");
        exchangeRates[6] = 125; 
        currencies[7] = ("CNY", "cny");
        exchangeRates[7] = 15; 
        currencies[8] = ("ZAR", "zar");
        exchangeRates[8] = 7; 
        currencies[9] = ("INR", "inr");
        exchangeRates[9] = 1.5; 
        currencies[10] = ("BDT", "bdt");
        exchangeRates[10] = 1; 
    }

    double convert(const string &from, const string &to, double amount)
    {
        double fromRate = 0, toRate = 0;
  
        for (int i = 0; i < 11; ++i)
        {
            if (currencies[i] == from)
            {
                fromRate = exchangeRates[i];
            }
            if (currencies[i] == to)
            {
                toRate = exchangeRates[i];
            }
        }

        if (fromRate == 0 || toRate == 0)
        {
            cerr << "Invalid currency code.\n";
            return 0;
        }

        return amount * (fromRate / toRate);
    }

private:
    string currencies[11];
    double exchangeRates[11];
};

int main()
{
    CurrencyConverter converter;

    string fromCurrency, toCurrency;
    double amount;

    cout << "Enter the currency to convert from: ";
    cout << "(USD,EUR,GBP,JPY,AUD,CAD,CHF,CNY,ZAR,INR,BDT)";
    cin >> fromCurrency;
    cout << "Enter the currency to convert to: ";
    cin >> toCurrency;
    cout << "Enter the amount: ";
    cin >> amount;

    double convertedAmount = converter.convert(fromCurrency, toCurrency, amount);

    if (convertedAmount != 0)
    {
        cout << amount << " " << fromCurrency << " is equivalent to " << convertedAmount << " " << toCurrency << endl;
    }
    else
    {
        cout << "Conversion failed. Please check the currency codes.\n";
    }

    return 0;
}

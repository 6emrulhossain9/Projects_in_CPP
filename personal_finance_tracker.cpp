#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction
{
private:
    string description;
    double amount;
    string type;

public:
    Transaction(string desc, double amt, string t) : description(desc), amount(amt), type(t) {}

    double getAmount()
    {
        return amount;
    }

    string getType()
    {
        return type;
    }

    void displayTransaction()
    {
        cout << type << ": " << description << " - $" << amount << endl;
    }
};

class PersonalFinanceTracker
{
private:
    vector<Transaction> transactions;
    double totalIncome;
    double totalExpenses;

public:
    PersonalFinanceTracker()
    {
        totalIncome = 0.0;
        totalExpenses = 0.0;
    }

    void addTransaction(string description, double amount, string type)
    {
        if (type == "Income")
        {
            totalIncome += amount;
        }
        else if (type == "Expense")
        {
            totalExpenses += amount;
        }

        Transaction newTransaction(description, amount, type);
        transactions.push_back(newTransaction);
    }

    void displayTransactions()
    {
        cout << "\nAll Transactions:\n";
        for (Transaction t : transactions)
        {
            t.displayTransaction();
        }
        cout << "------------------------\n";
    }

    void displayTotalIncome()
    {
        cout << "Total Income: $" << totalIncome << endl;
    }

    void displayTotalExpenses()
    {
        cout << "Total Expenses: $" << totalExpenses << endl;
    }

    void displayBalance()
    {
        double balance = totalIncome - totalExpenses;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main()
{
    PersonalFinanceTracker tracker;
    int option;
    string description;
    double amount;
    string type;

    while (true)
    {

        cout << "\nPersonal Finance Tracker\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View All Transactions\n";
        cout << "4. View Total Income\n";
        cout << "5. View Total Expenses\n";
        cout << "6. View Current Balance\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter income description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter amount: $";
            cin >> amount;
            tracker.addTransaction(description, amount, "Income");
            cout << "Income added successfully!" << endl;
            break;
        case 2:
            cout << "Enter expense description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter amount: $";
            cin >> amount;
            tracker.addTransaction(description, amount, "Expense");
            cout << "Expense added successfully!" << endl;
            break;
        case 3:
            tracker.displayTransactions();
            break;
        case 4:
            tracker.displayTotalIncome();
            break;
        case 5:
            tracker.displayTotalExpenses();
            break;
        case 6:
            tracker.displayBalance();
            break;
        case 7:
            cout << "Exiting... Thank you for using the Personal Finance Tracker!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

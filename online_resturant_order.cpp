#include <iostream>
#include <string>

using namespace std;

// Class representing a food item
class FoodItem {
private:
    string name;
    double price;

public:
    FoodItem() {}

    // Constructor to initialize food item
    FoodItem(string foodName, double foodPrice) {
        name = foodName;
        price = foodPrice;
    }

    // Function to display food item details
    void displayItem() {
        cout << name << " - $" << price << endl;
    }

    // Get the price of the food item
    double getPrice() {
        return price;
    }

    // Get the name of the food item
    string getName() {
        return name;
    }

    // Set the name of the food item
    void setName(string foodName) {
        name = foodName;
    }

    // Set the price of the food item
    void setPrice(double foodPrice) {
        price = foodPrice;
    }
};

// Class representing a restaurant
class Restaurant {
private:
    string name;
    FoodItem menu[10];  // Menu with a maximum of 10 food items
    int totalItems;

public:
    Restaurant() {
        totalItems = 0;
    }

    // Function to set restaurant name
    void setName(string restName) {
        name = restName;
    }

    // Function to add food items to the menu
    void addFoodItem() {
        if (totalItems < 10) {
            string foodName;
            double foodPrice;

            cout << "Enter the name of the food item: ";
            getline(cin, foodName);
            cout << "Enter the price of the food item: ";
            cin >> foodPrice;
            cin.ignore();  // Clear newline character left by cin

            menu[totalItems] = FoodItem(foodName, foodPrice);
            totalItems++;
        } else {
            cout << "Menu is full. Can't add more items." << endl;
        }
    }

    // Function to display the restaurant menu
    void displayMenu() {
        cout << "Welcome to " << name << "!" << endl;
        cout << "Here is the menu:\n";
        for (int i = 0; i < totalItems; i++) {
            cout << i + 1 << ". ";
            menu[i].displayItem();
        }
    }

    // Get a food item by its index
    FoodItem getFoodItem(int index) {
        if (index >= 0 && index < totalItems) {
            return menu[index];
        } else {
            return FoodItem();
        }
    }

    // Get the restaurant name
    string getName() {
        return name;
    }
};

// Class representing a customer
class Customer {
private:
    string name;
    double balance;

public:
    Customer(string customerName, double initialBalance) {
        name = customerName;
        balance = initialBalance;
    }

    // Display customer balance
    void displayBalance() {
        cout << "Your balance: $" << balance << endl;
    }

    // Place an order and deduct payment
    bool placeOrder(Restaurant& restaurant) {
        restaurant.displayMenu();
        int choice;
        cout << "\nEnter the number of the food item you'd like to order: ";
        cin >> choice;
        choice--;  // Adjust for 0-based index

        FoodItem item = restaurant.getFoodItem(choice);
        if (item.getName() != "") {
            double price = item.getPrice();
            cout << "You selected: " << item.getName() << " - $" << price << endl;

            if (balance >= price) {
                balance -= price;
                cout << "Order placed successfully!" << endl;
                displayBalance();
                return true;
            } else {
                cout << "Insufficient balance to place the order." << endl;
                return false;
            }
        } else {
            cout << "Invalid selection." << endl;
            return false;
        }
    }
};

// Main system to run the online food ordering
int main() {
    Restaurant restaurant;
    string restaurantName;
    int numItems;

    // Admin setup
    cout << "Admin setup mode\n";
    cout << "Enter the name of the restaurant: ";
    getline(cin, restaurantName);
    restaurant.setName(restaurantName);

    cout << "How many food items do you want to add to the menu? ";
    cin >> numItems;
    cin.ignore();  // Clear newline character left by cin

    for (int i = 0; i < numItems; i++) {
        cout << "\nAdding food item " << i + 1 << ":\n";
        restaurant.addFoodItem();
    }

    // Customer interaction
    string customerName;
    double initialBalance;

    cout << "\nCustomer setup mode\n";
    cout << "Enter your name: ";
    getline(cin, customerName);
    cout << "Enter your initial balance: ";
    cin >> initialBalance;
    cin.ignore();  // Clear newline character left by cin

    Customer customer(customerName, initialBalance);

    cout << "\nWelcome, " << customerName << "!" << endl;
    customer.displayBalance();

    // Customer places an order
    customer.placeOrder(restaurant);
return 0;
}

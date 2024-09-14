#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

int main() {
    // Declare variables
    double weight, height, bmi;

    // Get user input
    cout << "Enter your weight in kilograms: ";
    cin >> weight;

    cout << "Enter your height in meters: ";
    cin >> height;

    // Calculate BMI
    bmi = weight / (height * height);

    // Set precision for output
    cout << fixed << setprecision(2);

    // Display the result
    cout << "Your BMI is: " << bmi << endl;

    // Determine BMI category
    if (bmi < 18.5) {
        cout << "You are underweight." << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "You have a normal weight." << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "You are overweight." << endl;
    } else {
        cout << "You are obese." << endl;
    }

    return 0;
}

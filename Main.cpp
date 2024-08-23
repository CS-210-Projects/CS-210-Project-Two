#include "BankingApp.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Function to print the headers
void printHeader(const string& title) {
    cout << "\n" << setw(70) << setfill('=') << "" << endl;
    cout << title << endl;
    cout << setw(70) << setfill('=') << "" << endl;
    cout << setw(4) << setfill(' ') << "Year" << setw(30) << "Year End Balance" << setw(35) << "Interest Earned" << endl;
    cout << setw(70) << setfill('=') << "" << endl;
}

//Function to get user input and ensure it is a positive integer
double getPositiveRealNumber(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value) || value <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int main() {
    char continueChoice;

    do {
        //User input prompts for data collection
        double initialInvestment = getPositiveRealNumber("Enter initial investment amount: "); //Initial investment amount
        double monthlyDeposit = getPositiveRealNumber("Enter monthly deposit amount: "); //Monthly deposit amount
        double annualInterestRate = getPositiveRealNumber("Enter annual interest rate (in percentage): "); //Annual interest rate (in percentages)
        int numberOfYears = static_cast<int>(getPositiveRealNumber("Enter number of years: ")); //Number of years for investment

        cout << endl; //Add a line after the inputs for readability

        // Prompt to continue
        cout << "Press any key to continue..." << endl;
        cin.ignore(); // Ignore any newline character in the input buffer
        cin.get(); // Wait for the user to press any key

        //Creates an instance of BankingApp with user input
        BankingApp app(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

        //Calculate and display balance without monthly deposits
        printHeader("       Balance and Interest Without Additional Monthly Deposits        ");
        app.calculateBalanceWithoutMonthlyDeposit();

        cout << endl;

        //Calculate and display balance with monthly deposits
        printHeader("        Balance and Interest With Additional Monthly Deposits        ");
        app.calculateBalanceWithMonthlyDeposit();

        //Ask user if they want to run another simulation
        cout << "\nWould you like to run another simpulation? (y/n): ";
        cin >> continueChoice;
        cin.ignore(); //Ignore any newline character in the input buffer
    } while (continueChoice == 'y' || continueChoice == 'Y');
    return 0;
}
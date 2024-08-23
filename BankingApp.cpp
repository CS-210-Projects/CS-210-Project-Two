#include "BankingApp.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

//Constructor implementation
BankingApp::BankingApp(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    m_initialInvestment = initialInvestment;
    m_monthlyDeposit = monthlyDeposit;
    m_interestRate = interestRate;
    m_numberOfYears = numberOfYears;
}

//Calculates the monthly interest rate from the annual rate
double BankingApp::monthlyInterestRate() {
    return (m_interestRate / 100) / 12;
}

//Helper function for detailed monthly calculations
void BankingApp::calculateMonthlyDetails(double& balance, double& interestEarnedThisYear, bool withMonthlyDeposit) {
    double monthlyInterest = balance * monthlyInterestRate();
    interestEarnedThisYear += monthlyInterest;
    balance += monthlyInterest;
    if (withMonthlyDeposit) {
        balance += m_monthlyDeposit;
    }
}

//Prints the year, year-end balance, and interest earned with appropriate formatting
void BankingApp::printDetails(int year, double yearEndBalance, double interestEarnedThisYear) {

    //Formating the balances as strings
    stringstream balanceString, interestString;
    balanceString << fixed << setprecision(2) << "$" << yearEndBalance;
    interestString << fixed << setprecision(2) << "$" << interestEarnedThisYear;

    //Prints the year, year-end balance, and interest earned
    cout << setw(4) << setfill(' ') << year
        << setw(25) << setfill(' ') << right << balanceString.str()
        << setw(35) << setfill(' ') << right << interestString.str() << endl;
}

//Calculates and prints the balance without additional monthly deposits
double BankingApp::calculateBalanceWithoutMonthlyDeposit() {
    double balance = m_initialInvestment;
    double annualInterest;
    for (int year = 1; year <= m_numberOfYears; year++) {
        annualInterest = 0.0;
        for (int month = 0; month < 12; month++) {
            calculateMonthlyDetails(balance, annualInterest, false);
        }
        printDetails(year, balance, annualInterest);
    }
    return balance;
}

//Calculates and prints the balance with additional monthly deposits
double BankingApp::calculateBalanceWithMonthlyDeposit() {
    double balance = m_initialInvestment;
    double annualInterest;
    for (int year = 1; year <= m_numberOfYears; year++) {
        annualInterest = 0.0;
        for (int month = 0; month < 12; month++) {
            calculateMonthlyDetails(balance, annualInterest, true);
        }
        printDetails(year, balance, annualInterest);
    }
    return balance;
}
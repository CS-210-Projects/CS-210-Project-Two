#pragma once

#ifndef BANKINGAPP_H
#define BANKINGAPP_H

class BankingApp {
public:
    //Constructor to initialize the BankingApp with user input
    BankingApp(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);

    //Calculates and returns the balance without monthly deposits
    double calculateBalanceWithoutMonthlyDeposit();

    //Calculates and returns the balance with monthly deposits
    double calculateBalanceWithMonthlyDeposit();

    //Prints the details of the calculation for a given year
    void printDetails(int year, double yearEndBalance, double interestEarnedThisYear);

private:
    double m_initialInvestment; //Initial investment amount
    double m_monthlyDeposit; //Monthly deposit amount
    double m_interestRate; //Annual interest rate
    int m_numberOfYears; //Number of years for investment

    //Calculates the monthly interest rate from the annual rate
    double monthlyInterestRate();

    //Helper function for detailed monthly calculations
    void calculateMonthlyDetails(double& balance, double& interestEarnedThisYear, bool withMonthlyDeposit);
};

#endif

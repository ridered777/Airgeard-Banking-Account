#include <iostream>
#include <iomanip>

#include "account.h" //imports my created header and cpp file

/*
 * Project 2 - CS 210
 * Author: Craig Harrigan
 * Airgead Banking Application
 */

using namespace std;

/*A function to display the report prescribed in the tech document.
 * The given function for calculating the totals weren't working so I messed around with the equations.
 */
void DisplayReport(double depositAmount, double mnthDeposit, float annlInterest, int yrsOfAccount) {
    double monthlyRate = (annlInterest/12)/100;
    int monthsOfAccount = yrsOfAccount*12;
    double interestND;
    double interestYD;
    cout << fixed << setprecision(2);
    for(int i = 1; i <= monthsOfAccount; i++){
        interestND = (depositAmount) * (monthlyRate);
        interestYD = (depositAmount + (i * mnthDeposit)) * (monthlyRate);
        //This is a loop to display the amounts on first month of each year (12months in a year).
        if(i%12 ==0){

            cout << "Balance and Interest without the Additional Monthly Deposits" << endl;
            cout << "Year: " << i/12 << " Year End Balance: $ " <<  depositAmount + interestND
                 << " Year End Interest: $ " <<  interestND << endl << endl;
            cout << "Balance and Interest with the Additional Monthly Deposits" << endl;
            cout << "Year: " << i/12 << " Year End Balance: $ " << depositAmount + (mnthDeposit * i) + interestND
                 << " Year End Interest: $ " << interestYD << endl << endl;
        }

    }
}

//A function to display the menu - also could be called Initialize(). Passes the values to the account class.
void Menu() {
    double initialInvestAmount;
    double monthDeposit;
    float annualInterest;
    int yearsOfAccount;
    char input;
    account userAccount;

    cout << "Please enter Initial Investment Amount: $";
    cin >> initialInvestAmount;
    //Always check input for legitimacy.
    if(initialInvestAmount > 0) {
        userAccount.SetOpenBalance(initialInvestAmount);
    }else{
        cout << "Please enter a valid dollar amount.";
    }
    cout << "Please enter Monthly Deposit Amount: $";
    cin >> monthDeposit;
    //Always check input for legitimacy.
    if (monthDeposit > 0) {
        userAccount.SetMonthDeposit(monthDeposit);
    }else{
        cout << "Please enter a valid dollar amount.";
    }
    cout << "Please enter Annual Interest Percentage: %";
    cin >> annualInterest;
    //Always check input for legitimacy.
    if(annualInterest > 0 && annualInterest <=100) {
        userAccount.SetInterestRate(annualInterest);
    }else{
        cout << "Please enter a valid annual interest percentage (1-100)";
    }
    cout << "Please enter Number of years for Account to accrue interest: ";
    cin >> yearsOfAccount;
    //Always check input for legitimacy.
    if( yearsOfAccount > 0){
        userAccount.SetAgeAccount(yearsOfAccount);
    }else{
        cout << "Please enter a valid lifespan of the account. Must be greater than 0 years - otherwise you're not saving!";
    }
    cout << "Thank you. Input Y when you'd like to continue" << endl;
    cin >> input;
    if (input == 'Y'|| 'y') {
        DisplayReport(userAccount.GetOpenBalance(), userAccount.monthlyDeposit, userAccount.yearlyInterestRate, userAccount.accountAge);
    }
}





int main() {
    Menu();
}
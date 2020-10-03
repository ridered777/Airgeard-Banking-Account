//
// Created by CDH on 9/15/2020.
//
#include "account.h"
//Some items created to enhance versatility and expandability in the future.

using namespace std;

double account::SetPreInterestTotal(double deposit, double balance) {
    double preInterestTotal = deposit + balance;
    return preInterestTotal;
}
double account::SetPostInterestTotal(float interestRate, double preInterestTotal) {
    float postInterestTotal = interestRate + preInterestTotal;
    return postInterestTotal;
}

double account::GetOpenBalance() {
    return openBalance;
}
void account::SetInterestRate(float rate){
    yearlyInterestRate = rate;
}
void account::SetOpenBalance(double depositAmount){
    openBalance = depositAmount;
}
void account::SetMonthDeposit(double mnthDeposit){
    monthlyDeposit = mnthDeposit;
}
void account::SetAgeAccount(int timeInYears){
    accountAge = timeInYears;
}
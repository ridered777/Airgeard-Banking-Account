//
// Created by CDH on 9/15/2020.
//

#ifndef PROJECT_2_ACCOUNT_H
#define PROJECT_2_ACCOUNT_H
//Class created to hold the account properties. Some extra properties exist to assist in expansion/versatility.
class account
{
public:
    float yearlyInterestRate;
    double monthlyDeposit;
    int accountAge;
    double SetPreInterestTotal(double deposit, double balance);
    double SetPostInterestTotal(float interest, double preInterestTotal);
    double GetOpenBalance();
    void SetInterestRate(float rate);
    void SetOpenBalance(double initialInvestment);
    void SetMonthDeposit(double mnthDeposit);
    void SetAgeAccount(int timeInYears);
private:
    double openBalance;
    double interest;
    double closingBalance;

};

#endif //PROJECT_2_ACCOUNT_H

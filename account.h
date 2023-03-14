#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <string>
class Account
{
private:
    int m_account;
    std::string m_name;
    int m_password;
    double m_withdrawable;
    std::string m_category;
    double m_loan_amount;
    double m_loan_quota_left;
    double m_net_value;

public:
    Account(int account, std::string name, int password, double withdrawable, std::string category, double loan_amount, double loan_quota_left, double net_value);
    void printInfo();
    void changePassword(int newpassword);
    void changeDeposit(double newdepost);
    void changeWithdraw(double newwithdraw);
    void changeNetValue(double newnetvalue);
    void changeloan_amount(double newloan_amount);
    void changeloan_quota_left(double newloan_quota_left);

    int getAccount() { return m_account; }
    std::string getName() { return m_name; }
    int getPassword() { return m_password; }
    double getwithdrawable() { return m_withdrawable; }
    std::string getCategory() { return  m_category; }
    double getLoan_amount() { return m_loan_amount; }
    double getLoan_quota_left() { return m_loan_quota_left; }
    double getNet_value() { return m_net_value; }
};



#endif

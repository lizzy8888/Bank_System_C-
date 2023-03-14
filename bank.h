#pragma once
#ifndef _BANK_H
#define _BANK_H
#include <string>
class Bank
{
private:
    int m_account;
    std::string m_name;
    int m_password;
    double m_borrowable_amount;
    double m_total_deposits;
    double m_loan_interest_personal;
    double m_loan_interest_enterprise;

public:
    Bank(int account, std::string name, int password, double borrowable_amount, double total_deposits, double loan_interest_personal, double loan_interest_enterprise);
    int getAccount() { return m_account; }
    std::string getName() { return m_name; }
    int getPassword() { return m_password; }
    double getBorrowable_amount() { return  m_borrowable_amount; }
    double getTotal_deposits() { return m_total_deposits; }
    double getLoan_interest_personal() { return m_loan_interest_personal; }
    double getLoan_interest_enterprise() { return m_loan_interest_enterprise; }

    void change_borrowable_amount(double new_borrowable_amount);
    void change_total_deposits(double new_total_deposits);

    void printInfo();
    
 };

#endif

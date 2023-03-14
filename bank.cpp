#include"bank.h"
#include<iostream>
#include<string>

 Bank::Bank(int account, std::string name, int password, double borrowable_amount, double total_deposits, double loan_interest_personal, double loan_interest_enterprise)
        : m_account(account), m_name(name), m_password(password), m_borrowable_amount(borrowable_amount), m_total_deposits(total_deposits), m_loan_interest_personal(loan_interest_personal), m_loan_interest_enterprise(loan_interest_enterprise)
    {
    }

void Bank::printInfo()
{
    std::cout << m_account << " " << m_name << " " << m_password << " " ;
    printf("%.2f ", m_borrowable_amount);
    printf("%.2f ", m_total_deposits);
    printf("%.2f ", m_loan_interest_personal);
    printf("%.2f \n", m_loan_interest_enterprise);
}

void Bank::change_borrowable_amount(double new_borrowable_amount)
{
    m_borrowable_amount = new_borrowable_amount;
}
 
void Bank::change_total_deposits(double new_total_deposits) 
{
    m_total_deposits = new_total_deposits;
}
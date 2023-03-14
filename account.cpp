#include"account.h"
#include<iostream>
#include<string>

Account::Account(int account, std::string name, int password, double withdrawable, std::string category, double loan_amount, double loan_quota_left, double net_value)
    : m_account(account), m_name(name), m_password(password), m_withdrawable(withdrawable), m_category(category), m_loan_amount(loan_amount), m_loan_quota_left(loan_quota_left), m_net_value(net_value)
{
}

void Account::printInfo()
{
    std::cout << m_account << " " << m_name << " " << m_password << " " << m_withdrawable << " ";
    printf("%.2f ", m_withdrawable);
    std::cout << m_category << " ";
    printf("%.2f ", m_loan_amount);
    printf("%.2f ", m_loan_quota_left);
    printf("%.2f \n", m_net_value);
}

void Account::changePassword(int newpassword)
{
    m_password = newpassword;
}
void Account::changeDeposit(double newdeposit)
{
    m_withdrawable = newdeposit;
}
void Account::changeWithdraw(double newwithdraw)
{
    m_withdrawable = newwithdraw;
}

void Account::changeNetValue(double newnetvalue)
{
    m_net_value = newnetvalue;
}

void Account::changeloan_amount(double newloan_amount) {
    m_loan_amount = newloan_amount;
};
void Account::changeloan_quota_left(double newloan_quota_left) {
    m_loan_quota_left = newloan_quota_left;
};

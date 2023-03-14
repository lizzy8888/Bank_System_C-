#pragma once

#ifndef _COMMON_H
#define _COMMON_H
#include <vector>
#include <string>
#include "account.h"
#include "bank.h"

void load_accounts(std::vector<Account>&, std::string);
void load_bank(std::vector<Bank>& , std::string);

void log_in( std::vector<Bank>&, std::vector<Account>&);

void showMenu1();
void showMenu2();
void menu2(std::vector<Bank>&, std::vector<Account>&);
void menu3(std::vector<Bank>&, std::vector<Account>&);

//customer
void customer(std::vector<Bank>& , std::vector<Account>&);
void inquiey_accounts(std::vector<Account>&);
void deposit_accounts(std::vector<Bank>&, std::vector<Account>&);
void withdraw_accounts(std::vector<Bank>&, std::vector<Account>&);
void transfer(std::vector<Account>&);
void loan(std::vector<Bank>&, std::vector<Account>&);
void Repayment(std::vector<Bank>&, std::vector<Account>&);
void change_password(std::vector<Account>&);
void display_accounts(std::vector<Account>&);

//manager
void manager(std::vector<Bank>&, std::vector<Account>&);
void manager_create_account(std::vector<Bank>& bank, std::vector<Account>& accounts);
void check_bank_borrowable_am(std::vector<Bank>& bank, std::vector<Account>& accounts);
void totaldeposit_bank(std::vector<Bank>&);
void checkcustomer(std::vector<Account>&);
void reset_password(std::vector<Account>&);
void display_manager(std::vector<Bank>&);

void save_accounts(std::vector<Account>&);
void save_bank(std::vector<Bank>&);

#endif
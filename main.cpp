#include"account.h"
#include"bank.h"
#include"common.h"
using namespace std;

int main()
{
    vector<Account> accounts;//create a vector base on Account class
    vector<Bank> bank;//create a vector base on Bank class
    load_accounts(accounts, "account.txt");//load account.txt
    load_bank(bank, "bank.txt");//load bank.txt
    log_in(bank, accounts);//enter the program

    return 0;
}

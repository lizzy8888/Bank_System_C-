#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include"common.h"
#include"account.h"
#include"bank.h"

using namespace std;
int counter;
int num;

void load_bank(vector<Bank>& bank, string filename)//store the data from bank.txt into the Bank class
{
    int account;
    string name;
    int password;
    double borrowable_amount;
    double total_deposits;
    double loan_interest_personal;
    double loan_interest_enterprise;


    ifstream sfile{ "bank.txt" };
    if (!sfile)
    {
        cout << "Error opening file.\n";
        exit(1);
    }

    counter = 0;


    while (!sfile.eof()) {

        sfile >> account >> name >> password >> borrowable_amount >> total_deposits >> loan_interest_personal >> loan_interest_enterprise;

        counter++;

       bank.push_back(Bank(account, name, password, borrowable_amount, total_deposits, loan_interest_personal, loan_interest_enterprise));
    };
    sfile.close();

}

void load_accounts(vector<Account>& accounts, string filename)//store the data from account.txt into the Account class
{
    int account;
    string name;
    int password;
    double withdrawable;
    string category;
    double loan_amount;
    double loan_quota_left;
    double net_value;

    ifstream sfile{ "account.txt" };
    if (!sfile)
    {
        cout << "Error opening file.\n";
        exit(1);
    }

    counter = 0;


    while (!sfile.eof()) {

        sfile >> account >> name >> password >> withdrawable >> category >> loan_amount >> loan_quota_left >> net_value;
        // check if reach the end of file
        if (sfile.peek() == EOF)
            break;

        counter++;

        accounts.push_back(Account(account, name, password, withdrawable, category, loan_amount, loan_quota_left, net_value));
    };
    sfile.close();

}



void log_in(vector<Bank>& bank, vector<Account>& accounts)//login
    {
        int acc, i = 0, password;
        cout << "please input your account number: ";
        cin >> acc;

        for (int i = 0; i <= accounts.size() - 1; i++)
        {

            if (acc == accounts[i].getAccount())
            {
                std::cout << "please input your account passward: " << endl;//check account's password
                cin >> password;
                if (password != accounts[i].getPassword()) {
                    cout << "Error, please input the correct password" << endl;
                    log_in(bank, accounts);//if password is wrong, go back to input account
                }
                else {
                    num = accounts[i].getAccount() - 1000 - 1;//this account's position in Account vector
                    cout << "Welcome!" << endl;
                    customer(bank, accounts);//enter the customer menu
                }
                break;
            }
            else if (acc == bank[0].getAccount()) {
                std::cout << "please input your account passward: " << endl; // check manager's password
                cin >> password;
                if (password != bank[0].getPassword()) {
                    cout << "Error, please input the correct password" << endl;
                    log_in(bank, accounts); //if password is wrong, go back to input account
                }
                else {
                    num = 0;
                    cout << "Welcome!" << endl;
                    manager(bank, accounts);//enter the manager menu
                }
                break;
            }
            else if (i == accounts.size() - 1) {
                std::cout << "not exist" << endl;
                log_in(bank, accounts); // if account's number is not exist, go back to input account
            }
        }
    }


void showMenu1()//customer menu
{
    printf("------------------------------------------------------\n");
    printf("\t\t   Welcome! \n");
    printf("\t\t  1. Inquiry \n");
    printf("\t\t  2. Deposit \n");
    printf("\t\t  3. Withdraw \n");
    printf("\t\t  4. Transfer \n");
    printf("\t\t  5. Loan \n");
    printf("\t\t  6. Repay \n");
    printf("\t\t  7. Change password \n");
    printf("\t\t  8. Quit\n");
    printf("\t\t  Please Select:\n");
    printf("------------------------------------------------------\n");
}

void showMenu2()//manager menu
{
    printf("------------------------------------------------------\n");
    printf("\t\t   Welcome! \n");
    printf("\t\t  1. Create a new account \n");
    printf("\t\t  2. Check borrowable amount of bank \n");
    printf("\t\t  3. Check total_deposits of bank \n");
    printf("\t\t  4. Check customer's information \n");
    printf("\t\t  5. Reset password for customer \n");
    printf("\t\t  6. Quit \n");
    printf("\t\t  Please Select:\n");
    printf("------------------------------------------------------\n");
}

void customer(vector<Bank>& bank, vector<Account>& accounts) {//customer program
    int k;
    system("cls");
    showMenu1();  //show the menu
    cin >> k;

    if (k == 1)//inquiey
    {
        system("cls");
        inquiey_accounts(accounts);
        menu2(bank, accounts);
    }
    else if (k == 2)//deposit
    {
        system("cls");
        deposit_accounts(bank, accounts);
        menu2(bank, accounts);
    }
    else if (k == 3)//withdraw
    {
        system("cls");
        withdraw_accounts(bank, accounts);
        menu2(bank, accounts);
    }
    else if (k == 4)//transfer
    {
        system("cls");
        transfer(accounts);
        menu2(bank, accounts);
    }
    else if (k == 5)//loan
    {
        system("cls");
        loan(bank, accounts);
        menu2(bank, accounts);
    }
    else if (k == 6)//repayment
    {
        system("cls");
        Repayment(bank, accounts);
        menu2(bank, accounts);
    }
    else if (k == 7)//change password
    {
        system("cls");
        change_password(accounts);
        menu2(bank, accounts);
    }
    else if (k == 8)//exit
    {
        save_bank(bank);
        save_accounts(accounts);
        cout << "Thanks for your using, bye! ";
        exit(0);
    }

    else {
        cout << "Please choose number from 1 to 8.";
        menu2(bank, accounts);
    }

}

void menu2(vector<Bank>& bank, vector<Account>& accounts) {//after each customer's operation
    int k;
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("\t\t  1. Continue \n");//Back to Operation menu
    printf("\t\t  2. Quit \n"); //Terminate the program
    printf("------------------------------------------------------\n");
    cin >> k;
    if (k == 1)
    {
        system("cls");
        customer(bank, accounts);
    }
    else if (k == 2)
    {
        save_bank(bank);
        save_accounts(accounts);
        cout << "Thanks for your using, bye! ";
        exit(0);
    }

    else {
        cout << "Please choose number from 1 to 2.";
        menu2(bank, accounts);
    }
}

void menu3(vector<Bank>& bank, vector<Account>& accounts) {//after manager's each operation
    int k;
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("\t\t  1. Continue \n");//Back to Operation menu
    printf("\t\t  2. Quit \n"); //Terminate the program
    printf("------------------------------------------------------\n");
    cin >> k;
    if (k == 1)
    {
        system("cls");
        manager(bank, accounts);
    }
    else if (k == 2)
    {
        save_bank(bank);
        save_accounts(accounts);
        cout << "Thanks for your using, bye! ";
        exit(0);
    }

    else {
        cout << "Please choose number from 1 to 2.";
        menu2(bank, accounts);
    }

}


void manager(vector<Bank>& bank, vector<Account>& accounts) {//manager program
    int k;
    system("cls");
    showMenu2();  //show the menu
    cin >> k;

    if (k == 1)//create a new account
    {
        system("cls");
        manager_create_account(bank, accounts);
        display_manager(bank);
        menu3(bank, accounts);
    }
    else if (k == 2)// check borrowable amout result
    {
        system("cls");
        check_bank_borrowable_am(bank, accounts);
        menu3(bank, accounts);
    }

    else if (k == 3)//check total_deposit of bank
    {
        system("cls");
        totaldeposit_bank(bank);
        menu3(bank, accounts);
    }

    else if (k == 4)//check customer's information
    {
        system("cls");
        checkcustomer(accounts);
        menu3(bank, accounts);
    }

    else if (k == 5)//reset password for customer
    {
        system("cls");
        reset_password(accounts);
        menu3(bank, accounts);
    }
   
    else if (k == 6)//exit
    {
        save_bank(bank);
        save_accounts(accounts);
        cout << "Thanks for your using, bye! ";
        exit(0);
    }

    else {
        cout << "Please choose number from 1 to 8.";
        menu3(bank, accounts);
    }
}

//customer

void inquiey_accounts(vector<Account>&accounts)//check the balance of the account
{
    cout << "Dear " << accounts[num].getName() << ", your balance is ";
    printf("%.2f ", accounts[num].getwithdrawable());
}
void deposit_accounts(vector<Bank>& bank, vector<Account>& accounts)
{
    double dep;
    cout << "Please input the amount to save£º ";
    cin >> dep;
    double dep2 = dep + accounts[num].getwithdrawable();
    double dep3 = dep + accounts[num].getNet_value();
    accounts[num].changeDeposit(dep2);//withdrawable of account changed
    accounts[num].changeNetValue(dep3);//netvalue of account changed
    double total_deposit = dep + bank[0].getTotal_deposits();
    bank[0].change_total_deposits(total_deposit);//total deposit of bank changed
    cout << "Dear " << accounts[num].getName() << ", your balance has been updated to ";
    printf("%.2f ", accounts[num].getwithdrawable());
}

void withdraw_accounts(vector<Bank>& bank, vector<Account>& accounts)
{
    double w,amount3,amount4;
    cout << "Please input the amount to withdraw£º ";
    cin >> w;
    int limit1 = 2000; int limit2 = 5000;//max of personal is 2000,mas of enterprise is 5000.
    if (w > accounts[num].getwithdrawable()) {//if withdrawal exceeds the balance, a warning will be given
        cout << "Error! Not enough money!\n";
        cout << "Please input the amount to withdraw£º ";
        cin >> w;
    }
    if (accounts[num].getCategory() == "enterprise") {
        do {
            if (w < limit2)
                break;
            cout << "Error! Enterprise could withdraw at most 5000 once!\n";
            cout << "Please input the amount to withdraw: ";
            cin >> amount3;
            w = amount3;
        } while (w > limit1);
    }
    else if (accounts[num].getCategory() == "personal") {
        do {
            if (w < limit1)
                break;
            cout << "Error! Personal account could withdraw at most 2000 once!\n";
            cout << "Please input the amount to withdraw: ";
            cin >> amount4;
            w = amount4;
        } while (w > limit1);
    }

    double w2 = accounts[num].getwithdrawable() - w;
    double w3 = accounts[num].getNet_value() - w;
    accounts[num].changeWithdraw(w2);
    accounts[num].changeNetValue(w3);
    double totaldeposit = bank[0].getTotal_deposits() - w;
    bank[0].change_total_deposits(totaldeposit);
    cout << "Dear " << accounts[num].getName() << ", your balance has been updated to ";
    printf("%.2f ", accounts[num].getwithdrawable());
}
//transfer function
void transfer(vector<Account>& accounts) {
    int target, amount, amount2, amount3, amount4;
    cout << "Please input the target account number: ";
    cin >> target;
    int limit1 = 20000, limit2 = 10000;// set the limit data of different category
    for (int i = 0; i <= accounts.size() - 1; i++)
    {
        if (target == accounts[i].getAccount())
        {
            cout << "Please input the amount to transfer: ";
            cin >> amount;
            do{
                if (amount < accounts[num].getwithdrawable())//recognize whether this account have enough money to transfer
                    break;
                cout << "Error! Not enough money!\n";
                cout << "Please input the amount to transfer: ";
                cin >> amount2;
                amount = amount2;//use new data to replace the old, not-fitting-rules data
            } while (amount > accounts[num].getwithdrawable());

          
            if (accounts[num].getCategory() == "enterprise") {//recognize the category of the data
                do {
                    if (amount < limit1)
                        break;
                    cout << "Error! Enterprise could transfer at most 20,000 once!\n";
                    cout << "Please input the amount to transfer: ";
                    cin >> amount3;
                    amount = amount3;
                } while (amount > limit1);
            }
            else if (accounts[num].getCategory() == "personal") {
                do {
                    if (amount < limit2)
                        break;
                    cout << "Error! Personal account could transfer at most 10,000 once!\n";
                    cout << "Please input the amount to transfer: ";
                    cin >> amount4;
                    amount = amount4;
                } while (amount > limit2);
            }
            double w31 = accounts[num].getwithdrawable() - amount;
            double w32 = accounts[num].getNet_value() - amount;
            double w41 = accounts[i].getwithdrawable() + amount;
            double w42 = accounts[i].getNet_value() - amount;
            accounts[num].changeWithdraw(w31);
            accounts[num].changeNetValue(w32);
            accounts[i].changeWithdraw(w41);
            accounts[num].changeNetValue(w42);//change data
            cout << "Transfer success ! Your withdrawable amount has been updated to ";
            printf("%.2f ", accounts[num].getwithdrawable());
            
        }
        else if (i == accounts.size() - 1) {
            cout << "Error! This account isn't exists.";//Give an error when the account doesn't exist
            transfer(accounts);
        }
    }
}


void loan(vector<Bank>& bank, vector<Account>& accounts) {
    int loan1;
    cout << "Please input the amount to loan: ";
    cin >> loan1;
    if (loan1 > accounts[num].getLoan_quota_left()) {//judge whether there is enough loan quota left
        cout << "Error! Not  enough loan quota left\n";
        loan(bank,accounts);
    }
    else if (loan1 > bank[0].getBorrowable_amount()) {//check whether the bank has ehough money that can be boorrowed
        cout << "Sorry, not enough borrowable money in the bank!\n";
        loan(bank, accounts);
    }
    else{
        double w51 = accounts[num].getLoan_amount() + loan1;
        double w61 = accounts[num].getwithdrawable() + loan1;
        double w71 = accounts[num].getLoan_quota_left() - loan1;
        double w52 = bank[0].getBorrowable_amount() - loan1;
        accounts[num].changeloan_amount(w51);
        accounts[num].changeWithdraw(w61);
        accounts[num].changeloan_quota_left(w71);
        bank[0].change_borrowable_amount(w52);
        cout << "Your withdrawable amount now is ";
        printf("%.2f \n", accounts[num].getwithdrawable());
        cout << "Your loan quota left is ";
        printf("%.2f \n", accounts[num].getLoan_quota_left());
    }
}

void Repayment(vector<Bank>& bank, vector<Account>& accounts) {
    
    int loan2 = accounts[num].getLoan_amount();
    if (loan2 > accounts[num].getwithdrawable()) {//if account's withdrawable is not enough
        cout << "Error! Not enough withdrawable\n";
        Repayment(bank,accounts);
    }
    else{
        double w51 = accounts[num].getLoan_amount() - loan2;
        double w71 = accounts[num].getLoan_quota_left() + loan2;
        double w52 = bank[0].getBorrowable_amount() + loan2;

        if (accounts[num].getCategory() == "personal") {
             double w61 = accounts[num].getwithdrawable() - loan2 * (1 + 0.05);
             double w63 = accounts[num].getNet_value() - loan2 * (1 + 0.05);
             double w62 = bank[0].getTotal_deposits() + loan2 * (1 + 0.05);
             accounts[num].changeWithdraw(w61);
             accounts[num].changeNetValue(w63);
             bank[0].change_total_deposits(w62);
            } 
        else if (accounts[num].getCategory() == "enterprise") {
            double w61 = accounts[num].getwithdrawable() - loan2 * (1 + 0.03);
            double w63 = accounts[num].getNet_value() - loan2 * (1 + 0.03);
            double w62 = bank[0].getTotal_deposits() + loan2 * (1 + 0.03);
            accounts[num].changeWithdraw(w61);
            accounts[num].changeNetValue(w63);
            bank[0].change_total_deposits(w62);
        }
            accounts[num].changeloan_amount(w51);
            accounts[num].changeloan_quota_left(w71);
            bank[0].change_borrowable_amount(w52);
           
        cout << "Cheers!Your loan amount now is ";
        printf("%.2f ", accounts[num].getLoan_amount());
        cout << "Your loan quota now is ";
        printf("%.2f \n", accounts[num].getLoan_quota_left());
        cout << "Your withdrawable amount has been updated is ";
        printf("%.2f \n", accounts[num].getwithdrawable());
      
    }
}

void change_password(vector<Account>& accounts) {
    int p, np1, np2;
    cout << "Please input your original password:";
    cin >> p;
    if (p != accounts[num].getPassword()) {//if password is wrong
        system("cls");
        cout << "Error, please input the correct password" << endl;
        change_password(accounts);
    }
    else {
        cout << "Please input your new password:";
        cin >> np1;
        if (np1 >= 1000000 || np1 < 100000) {//if new password is not 6-digit            cout << "Password must be 6-digit! Please change it!\n";
            cout << "Please input your new password:";
            cin >> np1;
        }
        cout << "Please input your new password again:";
        cin >> np2;
        if (np1 == np2) {
            accounts[num].changePassword(np1);
            cout << "Update password successfully.";
        }
        else {//if password is entered incorrectly for the second time
            system("cls");
            cout << "The new password is entered incorrectly for the second time, update failed.\n";
            change_password(accounts);

        }
    }

}

//manager

void manager_create_account(vector<Bank>& bank, vector<Account>& accounts) {
    int account_new = 0;
    string name_new;
    int password_new = 0;
    double withdrawable_new = 0;
    string category_new;
    double loan_amount_new = 0;
    double loan_quota_left_new = 0;
    double net_value_new = 0;

    cout << "Please input a cusomer information \n (name  password   withdrawable  category) \n";
    cin >> name_new >> password_new >> withdrawable_new >> category_new;//load the new data
    if (password_new > 1000000 || password_new < 100000) {//limit the password should be 6 digits
        cout << "The password should be formed by 6 digital numbers! Please input the right information again.\n";
        manager_create_account(bank, accounts);
    }
    account_new = 1000 + accounts.size() + 1;
    if (category_new == "enterprise") {
        loan_amount_new = 0.05 * withdrawable_new;//calculate the loan amount

        double w81 = bank[0].getTotal_deposits() + withdrawable_new;
        bank[0].change_total_deposits(w81);

        net_value_new = withdrawable_new;
        loan_quota_left_new = 0;
        accounts.push_back(Account(account_new, name_new, password_new, withdrawable_new, category_new, loan_amount_new, loan_quota_left_new, net_value_new));
        cout << "Create success! \n";
    }
    else if (category_new == "personal") {
        loan_amount_new = 0.03 * withdrawable_new;

        double w81 = bank[0].getTotal_deposits() + withdrawable_new;
        bank[0].change_total_deposits(w81);

        net_value_new = withdrawable_new;
        loan_quota_left_new = 0;
        accounts.push_back(Account(account_new, name_new, password_new, withdrawable_new, category_new, loan_amount_new, loan_quota_left_new, net_value_new));
        cout << "Create success! \n";
    }
    else {
        cout << "The category should be either enterprise or personal! \n Please input the right information again. \n";
        manager_create_account(bank, accounts);
    }   
}

void check_bank_borrowable_am(vector<Bank>& bank, vector<Account>& accounts) {
    cout << "The borrowable amount : ";
    printf("%.2f", bank[0].getBorrowable_amount());//output the bank's borrowable amount
}

void totaldeposit_bank(vector<Bank>& bank)//check the total deposit of bank
{
    cout << "The total deposits amount now is: ";
    printf("%.2f ", bank[0].getTotal_deposits());

}

void checkcustomer(vector<Account>& accounts)//use the vector of account to check the customer's info
{
    int num;
    cout << "Please input the account number: ";
    cin >> num;
    int i = 0;
    for (int i = 0;i <= accounts.size() - 1;i++)
    {
        if (num == accounts[i].getAccount()) {
            cout << "account:" << accounts[num - 1001].getAccount() << endl;
            cout << "name:" << accounts[num - 1001].getName() << endl;
            cout << "withdrawable: ";
            printf("%.2f ", accounts[num - 1001].getwithdrawable());
            cout << endl;
            cout << "category: " << accounts[num - 1001].getCategory() << endl;
            cout << "loan_amount: ";
            printf("%.2f ", accounts[num - 1001].getLoan_amount());
            cout << endl;
            cout << "loan_quota_left: ";
            printf("%.2f ", accounts[num - 1001].getLoan_quota_left());
            cout << endl;
            cout << "net_value: ";
            printf("%.2f ", accounts[num - 1001].getNet_value());
            break;
        }
        else if (i == accounts.size() - 1) {
            cout << "not exist" << endl;
            checkcustomer(accounts);
        }

    }

}

void reset_password(vector<Account>& accounts) {
    int acc, np1, np2;
    cout << "Please input the account number:";
    cin >> acc;
    for (int i = 0; i <= accounts.size() - 1; i++)
    {
        if (acc == accounts[i].getAccount()) {
            cout << "Please input the new password:";
            cin >> np1;
            if (np1 >= 1000000 || np1 <100000) {//if new password is not 6-digit
                cout << "Password must be 6-digit! Please change it!\n";
                cout << "Please input the new password:";
                cin >> np1;
            }
            cout << "Please input the new password again:";
            cin >> np2;
            if (np1 == np2) {
                accounts[i].changePassword(np1);
                cout << "Cheers! Password successfully.";
                break;
            }

            //if password is entered incorrectly for the second time
            else {
                system("cls");
                cout << "The new password is entered incorrectly for the second time, update failed.\n";
                reset_password(accounts);
            }

        }
        else if (i == accounts.size() - 1) {//if account is not exist
            std::cout << "not exist" << endl;
            reset_password(accounts);
        }
       
    }
   
}


void display_accounts(vector<Account>& accounts)
{
    unsigned int length = accounts.size();
    for (unsigned int i = 0; i < length; ++i)
    {
        accounts[i].printInfo();
    }
}

void display_manager(vector<Bank>& bank)
{
    unsigned int length = bank.size();
    for (unsigned int i = 0; i < length; ++i)
    {
        bank[i].printInfo();
    }
}

void save_accounts(vector<Account>& accounts)//save Account's vector into account.txt
{
    ofstream outf{ "account.txt" };
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, account.txt could not be opened for writing!\n";
        return;
    }

    unsigned int length = accounts.size();
    for (unsigned int i = 0; i < length; ++i)
    {
        outf <<setiosflags(ios::fixed)<<setprecision(2)<< accounts[i].getAccount() << " " << accounts[i].getName() << " " << accounts[i].getPassword() << " " << accounts[i].getwithdrawable() << " " << accounts[i].getCategory() << " " << accounts[i].getLoan_amount() << " " << accounts[i].getLoan_quota_left() << " " << accounts[i].getNet_value() << "\n";
    }
    outf.close();
} 


void save_bank(vector<Bank>& bank)//save Bank's vector into bank.txt
{
    ofstream outf{ "bank.txt" };
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, account.txt could not be opened for writing!\n";
        return;
    }

    unsigned int length = bank.size();

    outf << setiosflags(ios::fixed) << setprecision(2) << bank[0].getAccount() << " " << bank[0].getName() << " " << bank[0].getPassword() << " " << bank[0].getBorrowable_amount() << " " << bank[0].getTotal_deposits() << " " << bank[0].getLoan_interest_personal() << " " << bank[0].getLoan_interest_enterprise() << "\n";

    outf.close();
}
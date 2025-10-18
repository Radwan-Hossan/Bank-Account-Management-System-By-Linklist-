
//This project owner is Radwan Hossan
#include<bits/stdc++.h>
using namespace std;

struct Account{
    int accNo;
    string name;
    double balance;
    Account* next;
};

Account* head = NULL;

// Add  account
void add_Account() {
    Account* newAcc = new Account();
    cout <<"Enter Your Account Number: ";
    cin >>newAcc->accNo;
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin,newAcc->name);
    cout << "Enter Initial Balance: ";
    cin >>newAcc->balance;
    newAcc->next=0;

    Account* temp = head;
    while(temp!=0) {
        if (temp->accNo==newAcc->accNo) {
            cout << "Sorry.Account already exists!\n";
            delete newAcc;
            return;
        }
        temp=temp->next;
    }

    if (head==0)
        head=newAcc;
    else{
        temp=head;
        while(temp->next!=0)
            temp=temp->next;
        temp->next=newAcc;
    }
    cout << " Account created successfully!\n";
}

// shoow all accounts
void show_Accounts() {
    if (head==0) {
        cout <<"No accounts found.\n";
        return;
    }
    cout<<"\n--- Account List ---\n";
    Account* temp=head;
    while (temp!=NULL) {
        cout <<"Account No: "<<temp->accNo
             <<" | Name: "<<temp->name
             <<" | Balance: "<<temp->balance << "\n";
        temp= temp->next;
    }
    cout << "--------------------\n";
}

// Search account by number
Account* searchAccountByNumber(int accNo) {
    Account* temp = head;
    while (temp!=0) {
        if (temp->accNo==accNo)
            return temp;
        temp = temp->next;
    }
    return 0;
}

void search_Account() {
    if (head==NULL) {
        cout <<"Sorry. No accounts found.\n";
        return;
    }
    int accNo;
    cout <<"Enter account number to search: ";
    cin >>accNo;
    Account* acc =searchAccountByNumber(accNo);
    if (acc!=NULL)
        cout <<"Found -> " << acc->accNo << " | " << acc->name << " | Balance: " << acc->balance << "\n";
    else
        cout <<" Account not found.\n";
}

// Deposit money
void deposit(){
    int accNo;
    double amount;
    cout <<"Enter account number: ";
    cin >>accNo;
    Account* acc = searchAccountByNumber(accNo);
    if (acc==0) {
        cout <<" Account not found.\n";
        return;
    }
    cout <<"Enter amount to deposit: ";
    cin >>amount;
    acc->balance += amount;
    cout << " Deposited successfully! New balance: " << acc->balance << "\n";
}

// Withdraw money
void withdraw(){
    int accNo;
    double amount;
    cout <<"Enter account number: ";
    cin >>accNo;
    Account* acc=searchAccountByNumber(accNo);
    if (acc == NULL){
        cout <<" Account not found.\n";
        return;
    }
    cout <<"Enter amount to withdraw: ";
    cin >>amount;
    if (amount>acc->balance) {
        cout <<" Insufficient balance!\n";
        return;
    }
    acc->balance-=amount;
    cout <<" Withdrawal successful! New balance: "<< acc->balance << "\n";
}

// Delete account
void delete_Account() {
    if (head==NULL) {
        cout <<"No accounts to delete.\n";
        return;
    }
    int accNo;
    cout <<"Enter account number to delete: ";
    cin >>accNo;

    Account* temp = head;
    Account* prev = NULL;

    while (temp!=NULL && temp->accNo!=accNo) {
        prev =temp;
        temp =temp->next;
    }

    if (temp==0) {
        cout <<"  Account not found.\n";
        return;
    }

    if (prev==0)
        head =temp->next;
    else
        prev->next=temp->next;

    delete temp;
    cout <<" Account deleted successfully.\n";
}


int main(){
    int choice;
    while (true){
        cout << "\nBank Account Management System\n";
        cout << "1. Add Account\n2. Show Accounts\n3. Search Account\n4. Deposit\n5. Withdraw\n6. Delete Account\n7. Exit\n";
        cout << "Enter Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                 add_Account();
                 break;
                 }
            case 2:{
                 show_Accounts();
                 break;
                 }
            case 3:{
                 search_Account();
                 break;
                 }
            case 4:{
                deposit();
                break;
                }
            case 5:{
                 withdraw();
                 break;
                }
            case 6:{
                 delete_Account();
                 break;
                }
            case 7:{
                 cout << "Goodbye!\n";
                 return 0;
                }
            default: {
                cout << "Invalid choice!\n";
                }
        }
    }
}

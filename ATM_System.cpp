#include <iostream.h>
#include <cctype> //Required for tolower()
#include <string>
#include <algorithm> //Required for transform
#include <stdio.h>
#include <conio.h>

class Bank{
    char name[100], address[100], account[100];
    int balance, deposited, withdrawal;
    public:
    void open_account();
    void withdraw();
    void deposit();
    void display_balance();
};
void Bank :: open_account(){
    cout << "Enter your full name: \n";
    cin.ignore();
    cin.getline(name,100);
    cout << "Enter your address: \n";
    cin.ignore();
    cin.getline(address,100);
    cout << "What type of account do you want to open(Savings or Cheque)? ";
    cin.ignore();
    cin.getline(account,100);
    cout << "Deposit account opening amount (R75 for Savings and R50 for Cheque)";
    cin >> balance;
    if (balance >= 75) && (account == "Savings"){
        cout << "Successful" << endl;
    }
    else if (balance < 75) && (account == "Savings"){
        cout << "Unsuccesful. Please deposit " << 75 << " rands." << endl;
    }
    else if (balance >= 50) && (account == "Cheque"){
        cout << "Successful" << endl;
    }
    else if (balance < 50) && (account == "Cheque"){
        cout << "Unsuccesful. Please deposit " << 50 << " rands." << endl;
    }
    
}

void Bank :: deposit(){
    cout << "Enter the money into the slot" << endl;
    cin >> deposited;
    balance += deposited;
}

void Bank :: withdraw(){
    cout << "Enter withdrawal amount? " << endl;
    cin >> withdrawal;
    if (withdrawal < balance){
        balance -= deposited;
        cout << "Take your card."
    }
    else {
        cout << "Insufficient funds" << endl;
        cout << "Current balance is " << balance << endl;
    }
}

void Bank :: display_balance(){
    cout << "Current balance is " << balance << endl;
}

int main()
{
    int button;
    char condition[3];
    Bank person;
    
    do{
        std::cout <<"1) Open account" << endl;
    std::cout <<"2) Deposit" << endl;
    std::cout <<"3) Withdraw" << endl;
    std::cout <<"4) Display balance" << endl;
    std::cout
    
    switch(button){
        case 1:
        person.open_account();
        break;
        case 2:
        person.deposit();
        break;
        case 3:
        person.withdraw();
        break;
        case 4:
        person.display_balance();
        break;
        default:
        cout << "Unsupported input" << endl;
    }
    cout << "Do you want to continue?" << endl;
    cin.ignore();
    cin.getline(condition, 3)
    std::transform(condition.begin(), condition.end(), condition.begin(), ::tolower);
    if (condition == "no"){
        exit()
    }
    } while (condition == "yes")
    
    

    return 0;
}

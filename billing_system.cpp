#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;

int k=7, r=0, flag=0;
COORD coord = {0,0};

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class date{
    public:
    int month, day, year;
};

ofstream fout;
ifstream fin;

class item{
    int itemNO;
    char name[100];
    date d;
    
    public:
    void add(){
        cout << "\n Item No: ";
        cin >> itemNO;
        cout >> "\n Name of item";
        cin >> name;
        cout << "Date manufactured: (dd/mm/yy)";
        cin >> d.day >> d.month >> d.year;
    }
    
    void display(){
        cout << "\n Item No: " << itemNO << endl;
        cout << "Item Name: " << name << endl;
        cout << "Item Date";
        cout << d.day << "/" << d.month << "/" << d.year << endl;
    }
    
    void report(){
        gotoxy(3,k);
        cout << itemNO;
        gotoxy(13,k);
        puts(name);
    }
    int returnITEM(){
        return(itemNO);
    }
};

class amount: public item{
    float price,quantity,tax,gross,discount,net;
    public:
    void add();
    void display();
    void report();
    void calculate();
    void pay();
    
    foat returnNET(){
        return(net);
    }
    
} amt;

void amountt::add(){
    item::add();
    cout << "\n Price: ";
    cin >> price;
    cout << "\n Quantity: ";
    cin >> quantity;
    cout << "\n Tax: ";
    cin >> tax;
    cout << "Discount: ";
    cin >> discount;
    
    calculate();
    fout<<write((char*)&amt,sizeof(amt));
    fout.close(;)
}
void amount::calculate(){
    gross = price + (price*(tax/100));
    net = quantity*(gross - (gross*(gross*(discount/100))));
}
void amount::display()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    item::display();
    cout<<"\n Net amount: " << net << endl;
    fin.close();
}
void amount::report(){
    item::report();
    gotoxy(23,k);
    cout << price;
    gotoxy(33,k);
    cout << quantity;
    gotoxy(44, k);
    cout << tax;
    gotoxy(52, k);
    cout << discount;
    gotoxy(64, k);
    cout << net;
    k = k+1;
    if (k==50){
        gotoxy(25, 50);
        cout << "Pres any key to continue";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout <<"Item details";
        gotoxy(3, 5);
        cout << "Number";
        gotoxy(13, 5);
        cout << "Price";
        gotoxy(33, 5);
        cout << "Quantity";
        gotoxy(44, 5);
        cout << "Tax";
        gotoxy(44,5);
        cout << "Tax";
        gotoxy(52, 5);
        cout << "Deduction";
        gotoxy(64, 5);
        cout << "Net Amount";
    }
}
void amount::pay(){
    display();
    cout << "\n\n\t\t*********************************************";
    cout << "\n\t\t             DETAILS               ";
    cout << "\n\n\t\t*********************************************";
    cout << "\n\n\t\t PRICE                       :"<<price;
    cout << "\n\n\t\t QUANTITY                    :"<<quantity;
    cout << "\n\n\t\t TAX                         :"<<tax;
    cout << "\n\t\t DISCOUNT                      :"<<discount;
    cout << "\n\n\t\t NET AMOUNT                  :"<<net;
    cout << "\n\n\t\t*********************************************";
}

int main(){
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
menu:
    system("cls");
    gotoxy(25,2);
    cout << "Super Market Billing";
    gotoxy(25,3);
    cout << "================\n\n";
    cout << "\n\t\t1.Bill Report\n\n";
    
    return 0;
}

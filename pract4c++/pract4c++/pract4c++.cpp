// pract4c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

using namespace std;

class bankaccount {
private:
    int accountnumber;
    double balance;
    double interestrate;

public:
    bankaccount(int accountnumber, double balance, double interestrate) {
        this->accountnumber = accountnumber;
        this->balance = balance;
        this->interestrate = interestrate;
    }

    void deposit(double amount) {
        if (amount < 0) {
            cout << "невозможно внести отрицательную сумму" << endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            cout << "невозможно снять отрицательную сумму" << endl;
            return;
        }
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "недостаточно средств для вывода" << endl;
        }
    }

    double getbalance() {
        return balance;
    }

    double getinterest() {
        return balance * interestrate * (1 / 12);
    }

    void setinterestrate(double newrate) {
        interestrate = newrate;
    }

    int getaccountnumber() {
        return accountnumber;
    }

    friend bool transfer(bankaccount& from, bankaccount& to, double amount) {
        if (amount < 0) {
            cout << "сумма перевода должна быть положительной" << endl;
            return false;
        }
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "перенос успешно выполнен" << endl;
            return true;
        }
        else {
            cout << "недостаточно средств для перевода" << endl;
            return false;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    bankaccount acc1(12345, 1000, 0.05);
    bankaccount acc2(54321, 500, 0.03);

    cout << "начальный баланс первого счета: $" << acc1.getbalance() << endl;
    cout << "начальный баланс второго счета: $" << acc2.getbalance() << endl;

    transfer(acc1, acc2, 300);

    cout << "окончательный баланс первого счета: $" << acc1.getbalance() << endl;
    cout << "окончательный баланс второго счета: $" << acc2.getbalance() << endl;

    return 0;
}

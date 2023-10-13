#include <iostream>
#include <iomanip>

void showBalance(double bal);
double deposit();
double withdraw(double bal);

int main(){

    double bal = 0;
    int choose = 0;

    do
    {
        std::cout << "======== BANK ========\n";
        std::cout << "1. Check balance\n";
        std::cout << "2. Deposit some money\n";
        std::cout << "3. Withdraw some money\n";
        std::cout << "4. Exit\n";
        std::cin >> choose;

        std::cin.clear();
        fflush(stdin);

        switch (choose) {
        case 1: showBalance(bal);
            break;
        case 2: bal += deposit();
                showBalance(bal);
            break;
        case 3: bal -= withdraw(bal);
                showBalance(bal);
            break;
        case 4: std::cout << "Thanks for using our bank!\n";
            break;
        
        default: std::cout << "Invalid choise!\n";
            break;
        }
    } while (choose != 4);
    

    return 0;
}

void showBalance(double bal) {
    std::cout << "Your balance: " << std::setprecision(2) << std::fixed << bal << "\n";
}
double deposit() {
    double amount = 0;
    std::cout << "Enter amount to deposit: ";
    std::cin >> amount;

    if(amount > 0) {
        return amount;
    }
    else {
        std::cout << "Write positive number!";
        return 0;
    }
}
double withdraw(double bal) {
    double amount = 0;
    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;

    if(amount > bal) {
        std::cout << "You are brok, wite valid money!";
        return 0;
    }
    else if(amount < 0) {
        std::cout << "Invalid amount!";
        return 0;
    }
    else {
        return amount;
    }
}
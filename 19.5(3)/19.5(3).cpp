#include <iostream>
#include <fstream>

int main() {
    std::ifstream list;
    list.open("List.txt");

    std::string dates, name, surname;
    int payment, sum = 0, max = 0;

    while (!(list.eof())) {
        list >> name >> surname >> payment >> dates;

        sum += payment;

        if (payment > max) max = payment;
        payment = 0;
    }
    list.close();

    std::cout << "Amount of payments: " << sum << std::endl;
    std::cout << "Maximum payout: " << max << std::endl;


    return 0;
}

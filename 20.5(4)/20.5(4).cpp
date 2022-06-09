#include <iostream>
#include <fstream>
#include <string>


int main() {

	int denomination[5] = { 5000, 1000, 500, 200, 100 };
	int banknotes[1000];

	std::ifstream ATM_in("ATM_machine.bin", std::ios::binary);

	if (ATM_in.peek() == EOF) {

		for (int i = 0; i < 1000; i++) {

			banknotes[i] = 0;
		}

	}
	else {
		for (int i = 0; i < 1000; i++) {
			ATM_in.read((char*)&banknotes[i], sizeof(int));
		}
	}
	


	std::cout << "Enter the operation (+ or -): " << std::endl;
	char operation;
	std::cin >> operation;
	

	if (operation == '+') {

		for (int i = 0; i < 1000; i++) {

			if (banknotes[i] == 0) {

				banknotes[i] = denomination[rand() % 5];

			}

		}

		std::ofstream ATM_out("ATM_machine.bin", std::ios::binary);
		ATM_out.write((char*)&banknotes, sizeof(banknotes));

		ATM_out.close();
		ATM_in.close();

		return 0;

	}


	if (operation == '-') {

		int amount;

		while (true) {

			std::cout << "Enter the withdrawal amount: " << std::endl;
			std::cin >> amount;

			if (amount % 100 == 0) break;
			else std::cout << "Invalid amount. Try again." << std::endl;

		}

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < 1000; j++) {

				if (banknotes[j] == denomination[i]) {

					if ((amount - denomination[i]) >= 0) {

						amount -= banknotes[j];
						banknotes[j] = 0;

						if (amount == 0) {

							std::cout << "Money successfully withdrawn!" << std::endl;

							std::ofstream ATM_out("ATM_machine.bin", std::ios::binary);
							ATM_out.write((char*)&banknotes, sizeof(banknotes));

							ATM_out.close();
							ATM_in.close();

							return 0;

						}

					}

				}

			}

		}

	}


	std::cout << "Withdrawal of funds is not possible." << std::endl;

	ATM_in.close();
	return 0;
}
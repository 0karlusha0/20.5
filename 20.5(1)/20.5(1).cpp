#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool valid(std::string name, std::string surname, std::string date, std::string sum) {
	if (!(name[0] >= 'A' && name[0] <= 'Z')) return false;
	if (!(surname[0] >= 'A' && surname[0] <= 'Z')) return false;

	for (int i = 1; i < name.length(); i++) {
		if (!(name[i] >= 'a' and name[i] <= 'z')) return false;
	}
	for (int i = 1; i < surname.length(); i++) {
		if (!(surname[i] >= 'a' and surname[i] <= 'z')) return false;
	}

	
	if (date.length() != 10) return false;
	for (int i = 0; i < 10; i++) {
		if (i == 2 or i == 5) {
			if (date[i] != '.') return false;
		}
		else {
			if (!(date[i] >= '0' && date[i] <= '9')) return false;
		}
	}
	
	if (!(std::stoi(date.substr(0, 2)) >= 1 && std::stoi(date.substr(0, 2)) <= 31)) return false;
	if (!(std::stoi(date.substr(3, 2)) >= 1 && std::stoi(date.substr(3, 2)) <= 12)) return false;
	if(std::stoi(date.substr(6))>2022) return false;

	
	int co = 0;
	for (int i = 0; i < sum.length(); i++) {
		if (sum[i] >= '0' and sum[i] <= '9');
		else if (sum[i] == '.') {
			co++;
			if (co > 1) return false;
		}else return false;
	}

	return true;

}

int main() {
	std::cout << "Enter the data: " << std::endl;
	std::string name, surname, date, sum;

	std::cin >> name >> surname >> sum >> date;

	if (valid(name, surname, date, sum)) {
		float summa = std::stof(sum);
		std::fstream list("list.txt", std::ios::app);
		list << name << " " << surname << " " << summa << " " << date << std::endl;
		list.close();
	}else
		std::cout << "Invalid data" << std::endl;
	

	return 0;
}
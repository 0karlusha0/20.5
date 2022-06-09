#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::string fish;
	std::cout << "What kind of fish will you catch?" << std::endl;
	std::cin >> fish;

	std::ifstream river("river.txt");
	std::ofstream basket("basket.txt", std::ios::app);
	std::string rvr_fsh;
	int co = 0;
	while (!river.eof()) {

		std::getline(river, rvr_fsh);

		if (rvr_fsh == fish) {
			std::cout << "You are lucky! It is a " << fish << std::endl;
			basket << fish << std::endl;
			co++;
			
		}
		else if(!rvr_fsh.empty())
			std::cout << "It's a pity, but it's a " << rvr_fsh << std::endl;
		
	}
	river.close();

	if (co > 0) std::cout << "Congratulations, you caught " << co << " fish during this fishing trip" << std::endl;
	else std::cout << "it looks like you didn't catch any fish on this fishing trip..." << std::endl;

	return 0;
}
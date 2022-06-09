#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

int main() {
	std::srand(std::time(nullptr));
	int width, height;
	std::cout << "Enter the width and height: " << std::endl;
	std::cin >> width >> height;

	std::ofstream pic("pic.txt");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pic << std::rand() % 2 << " ";
		}pic << std::endl;
	}

	pic.close();

	return 0;
}
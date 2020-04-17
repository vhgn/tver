#include <iostream>
#include <exception>
#include "tver.hpp"

int main() {
	tver::Parser parser;

	try {
		while (true) {
			parser.text = "";
			std::cout << "> ";
			std::getline(std::cin, parser.text);
			std::cout << parser.parse() << std::endl;
		}
	} catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
}

#include <iostream>
#include <exception>
#include "tver.hpp"

int main() {
	tver::Parser parser;

	while (true) {
		try {
			parser.text = "";
			std::cout << "> ";
			std::cin >> parser.text;
			std::cout << parser.parse() << std::endl;
		} catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
}

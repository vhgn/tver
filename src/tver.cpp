#include <iostream>
#include <exception>
#include "tver.hpp"

int main() {
	try {
		while (true) {
			std::cout << "> ";
			std::string text;
			std::getline(std::cin, text);
			std::cout << tver::Parser(text).parse() << std::endl;
		}
	} catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
}

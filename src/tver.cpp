#include <iostream>
#include "tver.hpp"

int main() {
	tver::Parser parser;

	try {
		while (true) {
			std::cout << "> ";
			std::cin >> parser.text;
			std::cout << parser.parse() << std::endl;
		}
	} catch (tver::Error error) {
		switch(error) {
			case tver::Error::UnrecognizedSymbol:
				std::cout << "Symbol not recognized" << std::endl;
				break;
			case tver::Error::ExtraOperand:
				std::cout << "Extra operand found in expression" << std::endl;
				break;
			case tver::Error::UnfinishedExpression:
				std::cout << "Expression is unfinished or contains an extra operand" << std::endl;
				break;
			default:
				std::cout << "Unexpected error happened" << std::endl;
		}
	}
}

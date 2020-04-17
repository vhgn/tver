#ifndef ErrorsHeader
#define ErrorsHeader

#include <exception>

namespace tver {
	namespace errors {
		struct UnrecognizedSymbol: std::runtime_error {
			UnrecognizedSymbol(): std::runtime_error{"A not recognized symbol found while parsing."} {}
		};
		
		struct UnfinishedExpression: std::runtime_error {
			UnfinishedExpression(): std::runtime_error{"The expression seems like unfinished, couldn't parse."} {}
		};

		struct ExtraOperator: std::runtime_error {
			ExtraOperator(): std::runtime_error{"An extra operand found while parsing, can't continue."} {}
		};

		struct ExpressionEndedUnexpectedly: std::runtime_error {
			ExpressionEndedUnexpectedly(): std::runtime_error{"The expression ended unexpectedly, halting."} {}
		};

		struct ExtraDecimalPoint: std::runtime_error {
			ExtraDecimalPoint(): std::runtime_error{"Extra decimal point found in a number, stopping parsing."} {}
		};

		struct ExpectedOperator: std::runtime_error {
			ExpectedOperator(): std::runtime_error{"An operator was expected but not found, can't continue."} {}
		};
	}
}

#endif // ErrorsHeader

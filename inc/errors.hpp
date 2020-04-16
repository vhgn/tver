#ifndef ErrorsHeader
#define ErrorsHeader

#include <exception>

namespace tver {
	namespace errors {
		struct UnrecognizedSymbol: std::runtime_error {
			UnrecognizedSymbol(): std::runtime_error{"UnrecognizedSymbol!"} {}
		};
		
		struct UnfinishedExpression: std::runtime_error {
			UnfinishedExpression(): std::runtime_error{"UnfinishedExpression!"} {}
		};

		struct ExtraOperand: std::runtime_error {
			ExtraOperand(): std::runtime_error{"ExtraOperand!"} {}
		};

		struct FileEndedUnexpectedly: std::runtime_error {
			FileEndedUnexpectedly(): std::runtime_error{"FileEndedUnexpectedly!"} {}
		};

		struct ExtraDecimalPoint: std::runtime_error {
			ExtraDecimalPoint(): std::runtime_error{"ExtraDecimalPoint!"} {}
		};

		struct ExpectedOperator: std::runtime_error {
			ExpectedOperator(): std::runtime_error{"ExpectedOperator!"} {}
		};
	}
}

#endif // ErrorsHeader

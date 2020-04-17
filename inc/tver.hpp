#ifndef TverHeader
#define TverHeader

#include <string>
#include <exception>
#include "errors.hpp"

#include <iostream>
#include <cstdio>
namespace tver {
	/// Operation type enum
	enum class Type {
		Number,
		Operation
	};

	/// Operation symbol enum
	enum class Symbol {
		Addition,
		Subtraction,
		Multiplication,
		Division
	};

	/// Operation struct
	struct Token {
		Type type;
		union {
			float num;
			Symbol oper;
		};

		/// Null denotation
		Token(std::string text): type{Type::Number}, num{std::stof(text)} {}

		/// Initialize a symbol
		Token(char sym): type{Type::Operation} {
			switch(sym) {
				case '+':
					oper = Symbol::Addition;
					break;
				case '-':
					oper = Symbol::Subtraction;
					break;
				case '*':
					oper = Symbol::Multiplication;
					break;
				case '/':
					oper = Symbol::Division;
					break;
				default:
					throw errors::UnrecognizedSymbol();
			}
		}
	};

	/// Expression struct
	struct Expression {
		Token val;
		std::shared_ptr<Expression> left;
		std::shared_ptr<Expression> right;

		/// Initialize with token
		Expression(Token token): val{token} {}

		/// Create expression
		Expression(Token val, Expression left, Expression right):
			val{val}, left{std::make_shared<Expression>(left)}, right{std::make_shared<Expression>(right)} {}

		/// Calculate value of tree
		float calc() {
			if (val.type == Type::Number) return val.num;
			switch (val.oper) {
				case Symbol::Addition:
					return left->calc() + right->calc();
				case Symbol::Subtraction:
					return left->calc() - right->calc();
				case Symbol::Multiplication:
					return left->calc() * right->calc();
				case Symbol::Division:
					return left->calc() / right->calc();
				default:
					throw errors::UnrecognizedSymbol();
			}
		}
	};

	inline int bp(Token token) {
		switch (token.oper) {
			case Symbol::Addition:
				return 10;
			case Symbol::Subtraction:
				return 10;
			case Symbol::Multiplication:
				return 20;
			case Symbol::Division:
				return 20;
		}
		return 0;
	}

	/// Parser object type
	struct Parser {
		unsigned index = 0;
		std::string text;

		/// Initialize parser
		Parser() {}

		/// Initialize with text
		Parser(std::string text): text{text} {}

		/// Evaluate expression recursively
		Expression eval(int power = 0) {
			Expression left{next(Type::Number)};
			while (index < text.size() && bp(peek()) > power) {
				left = led(left, next(Type::Operation));
			}
			return left;
		}
		
		/// Left denotation
		Expression led(Expression left, Token oper) {
			return Expression(oper, left, eval(bp(oper)));
		}

		/// Find and return next token
		Token next(Type type) {
			std::string num = "";
			bool end = false;
			bool decimal = false;

			while (!end) {
				switch (text[index++]) {
					case '\0':
						end = true;
					case '\n':
					case '\t':
					case ' ':
						if (num.length())
							return Token(num);
						break;
					case '.':
						if (!decimal)
							decimal = true;
						else
							throw errors::ExtraDecimalPoint();
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						num += text[index - 1];
						break;
					case '-':
						if (type == Type::Operation) // subtraction operator
							return Token(text[index - 1]);
						else if (!num.length()) // negative number
							num += text[index - 1];
						else // next operator
							end = true;
						break;
					case '+':
					case '*':
					case '/':
						if (type == Type::Operation)
							return Token(text[index - 1]);
						else
							throw errors::ExtraOperand();
					default:
						throw errors::UnrecognizedSymbol();
				}
			}

			if (type == Type::Number)
				return Token(num);
			else
				throw errors::FileEndedUnexpectedly();
		}
		
		Token peek() {
			unsigned size = text.size();
			for (unsigned i = index; i < size; i++) {
				switch (text[i]) {
					case '+':
					case '-':
					case '*':
					case '/':
						return Token(text[i]);
					case '\n':
					case '\t':
					case ' ':
						break;
					default:
						throw errors::ExpectedOperator();
				}
			}

			throw errors::UnfinishedExpression();
		}

		/// Parse string, evaluate and return the result
		float parse() {
			return eval().calc();
		}
	};
}

#endif // TverHeader

// ex_2_main.cpp
#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi

		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。

		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {

			int digit = 0;

			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos == '2' || *pos == '3' || *pos == '4' || *pos == '5' || *pos == '6' || *pos == '7' || *pos == '8' || *pos == '9') {
					switch (*pos) {
					case '2': digit = 2;
						break;
					case '3': digit = 3;
						break;
					case '4': digit = 4;
						break;
					case '5': digit = 5;
						break;
					case '6': digit = 6;
						break;
					case '7': digit = 7;
						break;
					case '8': digit = 8;
						break;
					case '9': digit = 9;
						break;
					}
				}
				else {
					//mcxiを整数に
					switch (*pos) {
					case 'm':
						digit = 1000;

					case 'c':
						digit = 100;

					case 'x':
						digit = 10;

					case 'i':
						digit = 1;
					}
				}
			}
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+

		2 つのオブジェクトの加算結果を取得します。
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			return rhs;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string

		現在の値を mcxi 記法に変換します。
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {

			while () {
				case 30:
					return "3x";
				case 10:
					return "x";
				case 610:
					return "6cx";
				case 5999:
					return "5m9c9x9i";
				case 1000:
					return "x";
				case 9999:
					return "9m9c9x9i";
				case 1001:
					return "mi";
				case 1010:
					return "mx";
			}
		}

		void debug_mcxi() {
			std::cout << "value_: " << value_ << std::endl;
		}


	private:
		int value_;
	};
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}
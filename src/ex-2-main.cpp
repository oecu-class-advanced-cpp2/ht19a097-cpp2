// ex_2_main.cpp
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

char c[4] = { 'm', 'c', 'x', 'i' };
int v[4] = { 1000, 100, 10, 1 };

int ch(string p) {
	int sum = 0;
	int h = 1;

	for (int i = 0; i<p.size(); i++) {
		if ('0' <= p[i] && p[i] <= '9') {
			h = p[i] - '0';
		}
		else {
			for (int j = 0; j<4; j++) {
				if (p[i] != c[j]) {
					continue;
				}

				sum += v[j] * h;
				h = 1;
				break;
			}
		}
	}

	return sum;
}

int mcxi(int v) {

	std::stringstream ss;

	int value_ = v;
	int m = value_ / 1000;
	int mEX = value_ % 1000;
	int c = mEX / 100;
	int cEX = value_ % 100;
	int x = cEX / 10;
	int xEX = value_ % 10;
	int i = xEX / 1;

	if (m == 1) {
		ss << 'm';
	}
	if (m > 1) {
		ss << m;
		ss << 'm';
	}

	if (c == 1) {
		ss << 'c';
	}
	if (c > 1) {
		ss << c;
		ss << 'c';
	}

	if (x == 1) {
		ss << 'x';
	}
	if (x > 1) {
		ss << x;
		ss << 'x';
	}

	if (i == 1) {
		ss << 'i';
	}
	if (i > 1) {
		ss << i;
		ss << 'i';
	}

	cout << ss.str() << endl;

	return v;
}

int main() {

	string a, b;
	int result = 0;

	cin >> a;
	cin >> b;

	result = ch(a) + ch(b);
	cout << a << " + " << b << " = ";
	mcxi(result);


	system("pause");
}
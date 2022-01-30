// kadai01.cpp
#include <iostream>
#include <math.h>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
* is_prime
*
* 与えられた正整数ｘに対して、素数判定を行い結果をTrue(1),False(0)で返す
*
*/
/* -------------------------------------------------------------- */

bool is_prime(unsigned int x) {
	//2～x-1までの数がｘを割れるか判定する
	//割れたら即falseを返す

	if (x < 2) {
		return false; //  2以下の数を除去
	}
	else if (x == 2) {
		return true;  //  2の場合、素数である
	}
	else if (x % 2 == 0) {
		return false; //  偶数は除去
	}

	double sqrtx = sqrt(x);
	for (int i = 3; i <= sqrtx; i += 2) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {

	int k;
	int s;

	int p[1000],in[1000];

	for (int i = 0; i < 300; i++) {
		//std::cout << i << std::endl;
		k = a + (i * d);
		//std::cout << i <<" : "<< k << std::endl;

		in[i] = k;

		//is_primeの返り値が１であった場合、素数用配列に整数用配列のi番目の値をいれる
		if (is_prime(in[i]) == 1) {
			p[i] = in[i];

		}
	}

	//  素数リストからn番目の値を結果として出力
	s = p[n];

	return s;
}

int main() {
	 std::cout << nth_prime(367, 186, 151) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。

	system("pause");
	return 0;
}
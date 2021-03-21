문제
자연수 과 정수 가 주어졌을 때 이항 계수 
를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 과 가 주어진다. (1 ≤  ≤ 10, 0 ≤  ≤ )

출력
 
를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10

------------------------------------------------------
재귀

#include <iostream>
#include <string>
#include <deque>
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int fac(int N) {
	if (N == 1) return 1;
	return N * fac(N - 1);
}
int main() {
	fastio;
	int N, K;
	cin >> N >> K;
	if (K == 0) {
		cout << 1;
		return 0;
	}
	cout << fac(N) / (fac(N - K) * fac(K));
	return 0;
}

-----------------------------------------------------
DP

#include <iostream>
#include <string>
#include <deque>
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int fac[11] = { 0 };
int main() {
	fastio;
	int N, K;
	fac[0] = 1;
	fac[1] = 1;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
	}
	cout << fac[N] / (fac[N - K] * fac[K]);
	return 0;
}

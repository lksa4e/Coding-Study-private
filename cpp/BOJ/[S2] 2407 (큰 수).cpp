문제
nCm을 출력한다.

입력
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

출력
nCm을 출력한다.

예제 입력 1 
100 6
예제 출력 1 
1192052400

알고리즘 분류
수학
다이나믹 프로그래밍
조합론
임의 정밀도 / 큰 수 연산

---------------------------------------------------------------------
n, m의 범위가 5 ~ 100인 경우 nCr의 값은 long long을 넘어갈 수 있다.
따라서 단순 연산이 아닌 string으로 변환하여 값을 계산하는 방법이 필요하다.

-----------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin,(x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second


using namespace std;
typedef pair<int, int> pii;

int N, M;
string combi[101][101];
string add_num(string s1, string s2) {
	string result = "";
	string temp1(s1); 
	string temp2(s2);
	long long sum = 0;
	while (!temp1.empty() || !temp2.empty() || sum) {  // 마지막 ||sum은 10 넘을때 if else 이런거 없이 처리할 수 있음
		if (!temp1.empty()) {
			sum += temp1.back() - '0';
			temp1.pop_back();
		}
		if (!temp2.empty()) {
			sum += temp2.back() - '0';
			temp2.pop_back();
		}
		result += (sum % 10) + '0';
		sum /= 10;
	}
	reverse(result.begin(), result.end());  // 정답이 뒤집혀져 있으므로 reverse 시켜준다.
	return result;
}
void combination(int n, int r) {
	combi[1][0] = "1";
	combi[1][1] = "1";
	if (r == 0 || r == N) {
		cout << 1;
		return;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == 0 || j == N) combi[i][j] = "1";
			else combi[i][j] = add_num(combi[i - 1][j - 1], combi[i - 1][j]);
		}
	}
	cout << combi[n][r];
}
int main() {
	fastio;
	int a;
	cin >> N >> M;
	combination(N,M);
	return 0;
}

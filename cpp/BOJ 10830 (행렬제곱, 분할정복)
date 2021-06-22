문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

예제 입력 1 
2 5
1 2
3 4
예제 출력 1 
69 558
337 406
예제 입력 2 
3 3
1 2 3
4 5 6
7 8 9
예제 출력 2 
468 576 684
62 305 548
656 34 412
예제 입력 3 
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
예제 출력 3 
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512

알고리즘 분류
수학
분할 정복
분할 정복을 이용한 거듭제곱
선형대수학

---------------------------------------
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
typedef long long ll;
typedef vector<vector<ll>> matrix;

int N;
long long M; // 행렬 size, 제곱수
matrix origin;

matrix cal(matrix a, matrix b) {
	matrix ret(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= 1000;
		}
	}
	return ret;
}

matrix solve(ll n) {
	if (n == 1) return origin;
	if (n % 2 == 1) {
		matrix ans = solve(n - 1);
		return cal(ans, origin);
	}
	else {
		matrix ans = solve(n / 2);
		return cal(ans, ans);
	}
}
int main() {
	fastio;
	int a;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		vector<ll> temp;
		for (int j = 0; j < N; j++) {
			cin >> a;
			temp.push_back(a);
		}
		origin.push_back(temp);
	}
	matrix result = solve(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] % 1000 << " ";
		}
		cout << '\n';
	}

	return 0;
}

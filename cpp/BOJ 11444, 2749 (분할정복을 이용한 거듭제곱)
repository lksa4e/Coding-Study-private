문제
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.

예제 입력 1 
1000
예제 출력 1 
517691607


알고리즘 분류
수학
분할 정복을 이용한 거듭제곱

-----------------------------------------------------
이 문제는 일반적인 재귀함수로 풀면 시간 초과를 받고, 메모이제이션을 적용하려 해도 메모리 제한에 걸리게 된다.
이 문제는 피보나치 수를 행렬로 생각하고, 행렬의 거듭제곱을 이용해서 풀어야 한다.

A^N 을 구하는 방법 중 하나는 A를 N번 곱하는 것이 아닌 A^ N -> A ^((N/2) *N) 방식으로 쪼개어 분할정복으로 log N에 해결하는 방법이 있다.
피보나치 수열도 동일하게 같은 방법을 사용하여 행렬의 제곱거듭을 이용한 피보나치 풀이에서 행렬의 거듭제곱을 분할정복을 이용하여 해결한다.
f(n+1)  = [ 1,1 ]^ N f(1) 
f(n)      [ 1,0 ]    f(0)

--------------------------------------------------------
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

ll mod = 1000000;
ll N;
matrix origin = { {1,1},{1,0} };

matrix cal(matrix a, matrix b) {
	matrix ret(2, vector<long long>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
			ret[i][j] %= mod;
		}
	}
	return ret;
}
matrix solve(ll n) {             // 1 1 1 0 행렬의 N승을 구하는 
	matrix temp;
	if (n == 1) return origin;
	if (n % 2 == 1) { // 홀수
		temp = solve(n - 1);
		return cal(temp, origin);
	}
	else {     //짝수
		temp = solve(n / 2);
		return cal(temp, temp);
	}
}
int main() {
	fastio;
	cin >> N;
	matrix answer = solve(N);
	cout << answer[1][0];
	return 0;
}

문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

예제 입력 1 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
예제 출력 1 
30

알고리즘 분류
다이나믹 프로그래밍

-----------------------------------------------------------------
예제 입력처럼 진짜 삼각형이 아닌 한쪽이 평면인 삼각형일 때
대각선 왼 오른쪽에서 내려오는 경우는 i -> i , i+ 1 로 직선과 대각선 오른쪽으로 내려오는 경우이다.
따라서 0번째인 경우에만 예외처리를 해주고 나머지는 dp 점화식으로 해결한다.

---------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);

using namespace std;
vector<int> v[501];
int dp[501][501];
int main() {
	fastio;
	int N, a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			cin >> a;
			if (i == 1) dp[i][j] = a;
			else {
				if (j == 0) {
					dp[i][j] = dp[i - 1][j] + a;
				}
				else {
					dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a;
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (result < dp[N][i]) result = dp[N][i];
	}
	cout << result;
	return 0;
}

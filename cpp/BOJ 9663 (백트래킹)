문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

예제 입력 1 
8
예제 출력 1 
92


--------------------------------------------------------------------------
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
int cnt = 0;
int col[15] = { 0 };
bool queen_check(int x) {
	for (int i = 0; i < x; i++) {
		if (col[x] == col[i] || abs(col[x] - col[i]) == (x - i))          // 이전에 놓았던 queen들과 같은 열인지 or 대각선 위치에 있는지 check
			return false;
	}
	return true;           // 이전 queen들과 겹치는 것이 없으면 true
}
void dfs(int x) {
	if (x == N) {          // N개의 queen을 전부 설치했다면 count 증가
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++){
		col[x] = i;               // 특정 열을 선택
		if (queen_check(x)){      // 그 열에 queen 놓는것이 가능한지?
			dfs(x + 1);
		}
	}
}
int main() {
	cin >> N;
	dfs(0);
	cout << cnt;
	return 0;
}

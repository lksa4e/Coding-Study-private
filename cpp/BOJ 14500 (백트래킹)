문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 
입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

예제 입력 1 
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
예제 출력 1 
19
예제 입력 2 
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
예제 출력 2 
20
예제 입력 3 
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
예제 출력 3 
7



--------------------------------------------------------
ㅗ 모양을 제외한 테트로미노들은 깊이 4까지의 dfs를 통해서 검사 가능하다.
하지만 ㅗ 모양은 dfs로 검사할 수 없기 때문에 따로 함수를 구현해서 검사해주어야 한다.

가능한 경우의 가지수는 ㅜ,ㅓ,ㅏ,ㅗ 의 4가지이고 dfs 호출과 함께 ㅗ 검사함수도 호출하여 최대값을 갱신한다.

---------------------------------------------------------

#include <iostream>
#include <bitset>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int pixel[501][501] = { 0 }; 
bool visit[501][501] = { 0 }; 
int dx[4] = { 1,-1,0,0 };  //dfs 위한 좌표
int dy[4] = { 0,0,1,-1 };
int ex[4][4] = { {0,0,0,1} , {0,0,-1,1}, {0,1,2,1} , {0,0,0,-1} };  // ㅗ 모양 검사 위한 좌표모음 (ㅜ ㅓ ㅏ ㅗ)
int ey[4][4] = { {0,1,2,1}, {0,1,1,1}, {0,0,0,1}, {0,1,2,1} };
int N, M;
int result = 0;
void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		result = max(result, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				dfs(nx, ny, cnt + 1 , sum + pixel[nx][ny]);
				visit[nx][ny] = 0;
			}
		}
	}
}
void arrow_shape(int x, int y) {  // ㅗ 모양은 DFS로 구현이 안되기 때문에 별도로 빼서 검사
	for (int i = 0; i < 4; i++) {
		int sum = 0;
		bool flag = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + ex[i][j];
			int ny = y + ey[i][j]; 

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				sum += pixel[nx][ny];
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			result = max(result, sum);
		}
	}
}
int main() {
	fastio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, answer = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			pixel[i][j] = a;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result = 0;
			visit[i][j] = 1;
			dfs(i, j, 1, pixel[i][j]);
			visit[i][j] = 0;
			arrow_shape(i, j);
			answer = max(answer, result);
		}
	}
	cout << answer;
	return 0;
}

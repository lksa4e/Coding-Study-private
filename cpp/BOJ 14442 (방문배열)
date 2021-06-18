문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

예제 입력 1 
6 4 1
0100
1110
1000
0000
0111
0000
예제 출력 1 
15
예제 입력 2 
6 4 2
0100
1110
1000
0000
0111
0000
예제 출력 2 
9
예제 입력 3 
4 4 3
0111
1111
1111
1110
예제 출력 3 
-1

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색

--------------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin, (x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first
#define snd second

using namespace std;
typedef pair<int, int> pii;

bool graph[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[11][1001][1001];
int N, M, K;
int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ 0,0,1,0 });
	visit[0][0][0] = 1;
	int find = -1;
	int result = INF;
	while (!q.empty()) {
		auto [x, y, cnt, brk] = q.front(); q.pop();
		if (x == N - 1 && y == M - 1) {
			find = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (graph[nx][ny] == 1 && brk < K && !visit[brk + 1][nx][ny]) {
					visit[brk + 1][nx][ny] = 1;
					q.push({ nx, ny, cnt + 1, brk + 1 });
				}
				else if (!visit[brk][nx][ny] && graph[nx][ny] == 0) {
					visit[brk][nx][ny] = 1;
					q.push({ nx, ny, cnt + 1, brk });
				}
			}
		}
	}
	return find;
}
int main() {
	fastio;
	string s;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}
	cout << bfs();
	return 0;
}

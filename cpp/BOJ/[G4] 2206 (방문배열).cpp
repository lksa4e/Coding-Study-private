문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 
이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

예제 입력 1 
6 4
0100
1110
1000
0000
0111
0000
예제 출력 1 
15
예제 입력 2 
4 4
0111
1111
1111
1110
예제 출력 2 
-1

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색

---------------------------------------------------------
방문배열이란 것은, bfs에서 '모든 경우'를 살펴보며 진행할 때, 같은 행위를 두번하면 비효율적이니 그걸 막기 위해 사용합니다.

방문배열은 '모든 경우'를 나타낼 수 있어야 합니다. 일반적인 bfs 문제에서 모든 경우는 결국 '이 위치에 이미 왔었다' 입니다.
따라서 그냥 2차원 방문배열로 나타내면 되는거구요.

이 문제에서 모든 경우는 말로 설명하자면 '해당 위치에 벽을 부순 상태로 이미 왔었거나, 해당 위치에 아직 벽을 부수지 않은 상태로 이미 왔었다.' 정도가 되겠습니다.
따라서 이걸 표현하기 위해 3차원 배열로 나타내야 한다.

000000
111110
010000
010111
010011
011011
000*10


1,1 지점에서 아래쪽으로 벽을 뚫고 진행한 녀석은 *까지 빠르게 갈꺼구요. *도 0이라고 칩시다.

어쨌든 *까지 도달했으니 *에도 방문배열에 체크를 했구요. 벽을 뚫고 진행했으니 목적지에는 도달할 수 없습니다.

그 와중에 1,1 지점에서 오른쪽으로 진행한 녀석은 꼬불꼬불한 길을 따라 천천히 * 직전까지 옵니다.

사실 얘는 *까지만 오면 벽을 아직 안부셨으니깐 목적지 좌측의 벽을 부수고 목적지에 갈 수 있습니다.

하지만 이미 방문체크가 되어있으니 * 지점에 갈수가 없어요 ㅠ

따라서 프로그램은 목적지에 도달하지 못한다고 판단할껍니다.

------------------------------------------------------------
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
bool visit[2][1001][1001];
int N, M;
int bfs() {
	queue<tuple<int,int,int,int>> q;
	q.push({ 0,0,1,1});
	visit[1][0][0] = 0;
	int find = -1;
	int result = INF;
	while (!q.empty()) {
		auto [x, y, cnt, brk] = q.front(); q.pop();
		if (x == N - 1 && y == M - 1) {
			find = 1;
			result = min(result, cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[brk][nx][ny]) {
					if (graph[nx][ny] == 1 && brk == 1) {
						visit[0][nx][ny] = 1;
						q.push({ nx,ny, cnt + 1, 0 });
					}
					else if (graph[nx][ny] == 0) {
						visit[brk][nx][ny] = 1;
						q.push({ nx,ny,cnt + 1, brk });
					}
				}
			}
		}
	}
	if (find == -1) return find;
	else return result;
}
int main() {
	fastio;
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			graph[i][j] = (s[j] - '0');
		}
	}
	cout << bfs();
	return 0;
}

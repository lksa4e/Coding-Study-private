문제
어제 선물을 모두 포장한 민식이는 이제 선물을 배달하려고 한다. 민식이가 선물을 배달할 곳은 이 문제를 읽는 사람들이 앉아 있는 교실이다. 
교실은 직사각형모양이고, 모두 같은 크기의 정사각형 블록으로 나누어져 있다.
	

입력으로 교실의 지도가 주어진다. 각각의 정사각형 블록은 다음과 같이 4가지 종류가 있다.

S : 지금 민식이가 있는 곳이다. 이곳이 민식이가 배달을 시작하는 곳이다.
C : 민식이가 반드시 선물을 배달해야 하는 곳이다. 이러한 블록은 정확하게 2개 있다.
# : 민식이가 갈 수 없는 곳이다.
. : 민식이가 자유롭게 지나갈 수 있는 곳이다.
민식이가 한 블록 동서남북으로 이동하는데는 1분이 걸린다. 민식이는 네가지 방향 중 하나로 이동할 수 있으며, 교실을 벗어날 수 없다. 
민식이가 선물을 배달해야 하는 곳에 들어갈 때, 민식이는 그 곳에 있는 사람 모두에게 선물을 전달해야 한다. 이 상황은 동시에 일어나며, 추가적인 시간이 소요되지 않는다.

민식이는 어느 누구도 자신을 보지 않았으면 하기 때문에, 멈추지 않고 매 시간마다 방향을 바꿔야 한다. 이 말은 같은 방향으로 두 번 연속으로 이동할 수 없다는 말이다.
민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 교실의 세로 크기 N과 가로 크기 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 교실의 지도가 주어진다.

출력
첫째 줄에 민식이가 선물을 모두 배달하는데 걸리는 시간의 최솟값을 출력한다. 만약 불가능 할 때는 -1을 출력한다.

예제 입력 1 
2 3
SCC
...
예제 출력 1 
4

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색

-----------------------------------
기존 벽부수기2 문제와는 다르게 선물이 2개이고 각각의 선물이 지정되어 있다.
따라서 단순히 N개의 벽을 부수는것으로 모든 경우를 표시했던 벽부수기 문제와 다르게
1번 선물, 2번 선물 순서를 지정해주어야한다.
5차원 배열을 통해
bool visit[51][51][4][2][2];    // 0 1 2 3 아 위 오 왼 // 남은선물 C, D
x,y 좌표, 이전 방향, C 배달여부, D 배달여부를 체크해준다.

----------------------------------------
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
char graph[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[51][51][4][2][2];    // 0 1 2 3 아 위 오 왼 // 남은선물 C, D
int N, M;
int start_x, start_y;
int bfs() {
	queue<tuple<int, int, int, int, int, int>> q;     // x, y, cnt, 방향, C, D
	q.push({ start_x,start_y, 0, -1, 0, 0 });
	int find = -1;
	while (!q.empty()) {
		auto [x, y, cnt, dir, c_visit, d_visit] = q.front(); q.pop();
		if (c_visit && d_visit) {
			find = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			int temp_c = c_visit;
			int temp_d = d_visit;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny][i][c_visit][d_visit] && graph[nx][ny] != '#') {
					if (graph[nx][ny] == 'C') temp_c = 1;
					if (graph[nx][ny] == 'D') temp_d = 1;
					visit[nx][ny][i][temp_c][temp_d] = 1;
					q.push({ nx, ny, cnt + 1, i, temp_c, temp_d });
				}
			}
		}
	}
	return find;
}
int main() {
	fastio;
	string s;
	cin >> N >> M;
	int flag = 1;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			graph[i][j] = s[j];
			if (s[j] == 'S') {
				start_x = i;
				start_y = j;
			}
			if (s[j] == 'C') {
				if (flag) {
					graph[i][j] = 'C';
					flag = 0;
				}
				else graph[i][j] = 'D';
			}
		}
	}
	cout << bfs();
	return 0;
}

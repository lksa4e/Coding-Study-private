문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

예제 입력 1 
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
예제 출력 1 
27


알고리즘 분류
그래프 이론
그래프 탐색
브루트포스 알고리즘
너비 우선 탐색

---------------------------------------------------------
1. 벽을 3개 세우는 가지수는 통로의 개수 n개 중에 3개를 고르는 경우의 수인 nC3가지이다.
2. nC3의 케이스마다 안전영역의 크기를 구한다.
   -- 방법 1 BFS를 돌면서 바이러스의 크기를 세준다. 전체 영역 - 바이러스 영역 - 벽 == 안전영역
   -- 방법 2 BFS를 돌면서 바이러스를 퍼트린 후 안전영역을 찾는다. 전체 배열 중 0인 것 == 안전영역
3. 모든 케이스에서 안전영역 중 최대값을 구한다. 

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

int N, M;
int graph[9][9];
bool visit[9][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int wall_num = 3;
vector<pii> blank;
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}
int bfs(int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	visit[x][y] = 1;
	int count = 1;
	while (!q.empty()) {
		auto [cur_x, cur_y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visit[nx][ny] && graph[nx][ny] != 1) {
					visit[nx][ny] = 1;
					q.push({ nx,ny });
					count++;
				}
			}
		}
	}
	return count;
}
int solve2() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && graph[i][j] == 2) {
				result += bfs(i, j);
			}
		}
	}
	return result;
}
void solve() {
	int start = 0;
	int final = 999999;
	vector<int> temp;
	for (int i = 0; i < blank.size(); i++) {
		if (i < 3) temp.push_back(1);
		else temp.push_back(0);
	}
	sort(temp.begin(), temp.end());
	do {                                            // next_permutation을 이용한 조합 찾기
		vector<pii> wall;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1) {
				wall.push_back(blank[i]);
			}
		}
		for (int i = 0; i < 3; i++) {
			graph[wall[i].fst][wall[i].snd] = 1;
		}
		init();
		final = min(final, solve2());
		for (int i = 0; i < 3; i++) {
			graph[wall[i].fst][wall[i].snd] = 0;
		}
	} while (next_permutation(temp.begin(), temp.end()));
	cout << (N * M) - final - wall_num;
}

int main() {
	fastio;
	cin >> N >> M;
	ll answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) blank.push_back({ i,j });
			if (graph[i][j] == 1) wall_num++;
		}
	}
	solve();
	return 0;
}

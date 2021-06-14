
문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 
이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 
두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 
시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.

모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

예제 입력 1 
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
예제 출력 1 
10

--------------------------------------------------------------------------
문제는 i -> X 까지의 최단거리 + X -> i 까지의 최단거리 중 최대값을 찾는 문제이다.
1. 플로이드 - 와샬 알고리즘을 통해 모든 최단거리를 구한 후 최대값을 찾는다.
2. 모든 N에 대해 다익스트라 알고리즘을 사용한 후 최대값을 찾는다.

플로이드 와샬은 기본적으로 N^3 알고리즘 + 2차원 dist 배열을 사용하므로 메모리, 시간 소모가 많다.
-------------------------------------------------------------------------------
// 플로이드 - 와샬

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
using namespace std;
int graph[1001][1001];
int dist[1001][1001];
int N, M, X; // 사람, 도로수, 도착점

void floid() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else if (graph[i][j] == 0) dist[i][j] = 999999;
			else {
				dist[i][j] = graph[i][j];
			}
		}
	}
}
int main() {
	fastio;
	int a, b, c, result = 0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	init();
	floid();
	for (int i = 1; i <= N; i++) {
		result = max(dist[i][X] + dist[X][i], result);
	}
	cout << result;
	return 0;
}

-------------------------------------------------------
// 다익스트라
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
using namespace std;
vector<pair<int,int>> v[1001];
int dist[1001];
int N, M, X; // 사람, 도로수, 도착점
void dijk(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (auto data : v[node]) {
			int next_cost = cost + data.second;
			int next_node = data.first;
			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push({ -next_cost, next_node });
			}
		}
	}
}
void init() {
	for (int i = 0; i <= N; i++) {
		dist[i] = 999999;
	}
}
int main() {
	fastio;
	int a, b, c, result = 0;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	for (int i = 1; i <= N; i++) {
		int result1, result2;
		init();
		dijk(i);
		result1 = dist[X];
		init();
		dijk(X);
		result2 = dist[i];
		result = max(result1 + result2, result);
	}
	cout << result;
	return 0;
}

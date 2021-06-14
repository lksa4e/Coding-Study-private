문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 
둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1 
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1 
0
2
3
7
INF

-------------------------------------------------

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
vector<pair<int, int>> v[20001];
int dist[20001];
int N, M, must_1, must_2; // 정점, 간선, 필수 정점
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
		dist[i] = 9999999;
	}
}
int main() {
	fastio;
	int a, b, c, start, result = 0;
	cin >> N >> M;
	cin >> start;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	init();
	dijk(start);
	for (int i = 1; i <= N; i++) {
		if (i == start) cout << 0 << '\n';
		else {
			if (dist[i] == 9999999) cout << "INF\n";
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}

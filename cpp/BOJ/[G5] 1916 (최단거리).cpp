문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다.
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.

입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 
그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 
그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

예제 입력 1 
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
예제 출력 1 
4

알고리즘 분류
그래프 이론
다익스트라

----------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#pragma warning(disable:4996)
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);

using namespace std;
typedef pair<int, int> pii;
vector<pii> graph[1001];
long long dist[1001];
int N, M, start_node, end_node;

void dijk(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		auto [cost, cur_node] = pq.top(); pq.pop();
		if (dist[cur_node] < cost) continue;
		for (auto [next_node, ncost] : graph[cur_node]) {
			if (dist[next_node] > cost + ncost) {
				dist[next_node] = cost + ncost;
				pq.push({ dist[next_node], next_node });
			}
		}
	}
}
int main() {
	fastio;
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> start_node >> end_node;
	fill(dist + 1, dist + 1 + N, INF);
	dijk(start_node);
	cout << dist[end_node];
	return 0;
}

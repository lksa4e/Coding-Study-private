문제
n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다. 
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라. 
항상 시작점에서 도착점으로의 경로가 존재한다.

입력
첫째 줄에 도시의 개수 n(1≤n≤1,000)이 주어지고 둘째 줄에는 버스의 개수 m(1≤m≤100,000)이 주어진다. 
그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 
그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.

그리고 m+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다.

출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

둘째 줄에는 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수를 출력한다. 출발 도시와 도착 도시도 포함한다.

셋째 줄에는 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력한다.

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
3
1 3 5

알고리즘 분류
그래프 이론
다익스트라

---------------------------------------------
일반적인 다익스트라 문제에서 경로를 추가하는 문제이다.

Node의 이전 Node 정보를 저장할 수 있는 배열을 추가한다.
거리가 최단거리로 갱신되는 순간에 이전 Node에 대한 정보를 갱신한다. 
(ex 4 -> 5 연결간선 처리될 때 5로 가는 최단거리 갱신되면 Node[5] = 4

--------------------------------------------------
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

int N,M, start_idx, end_idx;
vector<pii> graph[1001];
int dist[1001];
int path[1001];
void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[start_idx] = 0;
}
void solve() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start_idx });
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();

		if (dist[cur] < cost) continue;

		for (auto [nidx, ncost] : graph[cur]) {
			if (dist[nidx] > cost + ncost) {
				dist[nidx] = cost + ncost;
				path[nidx] = cur;
				pq.push({ cost + ncost, nidx });
			}
		}
	}
}
int main() {
	fastio;
	int a,b,c;
	vector<int> answer;
	cin >> N>>M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> start_idx >> end_idx;
	init();
	solve();
	int root = end_idx;
	while (root != start_idx) {
		answer.push_back(root);
		root = path[root];
	}
	answer.push_back(start_idx);

	cout << dist[end_idx] << '\n' << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	return 0;
}

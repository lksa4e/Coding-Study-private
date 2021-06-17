문제
트리(tree)는 사이클이 없는 무방향 그래프이다. 트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 
트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 
이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.



이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.

입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 
아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.



트리의 노드는 1부터 n까지 번호가 매겨져 있다.

입력
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. 
간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 
두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 
부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

예제 입력 1 
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
예제 출력 1 
45

그래프 이론
그래프 탐색
트리
깊이 우선 탐색

---------------------------------------------------
트리의 지름을 구하는 법 
1. 한 점에서 가장 먼 점을 선택한다. (u)
2. 그 점에서 가장 먼 점을 선택한다. (v)
3. 두 점 사이의 거리가 트리의 지름이다 d(u,v)

귀류법을 통한 증명 -> https://www.quora.com/How-does-following-algorithm-for-finding-longest-path-in-tree-work 

정답을 구하는법 
1. dfs를 통해 가장 먼 거리의 정점을 찾기
2. 다익스트라를 통해 가장 먼 거리의 정점을 찾기


---------------------------------------------------

다익스트라
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
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

vector<pii> graph[10001];               // 다음노드, 거리
int dist[10001];
int N;
void dijk(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		auto [cost, idx] = pq.top(); pq.pop();
		if (dist[idx] < cost) continue;
		for (auto [nidx, ncost] : graph[idx]) {
			if (dist[nidx] > cost + ncost) {
				dist[nidx] = cost + ncost;
				pq.push({ ncost + cost, nidx });
			}
		}
	}
}
void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
}
pii find_max(int start) {
	int max_result = 0, max_idx;
	for (int i = 1; i <= N; i++) {
		if (max_result < dist[i]) {
			max_idx = i;
			max_result = dist[i];
		}
	}
	return { max_result, max_idx };
}
int main() {
	fastio;
	int a,b,c;
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	init();
	dijk(1);

	int mid_result = find_max(1).snd;
	init();
	dijk(mid_result);
	int final_result = find_max(mid_result).fst;

	cout << final_result;
	return 0;
}

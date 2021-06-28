문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

예제 입력 1 
3 3
1 2 1
2 3 2
1 3 3
예제 출력 1 
3


알고리즘 분류
그래프 이론
최소 스패닝 트리


--------------------------------------------------------------------------
MST를 구하는 방법 
1. 프림 알고리즘 O(E*log(V))
2. 크루스칼 알고리즘 O(E*log(E))

프림알고리즘
- 임의의 한 점을 잡아두고 해당 정점에서 연결된 간선들 중 최소의 가중치를 고르는 정점을 선택
- 위의 과정을 반복

크루스칼 알고리즘
- 전체 간선을 가중치 기준으로 정렬함
- 주어진 간선들에 대해 새롭게 추가하는 경우 싸이클(유니온파인드)이 발생하지 않는다면 정답에 추가

----------------------------------------------------------------------------
프림 

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x) (x).begin(),(x).end()
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int V, E;
vector<pii> graph[10001];
int parent[10001];
bool visit[10001];
void solve() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,1 });
	int result = 0;
	while (!pq.empty()) {
		auto [w, idx] = pq.top(); pq.pop();

		if (visit[idx]) continue;
		visit[idx] = 1;
		result += w;

		for (auto [nidx, nw] : graph[idx]) {
			if (visit[nidx]) continue;
			pq.push({ nw, nidx });
		}
	}
	cout << result;
}

int main() {
	fastio;
	int a, b, c; 
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	solve();
	return 0;
}

-------------------------------------------------------------------


크루스칼

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x) (x).begin(),(x).end()
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int V, E;
vector<tuple<int,int,int>> edges;
int parent[10001];
void parent_set() {
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
}
int Find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void solve() {
	parent_set();
	sort(all(edges));
	int result = 0;
	int cnt = 1;
	for (auto [w, v1, v2] : edges) {
		if (Find(v1) != Find(v2)) {
			Union(v1, v2);
			cnt++;
			result += w;
		}
		if (cnt == V) break;
	}
	cout << result;
}

int main() {
	fastio;
	int a, b, c; 
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edges.push_back({ c,a,b });
	}
	solve();
	return 0;
}

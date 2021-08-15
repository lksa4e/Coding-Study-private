문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

예제 입력 1 
7
1 6
6 3
3 5
4 1
2 4
4 7
예제 출력 1 
4
6
1
3
1
4
예제 입력 2 
12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12
예제 출력 2 
1
1
2
3
3
4
4
5
5
6
6
출처

알고리즘 분류
그래프 이론
그래프 탐색
트리
너비 우선 탐색
깊이 우선 탐색


--------------------------------------------------------------
1부터 시작하여 BFS로 연결된 간선을 모두 탐색한다.

a <-> b 연결관계일 때 
1부터 시작하여 먼저 만나게 되는 노드가 무조건 부모가 된다.

BFS를 수행하였기 때문에 먼저 나오는 노드가 1에 더 가까운 노드가 되고, 부모가 되게 된다.

1에서 시작하여 연결된 간선들을 탐색하며 부모를 1로 만들어 주고
그 다음 노드들도 동일한 작업을 수행한다.

------------------------------------------------------
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
vector<int> adj[100001];
bool visit[100001];
int parent[100001];

void solve() {
	queue<int> q; // 나, 부모
	q.push(1); 
	visit[1] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto next : adj[cur]) {
			if (!visit[next]) {
				visit[next] = 1;
				parent[next] = cur;
				q.push(next);
			}
		}
	}
}

int main() {
	fastio;
	int a,b;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve();
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}


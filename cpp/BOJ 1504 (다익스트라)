문제
방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다. 
또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.

세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 
1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 
둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데,
a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 
다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v1과 v2가 주어진다. (v1 ≠ v2, v1 ≠ N, v2 ≠ 1)

출력
첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.

예제 입력 1 
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
예제 출력 1 
7


알고리즘 분류
그래프 이론
다익스트라


---------------------------------------------------------------------------------
양방향 그래프인거 신경쓰자

두개의 정점을 모두 지나야 하므로
start -> v1 -> v2 -> end
start -> v2 -> v1 -> end
두개의 가지수가 존재한다.

--------------------------------------------------------------------------
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
vector<pair<int, int>> v[801];
int dist[801];
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
	int a, b, c, result = 0;
	int case1 = 0, case2 = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a,c });
	}
	cin >> must_1 >> must_2;
	init();
	dijk(1);
	case1 = dist[must_1];          // 1 -> c1
	case2 = dist[must_2];          // 1 -> c2
	init();
	dijk(must_1);
	case1 += dist[must_2];         // 1 -> c1 -> c2
	case2 += dist[N];              // 1 -> c2    c1 -> N
	init();
	dijk(must_2);
	case2 += dist[must_1];         // 1 -> c2 -> c1 -> N
	case1 += dist[N];              // 1 -> c1 -> c2 -> N

	result = min(case1, case2);
	if (result >= 9999999) cout << -1;
	else cout << result;
	return 0;
}

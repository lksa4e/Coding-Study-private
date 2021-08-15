문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 각 버스는 A, B, C로 나타낼 수 있는데, 
A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는 순간 이동을 하는 경우, 
C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.

1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 
둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다. 

출력
만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다. 
그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다. 
만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.

예제 입력 1 
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2
예제 출력 1 
4
3
예제 입력 2 
3 4
1 2 4
1 3 3
2 3 -4
3 1 -2
예제 출력 2 
-1
예제 입력 3 
3 2
1 2 4
1 2 3
예제 출력 3 
3
-1

알고리즘 분류
그래프 이론
벨만–포드

------------------------------------------------
음수 가중치를 사용하며, 싸이클이 생기는지 확인하는 문제이므로 
벨만 -포드 알고리즘을 사용한다.

이 때 dist의 범위가 int를 초과할 수 있으므로 long long 자료형을 사용한다.

---------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#pragma warning(disable:4996)
#define INF 9999999
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
using namespace std;
vector<pair<int, int>> v[501];
long long dist[501];
int N, M;
void bellman() {
	dist[1] = 0;
	int flag = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 1; i <= N; i++) {  // 모든 정점에 대해
			for (auto data : v[i]) {   // 연결된 간선
				if (dist[i] != INF && dist[data.first] > dist[i] + data.second) {
					dist[data.first] = dist[i] + data.second;
					if (k == N - 1) flag = 1;
				}
			}
		}
	}
	if (flag) cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
}
void init() {
	for (int i = 1; i <= N; i++) dist[i] = INF;
}
int main() {
	fastio;
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	init();
	bellman();
	return 0;
}

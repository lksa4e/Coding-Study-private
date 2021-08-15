문제
요즘 많은 자동차에서는 GPS 네비게이션 장비가 설치되어 있다. 네비게이션은 사용자가 입력한 출발점과 도착점 사이의 최단 경로를 검색해 준다. 
하지만, 교통 상황을 고려하지 않고 최단 경로를 검색하는 경우에는 극심한 교통 정체를 경험할 수 있다.

상근이는 오직 자기 자신만 사용 가능한 네비게이션을 만들고 있다. 이 네비게이션은 절대로 최단 경로를 찾아주지 않는다. 항상 거의 최단 경로를 찾아준다.

거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다. 

예를 들어, 도로 지도가 아래와 같을 때를 생각해보자. 원은 장소를 의미하고, 선은 단방향 도로를 나타낸다. 시작점은 S, 도착점은 D로 표시되어 있다. 
굵은 선은 최단 경로를 나타낸다. (아래 그림에 최단 경로는 두 개가 있다)거의 최단 경로는 점선으로 표시된 경로이다. 
이 경로는 최단 경로에 포함되지 않은 도로로 이루어진 경로 중 가장 짧은 경로이다. 거의 최단 경로는 여러 개 존재할 수도 있다. 
예를 들어, 아래 그림의 길이가 3인 도로의 길이가 1이라면, 거의 최단 경로는 두 개가 된다. 또, 거의 최단 경로가 없는 경우도 있다.



입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 
장소는 0부터 N-1번까지 번호가 매겨져 있다. 둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N) 다음 M개 줄에는 도로의 정보 U, V, P가 주어진다.
(U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다. U에서 V로 가는 도로는 최대 한 개이다. 
또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다. 

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다. 만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.

예제 입력 1 
7 9
0 6
0 1 1
0 2 1
0 3 2
0 4 3
1 5 2
2 6 4
3 6 2
4 6 4
5 6 1
4 6
0 2
0 1 1
1 2 1
1 3 1
3 2 1
2 0 3
3 0 2
6 8
0 1
0 1 1
0 2 2
0 3 3
2 5 3
3 4 2
4 1 1
5 1 1
3 0 1
0 0


-----------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int dist[MAX];
vector<pair<int, int>> graph[MAX]; //{상대 노드, 길이}
vector<int> path[MAX];

void dijk(int start) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	dist[start] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int cur_node = q.top().second;
		q.pop();
		if (cost > dist[cur_node]) continue;

		for (auto next : graph[cur_node]) { //현재 노드에 연결된 엣지들
			int next_cost = cost + next.second;
			int next_node = next.first;

			if (next.second == -1) continue;  //사용할 수 없는 엣지

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				q.push({ -next_cost, next_node });

				path[next_node].clear();
				path[next_node].push_back(cur_node);
			}
			else if (next_cost == dist[next_node]) {
				path[next_node].push_back(cur_node);
			}
		}
	}
}
void findpath(int start, int end) {
	queue<int> temp;
	bool visit[MAX] = { 0 };
	temp.push(end);
	while (!temp.empty()) {
		int next_node = temp.front();
		temp.pop();

		if (next_node == start) continue;

		for (int i = 0; i < path[next_node].size(); i++) {
			int prev_node = path[next_node][i];
			if (visit[prev_node]) continue;
			for (int j = 0; j < graph[prev_node].size(); j++) {
				if (graph[prev_node][j].first == next_node) {
					graph[prev_node][j].second = -1;
					break;
				}
			}
			temp.push(prev_node);
		}
		visit[next_node] = 1;
	}
}

int main() {
	fastio;
	int N, M, S, D, U, V, P; // N - 장소의 수, M-도로의 수, S- 시작점, D - 도착점 ,  UVP - 도로 정보 (U -> V 도로 길이 P)
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;

		// 초기화 
		for (int i = 0; i < N; i++) {
			dist[i] = 1e9;
			graph[i].clear();
		}

		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			graph[U].push_back({ V,P });
		}
		dijk(S);
		findpath(S, D);  // 최단 경로 지우기
		for (int i = 0; i < N; i++) {
			dist[i] = 1e9;
		}
		dijk(S);

		if (dist[D] == 1e9) cout << -1 << '\n';
		else cout << dist[D] << '\n';
	}
	return 0;
}

문제
때는 2020년, 백준이는 월드나라의 한 국민이다. 월드나라에는 N개의 지점이 있고 N개의 지점 사이에는 M개의 도로와 W개의 웜홀이 있다. 
(단 도로는 방향이 없으며 웜홀은 방향이 있다.) 웜홀은 시작 위치에서 도착 위치로 가는 하나의 경로인데,
특이하게도 도착을 하게 되면 시작을 하였을 때보다 시간이 뒤로 가게 된다. 웜홀 내에서는 시계가 거꾸로 간다고 생각하여도 좋다.

시간 여행을 매우 좋아하는 백준이는 한 가지 궁금증에 빠졌다. 
한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 위치로 돌아왔을 때, 출발을 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 궁금해졌다. 
여러분은 백준이를 도와 이런 일이 가능한지 불가능한지 구하는 프로그램을 작성하여라.

입력
첫 번째 줄에는 테스트케이스의 개수 TC(1 ≤ TC ≤ 5)가 주어진다. 
그리고 두 번째 줄부터 TC개의 테스트케이스가 차례로 주어지는데 
각 테스트케이스의 첫 번째 줄에는 지점의 수 N(1 ≤ N ≤ 500), 도로의 개수 M(1 ≤ M ≤ 2500), 웜홀의 개수 W(1 ≤ W ≤ 200)이 주어진다. 
그리고 두 번째 줄부터 M+1번째 줄에 도로의 정보가 주어지는데 각 도로의 정보는 S, E, T 세 정수로 주어진다. 
S와 E는 연결된 지점의 번호, T는 이 도로를 통해 이동하는데 걸리는 시간을 의미한다. 
그리고 M+2번째 줄부터 M+W+1번째 줄까지 웜홀의 정보가 S, E, T 세 정수로 주어지는데 S는 시작 지점, E는 도착 지점, T는 줄어드는 시간을 의미한다. 
T는 10,000보다 작거나 같은 자연수 또는 0이다.

두 지점을 연결하는 도로가 한 개보다 많을 수도 있다. 지점의 번호는 1부터 N까지 자연수로 중복 없이 매겨져 있다.

출력
TC개의 줄에 걸쳐서 만약에 시간이 줄어들면서 출발 위치로 돌아오는 것이 가능하면 YES, 불가능하면 NO를 출력한다.

예제 입력 1 
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
예제 출력 1 
NO
YES


-----------------------------------------------------------
가중치가 음수가 나오는 그래프이므로 벨만-포드 알고리즘을 사용한다.
특정 지점에서 출발하여 자기 자신으로 돌아올 수 있고, 그 때의 시간값이 0보다 작다(음수) 이므로
음수 사이클이 생기는지의 판단을 통해 정답을 구할 수 있다.

모든 지점에서의 벨만-포드를 계산하는것이 직관적인 생각이지만, 전체 그래프 내에서 싸이클이 생기는지만 판단하더라도 다른 정점을 구할 필요가 없다.
대신 오리지널 벨만-포드는 거리를 구하기 위해서 dist 값이 갱신되지 않은 경우에는 pass 했지만 
단절된 그래프에서도 싸이클 유무를 판단해야  하기 때문에 dist[j] != INF 구문을 삭제한다.

if (dist[next_node] > next_weight + dist[j]) {     // (dist[j] != INF && dist[next_node] > next_weight + dist[j])
			if (k == N - 1) flag = 1;
			dist[next_node] = next_weight + dist[j];
}

------------------------------------------------------
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
vector<pair<int, int>> graph[501];
int dist[501];
map<pair<int, int>, int> m;
int N, M, W;  // 지점, 도로, 웜홀
void bellman() {
	int flag = 0;
	dist[1] = 0;
	for (int k = 0; k < N; k++) { //(V - 1)번의 루프 
		for (int j = 1; j <= N; j++) {
			for (auto data : graph[j]) {
				int next_node = data.first;
				int next_weight = data.second;
				if (dist[next_node] > next_weight + dist[j]) {
					if (k == N - 1) flag = 1;
					dist[next_node] = next_weight + dist[j];
				}
			}
		}
	}
	if (flag) cout << "YES\n";
	else cout << "NO\n";
}
void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		graph[i].clear();
	}
}
int main() {
	fastio;
	int T;
	int a, b, c;
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		init();
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			graph[a].push_back({ b,-c });
		}
		bellman();
	}
	return 0;
}

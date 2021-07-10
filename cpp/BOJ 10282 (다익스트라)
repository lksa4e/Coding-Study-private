문제
최흉최악의 해커 yum3이 네트워크 시설의 한 컴퓨터를 해킹했다! 이제 서로에 의존하는 컴퓨터들은 점차 하나둘 전염되기 시작한다. 
어떤 컴퓨터 a가 다른 컴퓨터 b에 의존한다면, b가 감염되면 그로부터 일정 시간 뒤 a도 감염되고 만다. 이때 b가 a를 의존하지 않는다면,a가 감염되더라도 b는 안전하다.

최흉최악의 해커 yum3이 해킹한 컴퓨터 번호와 각 의존성이 주어질 때, 해킹당한 컴퓨터까지 포함하여 총 몇 대의 컴퓨터가 감염되며 그에 걸리는 시간이 얼마인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 개수는 최대 100개이다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

첫째 줄에 컴퓨터 개수 n, 의존성 개수 d, 해킹당한 컴퓨터의 번호 c가 주어진다(1 ≤ n ≤ 10,000, 1 ≤ d ≤ 100,000, 1 ≤ c ≤ n).
이어서 d개의 줄에 각 의존성을 나타내는 정수 a, b, s가 주어진다(1 ≤ a, b ≤ n, a ≠ b, 0 ≤ s ≤ 1,000). 이는 컴퓨터 a가 컴퓨터 b를 의존하며, 
컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염됨을 뜻한다.
각 테스트 케이스에서 같은 의존성 (a, b)가 두 번 이상 존재하지 않는다.

출력
각 테스트 케이스마다 한 줄에 걸쳐 총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간을 공백으로 구분지어 출력한다.

예제 입력 1 
2
3 2 2
2 1 5
3 2 5
3 3 1
2 1 2
3 1 8
3 2 4
예제 출력 1 
2 5
3 6



-----------------------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10001
#define INF 10000001
int dist[MAX];
vector<pair<int, int>> graph[MAX];   // 노드, 시간
void dijk(int start) {
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	dist[start] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (cost + next_cost < dist[next]) {
				dist[next] = cost + next_cost;
				q.push({ -dist[next], next });
			}
		}
	}
}
int cnt;
int main() {
	int T, n, d, c, a, b, s; // T - 테케, n - 컴퓨터, d - 의존성, c - 해킹당한, a,b - 의존관계, s - time
	cin >> T;
	while (T--) {
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			graph[i].clear();
		}
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}
		int com_cnt = 0;
		int time_cnt = 0;
		dijk(c);
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				com_cnt++;
				time_cnt = max(time_cnt, dist[i]);
			}
		}
		cout << com_cnt << " " << time_cnt << endl;
	}
	return 0;
}

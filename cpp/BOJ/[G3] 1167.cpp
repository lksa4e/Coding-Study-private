문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.

먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

예제 입력 1 
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1

예제 출력 1 
11


===========================================================================================================================
최장거리 그딴거 없이 최단거리 해도 알아서 최장거리 구할수 있음

#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dist[100001] = { 0 };
vector <vector<pair<int, int>>> v; 
int maxx = -1;
void dijk(int src) {   //다익스트라
	priority_queue < pair<int, int> >pq;
	dist[src] = 0;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] > cost) continue;

		for (int i = 0; i < v[here].size(); i++) {
			int there = v[here][i].first;
			int nextdist = cost + v[here][i].second;

			if (dist[there] > nextdist) {
				maxx = max(maxx, nextdist);   //최장거리값 저장
				dist[there] = nextdist;
				pq.push({ -nextdist,there });
			}
		}
	}
}

int main() {
	fastio;
	int N;
	int a, b, c;
	v.resize(100001);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			v[a].push_back(make_pair(b, c));
		}
	}
	fill(dist, dist + N + 1, 1e9);
	dijk(1);
	int cnt = 0;
	int maxidx = -1;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == maxx) {
			cnt++;
			maxidx = i;
		}
	}
	if (cnt == 2) {  //최대값 2개 나오면 그거 2개가 트리의 지름임
		cout << maxx * 2;
	}else {  //최대값 1개면
		fill(dist, dist + N + 1, 1e9);
		maxx = -1;
		dijk(maxidx);   //그 최대값 기준으로 다익스트라 한번더
		cout << maxx;
	}
}

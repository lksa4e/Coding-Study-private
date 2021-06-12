문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.

예제 입력 1 
6 5
1 2
2 5
5 1
3 4
4 6
예제 출력 1 
2
예제 입력 2 
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
예제 출력 2 
1

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색
깊이 우선 탐색

----------------------------------------------------------------------------
1. Union Find를 통해 집합을 묶어두고 전체 집합의 개수를 세는 방법
2. 그래프 탐색을 통해 집합의 개수를 세는 방법

1 번의 경우 그래프 연결관계를 위한 2차원 배열을 생성하지 않으므로 메모리 효율이 좋다. 
----------------------------------------------------------------------

#include <iostream>
#include <bitset>
#include <string>
#include <map>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[1001] = { 0 };
int N;
int find(int a) {
	a = parent[a];
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}
void uniom(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}
int main() {
	fastio;
	map<int, int> m;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int M, a, b, cnt = 0;
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		uniom(a, b);
	}
	for (int i = 1; i <= N; i++) {
		m[find(i)] = 1;
	}
	for (auto iter : m) {
		cnt++;
	}
	cout << cnt;
	return 0;
}

--------------------------------------------------------------

#include <iostream>
#include <bitset>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool graph[1001][1001] = { 0 };
bool visit[1001] = { 0 };
int N;
void bfs(int idx) {
	queue<int> q;
	visit[idx] = 1;
	q.push(idx);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	fastio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int M, a, b, cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

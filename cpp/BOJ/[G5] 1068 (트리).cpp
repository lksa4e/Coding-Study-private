문제
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 
노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

예를 들어, 다음과 같은 트리가 있다고 하자.



현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 다음과 같이 변한다. 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.



이제 리프 노드의 개수는 1개이다.

입력
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 
둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

예제 입력 1 
5
-1 0 0 1 1
2
예제 출력 1 
2
예제 입력 2 
5
-1 0 0 1 1
1
예제 출력 2 
1
예제 입력 3 
5
-1 0 0 1 1
0
예제 출력 3 
0
예제 입력 4 
9
-1 0 0 2 2 4 4 6 6
4
예제 출력 4 
2

알고리즘 분류
그래프 이론
그래프 탐색
트리
깊이 우선 탐색

--------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

#pragma warning(disable:4996)
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);

using namespace std;
vector<int> child[51];
int N, del, cnt = 0;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (child[cur].size() == 0) cnt++;
		else {
			int flag = 0;
			for (auto data : child[cur]) {
				if (data != del) {
					flag = 1;
					q.push(data);
				}
			}
			if (flag == 0) cnt++;
		}
	}
}
int main() {
	fastio;
	int N, a, root_idx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == -1) root_idx = i;
		else {
			child[a].push_back(i);
		}
	}
	cin >> del;
	if (del == root_idx) {
		cout << 0;
		return 0;
	}
	bfs(root_idx);
	cout << cnt;
	return 0;
}


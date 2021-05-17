문제
그래프 G(V, E)에서 정점의 부분 집합 S에 속한 모든 정점쌍이 서로 인접하지 않으면 (정점쌍을 잇는 에지가 없으면) S를 독립 집합(independent set)이라고 한다.
독립 집합의 크기는 정점에 가중치가 주어져 있지 않을 경우는 독립 집합에 속한 정점의 수를 말하고, 정점에 가중치가 주어져 있으면 독립 집합에 속한 정점의 가중치의 합으로 정의한다. 
독립 집합이 공집합일 때 그 크기는 0이라고 하자. 크기가 최대인 독립 집합을 최대 독립 집합이라고 한다.

문제는 일반적인 그래프가 아니라 트리(연결되어 있고 사이클이 없는 그래프)와 각 정점의 가중치가 양의 정수로 주어져 있을 때, 최대 독립 집합을 구하는 것이다.

입력
첫째 줄에 트리의 정점의 수 n이 주어진다. n은 10,000이하인 양의 정수이다. 1부터 n사이의 정수가 트리의 정점이라고 가정한다. 
둘째 줄에는 n개의 정수 w1, w2, ..., wn이 주어지는데, wi는 정점 i의 가중치이다(1 ≤ i ≤ n). 셋째 줄부터 마지막 줄까지는 에지 리스트가 주어지는데, 
한 줄에 하나의 에지를 나타낸다. 에지는 정점의 쌍으로 주어진다. 입력되는 정수들 사이에는 콤마가 없고 대신 빈칸이 하나 혹은 그 이상 있다. 
가중치들의 값은 10,000을 넘지 않는 자연수이다.

출력
첫째 줄에 최대 독립집합의 크기를 출력한다. 둘째 줄에는 최대 독립집합에 속하는 정점을 오름차순으로 출력한다. 최대 독립 집합이 하나 이상일 경우에는 하나만 출력하면 된다.

예제 입력 1 
7
10 30 40 10 20 20 70
1 2
2 3
4 3
4 5
6 2
6 7
예제 출력 1 
140
1 3 5 7


------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10001
using namespace std;

vector<int> tree[MAX];   // 마을의 연결정보
vector<int> answer;
int weight[MAX];         // 가중치 정보
int dp[MAX][2];          // [][1] - > 독립집합 포함 , [][0] -> 독립집합 미포함
bool visit[MAX];
void treedp(int start) {
	visit[start] = 1;
	dp[start][0] = 0;
	dp[start][1] = weight[start];
	for (auto next : tree[start]) {
		if (!visit[next]) {
			treedp(next);
			dp[start][0] += max(dp[next][0], dp[next][1]);
			dp[start][1] += dp[next][0];
		}
	}
}
void search(int start, int flag) {  // 이전 Case에서 포함인지(flag 1), 미포함(flag 0)인지에 따라 나누어서 탐색하는 함수
	visit[start] = 1;
	if (flag == 1) {                  // 지금 노드가 포함되어있다면
		answer.push_back(start);
		for (auto next : tree[start]) {
			if (!visit[next]) {
				search(next, 0);         // 연결된 노드들은 포함하면 안된다.
			}
		}
	}
	else {                                 // 지금 노드가 미포함인 경우
		for (auto next : tree[start]) {
			if (!visit[next]) {
				if (dp[next][0] < dp[next][1]) search(next, 1);  // 만약 연결된 노드가 포함인 경우가 Max이면 포함해서 탐색
				else  search(next, 2);  //만약 연결된 노드가 미포함인 경우가 Max면 미포함해서 탐색
			}
		}
	}
}
int main() {
	int n, p, u, v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		weight[i] = p;
	}
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	treedp(1);
	memset(visit, 0, sizeof(visit));                 // treedp 돌면서 한번 사용했기 때문에 초기화
	cout << max(dp[1][0], dp[1][1])<<'\n';
	if (dp[1][0] < dp[1][1]) search(1, 1);
	else search(1, 0);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}

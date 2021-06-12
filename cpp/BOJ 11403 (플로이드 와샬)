문제
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다.
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.

출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다. 정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.

예제 입력 1 
3
0 1 0
0 0 1
1 0 0
예제 출력 1 
1 1 1
1 1 1
1 1 1
예제 입력 2 
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0
예제 출력 2 
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0

알고리즘 분류
그래프 이론
플로이드–와샬

-----------------------------------------------------------------------
모든 정점의 연결관계 -> 플로이드 와샬
최단 거리가 아닌 단순 연결관계만 체크해주므로 dist 계산 필요없이 1로만 갱신

----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool graph[101][101];
int N;
void floid() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][k] == 1 && graph[k][j] == 1) graph[i][j] = 1;
			}
		}
	}
}
int main() {
	fastio;
	vector<int> v;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	floid();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

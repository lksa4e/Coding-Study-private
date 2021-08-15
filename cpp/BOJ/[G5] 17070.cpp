문제
유현이가 새 집으로 이사했다. 새 집의 크기는 N×N의 격자판으로 나타낼 수 있고, 1×1크기의 정사각형 칸으로 나누어져 있다.
각각의 칸은 (r, c)로 나타낼 수 있다. 여기서 r은 행의 번호, c는 열의 번호이고, 행과 열의 번호는 1부터 시작한다. 각각의 칸은 빈 칸이거나 벽이다.

오늘은 집 수리를 위해서 파이프 하나를 옮기려고 한다. 파이프는 아래와 같은 형태이고, 2개의 연속된 칸을 차지하는 크기이다.



파이프는 회전시킬 수 있으며, 아래와 같이 3가지 방향이 가능하다.



파이프는 매우 무겁기 때문에, 유현이는 파이프를 밀어서 이동시키려고 한다. 벽에는 새로운 벽지를 발랐기 때문에, 파이프가 벽을 긁으면 안 된다. 
즉, 파이프는 항상 빈 칸만 차지해야 한다.

파이프를 밀 수 있는 방향은 총 3가지가 있으며, →, ↘, ↓ 방향이다. 파이프는 밀면서 회전시킬 수 있다. 
회전은 45도만 회전시킬 수 있으며, 미는 방향은 오른쪽, 아래, 또는 오른쪽 아래 대각선 방향이어야 한다.

파이프가 가로로 놓여진 경우에 가능한 이동 방법은 총 2가지, 세로로 놓여진 경우에는 2가지, 대각선 방향으로 놓여진 경우에는 3가지가 있다.

아래 그림은 파이프가 놓여진 방향에 따라서 이동할 수 있는 방법을 모두 나타낸 것이고, 꼭 빈 칸이어야 하는 곳은 색으로 표시되어져 있다.


가장 처음에 파이프는 (1, 1)와 (1, 2)를 차지하고 있고, 방향은 가로이다. 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.

입력
첫째 줄에 집의 크기 N(3 ≤ N ≤ 16)이 주어진다. 둘째 줄부터 N개의 줄에는 집의 상태가 주어진다. 빈 칸은 0, 벽은 1로 주어진다. (1, 1)과 (1, 2)는 항상 빈 칸이다.

출력
첫째 줄에 파이프의 한쪽 끝을 (N, N)으로 이동시키는 방법의 수를 출력한다. 이동시킬 수 없는 경우에는 0을 출력한다. 방법의 수는 항상 1,000,000보다 작거나 같다.

예제 입력 1 
3
0 0 0
0 0 0
0 0 0
예제 출력 1 
1

------------------------------------------------------------------
BFS를 통해 모든 경우의 수를 발견한다.
BFS를 통해 탐색을 할 때 이전 상태를 저장하여
가로 -> 2가지
세로 -> 2가지
대각선 -> 3가지의 경우의 수를 모두 탐색한다.

------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin,(x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;
int graph[16][16];
void solve() {
	int count = 0;
	queue<tuple<int, int, int>> q;   // 끝좌표, 이전상태 (0 - 가로 1 - 세로 2 - 대각선)
	q.push({ 0,1,0 });
	while (!q.empty()) {
		auto [x,y, sign] = q.front(); q.pop();
		if (x == N - 1 && y == N - 1) {
			count++;
			continue;
		}
		if (sign == 0) {   //가로 
			if (y + 1 < N) {
				if (graph[x][y + 1] == 0) q.push({ x,y + 1,0 });
			}
			if (y + 1 < N && x + 1 < N) {
				if (graph[x + 1][y] == 0 && graph[x + 1][y + 1] == 0 && graph[x][y + 1] == 0) {
					q.push({ x + 1,y + 1,2 });
				}
			}
		}
		else if (sign == 1) { //세로
			if (x + 1 < N) {
				if (graph[x+1][y] == 0) q.push({ x+1,y,1 });
			}
			if (y + 1 < N && x + 1 < N) {
				if (graph[x + 1][y] == 0 && graph[x + 1][y + 1] == 0 && graph[x][y + 1] == 0) {
					q.push({ x + 1,y + 1, 2 });
				}
			}
		}
		else { // 대각선
			if (y + 1 < N) {
				if (graph[x][y + 1] == 0) q.push({ x,y + 1,0 });
			}
			if (x + 1 < N) {
				if (graph[x + 1][y] == 0) q.push({ x + 1,y,1 });
			}
			if (y + 1 < N && x + 1 < N) {
				if (graph[x + 1][y] == 0 && graph[x + 1][y + 1] == 0 && graph[x][y + 1] == 0) {
					q.push({ x + 1,y + 1, 2 });
				}
			}
		}
	}
	cout << count;
}

int main() {
	fastio;
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	solve();
	return 0;
}

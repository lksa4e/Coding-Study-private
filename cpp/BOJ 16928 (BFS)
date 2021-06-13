문제
뱀과 사다리 게임을 즐겨 하는 큐브러버는 어느 날 궁금한 점이 생겼다.

주사위를 조작해 내가 원하는 수가 나오게 만들 수 있다면, 최소 몇 번만에 도착점에 도착할 수 있을까?

게임은 정육면체 주사위를 사용하며, 주사위의 각 면에는 1부터 6까지 수가 하나씩 적혀있다. 
게임은 크기가 10×10이고, 총 100개의 칸으로 나누어져 있는 보드판에서 진행된다. 보드판에는 1부터 100까지 수가 하나씩 순서대로 적혀져 있다.

플레이어는 주사위를 굴려 나온 수만큼 이동해야 한다. 예를 들어, 플레이어가 i번 칸에 있고, 주사위를 굴려 나온 수가 4라면, i+4번 칸으로 이동해야 한다. 
만약 주사위를 굴린 결과가 100번 칸을 넘어간다면 이동할 수 없다. 도착한 칸이 사다리면, 사다리를 타고 위로 올라간다. 
뱀이 있는 칸에 도착하면, 뱀을 따라서 내려가게 된다. 즉, 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 
뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아진다.

게임의 목표는 1번 칸에서 시작해서 100번 칸에 도착하는 것이다.

게임판의 상태가 주어졌을 때, 100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값을 구해보자.

입력
첫째 줄에 게임판에 있는 사다리의 수 N(1 ≤ N ≤ 15)과 뱀의 수 M(1 ≤ M ≤ 15)이 주어진다.

둘째 줄부터 N개의 줄에는 사다리의 정보를 의미하는 x, y (x < y)가 주어진다. x번 칸에 도착하면, y번 칸으로 이동한다는 의미이다.

다음 M개의 줄에는 뱀의 정보를 의미하는 u, v (u > v)가 주어진다. u번 칸에 도착하면, v번 칸으로 이동한다는 의미이다.

1번 칸과 100번 칸은 뱀과 사다리의 시작 또는 끝이 아니다. 모든 칸은 최대 하나의 사다리 또는 뱀을 가지고 있으며, 
동시에 두 가지를 모두 가지고 있는 경우는 없다. 항상 100번 칸에 도착할 수 있는 입력만 주어진다.

출력
100번 칸에 도착하기 위해 주사위를 최소 몇 번 굴려야 하는지 출력한다.

예제 입력 1 
3 7
32 62
42 68
12 98
95 13
97 25
93 37
79 27
75 19
49 47
67 17
예제 출력 1 
3
5를 굴려 6으로 이동한다.
6을 굴려 12로 이동한다. 이 곳은 98로 이동하는 사다리가 있기 때문에, 98로 이동한다.
2를 굴려 100으로 이동한다.
예제 입력 2 
4 9
8 52
6 80
26 42
2 72
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
예제 출력 2 
5
5를 굴려 6으로 이동하고, 사다리를 이용해 80으로 이동한다. 
6을 굴려 86으로
6을 또 굴려 92로
6을 또 굴려 98로 이동하고
2를 굴려 100으로 이동한다.

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색


----------------------------------------------------------------------
주사위가 양수라고 하더라도 뱀에 의해서 다시 뒤로 돌아가는 경우의 수가 발생할 수 있다.
따라서 단순하게 dp로 풀기보단 좌표를 이동해가는 bfs로 푼다.

-----------------------------------------------------------------------
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, int> ladder;
map<int, int> snake;
bool visit[101];
int N, M;
int result = 0;
void bfs() {
	queue<pair<int,int>> q;  // pos, cnt
	q.push({ 1, 0 });
	while (!q.empty()) {
		int cur_pos = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();
		if (cur_pos == 100) {
			result = cur_cnt;
			break;
		}
		for (int i = 1; i <= 6; i++) {
			int next_pos = cur_pos + i;
			if (visit[next_pos] == 0) {
				visit[next_pos] = 1;
				if (ladder[next_pos] > 1) {
					if (visit[ladder[next_pos]] == 0) {
						visit[ladder[next_pos]] = 1;
						q.push({ ladder[next_pos], cur_cnt + 1 });
					}
				}
				else if (snake[next_pos] > 1) {
					if (visit[snake[next_pos]] == 0) {
						visit[snake[next_pos]] = 1;
						q.push({ snake[next_pos], cur_cnt + 1 });
					}
				}
				else {
					q.push({ next_pos, cur_cnt + 1 });
				}
			}
		}
	}
}

int main() {
	fastio;
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		ladder[a] = b;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		snake[a] = b;
	}
	bfs();
	cout << result;
	return 0;
}

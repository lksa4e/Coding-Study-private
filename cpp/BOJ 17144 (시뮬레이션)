문제
미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 1×1 크기의 칸으로 나눴다. 
구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 시스템을 개발했다. (r, c)는 r행 c열을 의미한다.



공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 양은 Ar,c이다.

1초 동안 아래 적힌 일이 순서대로 일어난다.

미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다.
(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.
위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.
다음은 확산의 예시이다.



방의 정보가 주어졌을 때, T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.

입력
첫째 줄에 R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 가 주어진다.

둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 1,000)가 주어진다. 공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 미세먼지의 양이다.
-1은 2번 위아래로 붙어져 있고, 가장 윗 행, 아랫 행과 두 칸이상 떨어져 있다.

출력
첫째 줄에 T초가 지난 후 구사과 방에 남아있는 미세먼지의 양을 출력한다.

예제 입력 1 
7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
예제 출력 1 
188


---------------------------------------------------------------------------
먼지를 먼저 확산시키고,
다음에 먼지를 한바퀴 순회시킨다.
이것을 T번 반복하고 먼지의 총합을 구한다.

깔끔한 풀이를 위해 (하드코딩 없이 시계, 반시계 구현하기)
https://mygumi.tistory.com/351
사이트를 공부하고 다시풀어보자

------------------------------------------------------------------------
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

int R, C, T;  // 행, 렬, 시간
int graph[51][51];
int temp[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
pii cleaner_1;
pii cleaner_2;

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp[i][j] = 0;
		}
	}
}

void Print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (graph[i][j] == -1) cout << "- ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << "######################################################" << endl;
}

void update() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			graph[i][j] += temp[i][j];
		}
	}
}

void dust() {
	init();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) {
				int dust_size = graph[i][j] / 5;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
						if (graph[nx][ny] != -1) {
							temp[nx][ny] += dust_size;
							cnt++;
						}
					}
				}
				temp[i][j] -= dust_size * cnt;
			}
		}
	}
	update();
}

void clean() {
	//청소기 1
	for (int i = cleaner_1.fst - 1; i > 0; i--) {      //아래로 땡겨오기
		graph[i][0] = graph[i - 1][0];
	}
	for (int i = 0; i < C - 1; i++) {    // 왼쪽으로 땡겨오기
		graph[0][i] = graph[0][i + 1];
	}
	for (int i = 0; i < cleaner_1.fst; i++) {     // 위로 땡겨오기
		graph[i][C - 1] = graph[i+1][C - 1];
	}
	for (int i = C - 1; i > 1; i--) {              // 오른쪽으로 땡겨오기
		graph[cleaner_1.fst][i] = graph[cleaner_1.fst][i - 1];
	}
	graph[cleaner_1.fst][1] = 0;
	//청소기 2
	for (int i = cleaner_2.fst + 1; i < R - 1; i++) {     // 위로 땡겨오기
		graph[i][0] = graph[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {    // 왼쪽으로 땡겨오기
		graph[R - 1][i] = graph[R - 1][i + 1];
	}
	for (int i = R - 1; i >= cleaner_2.fst; i--) {      //아래로 땡겨오기
		graph[i][C - 1] = graph[i - 1][C - 1];
	}
	for (int i = C - 1; i > 1; i--) {              // 오른쪽으로 땡겨오기
		graph[cleaner_2.fst][i] = graph[cleaner_2.fst][i - 1];
	}
	graph[cleaner_2.fst][1] = 0;
}

void solve() {
	for (int i = 0; i < T; i++) {
		dust();
		clean();
	}
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) result += graph[i][j];
		}
	}
	cout << result;
}

int main() {
	fastio;
	int a;
	int flag = 0;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) {
				if (flag == 0) {
					cleaner_1 = { i,j };
					flag = 1;
				}
				else cleaner_2 = { i,j };
			}
		}
	}
	solve();
	return 0;
}

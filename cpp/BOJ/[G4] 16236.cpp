문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 
따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 
이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.

둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

0: 빈 칸
1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.

예제 입력 1 
3
0 0 0
0 0 0
0 9 0
예제 출력 1 
0
예제 입력 2 
3
0 0 1
0 0 0
0 9 0
예제 출력 2 
3
예제 입력 3 
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
예제 출력 3 
14
예제 입력 4 
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6
예제 출력 4 
60
예제 입력 5 
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1
예제 출력 5 
48
예제 입력 6 
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
예제 출력 6 
39


알고리즘 분류
구현
그래프 이론
그래프 탐색
너비 우선 탐색
시뮬레이션


------------------------------------------------------


------------------------------------------------------
#include <iostream>
#include <bitset>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int graph[21][21] = { 0 };
bool visit[21][21] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;
int shark_x, shark_y, shark_size = 2;  // 현재 상어의 좌표, 크기
int fish_num;                 // 전체 물고기 
int result = 0, end_flag = 0; // 최종 결과값
int shark_eat = 0;
void bfs() {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ shark_x,shark_y });
	int cnt = 0, find = 0;
	while (!q.empty()) {
		if (find == 1) {
			break;
		}
		cnt++;
		int size = q.size();
		while (size--) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (visit[nx][ny] == 0) {
						if (graph[nx][ny] == 0 || graph[nx][ny] == shark_size) {    // 상어 사이즈와 같거나 빈칸이면 못먹고 진행
							visit[nx][ny] = 1;
							q.push({ nx,ny });
						}
						else if(graph[nx][ny] < shark_size){    //먹을수 있는 물고기 찾으면
							find = 1;
							v.push_back({ nx,ny });   //먹을수있는 리스트에 저장
						}
					}
				}
			}
		}
	}
	if (find == 0) {
		end_flag = 1;
		return;
	}
	sort(v.begin(), v.end());  //제일 왼쪽위에 있는 물고기 찾기
	result += cnt;
	shark_x = v[0].first;
	shark_y = v[0].second;
	shark_eat++;
	if (shark_eat == shark_size) {  // 상어 사이즈만큼 물고기 먹으면 상어 사이즈업
		shark_eat = 0;
		shark_size++;
	}
	graph[shark_x][shark_y] = 0;
	fish_num--;
}
void init() {  // visit 배열 초기화
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++){
			visit[i][j] = 0;
		}
	}
}
int main() {
	fastio;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			graph[i][j] = a;
			if (a != 0 && a != 9) fish_num++;
			if (a == 9) {
				shark_x = i;
				shark_y = j;
				graph[i][j] = 0;
			}
		}
	}
	while (1) {
		init();
		bfs();
		if (end_flag == 1 || fish_num == 0) {
			cout << result;
			break;
		}
	}
	return 0;
}

문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다.
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

예제 입력 1 
2 4
CAAB
ADCB
예제 출력 1 
3



알고리즘 분류
그래프 이론
그래프 탐색
깊이 우선 탐색
백트래킹

----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int R, C;
char arr[21][21] = { 0 };
map<char,int> visit;
int result = -1;
void dfs(int x, int y, int cnt) {
	if (cnt > result) {   // 칸 수 비교
		result = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		char next_word = arr[nx][ny];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {  //범위 초과 안하는지
			if (visit[next_word] == 0) { //중복 알파벳 아니면
				visit[next_word] = 1;   // 해당 알파벳 처리
				dfs(nx, ny, cnt + 1);
				visit[next_word] = 0;   // 해당 알파벳 처리 취소
			}
		}
	}
}
int main() {
	string s;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
		}
	}
	visit[arr[0][0]] = 1;
	dfs(0, 0, 1);
	cout << result;
	return 0;
}

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 
가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.

예제 입력 1 
5 17
예제 출력 1 
4
2

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색

----------------------------------------------
단순하게 BFS를 사용하면 해결할 수 있다.
하지만 일반적인 BFS에서 큐에 넣기전에 bool 형태의 visit을 사용하여 방문체크를 했던것과 달리
X+1, X-1, X*2 의 3가지 케이스에서 파생되는 중복되는 숫자가 발생할 수 있기 때문에 
visit 배열을 int로 선언하고 count 값을 넣어준다. 따라서 같은 count에 해당 지점을 방문할 수 있다면
같은 좌표도 2번 이상 방문이 가능하다.

-----------------------------------------------
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

int N, M, result_time = 0, result_n = 0;
int visit[100001];
void init() {
	for (int i = 0; i <= 100000; i++) {
		visit[i] = INF;
	}
}
void solve() {
	queue<pii> q;
	q.push({ N, 0 });
	int find = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			auto [cur, cnt] = q.front(); q.pop();
			if (cur == M) {
				result_n++;
				result_time = cnt;
				find = 1;
			}
			if (cur + 1 <= 100000 && visit[cur + 1] >= cnt + 1) {
				visit[cur + 1] = cnt + 1;
				q.push({ cur + 1, cnt + 1 });
			}
			if (cur - 1 >= 0 && visit[cur - 1] >= cnt + 1) {
				visit[cur - 1] = cnt + 1;
				q.push({ cur - 1, cnt + 1 });
			}
			if (cur * 2 <= 100000 && visit[cur * 2] >= cnt + 1) {
				visit[cur * 2] = cnt + 1;
				q.push({ cur * 2, cnt + 1 });
			}
		}
		if (find) break;
	}
}
int main() {
	fastio;
	cin >> N>>M;
	init();
	solve();
	cout << result_time<<'\n'<<result_n;
	return 0;
}

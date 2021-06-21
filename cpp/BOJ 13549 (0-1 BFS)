문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1 
5 17
예제 출력 1 
2
힌트
수빈이가 5-10-9-18-17 순으로 가면 2초만에 동생을 찾을 수 있다.

비슷한 문제
1697번. 숨바꼭질
12851번. 숨바꼭질 2
13913번. 숨바꼭질 4

알고리즘 분류
그래프 이론
그래프 탐색
너비 우선 탐색
다익스트라
0-1 너비 우선 탐색

----------------------------------------------------
원래 이 문제는 단순한 BFS를 요구하는 문제가 아닙니다. 왜냐하면, BFS를 하기 위해서는 모든 간선의 가중치가 동일해야 한다는 전제 조건이 필요하기 때문입니다. 
이 문제는 가중치가 0인 간선이 있기 때문에 일반적으로는 단순한 BFS를 쓸 수 없습니다.

이 문제를 보다 일반화된 경우 (가중치가 0인 간선이 있는 경우)에 대해 해결하려면, 즉, 이 문제의 의도대로 풀려면 다음과 같은 방법들을 사용할 수 있습니다.

다익스트라 알고리즘
0-1 BFS: 가중치가 0인 간선에 연결된 정점은 큐의 맨 뒤가 아닌 맨 앞에 넣는 방법
* 2를 별도의 간선으로 생각하지 않고, +1이나 -1에 의한 좌표를 큐에 넣을 때 그 좌표의 2의 거듭제곱 배인 좌표들을 전부 큐에 넣는 방법
-------------------------------------------------------

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
bool visit[200001];
int result = INF;
void solve() {
	priority_queue<pii, vector<pii> ,greater<pii>> pq; // 나, 부모
	pq.push({ 0,N });
	visit[N] = 1;
	while (!pq.empty()) {
		auto [cnt, cur] = pq.top(); pq.pop();
		if (cur == M) {
			result = cnt;
			break;
		}
		if (cur * 2 <= 100000) {
			if (!visit[cur * 2]) {
				visit[cur * 2] = 1;
				pq.push({ cnt, cur * 2 });
			}
		}
		if (cur - 1 >= 0) {
			if (!visit[cur - 1]) {
				visit[cur - 1] = 1;
				pq.push({ cnt + 1, cur - 1});
			}
		}
		if (cur + 1 <= 100000) {
			if (!visit[cur + 1]) {
				visit[cur + 1] = 1;
				pq.push({ cnt + 1, cur + 1 });
			}
		}
	}

}

int main() {
	fastio;
	int a, b;
	cin >> N >> M;
	solve();
	cout << result;
	return 0;
}


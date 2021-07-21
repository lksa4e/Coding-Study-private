문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다. 정답이 여러 가지인 경우에는 아무거나 출력한다.

예제 입력 1 
2
예제 출력 1 
1
2 1
예제 입력 2 
10
예제 출력 2 
3
10 9 3 1
출처
문제를 만든 사람: baekjoon
알고리즘 분류
다이나믹 프로그래밍
그래프 이론
그래프 탐색
너비 우선 탐색


---------------------------------------------------
visit 체크를 해줘가면서 bfs를 돌리면 된다.

-----------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <cctype>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x) (x).begin(),(x).end()
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
#define fst first  
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N;
bool visit[1000001];
using namespace std;

string bfs() {
	queue<pair<int,string>> q;
	q.push({ N, to_string(N)+" " });
	while (!q.empty()) {
		auto [num, str] = q.front(); q.pop();
		if (visit[num]) continue;
		if (num == 1) return str;
		visit[num] = 1;
		if (num % 3 == 0 && !visit[num/3]) {
			q.push({ num / 3, str + to_string(num / 3) + " " });
		}
		if (num % 2 == 0 && !visit[num / 2]) {
			q.push({ num / 2, str + to_string(num / 2) + " " });
		}
		if (num - 1 > 0 && !visit[num - 1]) {
			q.push({ num - 1, str + to_string(num - 1) + " " });
		}
	}
}
int main() {
	fastio;
	cin >> N;
	int cnt = 0;
	string answer = bfs();
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == ' ') cnt++;
	}
	cout << cnt - 1<<'\n';
	cout << answer;
	return 0;
}

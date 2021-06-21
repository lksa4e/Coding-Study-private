문제
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.

1	2	3	4
2	3	4	5
3	4	5	6
4	5	6	7
여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.

표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

입력
첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 
둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 
다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 
표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

출력
총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

예제 입력 1 
4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4
예제 출력 1 
27
6
64
예제 입력 2 
2 4
1 2
3 4
1 1 1 1
1 2 1 2
2 1 2 1
2 2 2 2
예제 출력 2 
1
2
3
4


알고리즘 분류
다이나믹 프로그래밍
누적 합


--------------------------------------------------------------------------------------------------
1,1에서 출발하여 x, y 까지의 면적은 (A)

ㅁㅁㅁㅁㅁ      ㅁㅁㅁ     ㅁㅁ     ㅁㅁ 
ㅁㅁㅁㅁㅁ      ㅁㅁㅁ     ㅁㅁ     ㅁㅁ
ㅁㅁAㅁㅁ   -->        +   ㅁㅁ  -      ㅁ 
ㅁㅁㅁㅁㅁ
ㅁㅁㅁㅁㅁ

따라서 점화식은 (dp[i][j] ==> i,j 까지의 면적)
dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + graph[i][j]; 가 된다.

x1, y1 -> x2,y2 까지의 면적은 (A -> B)
전체 면적에서 
ㅁㅁㅁㅁㅁ                   ㅁㅁ    ㅁㅁㅁㅁㅁ     ㅁㅁ
ㅁㅁㅁㅁㅁ                   ㅁㅁ    ㅁㅁㅁㅁㅁ     ㅁㅁ
ㅁㅁ Aㅁㅁ   -->   B 면적 -( ㅁㅁ  +             -       ) 
ㅁㅁㅁㅁㅁ                   ㅁㅁ
ㅁㅁㅁㅁB                    ㅁㅁ
가 된다.

따라서 정답은
dp[x2][y2]- dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1-1][y1-1] 가 된다.

-----------------------------------------------------
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
int graph[1025][1025];
int dp[1025][1025];
void solve() {
	dp[1][1] = graph[1][1];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = dp[i-1][1] + graph[i][1];
		dp[1][i] = dp[1][i-1] + graph[1][i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + graph[i][j];
		}
	}
}
int main() {
	fastio;
	int x1,y1,x2,y2;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	solve();
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2]- dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1-1][y1-1] << '\n';
	}
	return 0;
}

문제
N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다. 
바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다. 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.



별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며, 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 
숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오. 점수는 원룡이가 위치한 곳의 수의 합이다.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 숫자가 세 개씩 주어진다. 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

출력
첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.

예제 입력 1 
3
1 2 3
4 5 6
4 9 0
예제 출력 1 
18 6
출처
빠진 조건을 찾은 사람: dreamian
잘못된 데이터를 찾은 사람: tncks0121
알고리즘 분류
다이나믹 프로그래밍
슬라이딩 윈도우

------------------------------------------
DP 점화식에서 바로 이전의 값밖에 사용하지 않는다.
따라서 N까지의 전체 크기의 dp 배열을 잡는것이 아닌 1줄짜리의 dp 배열만 사용하여 메모리 사용량을 줄인다.

------------------------------------------

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin, (x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first
#define snd second

using namespace std;
typedef pair<int, int> pii;

int min_dp[3];
int max_dp[3];
int N;
int main() {
	fastio;
	int a,b,c;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		int temp1 = max_dp[0], temp2 = max_dp[1], temp3 = max_dp[2];
		max_dp[0] = max(temp1, temp2) + a;
		max_dp[1] = max(max(temp1,temp2),temp3) + b;
		max_dp[2] = max(temp2,temp3) + c;
		temp1 = min_dp[0], temp2 = min_dp[1], temp3 = min_dp[2];
		min_dp[0] = min(temp1, temp2) + a;
		min_dp[1] = min(min(temp1, temp2), temp3) + b;
		min_dp[2] = min(temp2, temp3) + c;
	}
	cout << max(max(max_dp[0],max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0],min_dp[1]),min_dp[2]);
	return 0;
}

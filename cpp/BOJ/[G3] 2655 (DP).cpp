문제
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어 간다. 
아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프로그램을 작성하시오.

벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
벽돌들의 높이는 같을 수도 있다.
탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.
입력
첫째 줄에는 입력될 벽돌의 수가 주어진다. 입력으로 주어지는 벽돌의 수는 최대 100개이다. 둘째 줄부터는 각 줄에 한 개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 벽돌의 높이 그리고 무게가 차례대로 양의 정수로 주어진다. 각 벽돌은 입력되는 순서대로 1부터 연속적인 번호를 가진다. 벽돌의 넓이, 높이 무게는 10,000보다 작거나 같은 자연수이다.

출력
탑을 쌓을 때 사용된 벽돌의 수를 빈칸없이 출력하고, 두 번째 줄부터는 탑의 가장 위 벽돌부터 가장 아래 벽돌까지 차례로 한 줄에 하나씩 벽돌 번호를 빈칸없이 출력한다.

예제 입력 1 
5
25 3 4
4 4 6
9 2 3
16 2 5
1 5 2
예제 출력 1 
3
5
3
1

---------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101];
int arr[101];
int counts[101];
struct block {
	int xy;
	int h;
	int w;
	int idx;
};
vector<block> v; // 너비, 높이, 무게, 번호
bool cmp(const block & a, const block & b) {
	if (a.w == b.w) return a.xy > b.xy;
	else return a.w > b.w;
}
int main() {
	int n,xy,h,w;
	int max_hei = 0;
	vector<int> result;
	cin >> n;
	v.push_back({ 10001,0,10001,0 });  // 아무것도 없는 상태에서는 모든 block을 쌓을 수 있어야 하므로 더미 블록을 만들어준다.
	for (int i = 1; i <= n; i++) {
		cin >> xy >> h >> w;
		v.push_back({ xy, h, w, i});
	}
	sort(v.begin(), v.end(), cmp);  // 무게순 정렬 -> 앞으로는 너비만 비교하면 됨
	for (int i = 1; i <= n; i++) {  // i번째 블록을 놓는 경우
		for (int j = 0; j < i; j++) {   // j번째 블록 위에 i번째 블록을 올릴 수 있는지?
			if (v[i].xy < v[j].xy) {
				if (dp[j] + v[i].h > dp[i]) {     //만약 j번째 블록 위에 i번 블록을 올릴 수 있고 i번 블록을 올리는 경우 높이가 더 높아지는 경우
					dp[i] = dp[j] + v[i].h;
					max_hei = max(dp[i], max_hei);
				}
			}
		}
	}
	for (int i = n; i > 0; i--) {     // dp 배열에서 최대의 높이를 찾은 경우 블록을 하나하나 빼면서 idx를 추가해준다.
		if (dp[i] == max_hei) {
			max_hei -= v[i].h;
			result.push_back(v[i].idx);
		}
	}
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}

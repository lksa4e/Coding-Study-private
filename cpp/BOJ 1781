문제
상욱 조교는 동호에게 N개의 문제를 주고서, 각각의 문제를 풀었을 때 컵라면을 몇 개 줄 것인지 제시 하였다. 
하지만 동호의 찌를듯한 자신감에 소심한 상욱 조교는 각각의 문제에 대해 데드라인을 정하였다.

문제 번호	1	2	3	4	5	6	7
데드라인	1	1	3	3	2	2	6
컵라면 수	6	7	2	1	4	5	1
위와 같은 상황에서 동호가 2, 6, 3, 1, 7, 5, 4 순으로 숙제를 한다면 2, 6, 3, 7번 문제를 시간 내에 풀어 총 15개의 컵라면을 받을 수 있다.

문제는 동호가 받을 수 있는 최대 컵라면 수를 구하는 것이다. 위의 예에서는 15가 최대이다.

문제를 푸는데는 단위 시간 1이 걸리며, 각 문제의 데드라인은 N이하의 자연수이다. 
또, 각 문제를 풀 때 받을 수 있는 컵라면 수와 최대로 받을 수 있는 컵라면 수는 모두 231보다 작거나 같은 자연수이다.

입력
첫 줄에 숙제의 개수 N (1 ≤ N ≤ 200,000)이 들어온다. 
다음 줄부터 N+1번째 줄까지 i+1번째 줄에 i번째 문제에 대한 데드라인과 풀면 받을 수 있는 컵라면 수가 공백으로 구분되어 입력된다.

출력
첫 줄에 동호가 받을 수 있는 최대 컵라면 수를 출력한다.

예제 입력 1 
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
예제 출력 1 
15

알고리즘 분류
자료 구조
그리디 알고리즘
우선순위 큐
--------------------------------------------------------------------------------------------------
단순하게 컵라면으로 sorting / 데드라인으로 sorting 하는 방식으로는 풀 수 없다.
우선 데드라인 기준으로 sorting을 한다. 
데드라인 안에서 풀 수 있는 모든 문제를 풀되, 새 문제를 풀었을 때 데드라인을 넘는 경우 푼 문제 중 가장 손해를 많이 보는(컵라면이 제일 적은) 문제를 포기한다.

----------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<pair<int, int>> v;
priority_queue<int> pq;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}
int main() {
	int N, a, b;  // 데드라인, 컵라면
	long long result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (pq.size() < v[i].first) {  // 가진 문제 수가 데드라인 초과 안할 때
			pq.push(-v[i].second);
		}
		else {  // 데드라인보다 많은 문제를 가지고 있을 때
			pq.push(-v[i].second);
			pq.pop();
		}
	}
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << -result;
	return 0;
}

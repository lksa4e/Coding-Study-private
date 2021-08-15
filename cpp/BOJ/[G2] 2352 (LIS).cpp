문제
반도체를 설계할 때 n개의 포트를 다른 n개의 포트와 연결해야 할 때가 있다.



예를 들어 왼쪽 그림이 n개의 포트와 다른 n개의 포트를 어떻게 연결해야 하는지를 나타낸다. 
하지만 이와 같이 연결을 할 경우에는 연결선이 서로 꼬이기 때문에 이와 같이 연결할 수 없다. 
n개의 포트가 다른 n개의 포트와 어떻게 연결되어야 하는지가 주어졌을 때, 
연결선이 서로 꼬이지(겹치지, 교차하지) 않도록 하면서 최대 몇 개까지 연결할 수 있는지를 알아내는 프로그램을 작성하시오

입력
첫째 줄에 정수 n(1 ≤ n ≤ 40,000)이 주어진다. 다음 줄에는 차례로 1번 포트와 연결되어야 하는 포트 번호, 
2번 포트와 연결되어야 하는 포트 번호, …, n번 포트와 연결되어야 하는 포트 번호가 주어진다. 이 수들은 1 이상 n 이하이며 서로 같은 수는 없다고 가정하자.

출력
첫째 줄에 최대 연결 개수를 출력한다.

예제 입력 1 
6
4 2 6 3 1 5
예제 출력 1 
3


알고리즘 분류
이분 탐색
가장 긴 증가하는 부분 수열: O(n log n)


-----------------------------------------------------------
DP를 이용한 LIS 알고리즘의 경우 탐색하는 Length가 k일때 매번 1~k 까지의 dp 중 최대값을 구한다.
따라서 시간복잡도가 O(n^2)이 된다. 

하지만 특정값 X가 LIS 배열에 포함될 때 이분탐색을 통해 넣을 위치를 찾고, X보다 큰 수 중 가장 작은수 바로 앞에 X를 넣게된다면 
Nlog(N) 시간만에 LIS를 구할 수 있다. 

기존까지의 LIS 배열에서 새로 들어오는 숫자가 지금까지 존재하는 수보다 더 크다면 (LIS.back() < X) 그냥 LIS 배열 맨 뒤에 추가하면 되는것이고,
만약 기존 LIS 배열 안에 들어가야 한다면 처음으로 X보다 큰 수가 나오는 순간 X를 대체한다. 

** lower_bound를 사용하게 되면 배열 안에서 처음으로 x보다 큰 값이 나오는 위치를 반환한다. 
이 때 기존 LIS 배열에서 x보다 큰 수를 바꿔주더라도 이전 값들은 x보다 작고,
이후 값들은 기존 x보다도 큰 값이었으므로 LIS 구조는 바뀌지 않게 된다.

-------------------------------------------------------------
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<pair<int, int>> v;
int N;
int lis[40001];
bool cmp(pair<int,int> p1, pair<int,int> p2) {
	return p1.first < p2.first;
}
int main() {
	fastio;
	int a, b, result = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		v.push_back({ i,a });
	}
	sort(v.begin(), v.end(), cmp);
	vector<int> lis;
	for (int k = 0; k <N; k++) {
		if (k == 0) lis.push_back(v[k].second);
		else {
			if (lis.back() < v[k].second) lis.push_back(v[k].second);
			else {
				auto iter = lower_bound(lis.begin(), lis.end(), v[k].second) - lis.begin();
				lis[iter] = v[k].second;
			}
		}
	}
	cout << lis.size();
	return 0;
}


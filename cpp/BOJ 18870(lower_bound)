문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
1 ≤ N ≤ 1,000,000
-109 ≤ Xi ≤ 109
예제 입력 1 
5
2 4 -10 4 -9
예제 출력 1 
2 3 0 3 1
예제 입력 2 
6
1000 999 1000 999 1000 999
예제 출력 2 
1 0 1 0 1 0

알고리즘 분류
정렬
값 / 좌표 압축

------------------------------------------------------------
정렬된 상태에서
lower_bound(N)를 사용하면 처음으로 N보다 크거나 같은 원소, 즉 N의 위치를 찾아낸다.

0 ~ N의 위치까지가 N보다 작은 수들이므로 lower_bound를 사용하고 받은 값을 출력한다. 

중복은 허용하지 않는다고 하였으니 원래 숫자를 저장할 벡터, 중복을 제거할 벡터 2개를 사용한다.
---------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#pragma warning(disable:4996)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
using namespace std;
vector<int> v, v1;
map<int, int> m;
int main() {
	fastio;
	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
		if (m[a] == 0) {
			m[a] = 1;
			v1.push_back(a);
		}
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < N; i++) {
		auto temp = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
		cout<<temp<<" ";
	}
	return 0;
}

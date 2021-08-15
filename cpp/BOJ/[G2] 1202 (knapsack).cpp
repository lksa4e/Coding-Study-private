문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 
각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.

예제 입력 1 
2 1
5 10
100 100
11
예제 출력 1 
10
예제 입력 2 
3 2
1 65
5 23
2 99
10
2
예제 출력 2 
164
알고리즘 분류
자료 구조
그리디 알고리즘
정렬
우선순위 큐

---------------------------------------------
보석의 최대가격이니까 가격이 높은 보석부터 처리해주면 될 것이다 라고 생각할 수 있지만, 사실 무게부터 고려를

해봐야 한다.

아무리 가격이 높은 보석이라고 하더라도, 해당 보석의 무게가 가방이 담을 수 있는 최대 무게보다 더 나간다면

보석을 가져갈 수 없기 때문이다.

즉, 무게가 낮은 보석부터 우선적으로 고려를 해주어야 한다. 물론, 무게가 같은 보석이 여러개라면 당연히 가격이 더 높은

보석이 더 우선적으로 선택되어야 할 것이다.

가장먼저 가방을 무게순으로, 보석을 무게순으로(무게가 같으면 가격이 더 높은 순으로) 정렬을 해주었다.

------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x) (x).begin(),(x).end()
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, K;
vector<int> bag;
vector<pii> jew;
void solve() {
	sort(all(jew));
	sort(all(bag));
	priority_queue<int> pq;
	int pos = 0;
	ll result = 0;
	for (int i = 0; i < K; i++) {           // 가방
		while (pos < N)
		{
			if (jew[pos].fst <= bag[i])
			{
				pq.push(jew[pos].snd);
				pos++;
			}
			else break;
		}
		if (!pq.empty()) {
			result += pq.top(); pq.pop();
		}
	}
	cout << result;
}

int main() {
	fastio;
	int a, b, c; 
	cin >> N >> K;			        //보석개수, 가방개수
	for (int i = 0; i < N; i++) {
		cin >> a >> b;		        
		jew.push_back({ a, b });     // 무게, 가격
	}
	for (int i = 0; i < K; i++) {
		cin >> a;
		bag.push_back(a);
	}
	solve();
	return 0;
}

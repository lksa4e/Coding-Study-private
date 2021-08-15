문제
지민이는 파티에 가서 이야기 하는 것을 좋아한다. 파티에 갈 때마다, 지민이는 지민이가 가장 좋아하는 이야기를 한다. 
지민이는 그 이야기를 말할 때, 있는 그대로 진실로 말하거나 엄청나게 과장해서 말한다. 당연히 과장해서 이야기하는 것이 훨씬 더 재미있기 때문에,
되도록이면 과장해서 이야기하려고 한다. 하지만, 지민이는 거짓말쟁이로 알려지기는 싫어한다. 문제는 몇몇 사람들은 그 이야기의 진실을 안다는 것이다.
따라서 이런 사람들이 파티에 왔을 때는, 지민이는 진실을 이야기할 수 밖에 없다. 당연히, 어떤 사람이 어떤 파티에서는 진실을 듣고, 
또다른 파티에서는 과장된 이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다. 지민이는 이런 일을 모두 피해야 한다.

사람의 수 N이 주어진다. 그리고 그 이야기의 진실을 아는 사람이 주어진다. 그리고 각 파티에 오는 사람들의 번호가 주어진다. 
지민이는 모든 파티에 참가해야 한다. 이때, 지민이가 거짓말쟁이로 알려지지 않으면서, 과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N과 파티의 수 M이 주어진다.

둘째 줄에는 이야기의 진실을 아는 사람의 수와 번호가 주어진다. 진실을 아는 사람의 수가 먼저 주어지고 그 개수만큼 사람들의 번호가 주어진다. 
사람들의 번호는 1부터 N까지의 수로 주어진다.

셋째 줄부터 M개의 줄에는 각 파티마다 오는 사람의 수와 번호가 같은 방식으로 주어진다.

N, M은 50 이하의 자연수이고, 진실을 아는 사람의 수와 각 파티마다 오는 사람의 수는 모두 0 이상 50 이하의 정수이다.

출력
첫째 줄에 문제의 정답을 출력한다.

예제 입력 1 
4 3
0
2 1 2
1 3
3 2 3 4
예제 출력 1 
3
예제 입력 2 
4 1
1 1
4 1 2 3 4
예제 출력 2 
0
예제 입력 3 
4 1
0
4 1 2 3 4
예제 출력 3 
1
예제 입력 4 
4 5
1 1
1 1
1 2
1 3
1 4
2 4 1
예제 출력 4 
2
예제 입력 5 
10 9
4 1 2 3 4
2 1 5
2 2 6
1 7
1 8
2 7 8
1 9
1 10
2 3 10
1 4
예제 출력 5 
4
예제 입력 6 
8 5
3 1 2 7
2 3 4
1 5
2 5 6
2 6 8
1 8
예제 출력 6 
5
예제 입력 7 
3 4
1 3
1 1
1 2
2 1 2
3 1 2 3
예제 출력 7 
0

알고리즘 분류
그래프 이론
자료 구조
그래프 탐색
분리 집합

-------------------------------------------------------------
1. 모든 사람의 관계를 그래프 형식으로 플로이드-와샬 알고리즘을 통해 연결관계를 만들은 후 진실을 말하고 있는 사람과 연결관계가 있는지 검사하여 해결하는 방법
2. 유니온파인드를 사용하여 집합으로 묶고, 파티의 모든 멤버들에 대해 진실을 말하는 사람과 같은 집합인지 체크하는 방법

--> 시간 복잡도 측면에서 union find가 월등히 빠르다.
------------------------------------------------------------

#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int parent[51] = { 0 };
vector<int> v[50];
int N, M, t;
int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}
void uniom(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a == 0 || b == 0) {
		parent[a] = 0;
		parent[b] = 0;
	}
	else if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	fastio;
	int a, b, cnt = 0;
	cin >> N >> M >> t;
	for (int i = 1; i <= N; i++) {  // 유니온파인드 초기화
		parent[i] = i;
	}
	for (int i = 0; i < t; i++) {   // 진실맨 입력
		cin >> a;
		uniom(0, a);
	}
	for (int i = 0; i < M; i++) {     // 파티 입력
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			v[i].push_back(b);
		}
		for (auto data : v[i]) {    // 파티에 속한 사람들 같은 집합으로
			uniom(v[i][0], data);
		}
	}
	if (t == 0) cout << M;           // 진실맨 없으면 모든파티 참가
	else {
		for (int i = 0; i < M; i++) {     // 모든 파티에 대해
			int flag = 0;
			for (auto data : v[i]) {       // 파티의 모든 구성원에 대해
				if (find(data) == 0) {      // 한명이라도 진실맨과 같은 집합이라면
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
		cout << cnt;
	}
	return 0;
}
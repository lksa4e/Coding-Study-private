문제
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에, 
한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.

이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.

이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다. 
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다. 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

출력
첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.

예제 입력 1 
5 4
3 1
3 2
4 3
5 3
예제 출력 1 
1 2

------------------------------------------------------------------

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10001
bool visit[MAX];
int arr[MAX];
vector<int> graph[MAX];
int cnt;
void dfs(int start, int n) {
	visit[start] = 1;
	for (int i = 0; i < graph[start].size(); i++) {
		if (visit[graph[start][i]] == 0) {
			cnt++;
			dfs(graph[start][i], n);
		}
	}
}
int main() {
	int N, M, a, b, max_cnt = 0;
	vector<int> answer;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[b].push_back(a);
	}
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		dfs(i, N);
		arr[i] = cnt;
		flag = max(flag, cnt);
	}
	for (int i = 0; i <= N; i++) {
		if (arr[i] == flag) {
			cout << i << ' ';
		}
	}
	return 0;
}

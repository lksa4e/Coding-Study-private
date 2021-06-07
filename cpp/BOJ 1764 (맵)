문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, 
N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

 

듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

출력
듣보잡의 수와 그 명단을 사전순으로 출력한다.

예제 입력 1 
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton
예제 출력 1 
2
baesangwook
ohhenrie

----------------------------------------------
보를 입력받았을때 듣일 경우 정답에 추가한다.
index가 아닌 string으로 판단하므로 map 자료구조를 사용한다.

----------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, int> m1;
vector<string> result;
int main() {
	int N, M;
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m1[s] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (m1[s] == 1) result.push_back(s);
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}

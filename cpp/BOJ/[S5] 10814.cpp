문제
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 
나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 
200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 
입력은 가입한 순서로 주어진다.

출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

예제 입력 1 
3
21 Junkyu
21 Dohyun
20 Sunyoung
예제 출력 1 
20 Sunyoung
21 Junkyu
21 Dohyun

--------------------------------------------------------------------------------------------------
stable_sort 를 사용하면 기존 순서는 유지하면서 sort 할 수 있다. 값이 같은 경우에는 기존 형태를 유지할 수 있다 이마리야


--------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool cmp(tuple<int, int, string> t1, tuple<int, int, string> t2) {
	auto [a1, b1, c1] = t1;
	auto [a2, b2, c2] = t2;
	if (b1 == b2) {
		return a1 < a2;
	}
	return b1 < b2;
}
int main() {
	fastio;
	int N,a;
	string s;
	cin >> N;
	vector<tuple<int,int,string>> v;
	for (int i = 0; i < N; i++) {
		cin >> a >> s;
		v.push_back({ i,a,s });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		auto [a, b, c] = v[i];
		cout << b << " " << c << endl;
	}
	return 0;
}

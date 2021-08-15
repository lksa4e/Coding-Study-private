문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

예제 입력 1 
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
예제 출력 1 
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate


---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool cmp(string s1, string s2) {       //길이가 같으면 사전순으로 정리,
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	return s1.length() < s2.length();     // 길이가 다르면 길이 짧은 순서대로
}
int main() {
	int N;
	string S;
	vector<string> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		v.push_back(S);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());    //벡터에서 중복되는거 삭제하기, sort가 선행되어야함
	for (auto &T : v) {
		cout << T << endl;
	}
}
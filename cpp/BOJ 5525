문제
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다. (1 ≤ N ≤ 1,000,000, 2N+1 ≤ M ≤ 1,000,000)

출력
S에 PN이 몇 군데 포함되어 있는지 출력한다.

예제 입력 1 
1
13
OOIOIOIOIIOII
예제 출력 1 
4


-------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, M, cnt = 0, flag = 0, answer = 0;
	string s;
	vector<int> result;
	cin >> N >> M >> s;
	for (int i = 0; i < s.size(); i++) {
		if (flag == 0) {   //아닐때
			if (s[i] == 'I') {
				flag = 1;
				cnt++;
			}
		}
		else {   //진행중
			if (s[i] == s[i - 1]) {	//두개 연속 -> 중단
				result.push_back(cnt);
				if (s[i] == 'I') {
					flag = 1;
					cnt = 1;
				}
				else {
					flag = 0;
					cnt = 0;
				}
			}
			else {
				cnt++;
			}
		}
	}
	if (cnt > 0) result.push_back(cnt);
	for (int i = 0; i < result.size(); i++) {
		answer += max(0, (result[i] + 2 - (2 * N + 1)) / 2);
	}
	cout << answer;
	return 0;
}

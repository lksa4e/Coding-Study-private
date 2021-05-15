문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4

------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp[1001][1001] = { 0 };
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int s1_len = s1.size();
	int s2_len = s2.size();
	for (int i = 1; i <= s1_len; i++) {
		for (int j = 1; j <= s2_len; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[s1_len][s2_len];
	return 0;
}

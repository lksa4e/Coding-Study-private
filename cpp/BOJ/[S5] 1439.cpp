문제
다솜이는 0과 1로만 이루어진 문자열 S를 가지고 있다. 다솜이는 이 문자열 S에 있는 모든 숫자를 전부 같게 만들려고 한다. 
다솜이가 할 수 있는 행동은 S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것이다. 뒤집는 것은 1을 0으로, 0을 1로 바꾸는 것을 의미한다.

예를 들어 S=0001100 일 때,

전체를 뒤집으면 1110011이 된다.
4번째 문자부터 5번째 문자까지 뒤집으면 1111111이 되어서 2번 만에 모두 같은 숫자로 만들 수 있다.
하지만, 처음부터 4번째 문자부터 5번째 문자까지 문자를 뒤집으면 한 번에 0000000이 되어서 1번 만에 모두 같은 숫자로 만들 수 있다.

문자열 S가 주어졌을 때, 다솜이가 해야하는 행동의 최소 횟수를 출력하시오.

입력
첫째 줄에 문자열 S가 주어진다. S의 길이는 100만보다 작다.

출력
첫째 줄에 다솜이가 해야하는 행동의 최소 횟수를 출력한다.

예제 입력 1 
0001100
예제 출력 1 
1

--------------------------------------------------------------
#include <iostream>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	string s;
	int zero = 0, one = 0;    // 0 묶음의 개수, 1 묶음의 개수 둘중 더 작은걸 바꿔주면 된다.
	bool flag;
	cin >> s;
	if (s[0] == '0') {
		flag = 0;
		zero++;
	}
	else if (s[0] == '1') {
		flag = 1;
		one++;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1' && flag == 0) {
			flag = 1;
			one++;
		}
		else if (s[i] == '0' && flag == 1) {
			flag = 0;
			zero++;
		}
	}
	cout << min(one, zero);
	return 0;
}
----------------------------------------------------------------------
//간결화 코드
//flag 를 둘 필요 없이 단순히 앞뒤 문자를 비교하는 것만으로도 카운팅 할 수 있다.

#include <iostream>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
	string s;
	int zero = 0, one = 0;
	cin >> s;
	s[0] == '0' ? zero++ : one++;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) {
			if (s[i + 1] == '1') one++;
			else zero++;
		}
	}
	cout << min(one, zero);
	return 0;
}


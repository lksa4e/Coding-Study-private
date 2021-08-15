문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
55-50+40
예제 출력 1 
-35


알고리즘 분류
수학
문자열
그리디 알고리즘
파싱


-----------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> st;
int main() {
	string s, temp = "";
	int flag = 1, result = 0, sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			if (flag == 1) {
				st.push_back(stoi(temp));
				temp = "";
			}
			else {                      // - 로 괄호 묶여야 할 때
				sum += stoi(temp);
				temp = "";
			}
		}else if (s[i] == '-') {  //마이너스가 나오면 괄호를 묶는다.
			if (flag == 0) {      //이전에 마이너스였던 상태
				sum += stoi(temp);
				st.push_back(-1 * sum);
				temp = "";
				sum = 0;
			}else {                //처음 - 나온경우
				st.push_back(stoi(temp));
				temp = "";
				flag = 0;
			}
		}else {
			temp += s[i];
		}
	}
	if (flag == 1) st.push_back(stoi(temp));
	else {
		sum += stoi(temp);
		st.push_back(-1 * sum);
	}
	for (int i = 0; i < st.size(); i++) {
		result += st[i];
	}
	cout << result;
	return 0;
}

------------------------------------------------------최적화--------------------------------
처음 코드는 첫번째로 -가 나오는 경우에는 이전까지는 +로 집어넣고, 나머지는 -로 집어넣는 방식으로 구현하였지만,
어차피 st 벡터에서 첫번째는 + 연산을, 나머지는 전부 - 연산을 하게 된다.
따라서 그냥 단순히 '-' 가 나올때만 벡터에 집어넣은 다음 마지막에 첫번째를 제외한 나머지 벡터 원소들을 -해준다.

(계속 +가 나오는 경우) 마지막에 for문 밖에서 마지막 숫자에 대한 처리를 해주는데 이때까지 -가 안나왔다면 벡터의 값은 1개가 되어서 예외도 없다.

--------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> st;
int main() {
	string s, temp = "";
	int flag = 1, result = 0, sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			sum += stoi(temp);
			temp = "";
		}else if (s[i] == '-') {  //마이너스가 나오면 괄호를 묶는다.
			sum += stoi(temp);
			st.push_back(sum);
			temp = "";
			sum = 0;
		}else temp += s[i];
	}
	sum += stoi(temp);
	st.push_back(sum);

	for (int i = 0; i < st.size(); i++) {
		if (i == 0) result += st[i];
		else result -= st[i];
	}
	cout << result;
	return 0;
}


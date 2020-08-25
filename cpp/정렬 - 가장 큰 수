문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
  numbers의 길이는 1 이상 100,000 이하입니다.
  numbers의 원소는 0 이상 1,000 이하입니다.
  정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.

입출력 예
numbers	          return
[6, 10, 2]	      6210
[3, 30, 34, 5, 9]	9534330

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {                              //sort 함수의 비교함수 -> 문자열 두개를 붙여서 큰 String 찾는 함수
	string aa = a + b;
	string bb = b + a;
	if (a.size() == b.size()) {
		return a > b;
	}
	else {
		return aa > bb;
	}
}

bool solution(vector<string> phone_book) { 
	sort(phone_book.begin(), phone_book.end(),cmp);
	bool answer = true;
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i].size() == phone_book[i + 1].size()) {           //만약 문자열 길이가 같으면 첫번째 index만 비교해도 접두사 판단 가능
			if (phone_book[i] == phone_book[i + 1]) return false;
		}
		else {                                                            //문자열 길이가 다른 경우
			if (phone_book[i][0] != phone_book[i + 1][0]) {                 //첫번째 index가 다르면 무조건 접두사 안됨
				continue;
			}
			size_t s;
			if (phone_book[i].size() > phone_book[i + 1].size()) {          //사이즈 비교해서 for문 길이 맞추기 위함
				s = phone_book[i + 1].size();
			}
			else {
				s = phone_book[i].size();
			}
			for (int j = i; j < phone_book.size() - 1; j++) {                 // 하나 선택했을때 나머지와 비교하는 for문
				int check = 0;
				for (int k = 0; k < s; k++) {                                   // 스트링에서 Char 하나하나 비교
					if (phone_book[j][k] != phone_book[j + 1][k]) {
						check = 1;                                                  // 다른게 있으면 Check = 1 
					}
				}
				if (check == 0) return false;                                   // 다른게 없다 -> 접두사 일치
			}
		}
	}
	return answer;
}

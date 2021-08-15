문제 설명
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 
그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

제한 사항
  phone_book의 길이는 1 이상 1,000,000 이하입니다.
  각 전화번호의 길이는 1 이상 20 이하입니다.
  
입출력 예제
phone_book	                    return
[119, 97674223, 1195524421]	    false
[123,456,789]	                  true
[12,123,1235,567,88]	          false

입출력 예 설명
입출력 예 #1
앞에서 설명한 예와 같습니다.

입출력 예 #2
한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.

입출력 예 #3
첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다. 따라서 답은 false입니다.

알림
2019년 5월 13일, 테스트 케이스가 변경되었습니다. 이로 인해 이전에 통과하던 코드가 더 이상 통과하지 않을 수 있습니다.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b) {                                          // Sort 할 때 String 두개를 붙여서 비교하는 compare 함수
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
	sort(phone_book.begin(), phone_book.end(),cmp);                             // Sorting
	bool answer = true;
	for (int i = 0; i < phone_book.size() - 1; i++) {                           // 모든 전화번호에 대해서
		if (phone_book[i].size() == phone_book[i + 1].size()) {                   // 두개를 비교해서 만약 전화번호 길이가 같을 때
			if (phone_book[i] == phone_book[i + 1]) return false;                   //      전화번호가 같으면 접두사 존재하므로 바로 return false
		}
		else {                                                                    // 전화번호 길이가 다를 때
			if (phone_book[i][0] != phone_book[i + 1][0]) {                         //    처음 숫자가 다르면 다음 for문으로(처음 숫자가 다르면 접두사가 불가)
				continue;
			}                                                                       //    처음 숫자가 같을 때( 뒷자리도 비교해야한다)
            size_t s;
            if(phone_book[i].size() > phone_book[i+1].size()){                //    for문을 돌기 위해 숫자의 길이 중 작은것을 찾기
                s = phone_book[i+1].size();
            }else{
                s = phone_book[i].size();
            }
			for (int j = i; j < phone_book.size() - 1; j++) {                       //  두 개의 전화번호의 각 자리를 비교하기 위한 for 문
				int check = 0;
				for (int k = 0; k < s; k++) {                                         //  짧은 숫자 기준으로 for문(짧은 쪽 기준으로 돌았을때 끝까지 돌아서 체크를 통과하면 접두사 가능)
					if (phone_book[j][k] != phone_book[j + 1][k]){                      //  각 자리를 비교해서 만약 다르다면 check = 1
                        check = 1;
                    }
				}
                if(check == 0) return false;                                  // check == 0 은 각 자리 비교했을 때 다른게 없다 => 접두사가 된다.
			}
		}
	}
	return answer;
}

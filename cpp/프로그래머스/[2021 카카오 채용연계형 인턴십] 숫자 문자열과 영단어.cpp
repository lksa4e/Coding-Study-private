/**
* 1. 문자인 경우 : string 문자를 숫자로 변환
* 2. 숫자인 경우 : 숫자를 그대로 붙이기
*  
* 1을 위해 map<string, int> 를 사용한다.
*/

#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
map<string, int> m;
void init(){           // 문자를 숫자로 바꿔주기 위한 map 초기화
    m["zero"] = 1;      // map에 없는 string으로 검색을 하는 경우 0이 나오는데 zero도 0으로 세팅해준다면 0을 찾을 수 없다. 따라서 1 증가시켜서 저장 후 마지막에 1감소
    m["one"] = 2;
    m["two"] = 3;
    m["three"] = 4;
    m["four"] = 5;
    m["five"] = 6;
    m["six"] = 7;
    m["seven"] = 8;
    m["eight"] = 9;
    m["nine"] = 10;
}
int solution(string s) {
    string answer = "";
    string temp = "";
    init();
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){                  //숫자인 경우 그대로 붙이기
            answer.push_back(s[i]);
        }else{
            temp.push_back(s[i]);
            if(m[temp] != 0){                     //만약 지금까지 저장한 문자가 변환이 가능한 경우
                answer += to_string(m[temp]-1);    //변환 후 정답배열에 붙이기
                temp = "";
            }
        }
    }
    return stoi(answer);
}

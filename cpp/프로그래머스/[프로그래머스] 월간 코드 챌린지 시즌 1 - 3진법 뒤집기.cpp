/**
	n을 3으로 나눈 나머지를 string에 push_back 해주게 된다면 자동으로 앞뒤 반전까지 한 결과를 얻을 수 있다.
	이후에 string 형태의 3진법 숫자를 10진법으로 고치면 된다.

*/

#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    string th_num = "";
    while(n > 0){
        th_num.push_back((n % 3) + '0');
        n /= 3;
    }
    for(int i = 0; i < th_num.size(); i++){
        answer += (th_num[th_num.size() - i - 1] - '0') * pow(3,i);
    }
    return answer;
}

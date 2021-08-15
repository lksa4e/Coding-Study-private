/**
	가장 많은 부서에 예산을 주려면 가장 작은 금액을 신청한 부서부터 예산을 배정하면 된다.
	sort 이후 탐색하면서 예산보다 작으면 예산 차감, 크면 break 한다.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for(auto data: d){
        if(data <= budget) {
            answer++;
            budget-= data;
        }
        else break;
    }
    return answer;
}

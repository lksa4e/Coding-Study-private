/*
1. 당첨 번호의 숫자를 모두 센다.
2. 0의 개수를 센다.

최고 맞은 갯수 -> 당첨번호 숫자 + 0의 개수
최저 맞은 갯수 -> 당첨번호 숫자

맞은 개수를 세고 조건에 맞추어 등수를 매긴다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visit[46];
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_cnt = 0;
    int ans_cnt = 0;
    for(auto data : win_nums){
        visit[data] = 1;
    }
    for(auto data : lottos){
        if(data == 0){
            zero_cnt++;
        }else{
            if(visit[data]) ans_cnt++;
        }
    }
    if(ans_cnt + zero_cnt < 2) answer.push_back(6);
    else answer.push_back(7 - (ans_cnt + zero_cnt));
    
    if(ans_cnt < 2) answer.push_back(6);
    else answer.push_back(7 - ans_cnt);
    
    return answer;
}

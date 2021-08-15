
#include <string>
#include <vector>
#include <iostream>
using namespace std;
pair<int,int> pos[10] = {{3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
int dist(pair<int,int> a, pair<int,int> b){
    return (abs(a.first - b.first) + abs(a.second - b.second));
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left = {3,0};
    pair<int,int> right = {3,2};
    for(auto data: numbers){
        if(data == 1 || data == 4 || data == 7){
            left = pos[data];
            answer.push_back('L');
        }else if(data == 3 || data == 6 || data == 9){
            right = pos[data];
            answer.push_back('R');
        }else{
            int left_dist = dist(left, pos[data]);
            int right_dist = dist(right, pos[data]);
        
            if(left_dist == right_dist){
                if(hand == "right"){
                    right = pos[data];
                    answer.push_back('R');
                }else{
                    left = pos[data];
                    answer.push_back('L');
                }
            }else if(left_dist < right_dist){
                left = pos[data];
                answer.push_back('L');
            }else{
                right = pos[data];
                answer.push_back('R');
            }
        }
    }
    return answer;
}

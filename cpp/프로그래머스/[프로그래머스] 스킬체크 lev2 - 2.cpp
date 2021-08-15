/**
	주어진 조건이 여러개인 경우 수식으로 풀면 구현이 너무 복잡해질 것으로 생각 + 
	전체 인원수가 8밖에 되지 않아 모든 순열의 경우수를 세어봐도 8!으로 널널하게 구할 수 있다.
	next_permutation 함수를 사용하여 모든 순열의 경우의 수를 구하고.
	모든 조건을 탐색하면서 정답이 될 수 있는지를 체크한다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<char> v = {'A','C','F','J','M','N','R','T'};
int pos1;
int pos2;
void solve(char c1, char c2){
    for(int i = 0; i < 8; i++){
        if(c1 == v[i]) pos1 = i;
        if(c2 == v[i]) pos2 = i;
    }
}
int solution(int n, vector<string> data) {
    int answer = 0;
    
    do{
        int flag = 0;
        for(int i = 0; i < n; i++){
            char fst = data[i][0];
            char snd = data[i][2];
            char sign = data[i][3];
            int gap = data[i][4] - '0';
            solve(fst, snd);
            if(sign == '='){
                if(abs(pos1 - pos2) == gap + 1);
                else{
                    flag = 1;
                    break;
                }
            }else if(sign == '>'){
                if(abs(pos1 - pos2) > gap + 1);
                else{
                    flag = 1;
                    break;
                }
            }else if(sign == '<'){
                if(abs(pos1 - pos2) < gap + 1);
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0) answer++;
        
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}

문제 설명
n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
  주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
  각 숫자는 1 이상 50 이하인 자연수입니다.
  타겟 넘버는 1 이상 1000 이하인 자연수입니다.

입출력 예
numbers	          target	return
[1, 1, 1, 1, 1]	  3	      5

입출력 예 설명
문제에 나온 예와 같습니다.


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
size_t SS = 0;                                                // 숫자 갯수
int TT = 0;                                                   // 타겟 넘버
int an = 0;                                                   // 정답
void dfs(int st, vector<int> numbers, int sum, int cnt){
    if(cnt == SS){                                            //모든 숫자 사용했나?
        if(sum == TT){                                        //합이 목표하는 타겟 넘버와 일치하는가?
            an++;
        }
        return;
    }
    if(st == 0){                                              //처음 dfs 초기화 부분
        dfs(1, numbers, numbers[0],1);
        dfs(1, numbers,  -1 * numbers[0],1);
    }else{                                                    //양수인 경우, 음수인 경우 모두 dfs (start 지점 + 1, count +1)
        dfs(st + 1, numbers, sum + numbers[st], cnt +1);
        dfs(st + 1, numbers, sum - numbers[st], cnt +1);
    }
}
int solution(vector<int> numbers, int target) {
    SS = numbers.size();
    TT = target;
    int answer = 0;
    dfs(0,numbers,0,0);
    answer = an;
    return answer;
}

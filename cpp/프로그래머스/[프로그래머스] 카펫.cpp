// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.

// 모든 경우의 수를 파악하는 완전 탐색 문제이다.
// brown + red 를 합한 전체 카펫 사이즈를 구하고 가능한 모든 가로 * 세로 쌍에 대해서 주어진 brown과 yellow를 만족하는지 체크한다.
#include <vector>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
    int sum = brown + red;
    
	for(int i = 3; i <= sum; i++){
        if(sum % i == 0){
            int row = i;
            int col = sum / i;
            if((row - 2) * (col - 2) == red){
                answer.push_back(col);
                answer.push_back(row);
                break;
            }
        }
    }
	return answer;
}

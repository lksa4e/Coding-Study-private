/**
	dp를 이용하여 문제를 해결해 준다.

	dp[i][j]를 i행까지 내려온 경우 j번째 칸을 밟았을 때까지의 최대값 이라고 하자
	연속해서 두 칸을 밟지 못하므로, 점화식은 같은 j를 제외하는 아래와 같은 식이 된다.
	dp[i][j] = max(dp[i-1][0] ~ dp[i-1][j-1], dp[i-1][j+1] ~ dp[i-1][N-1])

	문제의 경우 전체 칸의 수가 4개밖에 안되므로 그냥 수작업으로 푸는게 편하다.
*/

#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 0; i < 4; i++){
        dp[0][i] = land[0][i];
    }
    for(int i = 1; i < land.size(); i++){
        dp[i][0] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]) + land[i][0];
        dp[i][1] = max(max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]) + land[i][1];
        dp[i][2] = max(max(dp[i-1][1], dp[i-1][0]), dp[i-1][3]) + land[i][2];
        dp[i][3] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][0]) + land[i][3];
    }
    for(int i = 0; i < 4; i++){
        answer = max(answer,dp[land.size()-1][i]);
    }

    return answer;
}

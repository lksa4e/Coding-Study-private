/**
	문제의 정답은 서로 다른 포켓몬의 개수가 몇개이냐에 따라 나누어진다.
	서로 다른 포켓몬이 N/2 보다 작은 경우에는 서로 다른 포켓몬의 개수가 되고,
	N/2보다 많은 경우에는 N/2가 정다비 된다.

	서로 다른 원소의 개수는 map의 size를 통해 센다.


*/
#include <vector>
#include <map>
using namespace std;
map<int,int> m;
int solution(vector<int> nums)
{
    int answer = 0;
    for(auto next : nums){
        m[next]++;
    }
    if(m.size() >= nums.size()/2){
        answer = nums.size()/2;
    }else{
        answer = m.size();
    }
    return answer;
}

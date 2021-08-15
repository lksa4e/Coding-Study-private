/**
문제풀이
1. 주어진 숫자 중 3개의 수를 고른다.
2. 3개의 수를 더한다.
3. 더한 수가 소수인지 판별한다.

1 ==> nC3 의 경우의 수를 모두 구하는 조합 구현 (next_permutation)
3 ==> 소수 판별

이 문제의 경우 nC3의 케이스에 대해 매번 O(N)에 소수판별을 하게된다면 시간낭비가 심하다.
따라서 O(Nlog(logN)) 으로 주어진 범위 내의 모든 소수를 판별한 후 저장하는 에라토스테네스의 체 알고리즘을 사용한다.

** 에라토스테네스의 체 알고리즘
- 임의의 수 n 까지의 소수를 구하고자 할 때 2부터 n의 제곱근까지 돌며 모든 배수들을 소수에서 제외시키는 방식이다.

*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> idn;
int prime_num[3001];

void init(){  //에라토스테네스의 체
    for(int i = 2; i <= 3000; i++){
        prime_num[i] = i;
    }
    for (int i = 2; i <= sqrt(3000); i++)
    {
        if (prime_num[i] == 0)
            continue;
        for (int j = i * i; j <= 3000; j += i)
            prime_num[j] = 0;
    }
}

bool is_prime(int a){  // 소수 판별
    if(prime_num[a] == 0) return 0;
    else return 1;
}

int solution(vector<int> nums) { 
    int answer = 0;
    init();
    
    //next_permutation을 활용한 nC3 구하기
    for(int i = 0; i < nums.size() - 3; i++){
        idn.push_back(0);
    }
    for(int i = 0; i < 3; i++){
        idn.push_back(1);
    }
    do{
        int cand = 0;
        for(int i = 0; i < idn.size(); i++){
            if(idn[i] == 1) cand += nums[i];
        }
        answer += is_prime(cand);
    }while(next_permutation(idn.begin(), idn.end()));
    return answer;
}

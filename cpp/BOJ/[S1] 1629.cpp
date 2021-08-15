
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

예제 입력 1 
10 11 12
예제 출력 1 
4
-----------------------------------------------------------------------------------------------------------------------------
분할 정복 


#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll sol(ll x, ll y, ll z) {
	if (y == 1)return x;
	ll T = sol(x, y / 2, z);
	if (y % 2)return ((T * T) % z * x) % z;
	else return (T * T) % z;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << sol(a % c, b, c);

	return 0;
}

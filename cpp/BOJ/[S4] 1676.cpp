문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.

예제 입력 1 
10
예제 출력 1 
2
예제 입력 2 
3
예제 출력 2 
0

---------------------------------------------------
0의 개수는 2와 5의 조합으로 만들어지는 10의 개수의 영향을 받고
2보다는 5가 더 적으므로 전체 팩토리얼에서 5가 들어가는 개수를 센다.

#include <iostream>
#include <string>
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N;
	cin >> N;
	int cnt = 0;

	cnt += N / 5;
	cnt += N / 25;
	cnt += N / 125;

	cout << cnt;
}

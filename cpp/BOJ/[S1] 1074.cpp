문제
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

만약, N > 1이 라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

다음 예는 22 × 22 크기의 배열을 방문한 순서이다.

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음은 N=3일 때의 예이다.

입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2N
예제 입력 1 
2 3 1
예제 출력 1 
11
예제 입력 2 
3 7 7
예제 출력 2 
63

--------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a = 0;
int b = 0;
int su = 0;
int r, c;
void div(int x, int y, int N, int sum) {  //시작점 x,y  , 2^N값, 누적값
	if (N == 1) {  // 최종 사분면의 왼쪽 위 좌표와 그동안의 누적값
		a = x;
		b = y;
		su = sum;
		return;
	}
	int temp = pow(2, N);  //temp 사분면을 조사하는 정사각형의 한 변의 길이
	int temp3;
	if (r >= x && r < x + temp / 2) {  //1,2사분면
		if (c >= y && c < y + temp / 2) {	//1사분면
			div(x, y, N - 1, sum);
			
		}
		else {	//2사분면
			temp3 = sum + (temp * temp / 4); //누적 결과값
			div(x, y + temp / 2, N - 1, temp3);
			
		}
	}
	else {	//3,4 사분면
		if (c >= y && c < y + temp / 2) {	//3사분면
			temp3 = sum + (temp * temp / 4) * 2;
			div(x + temp / 2, y , N - 1, temp3);
			
		}
		else {							//3사분면
			temp3 = sum + (temp * temp / 4) * 3;
			div(x + temp / 2, y + temp/2, N - 1, temp3);
			
		}
	}
}
int main() {
	fastio;
	int N;
	cin >> N >> r >> c;
	div(0, 0, N, 0);
	if (a == r) {
		if (b == c) cout << su;
		else cout << su + 1;
	}
	else {
		if (b == c) cout << su + 2;
		else cout << su + 3;
	}

	return 0;
}

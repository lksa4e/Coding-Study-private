문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N이 주어진다. N은 항상 3×2k 수이다. (3, 6, 12, 24, 48, ...) (0 ≤ k ≤ 10, k는 정수)

출력
첫째 줄부터 N번째 줄까지 별을 출력한다.

예제 입력 1 
24
예제 출력 1 
                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
            ***** ***** ***** *****             
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****


알고리즘 분류
재귀

---------------------------------------------------------------
길이가 3인 경우 항상 같은 모양의 삼각형을 출력한다.
전체 그림에서 길이가 1/2인 작은 삼각형 3개로 나누어지면서 진행된다는 점을 이용해서 재귀 형식으로 문제를 해결한다.
동일한 패턴의 3개의 삼각형으로 나누므로, 시작 좌표(꼭지점)만 기억한다면 일반적인 별찍기와는 달리 공백을 신경쓰지 않아도 된다.
재귀 방식으로 그림을 그리기 위해 전체 그림판(좌표)를 배열로 선언한다.

--------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin,(x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second


using namespace std;
typedef pair<int, int> pii;

int N;
char arr[3072][6143];
void draw(int row, int col) {
	arr[row][col] = '*';

	arr[row + 1][col - 1] = '*';
	arr[row + 1][col + 1] = '*';
	
	for (int i = -2; i < 3; i++) {
		arr[row + 2][col + i] = '*';
	}
}
void triangle(int len, int row, int col) {
	if (len == 3) {
		draw(row,col);
		return;
	}
	triangle(len / 2, row, col);
	triangle(len / 2, row + len / 2, col - len / 2);
	triangle(len / 2, row + len / 2, col + len / 2);
}
int main() {
	fastio;
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			arr[i][j] = ' ';
		}
	}
	triangle(N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}

문제
세준이는 도서관에서 일한다. 도서관의 개방시간이 끝나서 세준이는 사람들이 마구 놓은 책을 다시 가져다 놓아야 한다. 
세준이는 현재 0에 있고, 사람들이 마구 놓은 책도 전부 0에 있다. 각 책들의 원래 위치가 주어질 때, 책을 모두 제자리에 놔둘 때 드는 최소 걸음 수를 계산하는 프로그램을 작성하시오. 
세준이는 한 걸음에 좌표 1칸씩 가며, 책의 원래 위치는 정수 좌표이다. 책을 모두 제자리에 놔둔 후에는 다시 0으로 돌아올 필요는 없다. 그리고 세준이는 한 번에 최대 M권의 책을 들 수 있다.

입력
첫째 줄에 책의 개수 N과, 세준이가 한 번에 들 수 있는 책의 개수 M이 주어진다. 둘째 줄에는 책의 위치가 주어진다. N은 10,000보다 작거나 같은 자연수이고,
M은 10,000보다 작거나 같다. 책의 위치는 0이 아니며, 그 절댓값이 10,000보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
7 2
-37 2 -6 -39 -29 11 -28
예제 출력 1 
131

--------------------------------------------------------------------------------------------
-쪽과 + 쪽은 별도라는 것을 생각하면 쉬운 문제

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> book_left;
vector<int> book_right;
int main() {
	int N, M, a, result = 0, flag; //책의 개수, 한번의 들 수 있는 책의 수, 변수
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a < 0) book_left.push_back(a);
		else book_right.push_back(a);
	}
	sort(book_left.begin(), book_left.end());
	sort(book_right.begin(), book_right.end(), greater<int>());
	if (book_left.size() == 0) flag = book_right[0];
	else if (book_right.size() == 0) flag = abs(book_left[0]);
	else {
		if(abs(book_left[0]) > book_right[0]) flag = abs(book_left[0]);
		else flag = book_right[0];
	}
	for (int i = 0; i < book_left.size(); i++) {
		result += abs(book_left[i]) * 2;
		i += M - 1;
	}
	for (int i = 0; i < book_right.size(); i++) {
		result += book_right[i] * 2;
		i += M - 1;
	}
	cout << result - flag;
	return 0;
}



-----------------------------------------------------------------------------------------------

// 간결한 풀이

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> book;
int main() {
	int N, M, a, result = 0; //책의 개수, 한번의 들 수 있는 책의 수, 변수
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		book.push_back(a);
	}
	sort(book.begin(), book.end());
	for (int i = 0; i < book.size(); i += M) {  // 음수 영역 책들
		if (book[i] > 0) break;
		result += abs(book[i]) * 2;
	}
	for (int i = N - 1; i >= 0; i -= M) {  // 양수 영역 책들
		if (book[i] < 0) break;
		result += abs(book[i]) * 2;
	}
	result -= max(abs(book[N - 1]), abs(book[0]));
	cout << result;
	return 0;
}

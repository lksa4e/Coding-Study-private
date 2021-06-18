문제
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 
이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

출력
첫째 줄에 프리오더를 출력한다.

예제 입력 1 
3
1 2 3
1 3 2
예제 출력 1 
2 1 3


알고리즘 분류
트리
분할 정복
재귀


--------------------------------------------------------------------------
inorder, preorder, postorder의 특성을 잘 이해하고 있어야 한다.
preorder : 방문 -> 왼 -> 오
inorder : 왼 -> 방문 -> 오
postorder : 왼 -> 오 -> 방문

               1
            2     5
          3  4   6  7
위와같은 트리의 구조에서 트리 순회는 아래와 같다.
전위 순회 : 1 2 3 4 5 6 7
중위 순회 : 3 2 4 1 6 5 7
후위 순회 : 3 4 2 6 7 5 1

이 때 후위순회의 가장 마지막 원소는 항상 root 노드가 된다.
그리고 중위순회에서의 root의 왼쪽은 왼쪽 서브트리, root의 오른쪽은 오른쪽 서브트리이다.
후위순회 배열에서 왼쪽 서브트리는 맨 앞에, 오른쪽 서브트리는 바로 그 뒤에 붙어있다.
중위 : 3 2 4 || 1 || 6 5 7
후위 : ㅁㅁㅁ|| ㅁㅁㅁ || 1 

문제의 요구사항은 전위순회 (방문 -> 왼 -> 오 ) 이다.
문제를 해결하기 위해 전체 트리에서 root를 출력하고 왼쪽 subtree, 오른쪽 subtree로 나눈다
그리고 나눈 subtree에서 다시 root를 출력하고 subtree를 나누는 행위를 반복한다.

이때 tree 안에서의 root의 값은 postorder에서의 마지막 원소이므로 쉽게 찾을 수 있다.
하지만 postorder에서 왼쪽 subtree가 어디서부터 어디까지인지 알 수 없으므로 그것을 구하기 위해 inorder 배열을 사용한다.
inorder 배열에서 시작 ~ root-1 까지는 왼쪽 subtree가 되고, root+1 ~ 끝 까지가 오른쪽 서브트리가 되는 성질을 사용한다.

root에서 inorder의 시작위치를 빼면 왼쪽 서브트리의 길이(left_length)가 나오게 되고, 
inorder에서는 root의 위치를 기준으로 서브트리를 나누고
postorder에서는 left_length를 기준으로 서브트리를 나눈다.

inorder 배열에서의 root 위치를 쉽게 찾기 위해 값을 넣어주었을 때 index를 반환하는 배열 (or Map)을 선언하여 사용한다.ㅑ
--------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

#define all(x) (x).begin, (x).end
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define fst first  
#define snd second


using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> inorder;
vector<int> postorder;
int index_arr[100001];
void solve(int in_start, int in_end, int post_start, int post_end) { //inorder, postorder 배열의 시작, 끝 idx
	if (in_start > in_end || post_start > post_end) return;
	int root = postorder[post_end];  // root값 찾기
	int p = index_arr[root];         // inoder에서의 root 위치 찾기
	int left = p - in_start;      //  왼쪽 subtree의 길이 (root 포함)
	cout << root <<" ";
	solve(in_start, p - 1, post_start, post_start + left - 1);  // 왼쪽 subtree의 inorder, postorder 
	solve(p + 1, in_end, post_start + left, post_end - 1);    // 오른쪽 subtree의 inorder, postorder
}

int main() {
	fastio;
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		inorder.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		postorder.push_back(a);
	}
	for (int i = 0; i < N; i++) {   // inorder에서 값으로 index를 찾기 위한 배열
		index_arr[inorder[i]] = i;
	}
	solve(0, N - 1, 0, N - 1);
	return 0;
}


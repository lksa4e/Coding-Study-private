문제
이진 검색 트리는 다음과 같은 세 가지 조건을 만족하는 이진 트리이다.

노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.


전위 순회 (루트-왼쪽-오른쪽)은 루트를 방문하고, 왼쪽 서브트리, 오른쪽 서브 트리를 순서대로 방문하면서 노드의 키를 출력한다. 
후위 순회 (왼쪽-오른쪽-루트)는 왼쪽 서브트리, 오른쪽 서브트리, 루트 노드 순서대로 키를 출력한다. 
예를 들어, 위의 이진 검색 트리의 전위 순회 결과는 50 30 24 5 28 45 98 52 60 이고, 후위 순회 결과는 5 28 24 45 30 60 52 98 50 이다.

이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.

입력
트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 106보다 작은 양의 정수이다. 모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 
같은 키를 가지는 노드는 없다.

출력
입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력한다.

예제 입력 1 
50
30
24
5
28
45
98
52
60
예제 출력 1 
5
28
24
45
30
60
52
98
50

알고리즘 분류
그래프 이론
그래프 탐색
트리
깊이 우선 탐색
재귀

--------------------------------------------------------
방법 1. 전위순회 배열에서 root, left_subtree, right_subtree를 찾고 재귀 형식으로 탐색하며 출력하기
방법 2. 이진탐색트리를 만든 후 후위순회 실행

--------------------------------------------------------
전위순회 배열에서의 재귀 탐색
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
typedef long long ll;
int N, M;

vector<int> tree;

void solve(int start, int end) {
	if (start >= end) return;
	int root = tree[start];
	int right_idx = distance(tree.begin(), lower_bound(tree.begin() + start + 1, tree.begin() + end, root));

	solve(start + 1, right_idx);
	solve(right_idx, end);
	cout << root << " ";
}

int main() {
	fastio;
	int a;
	int cnt = 0;
	while(cin>>a){
		if (a == EOF) break;
		tree.push_back(a);
	} 
	solve(0, tree.size());
	return 0;
}

----------------------------------------------------------
이진탐색 만들기 --> 메모리 + 시간소모 

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
typedef long long ll;
int N, M;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main() {
	fastio;
	int a;
	Node* root = NULL;
	while(cin>>a){
		if (a == EOF) break;
		root = insert(root, a);
	}
	postorder(root);
	return 0;
}


문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.



예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현된다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

예제 입력 1 
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
예제 출력 1 
ABDCEFG
DBAECFG
DBEGFCA

================================================================================================================

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
void preorder(vector<pair<int,int>> v, int src) {
	cout << char(src + 65);
	if (v[src].first != -19) preorder(v, v[src].first);
	if (v[src].second != -19) preorder(v, v[src].second);
}
void inorder(vector<pair<int, int>> v, int src) {
	if (v[src].first != -19) inorder(v, v[src].first);
	cout << char(src + 65);
	if (v[src].second != -19) inorder(v, v[src].second);
}
void postorder(vector<pair<int, int>> v, int src) {
	if (v[src].first != -19) postorder(v, v[src].first);
	if (v[src].second != -19) postorder(v, v[src].second);
	cout << char(src + 65);
}

int main() {
	
	int N;
	char a, b, c;
	v.resize(26);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v[int(a - 65)] = { int(b-65), int(c-65) };
	}
	preorder(v,0);
	cout << endl;
	inorder(v, 0);
	cout << endl;
	postorder(v, 0);
	//cout << int('.' - 65); -19
	return 0;
}

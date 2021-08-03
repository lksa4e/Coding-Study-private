#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <cctype>
#include <sstream>
#pragma warning(disable:4996)

#define endl '\n';
#define all(x)
#define INF int(1e9)
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define txtcin freopen("input.txt", "r", stdin);
#define txtout freopen("output.txt", "w", stdout);
#define fst first
#define snd second

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int T, N, M;
string s, str;
stringstream in;
using namespace std;
int main() {
	fastio;
	txtcin;
	cin >> T;
	cin.ignore();
	vector<string> v;
	for (int i = 1; i <= T; i++) {
		v.clear();
		getline(cin, s);
		in.str(s);
		while (in >> str) {
			v.push_back(str);
		}
		cout << "Case" << " " << "#" << i << ": ";
		for (int j = v.size() - 1; j >= 0; j--) {
			cout << v[j] << " ";
		}
		cout << endl;
		in.clear();
	}

	return 0;
}

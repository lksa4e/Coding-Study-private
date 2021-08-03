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

int T,N,M;
using namespace std;
int main() {
	fastio;
	string s;
	cin >> T;
	cin.ignore();
	while (T--) {
		int sum = 0;
		string temp = "";
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				sum += stoi(temp);
				temp = "";
			}else {
				temp += s[i];
			}
		}
		if (temp != "") sum += stoi(temp);
		cout << sum << endl;
	}
	return 0;
}

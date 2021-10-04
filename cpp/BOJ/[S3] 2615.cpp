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
int N, a, b;
stringstream in;

using namespace std;

bool cmp(pii p1, pii p2) {
	if (p1.fst == p2.fst) return p2.snd > p1.snd;
	else return p1.fst < p2.fst;
}
// 우상,우,우하,하
int dx[4] = {-1,0,1,1 };
int dy[4] = {1,1,1,0};
bool oob(int x, int y) {
	return x < 0 || x >= 19 || y < 0 || y >= 19;
}
bool is_five(int x, int y, int color, vector<vector<int>>& v) {
	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;
		int cnt = 1;
		while (true) {
			nx += dx[i];
			ny += dy[i];
			if (oob(nx, ny)) break;
			if (v[nx][ny] != color) break;
			cnt++;
			if (cnt > 5) break;
		}
		if (cnt == 5) {
			if (!oob(x - dx[i], y - dy[i])) {
				if (v[nx - dx[i]][ny - dy[i]] == v[x - dx[i]][y - dy[i]]) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
int main() {
	fastio;
	vector<vector<int>> v;
	int answer = 0;
	int answer_idx[2] = { 0,0 };
	for (int i = 0; i < 19; i++) {
		vector<int> temp;
		for (int j = 0; j < 19; j++) {
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}

		int flag = 0;
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (v[i][j] == 1 || v[i][j] == 2) {
					if (is_five(i, j, v[i][j], v) == true) {
						answer = v[i][j];
						answer_idx[0] = i;
						answer_idx[1] = j;
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break;
		}
	cout << answer << endl;
	if (answer != 0) {
		cout << answer_idx[0]+1 << " " << answer_idx[1]+1;
	}
	return 0;
}

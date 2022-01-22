#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 60;
using ll = long long;

int n, m;
char cell[MAX_N][MAX_N];
int dist[MAX_N][MAX_N][MAX_N * MAX_N];
string str;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int getId(char c) {
	if(c == 'L')
		return 0;
	if(c == 'R')
		return 1;
	if(c == 'U')
		return 2;
	return 3;
}

bool isIn(int r, int c) {
	return (0 <= r && r < n) && (0 <= c && c < m);
}

int main() {
	for(int i = 0; i < MAX_N; i++)
		for(int j = 0; j < MAX_N; j++)
			for(int k = 0; k < MAX_N * MAX_N; k++)
				dist[i][j][k] = (int)1e9;

	cin >> n >> m;

	int gr = -1, gc = -1, sr = -1, sc = -1;
	for(int i = 0; i < n; i++) {
		cin >> cell[i];

		for(int j = 0; j < m; j++) {
			if(cell[i][j] == 'S')
				sr = i, sc = j;
			if(cell[i][j] == 'G')
				gr = i, gc = j;
		}
	}

	cin >> str;

	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int> >, greater<tuple<int, int, int, int> > > pque;

	dist[0][sr][sc] = 0;
	pque.push({dist[0][sr][sc], 0, sr, sc});

	while(!pque.empty()) {
		tuple<int, int, int, int> cur = pque.top();
		pque.pop();

		int du = get<0>(cur);
		int idx = get<1>(cur);
		int r = get<2>(cur);
		int c = get<3>(cur);

		//cerr << "Cac: " << idx << ' ' << r << ' ' << c << ' ' << dist[idx][r][c] << '\n';

		if(r == gr && c == gc) {
			cout << dist[idx][r][c] << '\n';
			return 0;
		}

		if(idx < (int)str.length()) {
			int id = getId(str[idx]);
			int nextR = r + dr[id];
			int nextC = c + dc[id];

			if(isIn(nextR, nextC) && cell[nextR][nextC] != '#') {
				if(dist[idx + 1][nextR][nextC] > du) {
					dist[idx + 1][nextR][nextC] = du;
					pque.push({dist[idx + 1][nextR][nextC], idx + 1, nextR, nextC});
				}
			} else {
				if(dist[idx + 1][r][c] > du) {
					dist[idx + 1][r][c] = du;
					pque.push({dist[idx + 1][r][c], idx + 1, r, c});
				}
			}
		}

		for(int k = 0; k < 4; k++) {
			int nextR = r + dr[k];
			int nextC = c + dc[k];

			if(isIn(nextR, nextC) && cell[nextR][nextC] != '#') {
				if(dist[idx][nextR][nextC] > du + 1) {
					dist[idx][nextR][nextC] = du + 1;
					pque.push({dist[idx][nextR][nextC], idx, nextR, nextC});
				}
			}
		}

		if(idx + 1 < (int)str.length()) {
			if(dist[idx + 1][r][c] > du + 1) {
				dist[idx + 1][r][c] = du + 1;
				pque.push({dist[idx + 1][r][c], idx + 1, r, c});
			}
		}
	}

    return 0;
}

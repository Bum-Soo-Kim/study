#include <iostream>
#include <vector>

using namespace std;

int computer, con;
vector<vector<int>> v(101);
int chk[101];

int dfs(int idx) {
	// 방문 체크
	chk[idx] = 1;
	// 연결되어 있는 모든 요소 방문
	for (int i = 0; i < v[idx].size(); i++) {
		// 방문하지 않은 곳
		if (chk[v[idx][i]] != 1) {
			dfs(v[idx][i]);
		}
	}
	return 0;
}

int main() {

	cin >> computer >> con;
	for (int i = 0; i < con; i++) {
		int num, num2;
		cin >> num >> num2;
		// 이차원 배열로 그래프 표시
		v[num].push_back(num2);
		v[num2].push_back(num);
	}

	chk[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		if (chk[v[1][i]] != 1) {
			dfs(v[1][i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < 101; i++) {
		if (chk[i] == 1)
			ans++;
	}
	cout << ans - 1;
	return 0;
}

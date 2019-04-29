#include <stdio.h>
int map[1001][1001];
int dfsVisit[1001];
int bfsVisit[1001];
int queue[1001];

void DFS(int v, int N) {
	dfsVisit[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && dfsVisit[i] == 0) {
			DFS(i, N);
		}
	}
	return;
}

void BFS(int v, int N) {
	int front = 0, end = 0, pop;
	printf("%d ", v);
	queue[0] = v;
	end++;
	bfsVisit[v] = 1;
	while (front < end) {
		pop = queue[front];
		front++;

		for (int i = 1; i <= N; i++) {
			if (map[pop][i] == 1 && bfsVisit[i] == 0) {
				printf("%d ", i);
				queue[end] = i;
				end++;
				bfsVisit[i] = 1;
			}
		}
	}
	return;
}

int main() {
	int N, M, V, x, y;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 1;
		map[y][x] = 1;
	}
	DFS(V, N);
	printf("\n");
	BFS(V, N);
	return 0;
}
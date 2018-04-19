#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(int graph[][101], int check[], int n) {
	queue<int> que;
	int cnt = 0; //감염되는 컴퓨터의 수
	que.push(1);

	while (que.empty() != 1) {
		int front = que.front();
		que.pop();
		check[front] = 1;

		for (int j = 1; j <= n; j++) {
			if (check[j] != 1 && graph[front][j] == 1) {
				check[j] = 1;
				que.push(j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int main() {

	int n, connect;
	int check[101] = { 0, };

	cin >> n >> connect;

	int graph[101][101] = { 0, };

	for (int i = 1; i <= connect; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		graph[t1][t2] = 1;
		graph[t2][t1] = 1;
	}

	bfs(graph, check, n);

	return 0;
}
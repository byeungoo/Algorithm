﻿//백준 1260번

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		// 방문하지 않았다면
		if (check[next] == false) {
			// 재귀함수를 호출한다.
			dfs(next, graph, check);
		}
	}

}

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();

		for (int i = 0; i < graph[tmp].size();i++) {
			// 방문하지 않았다면
			if (check[graph[tmp][i]] == false) {
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}

	}
}


int main() {

	int n, m, start;
	cin >> n >> m >> start;
	vector<int> graph[1001]; //그래프를 나타낼 벡터
	vector<int> dfs_graph[1001]; 
	bool *check = new bool[n+1];  //방문 표시할 배열
	bool *dfs_check = new bool[n + 1];  
	fill(check, check + n + 1, false);  //algorithme 함수. 배열의 모든 원소의 값을 false로 채운다.
	fill(dfs_check, dfs_check + n + 1, false);  

	//그래프 초기화
	for (int i = 0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		dfs_graph[u].push_back(v);
		dfs_graph[v].push_back(u);
	}

	// 나중에 하나의 정점에서 다음을 탐색할 때 node 값에 순차적으로 접근해야하기 때문
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
		sort(dfs_graph[i].begin(), dfs_graph[i].end());
	}

	dfs(start, dfs_graph, dfs_check);
	cout << endl;
	bfs(start, graph, check);

	delete[] check;
	return 0;
}
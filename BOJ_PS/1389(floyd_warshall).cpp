//floyd-warshall algorithm- for all pairs shortest path 
#define INF 150
#include <iostream>
using namespace std;
int* bacon;
int** cost;

int floyd_warshall_bacon(int V, int E) {
	for (int t = 1; t <= V; t++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (i == j)
					continue;
				else {
					if (cost[i][t] + cost[t][j] < cost[i][j])
						cost[i][j] = cost[i][t] + cost[t][j];
				}
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		int sum = 0;
		for (int j = 1; j <= V; j++) {
			sum += cost[i][j];
		}
		bacon[i] = sum;
	}
	int min = bacon[V];
	int minidx = V;
	for (int i = V - 1; i > 0; i--) {
		if (min >= bacon[i]) {
			min = bacon[i];
			minidx = i;
		}
	}
	return minidx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int V, E;
	int src, dest;
	cin >> V >> E;
	bacon = new int[V + 1];
	for (int i = 0; i <= V; i++) {
		bacon[i] = INF;
	}
	cost = new int* [V + 1];
	for (int i = 0; i < V + 1; i++) {
		*(cost + i) = new int[V + 1];
	}
	for (int i = 0; i <= V; i++) {
		for (int j = 0; j <= V; j++) {
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		cin >> src >> dest;
		cost[src][dest] = 1;
		cost[dest][src] = 1;
	}
	cout << floyd_warshall_bacon(V, E) << '\n';
	for (int i = 0; i < V + 1; i++) {
		delete[] * (cost + i);
	}
	delete[] cost;
	delete[] bacon;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		vector<int> sorted_vtx;
		queue<int> vtxqueue;
		int N, K, src, dest, W;
		int tmp;
		int cost[1001];
		int indegree[1001];
		bool** adj_mat, ** adj_mat2;
		cin >> N >> K;
		adj_mat = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			*(adj_mat + i) = new bool[N + 1];
		}
		adj_mat2 = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			*(adj_mat2 + i) = new bool[N + 1];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj_mat[i][j] = 0;
				adj_mat2[i][j] = 0;
			}
			indegree[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> src >> dest;
			adj_mat[src][dest] = 1;
			adj_mat2[src][dest] = 1;
			indegree[dest]++;
		}
		cin >> W;

		for (int i = 1; i <= N; i++)
			if (!indegree[i]) {
				vtxqueue.push(i);
				indegree[i]--;
			}
		for (int i = 1; i <= N; i++) {
			if (vtxqueue.empty()) {
				cerr << "No DAG(Directed Acyclic Graph)" << '\n';
				exit(-1);
			}
			tmp = vtxqueue.front();
			sorted_vtx.push_back(tmp);
			vtxqueue.pop();
			for (int i = 1; i <= N; i++) {
				if (adj_mat[tmp][i]) {
					adj_mat[tmp][i] = false;
					indegree[i]--;
				}
			}
			for (int i = 1; i <= N; i++) {
				if (!indegree[i]) {
					vtxqueue.push(i);
					indegree[i]--;
				}
			}
		}
		vector<int>::iterator iter;
		vector<int>::iterator iter2;
		int nowcost;
		for (iter = sorted_vtx.begin(); iter != sorted_vtx.end(); iter++) {
			nowcost = cost[*iter];
			for (iter2 = sorted_vtx.begin(); iter2 != iter; iter2++) {
				if (adj_mat2[*iter2][*iter]) {
					if (cost[*iter] < cost[*iter2] + nowcost) {
						cost[*iter] = cost[*iter2] + nowcost;
					}
				}
			}
		}
		cout << cost[W] << '\n';
		for (int i = 0; i < N + 1; i++) {
			delete[] * (adj_mat + i);
		}
		delete[] adj_mat;
		for (int i = 0; i < N + 1; i++) {
			delete[] * (adj_mat2 + i);
		}
		delete[] adj_mat2;
	}
	return 0;
}
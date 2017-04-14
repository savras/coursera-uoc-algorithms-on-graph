#include "Bidijkstra.h"
#include "vector"

using std::vector;

int main() {
	int n, m;
	scanf_s("%d%d", &n, &m);
	Adj adj(2, vector<vector<int>>(n));
	Adj cost(2, vector<vector<int>>(n));
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf_s("%d%d%d", &u, &v, &c);
		adj[0][u - 1].push_back(v - 1);
		cost[0][u - 1].push_back(c);
		adj[1][v - 1].push_back(u - 1);
		cost[1][v - 1].push_back(c);
	}

	Bidijkstra bidij(n, adj, cost);

	int t;
	scanf_s("%d", &t);
	for (int i = 0; i < t; ++i) {
		int u, v;
		scanf_s("%d%d", &u, &v);
		printf("%lld\n", bidij.query(u - 1, v - 1));
	}
}
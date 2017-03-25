#include <iostream>
#include <vector>

using std::vector;

// Assume no negative cycle for now.
int negative_cycle(const vector<vector<int>> &adj, const vector<vector<int>> &cost) {
	int size = adj.size();
	vector<int> dist(size, INT_MAX);
	vector<int> prev(size, 0);

	dist[0] = 0;

	for (size_t u = 0; u < cost.size() - 1; u++) {
		for (size_t v = 0; v < cost[u].size() - v; v++) {
			int distance = dist[u] + cost[u][v];
			if (dist[v] > distance) {
				dist[v] = distance;
			}
		}
	}

	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cout << negative_cycle(adj, cost);
}
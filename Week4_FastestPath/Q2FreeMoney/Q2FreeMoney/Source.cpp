#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(const vector<vector<int>> &adj, const vector<vector<int>> &cost) {
	int size = adj.size();
	vector<int> dist(size, INT_MAX);
	vector<int> prev(size, 0);

	dist[0] = 0;
	int hasNegativeCycle = 0;

	//Loop V times (as opposed to V - 1 to detect negative edge cycles)
	for (size_t i = 0; i < size; i++) {		// O(|V|)
		// Relax all edges. Each entry in cost array is an edge weight and is therefore an edge.
		for (size_t u = 0; u < cost.size() - 1; u++) {	// O(|E|)
			for (size_t v = 0; v < cost[u].size(); v++) {
				int weight = dist[u] + cost[u][v];
				if (dist[adj[u][v]] > weight) {
					if (i == size -1) {
						return 1;
					}
					dist[adj[u][v]] = weight;
					prev[adj[u][v]] = u;
				}
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
#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(const vector<vector<int> > &adj, const vector<vector<int> > &cost) {
	int size = adj.size();
	vector<int> dest(size, INT_MAX);
	vector<int> prev(size, INT_MAX);

	dest[0] = 0;

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
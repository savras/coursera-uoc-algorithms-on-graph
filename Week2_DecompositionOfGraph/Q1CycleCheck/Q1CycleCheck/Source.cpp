#include <iostream>
#include <unordered_set>
#include <vector>

using std::vector;
using std::pair;
using std::unordered_set;

bool explore(const vector<vector<int>> &adj, unordered_set<int> &visited, int v) {
	int size = adj[v].size();
	visited.insert(v);
	bool hasCycle = false;

	for (size_t i = 0; i < size; i++) {
		if (visited.find(adj[v][i]) == visited.end()) {
			hasCycle = explore(adj, visited, adj[v][i]);
		}
		else {
			hasCycle = true;
		}
	}	

	visited.erase(v);
	return hasCycle;
}

int acyclic(vector<vector<int> > &adj) {
	unordered_set<int> visited;

	bool hasCycle;
	for (size_t i = 0; i < adj.size(); i++) {
		hasCycle = explore(adj, visited, i);
	}

	return hasCycle ? 1 : 0;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	std::cout << acyclic(adj);
}

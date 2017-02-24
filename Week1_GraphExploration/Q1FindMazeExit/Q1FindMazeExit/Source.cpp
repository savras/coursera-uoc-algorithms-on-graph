#include <iostream>
#include <vector>
#include <unordered_set >

using std::vector;
using std::pair;
using std::unordered_set;

void explore(vector<vector<int>> &adj, unordered_set<int> &visited, int v) {
	int size = adj[v].size();

	visited.insert(v);
	for (size_t i = 0; i < size; i++) {		
		std::unordered_set<int>::const_iterator got;
		got = visited.find(adj[v][i]);
		if (got == visited.end()) {
			explore(adj, visited, adj[v][i]);
		}
	}
}

int reach(vector<vector<int>> &adj, int x, int y) {	
	unordered_set<int> visited;
	explore(adj, visited, x);

	std::unordered_set<int>::const_iterator got = visited.find(y);
	if (got == visited.end()) {
		return 0;
	}
	return 1;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);
}

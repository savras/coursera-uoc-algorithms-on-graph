// This solution seems to give a valid topological sort based on https://en.wikipedia.org/wiki/Topological_sorting#Depth-first_search
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
using std::find;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {

	// Guaranteed acyclic so we don't need to optimize using a temporary visited list (See Q1 solution).
	if (used[x] == 0) {
		int size = adj[x].size();
		used[x] = 1;
		for (size_t i = 0; i < size; i++) {			
			dfs(adj, used, order, adj[x][i]);
		}
		order.push_back(x);
	}	
}

vector<int> toposort(vector<vector<int> > adj) {
	vector<int> used(adj.size(), 0);
	vector<int> order;
	
	for (size_t i = 0; i < adj.size(); i++) {
		dfs(adj, used, order, i);
	}

	return order;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	vector<int> order = toposort(adj);
	for (int i = order.size() - 1; i >= 0 ; i--) {
		std::cout << order[i] + 1 << " ";
	}
}

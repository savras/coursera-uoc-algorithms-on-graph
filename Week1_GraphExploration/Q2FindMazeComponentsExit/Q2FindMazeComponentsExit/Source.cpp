#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;

void explore(const vector<vector<int>> &adj, unordered_set<int> &visited, int v) {
	int size = adj[v].size();
	visited.insert(v);
	
	for (size_t i = 0; i < size; i++) {
		int neighbour = adj[v][i];
		if (visited.find(neighbour) == visited.end()) {
			explore(adj, visited, neighbour);
		}
	}	
};

int number_of_components(vector<vector<int> > &adj) {
	unordered_set<int> visited;
	int res = 0;
	
	for (size_t i = 0; i < adj.size(); i++) {
		if (visited.find(i) == visited.end()) {			
			explore(adj, visited, i);
			res++;
		}
	}	

	return res;
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
	std::cout << number_of_components(adj);
}

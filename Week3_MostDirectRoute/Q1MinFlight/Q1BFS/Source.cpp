#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::vector;
using std::queue;

int distance(const vector<vector<int>> &adj, const int &s, const int &t) {
	queue<int> q;
	vector<int> dist(adj.size(), INT_MAX);	// Assume nodes are numbered in order from 0 to n. I.e equivalent to alphabetically sorting city names. Edge weight and direction stays the same.

	dist[s] = 0;	// Contains distances to other nodes from s ONLY.

	q.emplace(s);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		int neighbours = adj[u].size();

		for (size_t i = 0; i < neighbours; i++) {
			if (dist[adj[u][i]] == INT_MAX)
			{
				q.emplace(adj[u][i]);
				dist[adj[u][i]] = dist[u] + 1;
			}
		}
	}	

	return dist[t];
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, s, t);
}

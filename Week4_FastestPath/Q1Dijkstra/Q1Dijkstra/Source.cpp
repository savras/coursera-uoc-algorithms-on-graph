#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;

int distance(const vector<vector<int>> &adj, const vector<vector<int>> &cost, const int &s, const int &t) {
	int size = adj.size();
	vector<int> dist(size, INT_MAX);
	vector<int> prev(size, -1);
	priority_queue<pair<int, int>> q;

	dist[s] = 0;
	pair<int, int> u;

	pair<int, int> ps = make_pair(s, dist[s]);
	q.push(ps);	

	while (!q.empty()) {
		u = q.top();
		q.pop();

		for (size_t i = 0; i < adj[u.first].size(); i++) {
			int v = adj[u.first][i];
			int d = dist[u.first] + cost[u.first][i];
			if (dist[adj[u.first][i]] > d) {
				dist[adj[u.first][i]] = d;
			}
			q.emplace(make_pair(adj[u.first][i], d));
		}
	}	

	return 0;
	
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	vector<vector<int>> cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, cost, s, t);
}

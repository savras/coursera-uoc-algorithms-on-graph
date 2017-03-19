/*
 * Priority Queues - Min Heap with STL: 
 * http://stackoverflow.com/questions/649640/how-to-do-an-efficient-priority-update-in-stl-priority-queue
 * http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
 * http://quiz.geeksforgeeks.org/implement-min-heap-using-stl/
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;
using std::greater;

int extractMin(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &H) {
	pair<int,int> minPair = H.top();
	H.pop();

	return minPair.second;
}

int distance(const vector<vector<int>> &adj, const vector<vector<int>> &cost, const int &s, const int &t) {
	int size = adj.size();
	vector<int> dist(size, INT_MAX);
	vector<int> prev(size, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> H;	// Holds nodes NOT in the known region.

	dist[s] = 0;
	pair<int, int> ps = make_pair(dist[s], s);
	H.push(ps);	

	pair<int, int> u;
	while (!H.empty()) {
		int u = extractMin(H);		

		for (size_t i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			int d = dist[u] + cost[u][i];
			if (dist[v] > d) {
				dist[v] = d;
				prev[v] = u;
				H.push(make_pair(dist[v], v));				
			}			
		}
	}	

	int result = dist[t] == INT_MIN ? -1 : dist[t];
	return result;	
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

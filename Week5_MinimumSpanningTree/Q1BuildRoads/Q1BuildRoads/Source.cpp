#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <functional>

using std::vector;
using std::priority_queue;
using std::pair;
using std::sqrt;
using std::make_pair;
using std::greater;

double length_of_segments(const int &p1, const int &p2, const vector<int> &x, const vector<int> &y) {
	int weight = sqrt((x[p1] - x[p2]) + (y[p1] - y[p2]));
	return weight;
}

void build_adj(vector<vector<double>> &cost, const vector<int> &x, const vector<int> &y) {
	int size = x.size();
	for (size_t i = 0; i < size; i++) {
		for (size_t p = i + 1; p < size; p++) {
			double weight = length_of_segments(i, p, x, y);
			cost[i][p] = cost[p][i] = weight;
		}
	}
}

// Kruskal's
double minimum_distance_kruskal(vector<int> x, vector<int> y) {
	return 0.0;
}

double calc_minimum_distance(const vector<int> &dist) {
	double result = 0.0;
	for (size_t i = 0; i < dist.size(); i++) {
		result += dist[i];
	}

	return result;
}

// Prim's using priority heap
double minimum_distance_prim(vector<int> x, vector<int> y) {
	int size = x.size();
	vector<vector<double>> cost(size, vector<double>(size, 0));
	build_adj(cost, x, y);	
	
	vector<int> dist(size, INT_MAX);	
	dist[0] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> H;	// Min heap STL.
	H.push(make_pair(0, 0));
	
	while (!H.empty()) {
		int u = H.top().second;	// vertex index is stored as second value.
		H.pop();

		int d = dist[u];
		for (size_t m = 0; m < size; m++) {
			int v = m;
			int c = cost[u][m];
			if (c < dist[v]) {
				dist[v] = d;
				H.push(make_pair(c, v));
			}
		}
	}

	return calc_minimum_distance(dist);
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << std::setprecision(10) << minimum_distance_prim(x, y) << std::endl;
}

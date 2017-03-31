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
using std::make_pair;
using std::greater;

double build_adj(vector<vector<int>> &adj, const vector<int> &x, const vector<int> &y) {
	return 0.0;
}

double length_of_segments() {
	return 0.0;
}

double minimum_distance(vector<int> x, vector<int> y) {
	vector<vector<int>> adj;
	build_adj(adj, x, y);

	double result = 0.;

	vector<int> dist;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> H;	// Holds nodes NOT in the known region.



	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

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
	//write your code here
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

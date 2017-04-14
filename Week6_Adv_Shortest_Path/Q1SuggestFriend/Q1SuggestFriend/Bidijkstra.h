#include <vector>
#include <queue>
#include <cstdio>
#include <cassert>
#include <functional>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

typedef std::vector<std::vector<std::vector<int>>> Adj;

// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
typedef long long Len;

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
typedef std::vector<std::priority_queue<std::pair<Len, int>, std::vector<std::pair<Len, int>>, std::greater<std::pair<Len, int>>>> Queue;

// Distances can grow out of int type
class Bidijkstra {
	const Len INF = std::numeric_limits<Len>::max() / 4;

	// Number of nodes
	int n_;

	// Graph adj_[0] and cost_[0] correspond to the initial graph,
	// adj_[1] and cost_[1] correspond to the reversed graph.
	// Graphs are stored as vectors of adjacency lists corresponding
	// to nodes.
	// Adjacency list itself is stored in adj_, and the corresponding
	// edge costs are stored in cost_.
	Adj adj_;
	Adj cost_;

	// distance_[0] stores distances for the forward search,
	// and distance_[1] stores distances for the backward search.
	std::vector<std::vector<Len>> distance_;

	// Stores all the nodes visited either by forward or backward search.
	std::vector<int> workset_;

	// Stores a flag for each node which is True iff the node was visited
	// either by forward or backward search.
	std::vector<bool> visited_;

public:
	Bidijkstra(int n, Adj adj, Adj cost)
		: n_(n), adj_(adj), cost_(cost), distance_(2, std::vector<Len>(n, INF)), visited_(n)
	{
		workset_.reserve(n);
	}

	// Initialize the data structures before new query,
	// clear the changes made by the previous query.
	void clear();

	// Processes visit of either forward or backward search 
	// (determined by value of side), to node v trying to
	// relax the current distance by dist.
	void visit(Queue& q, int side, int v, Len dist);

	// Returns the distance from s to t in the graph.
	Len query(int s, int t);
};
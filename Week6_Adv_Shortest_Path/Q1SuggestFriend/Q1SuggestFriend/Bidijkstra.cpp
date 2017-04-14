#include "Bidijkstra.h"
#include "queue"

using std::queue;

Len Bidijkstra::query(int s, int t) {
	clear();
	Queue q(2);
	visit(q, 0, s, 0);
	visit(q, 1, t, 0);
	// Implement the rest of the algorithm yourself

	return -1;
}

void Bidijkstra:: visit(Queue& q, int side, int v, Len dist) {
	// Implement this method yourself
}

void Bidijkstra::clear()  {
	for (int i = 0; i < workset_.size(); ++i) {
		int v = workset_[i];
		distance_[0][v] = distance_[1][v] = INF;
		visited_[v] = false;
	}
	workset_.clear();
}
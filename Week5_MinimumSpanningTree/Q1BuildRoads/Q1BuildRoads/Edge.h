/**
 * Data structure to facilitate easy sorting of edge weights for Kruskal's algorithm
 */
#pragma once

class Edge
{
	int _nodeOne;
	int _nodeTwo;
	double _weight;

public:
	Edge::Edge(const int &nodeOne, const int &nodeTwo, const int &weight)
		: _nodeOne(nodeOne), _nodeTwo(nodeTwo), _weight(weight) {};
	int GetNodeOne();
	int GetNodeTwo();
	double GetWeight();

	bool operator > (const Edge& edge) const
	{
		return (_weight > edge._weight);
	}
};


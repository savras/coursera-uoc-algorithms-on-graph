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
	Edge(int nodeOne, int nodeTwo, int weight) : _nodeOne(nodeOne), _nodeTwo(nodeTwo), _weight(weight) {};
	int GetNodeOne();
	int GetNodeTwo();
	double GetWeight();	
};


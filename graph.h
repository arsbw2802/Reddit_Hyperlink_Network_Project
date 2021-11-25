#pragma once

#include "vector.h"
#include "edge.h"
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;


class Graph {
	public:
		Graph(vector<Vertex> target, vector<Vertex> source, vector<Vertex> sentiment);
		
		// create a map
		void assignID(vector<Vertex> target, vector<Vertex> source);

		vector<int> findAdjacentVertices(int vertex, int flag);

	private:
		// adjacency matrix (2D vector of edge pointers)
		vector<vector<Edge*>> _AdjacencyMatrix;
	
		map<string, int> map_UniqueID;


		

};
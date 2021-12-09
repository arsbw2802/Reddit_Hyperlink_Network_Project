#pragma once

#include "vertex.h"
#include "edge.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::string;
using std::map;


class Graph {
	public:
		Graph(vector<Vertex> target, vector<Vertex> source, vector<int> sentiment);
		
		// create a map
		void assignID(vector<Vertex> target, vector<Vertex> source);

		vector<int> findAdjacentVertices(int vertex, int flag);

		Vertex pageRank(int max_iteration);

		void printMatrix();

	private:
		// adjacency matrix (2D vector of edge pointers)
		vector<vector<Edge*>> _AdjacencyMatrix;
	
		map<string, int> map_UniqueID;


		

};

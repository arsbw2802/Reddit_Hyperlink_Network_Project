#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class Graph {
	public:
		Graph(vector<Vertex> target, vector<Vertex> source, vector<Vertex> sentiment);
		
		// create a map
		void assignID(vector<Vertex> target, vector<Vertex> source);

		vector<int> findAdjacentVertices(int vertex, int flag);

	private:
		// adjacency matrix (2D vector of edge pointers)
		vector<vector<>>;

		std::map<string, int> map_UniqueID;


		

};
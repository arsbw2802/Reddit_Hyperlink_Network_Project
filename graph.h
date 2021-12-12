#pragma once

#include "vertex.h"
#include "edge.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using std::vector;
using std::string;
using std::map;

typedef std::pair<int, int> vPair;

class Graph {
	public:
		/**
           * Constructor for Graph class that constructs graph instance based on target reddits, source reddits, and sentiments
           * Initialize the _AdjacencyMatrix and map_UniqueID (by calling assignID()) private variables
           * @param target - vector of all target nodes
		   * @param source - vector of all source nodes
		   * @param sentiment - vector of sentiments
        **/
		Graph(vector<Vertex> target, vector<Vertex> source, vector<int> sentiment);
		
		/**
           * Initialize map_UniqueID/ assign uniqueIDs to all the vertices from target and source
           * @param target - vector of all target nodes
		   * @param source - vector of all source nodes
		   * @param sentiment - vector of sentiments
        */
		void assignID(vector<Vertex> target, vector<Vertex> source);

		/**
           * Find adjacent vertices of a given vertex and a flag (outgoing/ incoming)
           * @param vertex - the vertex from which to find the incoming or outgoing nodes
		   * @param flag - Decides whether to find outgoing or incoming nodes
           * @return a vector of adjacent vertices of the specified vertex
        */
		vector<int> findAdjacentVertices(int vertex, int flag);

		/**
           * Given a certain number of iterations, the function will compute the pageRank value of every vertex within the graph
           * @param max_iteration- the number of iterations
           * @return a vector of pageRank values of all the vertices within the graph, indexed by the uniqueIDs of the vertices
        */
		vector<double> pageRank(int max_iteration);

		/**
           * Given a the uniqueID of the start vertex, the function will compute the shortest distance from every other vertices
           * within the graph to that start vertex
           * @param startID - the uniqueID of the starting node
           * @return a vector of distances, indexed by the uniqueIDs of the vertices
        */
		vector<int> dijkstra(int startID);

		vector<int> BFS(int source);

		void printMatrix();

		string get_Subreddit_ID(int index);

		int get_Unique_ID(string reddit);

	private:
		// adjacency matrix (2D vector of edge pointers)
		vector<vector<Edge*>> _AdjacencyMatrix;

		// map subreddits name to uniqueIDs
		map<string, int> map_UniqueID;

		vector<string> _subreddit_map;

};

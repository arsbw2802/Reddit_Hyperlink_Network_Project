#pragma once

#include "vertex.h"
#include "edge.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

#define MAX_DISTANCE 	10000

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
		
		Graph();

		~Graph();
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

		/**
		* Given the uniqueID of the source vertex, this function will run BFS on that 
		* source vertex and return a vector of uniqueIDs that BFS traverses through
		* @param int source
		* @return vector<int> vector of uniqueID of the subreddit traversed
		**/
		vector<int> BFS(int source);

		/**
		* Given the uniqueID of the specific vertex, return the subreddit string of
		* the corresponding uniqueID
		* @param int index
		* @return string subreddit title
		**/
		string get_Subreddit_ID(int index);

		/**
		* Given string of subreddit title, return the subreddit uniqueID of the
		* the corresponding string of subreddit title
		* @param string reddit
		* @return int index
		*/
		int get_Unique_ID(string reddit);

		/**
		* Return the map that stores the uniqueID & subreddit pair
		* @return map<string, int>
		*/
		map<string, int> * get_map() ;

	private:
		// adjacency matrix (2D vector of edge pointers)
		vector<vector<Edge*>> _AdjacencyMatrix;

		// map subreddits name to uniqueIDs
		map<string, int> map_UniqueID;

		// vector to store subreddits in 
		vector<string> _subreddit_map;

};

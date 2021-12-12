#include "read_tsv.h"
#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	// create vectors for target, source, and sentiment
	vector<string> target_data, source_data, sentiment_data;
	// parse data and put into vectors
	read_data(target_data, source_data, sentiment_data);
	
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	// int temp;
	// for (unsigned i = 0; i < target_data.size(); i++) {
	for (unsigned i = 0; i < NUM_COLS; i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		// sentiment.push_back((int)sentiment_data[i]);
	}
	cout << "finished converting vertex\n";
	// cout << sentiment[0] << endl;
	Graph full_graph = Graph(target, source, sentiment);
	// Graph short_graph = Graph(target, source, sentiment);
	// short_graph.printMatrix();

	// BFS traversal
	// vector<int> BFS_output = short_graph.BFS(0);
	// for (auto & it : BFS_output) {
	// 	cout << it;
	// }

	int start_vertex = 0;
	for (int i = 0; i < 1; i++) {
		// int start_vertex = rand() % NUM_COLS;
		// start_vertex = 0;
		vector <int> BFS_output = full_graph.BFS(start_vertex);
		cout << "\nBFS Traversal #" << start_vertex << endl;
		for (vector<int>::iterator it = BFS_output.begin(); it != BFS_output.end(); ++it) {
			cout << *it << " \n";
		}
	}
	
	cout << full_graph.get_Subreddit_ID(start_vertex);
	
	return 0;
}

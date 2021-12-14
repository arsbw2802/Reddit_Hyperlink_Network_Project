#include "read_tsv.h"
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "user_interface.h"

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

	// prompt user for input
	int dataset = 2;
	while (dataset < 0 || dataset > 1) {
		cout << "Please select a reddit dataset: 0 for title, 1 for body" << endl;
		cin >> dataset;
	}
	// parse data and put into vectors
	read_data(target_data, source_data, sentiment_data, dataset);
	
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	// int temp;
	// for (unsigned i = 0; i < target_data.size(); i++) {
	for (unsigned i = 0; i < NUM_COLS; i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		if (stoi(sentiment_data[i]) == -1)
			sentiment.push_back(3);
		else sentiment.push_back(1);
		// sentiment.push_back((int)sentiment_data[i]);
	}
	cout << "Finished converting strings to vertices\n\n";

	Graph full_graph = Graph(target, source, sentiment);
	get_user_input(&full_graph);

	
	return 0;
}

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
	vector<string> target, source, sentiment;
	// source.resize(1);
	// target.resize(1);
	// sentiment.resize(1);
	read_data(target, source, sentiment);

	// Graph(target, source, sentiment);

	return 0;
}

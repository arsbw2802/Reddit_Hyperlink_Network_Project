#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"graph.h"
#include"edge.h"
#include"vertex.h"


#include <vector>

// default constructor
TEST_CASE("Page rank 1") {
    vector<string> source_data = {"A", "A", "C", "C", "C","B", "D"};
	vector<string> target_data = {"C", "B", "A", "B", "D","D", "C"};
	vector<string> sentiment_data = {"-1", "-1", "-1", "-1", "-1","-1", "1"};
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	
	
	for (unsigned i = 0; i < source_data.size(); i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		
	}

	Graph short_graph = Graph(target, source, sentiment);

    vector<double> ranks = short_graph.pageRank(2);

    REQUIRE(ranks[0] == 0.375);
    REQUIRE(ranks[1] ==  Approx(0.166667));
    REQUIRE(ranks[2] ==  0.125);
    REQUIRE(ranks[3] == Approx(0.33333333));
}

TEST_CASE("Dijkstra") {
    vector<string> source_data = {"A", "A", "D", "D", "B","B", "E"};
	vector<string> target_data = {"B", "D", "B", "E", "E","C", "C"};
	vector<string> sentiment_data = {"3", "1", "1", "3", "1","3", "1"};
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	
	
	for (unsigned i = 0; i < source_data.size(); i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		
	}

	Graph short_graph = Graph(target, source, sentiment);

    vector<int> ranks = short_graph.dijkstra(4);
    REQUIRE(ranks[0] == 2);
    REQUIRE(ranks[1] ==  1);
    REQUIRE(ranks[2] ==  3);
    REQUIRE(ranks[3] == 4);
	REQUIRE(ranks[4] == 0);
}
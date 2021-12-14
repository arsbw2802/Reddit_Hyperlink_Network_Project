#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"graph.h"
#include"edge.h"
#include"vertex.h"


#include <vector>


TEST_CASE("BFS w/ small graph") {
    vector<string> source_data = {"C", "A", "D", "B", "C"};
	vector<string> target_data = {"A", "D", "B", "C", "D"};
	vector<string> sentiment_data = {"3", "1", "1", "3", "1"};
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	for (unsigned i = 0; i < source_data.size(); i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		
	}

	Graph small_graph = Graph(target, source, sentiment);

    vector<int> BFS = small_graph.BFS(0);

    REQUIRE(BFS[0] == 0);
    REQUIRE(BFS[1] == 1);
    REQUIRE(BFS[2] == 2);
    REQUIRE(BFS[3] == 3);
	
}


TEST_CASE("BFS w/ medium graph") {
    vector<string> source_data = {"A", "A", "B", "B", "C", "D", "E", "E", "E", "F"};
	vector<string> target_data = {"B", "C", "C", "D", "D","E", "B", "A", "F", "D"};
	vector<string> sentiment_data = {"3", "1", "1", "3", "1","3", "1", "1", "1", "3"};
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	for (unsigned i = 0; i < source_data.size(); i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		
	}

	Graph med_graph = Graph(target, source, sentiment);

    vector<int> BFS = med_graph.BFS(4);

    REQUIRE(BFS[0] == 4);
    REQUIRE(BFS[1] ==  0);
    REQUIRE(BFS[2] ==  1);
    REQUIRE(BFS[3] == 2);
	REQUIRE(BFS[4] == 3);
	REQUIRE(BFS[5] == 5);
}

TEST_CASE("BFS w/ big graph") {
    vector<string> source_data = {"A", "B", "C", "C", "D", "D", "E", "F", "F", "G", "G", "H", "I", "J", "J"};
	vector<string> target_data = {"C", "F", "D", "I", "B", "E", "F", "C", "J", "E", "H", "D", "G", "G", "A"};
	vector<string> sentiment_data = {"3", "1", "1", "3", "1","3", "1", "1", "1", "3", "3", "1", "1", "3", "1"};
	vector<Vertex> source, target;
	vector<int> sentiment;
	
	for (unsigned i = 0; i < source_data.size(); i++) {
		source.push_back(Vertex(source_data[i]));			// convert source and target strings to Vertices
		target.push_back(Vertex(target_data[i]));
		sentiment.push_back(stoi(sentiment_data[i]));
		
	}

	Graph big_graph = Graph(target, source, sentiment);

    vector<int> BFS = big_graph.BFS(9);

    REQUIRE(BFS[0] == 9);
    REQUIRE(BFS[1] == 0);
    REQUIRE(BFS[2] == 2);
    REQUIRE(BFS[3] == 3);
	REQUIRE(BFS[4] == 4);
	REQUIRE(BFS[5] == 5);
	REQUIRE(BFS[6] == 8);
    REQUIRE(BFS[7] == 1);
    REQUIRE(BFS[8] == 7);
    REQUIRE(BFS[9] == 6);
}


TEST_CASE("Graph Constructor simple") {
    vector<string> source_data = {"A", "B"};
    vector<string> target_data = {"B", "A"};
    vector<string> sentiment_data = {"-1", "-1"};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
        target.push_back(Vertex(target_data[i]));
        sentiment.push_back(stoi(sentiment_data[i]));
        
    }

    Graph short_graph = Graph(target, source, sentiment);



    REQUIRE(short_graph.get_Subreddit_ID(0) == "B");
    REQUIRE(short_graph.get_Subreddit_ID(1) == "A");
    
    
}

TEST_CASE("Graph Constructor Empty") {
    vector<string> source_data = {};
    vector<string> target_data = {};
    vector<string> sentiment_data = {};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
        target.push_back(Vertex(target_data[i]));
        sentiment.push_back(stoi(sentiment_data[i]));
        
    }

    Graph short_graph = Graph(target, source, sentiment);


    REQUIRE(short_graph.get_map()->size() == 0);    
    
}

TEST_CASE("Page rank simple") {
    vector<string> source_data = {"A", "B"};
    vector<string> target_data = {"B", "A"};
    vector<string> sentiment_data = {"-1", "-1"};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
        target.push_back(Vertex(target_data[i]));
        sentiment.push_back(stoi(sentiment_data[i]));
        
    }

    Graph short_graph = Graph(target, source, sentiment);

    vector<double> ranks = short_graph.pageRank(5);

    REQUIRE(ranks[0] == 0.5);
    REQUIRE(ranks[1] ==  0.5);
    
}

TEST_CASE("Page rank complex") {
    vector<string> source_data = {"A", "A", "C", "C", "C","B", "D"};
    vector<string> target_data = {"C", "B", "A", "B", "D","D", "C"};
    vector<string> sentiment_data = {"-1", "-1", "-1", "-1", "-1","-1", "1"};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
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


TEST_CASE("Dijkstra simple") {
    vector<string> source_data = {"A", "A", "C"};
    vector<string> target_data = {"B", "C", "B"};
    vector<string> sentiment_data = {"3", "1", "1"};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
        target.push_back(Vertex(target_data[i]));
        sentiment.push_back(stoi(sentiment_data[i]));
        
    }

    Graph short_graph = Graph(target, source, sentiment);

    vector<int> ranks = short_graph.dijkstra(2);
    REQUIRE(ranks[0] == 2);
    REQUIRE(ranks[1] ==  1);
    REQUIRE(ranks[2] ==  0);
}

TEST_CASE("Dijkstra complex") {
    vector<string> source_data = {"A", "A", "D", "D", "B","B", "E"};
    vector<string> target_data = {"B", "D", "B", "E", "E","C", "C"};
    vector<string> sentiment_data = {"3", "1", "1", "3", "1","3", "1"};
    vector<Vertex> source, target;
    vector<int> sentiment;
    
    
    
    for (unsigned i = 0; i < source_data.size(); i++) {
        source.push_back(Vertex(source_data[i]));            // convert source and target strings to Vertices
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

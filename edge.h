#pragma once

#include <string>

using std::string;

class Edge {
	public:
		Edge();  // default constructor for Edge class
		~Edge(); // default destructior for Edge class
		Edge(int sentiment);  // constructor with sentiment input
		void setSentiment(int sentiment); // getters and setters for sentiment
		int getSentiment(); 

	private:
		int _sentiment;
};

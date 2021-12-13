#pragma once

#include <string>

using std::string;

class Edge {
	public:
		Edge();
		~Edge();
		Edge(int sentiment);
		void setSentiment(int sentiment); // getters and setters for sentiment
		int getSentiment();

	private:
		int _sentiment;
};

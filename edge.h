#pragma once

#include <string>

using std::string;

class Edge {
	public:
		void setWeight(int weight);
		double getWeight();

		void setSentiment(int sentiment);
		int getSentiment();

	private:
		double _weight;
		int _sentiment;


};

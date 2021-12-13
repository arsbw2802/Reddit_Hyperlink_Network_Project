#include "edge.h"

Edge::Edge() {
	_sentiment = 0;
}

Edge::~Edge() {
	_sentiment = 0;
}

Edge::Edge(int sentiment) {
	_sentiment = sentiment;
}

void Edge::setSentiment(int sentiment) {
	_sentiment = sentiment;
}

int Edge::getSentiment() {
	return _sentiment;
}

#include "edge.h"

void Edge::setWeight(int weight) {
	_weight = weight;
}

double Edge::getWeight() {
	return _weight;
}

void Edge::setSentiment(int sentiment) {
	_sentiment = sentiment;
}

int Edge::getSentiment() {
	return _sentiment;
}

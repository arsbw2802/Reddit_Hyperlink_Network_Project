#include "vertex.h"

#include <string>

using std::string;

void Vertex::setSubreddit(string subreddit) {
	_subreddit = subreddit;
}

string Vertex::getSubreddit() {
	return _subreddit;
}

void Vertex::setUniqueID(int ID) {
	_unique_ID = ID;
}

int Vertex::getUniqueID() {
	return _unique_ID;
}


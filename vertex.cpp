#include "vertex.h"

#include <string>

using std::string;

Vertex::Vertex(string subreddit) {
	_subreddit = subreddit;
}

void Vertex::setSubreddit(string subreddit) {
	_subreddit = subreddit;
}

string Vertex::getSubreddit() {
	return _subreddit;
}


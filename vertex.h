#pragma once

#include <string>

using std::string;

class Vertex {
	public:
		Vertex(string subreddit); // default contructor for vertex

		void setSubreddit(string subreddit); // getters and setters for subreddit
		string getSubreddit();
	
	private:
		string _subreddit;		// name of current subreddit
};

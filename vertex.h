#pragma once

#include <string>

using std::string;

class Vertex {
	public:
		void setSubreddit(string subreddit);
		string getSubreddit();
		int getUniqueID();
		void setUniqueID(int ID);
	
	private:
		string _subreddit;		// name of current subreddit
		int _unique_ID;
}
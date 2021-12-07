#pragma once

#include <string>

using std::string;

class Vertex {
	public:
		void setSubreddit(string subreddit);
		string getSubreddit();
		void setUniqueID(int ID);
		int getUniqueID();
	
	private:
		string _subreddit;		// name of current subreddit
		int _unique_ID;
};

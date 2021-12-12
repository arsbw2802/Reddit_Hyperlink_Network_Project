#pragma once 

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::endl;

#define SOURCE_COL		0
#define TARGET_COL		1
#define SENTIMENT_COL	4
#define NUM_COLS		34324

// int read_data();
void read_data(vector<string> &target, vector <string>&source, vector <string>&sentiment);

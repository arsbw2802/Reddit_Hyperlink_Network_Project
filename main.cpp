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

int main() {

	string filename, column, headers;
	vector<double> data, tempData;
	int numColumn;

	ifstream dataFile;
	cout << "enter a filename" << endl;
	cin >> filename;
	dataFile.open(filename);
	cout << "enter a column name" << endl;
	cin >> column;
	cout << "reading column " << column << " from " << filename;
	getline(dataFile, headers);

	//here's where I feel stuck
	while(!dataFile.eof()) {
		std::string str;
		std::getline( dataFile, str);
		std::stringstream buffer(str);
		std::string temp;
		std::vector<double> values;

		while( getline( buffer, temp, '\t') ) {
			values.push_back( ::strtod(temp.c_str(), 0));
		}

		data.push_back(values[numColumn]);
	}

	return 0;
}

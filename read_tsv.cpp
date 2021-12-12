#include "read_tsv.h"


// int main() {
void read_data(vector<string> &target, vector <string>&source, vector <string>&sentiment) {

	string filename, column, headers;
	vector<double> data, tempData;
	// int numColumn = 0;

	ifstream dataFile;
	// cout << "enter a filename" << endl;
	// cin >> filename;
	filename = "reddit_title.tsv";
	dataFile.open(filename);
	// cout << "enter a column name" << endl;
	// cin >> column;
	cout << "reading column " << column << " from " << filename << endl;
	getline(dataFile, headers);
	
	cout << headers << endl;


	std::vector<string> values;
	while(!dataFile.eof()) {
		std::string str;
		std::getline( dataFile, str);
		std::stringstream buffer(str);
		std::string temp;
		
		while( getline( buffer, temp, '\t') ) {
			values.push_back(temp);
		}

		data.push_back(0);
	}
	unsigned num_cols = 6;
	// unsigned col_access = 1;

	// vector <string> source, target, sentiment;
	// vector<vector<string>> data;
	for (unsigned i = 0; i < values.size()/num_cols; i++) {
		// cout << values[num_cols*i + col_access] << endl;
		source.push_back(values[num_cols*i + SOURCE_COL]);				// extract data into source column vector
		target.push_back(values[num_cols*i + TARGET_COL]);				// target vector
		sentiment.push_back(values[num_cols*i + SENTIMENT_COL]);		// sentiment vector
	}

	// for (unsigned i = 0; i < NUM_COLS; i++) {						// printing data: Source, Target, Sentiment
	// 	cout << source[i] << " " << target[i] << " " << sentiment[i] << endl;
	// }

	// return 0;
}

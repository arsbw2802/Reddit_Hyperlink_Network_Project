#include "read_tsv.h"


void read_data(vector<string> &target, vector <string>&source, vector <string>&sentiment, int dataset) {
	string filename, column, headers; 	// local variables for processing

	ifstream dataFile;
	if (dataset == TITLE)
		filename = "reddit_title.tsv"; 	// depending on user input, use body or title dataset
	if (dataset == BODY)
		filename = "Reddit_body.tsv";

	dataFile.open(filename);			// open file and read data
	cout << "Reading column " << column << " from " << filename << endl;
	getline(dataFile, headers);
	
	cout << headers << endl << endl;	// print headers of file

	std::vector<string> values;
	while(!dataFile.eof()) {			// while not the end of file
		std::string str;
		std::getline( dataFile, str);
		std::stringstream buffer(str);
		std::string temp;
		
		while( getline( buffer, temp, '\t') ) {
			values.push_back(temp);		// parse arguments and remove the tabs, storing into 1D array
		}
	}

	unsigned num_cols = 6;				// number of columns in the data

	for (unsigned i = 0; i < values.size()/6; i++) {					
		source.push_back(values[num_cols*i + SOURCE_COL]);				// extract data into source column vector
		target.push_back(values[num_cols*i + TARGET_COL]);				// target vector
		sentiment.push_back(values[num_cols*i + SENTIMENT_COL]);		// sentiment vector
	}

}

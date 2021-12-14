#include "user_interface.h"

void get_user_input(Graph * input_graph) {
	int algorithm = 0, BFS_start;

	while (algorithm < 1 || algorithm > 4) {
		cout << "Enter the number corresponding to the algorithm/output you wish to see:" << endl;
		cout << "(1) BFS" << endl;
		cout << "(2) Dijkstra's Shortest Path" << endl;
		cout << "(3) Page Rank" << endl;
		cout << "(4) Most Popular Reddit" << endl;

		cin >> algorithm;
	}

	switch (algorithm) { // 3845, 3858, 4512, 5142
		case 1: {
			int break_flag = 1;
			while (break_flag) {
				BFS_start = 8821;
				cout << endl << "(1) BFS will print the traversal from a given user input. Since the graph is not completely connected, certain starting vertices will have no neighbors.";
				while (BFS_start < 0 || BFS_start > 8820) {
					cout << endl << "Select a number from [0, 8820]" << endl;
					cin >> BFS_start;
				}

				vector<int> BFS_output = input_graph->BFS(BFS_start);
				cout << endl << endl;
				if (BFS_output.size() <= 1) {
					cout << "This subreddit has no connections. Try a different number to see if you can get a subreddit with connections!" << endl;
				}
					
				for (auto & it : BFS_output) {
					if (it != BFS_output[0]) {
						cout << "  |" << endl;
						cout << "  v" << endl;
						break_flag = 0;
					}
					cout << input_graph->get_Unique_ID(input_graph->get_Subreddit_ID(it)) << " " << input_graph->get_Subreddit_ID(it) << endl;
				}
			}
			break;
		}
		case 2: {
			// take in two inputs to see what the shortest path between them is
			// dijkstra will return a vector of distance to every vertex, from the starting
			// use the 2nd input to see if there's a shortest path between the start and "end"
			// print starting and ending subreddit, if path exists
			int dijkstra_start = 8821;
			int dijkstra_end = 8821;
			cout << endl << "(2) Dijkstra's Algorithm will return a vector of distance to every vertex in the graph. Given two vertices," << endl;
			cout << "the shortest path between them will be printed." << endl;
			while (dijkstra_start < 0 || dijkstra_start > 8820 || dijkstra_end < 0 || dijkstra_end > 8820) {
				cout << "Please enter two numbers from [0, 8820] (i.e. 27 934)" << endl;
				cin >> dijkstra_start;
				cin >> dijkstra_end;
			}

			vector<int> dijkstra_output = input_graph->dijkstra(dijkstra_start);
			if (dijkstra_output[dijkstra_end] == MAX_DISTANCE) {
				cout << input_graph->get_Subreddit_ID(dijkstra_start) << " is not connected to " << input_graph->get_Subreddit_ID(dijkstra_end) << endl;
			}
			else {
				cout << "The distance between " << input_graph->get_Subreddit_ID(dijkstra_start) << " and " << input_graph->get_Subreddit_ID(dijkstra_end) << " is " << dijkstra_output[dijkstra_end] << "." << endl;
			}

			break;
		}
		case 3: {
			// two inputs, # of iterations and unique ID, print page rank and subreddit name
			// explain page rank
			int page_rank_start = 8821;
			cout << endl << "(3) Page Rank will print the page rank value for a given vertex. The page rank value determines the probability " << endl;
			cout << "of reaching the vertex from anywhere in the graph." << endl;
			while (page_rank_start < 0 || page_rank_start > 8820) {
				cout << "Select a vertex from [0, 8820]" << endl;
				cin >> page_rank_start;
			}
			int iterations = 11;
			while (iterations < 0 || iterations > 10) {
				cout << endl << "Please enter a number from [1, 10] for the number of iterations. A higher number indicates higher accuracy of the Page Rank estimate." << endl;
				cout << "Also note that higher iteration values will take longer time to run, since Page Rank must traverse the whole graph." << endl;
				cin >> iterations;
			}

			vector<double> page_rank_output = input_graph->pageRank(iterations);
			if (page_rank_output[page_rank_start] == 0) 
				cout << "The page rank value of " << input_graph->get_Subreddit_ID(page_rank_start) << " is 0, because it is not connected." << endl;

			else {
				cout << "The page rank value of " << input_graph->get_Subreddit_ID(page_rank_start) << " is " << page_rank_output[page_rank_start] << endl;
			}
			break;
		}
		case 4: {
			cout << endl << "(4) Page Rank will find the most popular subreddit based on the number of iterations chosen." << endl;
			
			int iterations = 11;
			while (iterations < 0 || iterations > 10) {
				cout << endl << "Please enter a number from [1, 10] for the number of iterations. A higher number indicates higher accuracy of the Page Rank estimate." << endl;
				cout << "Also note that higher iteration values will take longer time to run, since Page Rank must traverse the whole graph." << endl;
				cin >> iterations;
			}

			vector<double> page_rank_output = input_graph->pageRank(iterations);
			int max = 0, index = 0;
			for (unsigned i = 0; i < page_rank_output.size(); i++) {
				if (page_rank_output[i] > max) {
					max = page_rank_output[i];
					index = i;
				}
			}
			cout << "The page rank value of " << input_graph->get_Subreddit_ID(index) << " is " << page_rank_output[index] << endl;
			cout << "This is the most popular subreddit, according to " << iterations << " iterations in the Page Rank algorithm" << endl;
			break;
		}
		default:
			cout << "ur mom";
	}
}

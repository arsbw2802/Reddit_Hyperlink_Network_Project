#include "user_interface.h"

void get_user_input(Graph * input_graph) {
	cout << "Enter the number corresponding to the algorithm/output you wish to see:" << endl;
	cout << "(1) BFS" << endl;
	cout << "(2) Dijkstra's Shortest Path" << endl;
	cout << "(3) Page Rank" << endl;

	int algorithm, BFS_start = 8821;
	cin >> algorithm;
	switch (algorithm) {
		case 1: {
			// while (1) {
			BFS_start = 8821;
			cout << endl << "(1) BFS will print the traversal from a given user input. Since the graph is not completely connected, certain starting vertices will have no neighbors.";
			while (BFS_start < 0 || BFS_start > 8820) {
				cout << endl << "Select a number from [0, 8820]" << endl;
				cin >> BFS_start;
			}

			vector<int> BFS_output = input_graph->BFS(BFS_start);
			cout << endl << endl;
			if (BFS_output.size() <= 1) {
				cout << "This subreddit has no connections." << endl;
			}
			for (auto & it : BFS_output) {
				if (it != BFS_output[0]) {
					cout << "  |" << endl;
					cout << "  v" << endl;
				}
				cout << input_graph->get_Unique_ID(input_graph->get_Subreddit_ID(it)) << " " << input_graph->get_Subreddit_ID(it) << endl;
				
			}
			// }
			// cout << input_graph->get_Unique_ID(input_graph->get_Subreddit_ID(BFS_output[0])) << " " << input_graph->get_Subreddit_ID(BFS_output[0]) << endl;
			break;
		}
		case 2: {
			cout << "ur mom 2";
			break;
		}
		case 3: {
			cout << "grandass";
			break;
		}
		default:
			cout << "ur mom";
	}
}

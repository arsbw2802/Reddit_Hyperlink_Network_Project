#include "graph.h"
#include <algorithm>

using std::vector;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::queue;

#define INCOMING 0
#define OUTGOING 1

Graph::Graph(vector<Vertex> target, vector<Vertex> source, vector<int> sentiment) {

    assignID(target, source);
    int size = map_UniqueID.size();
    for(int j = 0; j < size; j++){
        vector<Edge*> v;
        for(int i = 0; i < size; i++){
            v.push_back(NULL);
        }
        _AdjacencyMatrix.push_back(v);
    }

    for(int i = 0; i < target.size(); i++){
        string target_name = target[i].getSubreddit();
        int target_id = map_UniqueID[target_name];
        string source_name = source[i].getSubreddit();
        int source_id = map_UniqueID[source_name];

        Edge* e = new Edge();
        e->setSentiment(sentiment[i]);
        _AdjacencyMatrix[source_id][target_id] = e;
    }
}

void Graph::assignID(vector<Vertex> target, vector<Vertex> source) {
    int count = 0;
    for(int i = 0; i<target.size(); i++){
        if(map_UniqueID.find(target[i].getSubreddit()) == map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(target[i].getSubreddit(), count));
            _subreddit_map.push_back(target[i].getSubreddit());
            count++;
        }
    }

    for(int j = 0; j<source.size(); j++){
        if(map_UniqueID.find(source[j].getSubreddit()) == map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(source[j].getSubreddit(), count));
            _subreddit_map.push_back(source[j].getSubreddit());
            count++;
        }
    }

}

vector<int> Graph::findAdjacentVertices(int vertex, int flag) {
    vector<int> adjacent;
    if(flag == INCOMING){
        for(int i = 0; i < _AdjacencyMatrix.size(); i++){
            if(_AdjacencyMatrix[i][vertex] != NULL){
                adjacent.push_back(i);
            }
        }
    }
    
    if(flag == OUTGOING){
        for(int i = 0; i < _AdjacencyMatrix[vertex].size(); i++){
            if(_AdjacencyMatrix[vertex][i] != NULL){
                adjacent.push_back(i);
            }
        }
    }

    return adjacent;
}

Vertex Graph::pageRank(int max_iteration){
    // initialize all pagerank val to 1 / size
    int size = map_UniqueID.size();
    int new_rank_val = 0;
    vector<int> rank;
    vector<int> new_rank;
    for (int i = 0; i < size; i++){
        rank.push_back(1 / size);
    }

    for(int count = 0; count < max_iteration; count++){
        new_rank.clear();
        for(int i = 0; i < size; i++){
            vector<int> in_edge = findAdjacentVertices(i, INCOMING);
            for(int j = 0; j < in_edge.size(); j++){
                vector<int> out_edge = findAdjacentVertices(in_edge[j], OUTGOING);
                new_rank_val = new_rank_val + (rank[in_edge[j]] / out_edge.size());
            }
            new_rank.push_back(new_rank_val);
            new_rank_val = 0;
        }
        rank = new_rank;
    }

    return Vertex("default");
}

void Graph::printMatrix() {
    for (int i = 0; i < _AdjacencyMatrix.size(); i++) {
        for (int j = 0; j < _AdjacencyMatrix.size(); j++) {
            if (_AdjacencyMatrix[i][j] != NULL) {
                cout << _AdjacencyMatrix[i][j]->getSentiment() << " ";
            }
            else cout << "0 ";
        }
        cout << endl;
    }
    // cout << map_UniqueID << endl;
    for (auto it = map_UniqueID.begin(); it != map_UniqueID.end(); ++it) {
        cout << it->first << " " << it->second << endl;

    }
}

vector<int> Graph::BFS(int source){
    int map_size = map_UniqueID.size();
    vector<bool> visited;
    vector<int> BFS;

    for (int i = 0; i < map_size; i++){
        visited.push_back(false);
    }
 
    // Create a queue for BFS
    queue<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[source] = true;
    queue.push(source);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue
        source = queue.front();
        BFS.push_back(source); // add the vertex to the vector to be returned 
        queue.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        vector<int> adjacentVertices = findAdjacentVertices(source, OUTGOING);

        for(vector<int>::iterator it = adjacentVertices.begin(); it != adjacentVertices.end(); ++it) {
            if (!visited[*it])
            {
                visited[*it] = true;
                queue.push(*it);
            }
        }
    }
    // reverse(BFS.begin(), BFS.end());
    return BFS;
}

string Graph::get_Subreddit_ID(int index) {
    return _subreddit_map[index];
}

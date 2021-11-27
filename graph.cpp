#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include <map>
#include <string>


using std::vector;
using std::string;
using std::map;

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
        if(map_UniqueID.find(target[i].getSubreddit()) != map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(target[i].getSubreddit(), count));
            count++;
        }
    }

    for(int j = 0; j<source.size(); j++){
        if(map_UniqueID.find(source[j].getSubreddit()) != map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(source[j].getSubreddit(), count));
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

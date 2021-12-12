#include "graph.h"
#include <queue>

using std::vector;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::queue;

#define INCOMING 0
#define OUTGOING 1

Graph::Graph(vector<Vertex> target, vector<Vertex> source, vector<int> sentiment) {

    assignID(target, source);//Populates the map and gives unique ID's to nodes
    int size = map_UniqueID.size();
    //Setting up adjacency matrix with all edges marked nullptr
    for(int j = 0; j < size; j++){
        vector<Edge*> v;
        for(int i = 0; i < size; i++){
            v.push_back(NULL);
        }
        _AdjacencyMatrix.push_back(v);
    }

    //Loops over the Target-Source pairs to get the Unique IDs
    for(unsigned i = 0; i < target.size(); i++){
        string target_name = target[i].getSubreddit();
        int target_id = map_UniqueID[target_name];
        string source_name = source[i].getSubreddit();
        int source_id = map_UniqueID[source_name];

        Edge* e = new Edge();
        e->setSentiment(sentiment[i]);
        _AdjacencyMatrix[source_id][target_id] = e;//Populates the edge in the Adjacency matric 
    }
}

void Graph::assignID(vector<Vertex> target, vector<Vertex> source) {
    int count = 0;

    //Goes over both source and target as to cover all the nodes in the Graph
    for(unsigned i = 0; i<target.size(); i++){
        //Checks if map_UniqueID already has a particular subreddit from Source vector if not then add its to the map
        if(map_UniqueID.find(target[i].getSubreddit()) == map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(target[i].getSubreddit(), count));
            _subreddit_map.push_back(target[i].getSubreddit());
            count++;
        }
    }
    
    for(unsigned j = 0; j<source.size(); j++){
        //Checks if map_UniqueID already has a particular subreddit from Source vector if not then add its to the map
        if(map_UniqueID.find(source[j].getSubreddit()) == map_UniqueID.end()){
            map_UniqueID.insert(std::make_pair(source[j].getSubreddit(), count));
            _subreddit_map.push_back(source[j].getSubreddit());
            count++;
        }
    }

}

vector<int> Graph::findAdjacentVertices(int vertex, int flag) {
    vector<int> adjacent;
    //Checks for edges incoming to vertex
    if(flag == INCOMING){
        for(unsigned i = 0; i < _AdjacencyMatrix.size(); i++){
            if(_AdjacencyMatrix[i][vertex] != NULL){
                adjacent.push_back(i);
            }
        }
    }
    //Checks for edges outgoing from vertex
    if(flag == OUTGOING){
        for(unsigned i = 0; i < _AdjacencyMatrix[vertex].size(); i++){
            if(_AdjacencyMatrix[vertex][i] != NULL){
                adjacent.push_back(i);
            }
        }
    }

    return adjacent;
}

vector<double> Graph::pageRank(int max_iteration){
    double size = map_UniqueID.size();
    double new_rank_val = 0;
    vector<double> rank;
    vector<double> new_rank;
    // initialize all pagerank values to 1 / size as default
    for (int i = 0; i < size; i++){
        rank.push_back(1 / size);
    }
    //Calculate page rank values for the number of iterations as given by the user.
    for(int count = 0; count < max_iteration; count++){
        new_rank.clear();
        for(int i = 0; i < size; i++){
            vector<int> in_edge = findAdjacentVertices(i, INCOMING);//Finds all nodes with incoming edges to a vertex
            //For all vertices in in_edge it finds the outgoing nodes
            for(unsigned j = 0; j < in_edge.size(); j++){
                vector<int> out_edge = findAdjacentVertices(in_edge[j], OUTGOING);
                new_rank_val = new_rank_val + (rank[in_edge[j]] / double(out_edge.size()));//updates page rank value
            }
            new_rank.push_back(new_rank_val);
            new_rank_val = 0;
        }
        //Changes previous iteration of page rank values to new iteration of values
        rank = new_rank;
    }

    return rank;
}

void Graph::printMatrix() {
    
}

vector<int> Graph::dijkstra(int startID) {
    vector<int> distance;
    vector<bool> visited;

    //Sets all the distances to infinite distance(very large number)
    for(unsigned i = 0; i < map_UniqueID.size(); i++) {
        distance.push_back(10000);//REMEBER TO CHANGE THIS TO INTMAX
        visited.push_back(false);
    }

    //Priority queue which takes a pair where first argument is the distance of the pair from the startID node and 
    //the second value is the uniqueID of the node. If node A is mapped to 1 then eg(5,1) means that A is distance of 5 
    //away from start node
    std::priority_queue <vPair, vector<vPair>, std::greater<vPair>> queue;

    //push start node with a distance of 0 from itself
    queue.push(std::make_pair(0, startID));
    //update the distance vector at the start point node
    distance[startID] = 0;

    while(queue.empty() == false) {
        int minimumID = queue.top().second;//getsthe node which is the least distance from the start node
        queue.pop();

        visited[startID] = true;//update that node in the visited vector as being visited

        vector<int> adj = findAdjacentVertices(minimumID, OUTGOING);//Finds all nodes which incoming edges from the node with
        // minimumID
        for(unsigned i = 0; i < adj.size(); i++) {

            if(visited[adj[i]] != true){//Only if node is not visited we check for distances
                Edge* edge_ = _AdjacencyMatrix[minimumID][adj[i]];
                int edgeWeight = edge_->getSentiment();
                //Update value only if the current distance is lower than what is already stored for that node
                if(distance[adj[i]] > (distance[minimumID] + edgeWeight)) {
                    distance[adj[i]] = distance[minimumID] + edgeWeight;

                    queue.push(std::make_pair(distance[adj[i]], adj[i]));
                }
            }
        }
    }

    return distance;
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

int Graph::get_Unique_ID(string reddit) {
    return map_UniqueID[reddit];
}

## Development Log: RunTime Terror 4

**(This development log was being kept on a seperate Google document and is now being uploaded to GitHub)**

**Week 1 (November 8 - 13)**

The majority of the week was spent by the members doing research on the different available datasets so that we could then choose the best one. The research also
included finding a way to parse the raw data, and the most appropriate traversals and algorithms. Every member had to put their chosen datasets into a shared google 
document and then a vote was conducted where the most popular dataset was chosen -- the Reddit Hyperlink Network which is one of the datasets under the Stanford large datset network collection. After choosing the dataset, all the members then worked together to revise the traversals and algorithms required for the dataset which was decided to be the following: Page Rank algorithm, BFS traversal and Dijkstra's shortest path algorithm. More details about the implementation of these algorithms and traversal with respect to the dataset is given in the project proposal. Once we had the necessary algorithms decided, we made a rough timeline of when to complete which task. 

**Week 2 (November 14 - 20)**

All the members worked on cleaning up and processing the raw data from the dataset. We also worked on writing a parsing algorithm for the data which was in a 
tsv (tab separted value) format. 
The other primary task this week was to sort out the classes we would need and the member functions for each. We came to the conclusion that we would need three 
classes: the Edge class, the Graph class and the Vertex class along with member variables and functions for each class. We wrote the function headers for each class 
and then segregated the work among all the members. The group was divided into two pairs (to reduce git merge issues) and each pair was given a certain 
class / certain functions to work on for the next week which was the thanksgiving break week. 

**Week 3 (November 21 - 27)**

This week consisted of both the pairs working on their given task individually. We finished writing the class functions which are in the files Edge.cpp, Vertex.cpp 
and Graph.cpp. For the edge class, we wrote the getter and setter functions for the two member variables - _ _weight_ and _ _sentiment_. Similarly, for the Vertex class, we wrote the getter and setter functions for the member variables - _ _Unique_ID_ and _ _subreddit_. Lastly, for the Graph class, we wrote the constructor function, a function called assignID which creates a map to assign each subreddit (data type: string) an unique integer or 'ID'. The last function is the graph class is findAdjacentVertices which, depending on the flag passed into the function, returns a vector of either incoming out outgoing edges to/from the specified vertex.

**Week 4 (November 28 - December 4)**

This week we had our midpoint check in (on the 2nd December) with our final project mentor. We clarified any questions we had regarding the project with our mentor 
and updated them with our progress. We then segregated the remaining work we had i.e. debugging the existing code, writing the two algorithms, the traversal, 
the makefile and the tests between the same pairs as before. We decided to debug and write the tests as a group together whereas the remaining work was split between both the groups like before. 

**Week 5 (December 5 - 11)**

We started the week off by getting together and debugging our existing code In order to do so, we also needed a makefile to compile and test our code. One of the members working on making the skeleton of the makefile with the help of the previous makefiles provided to us in our MPs. As a group, we debugged our makefile to have it working and included any required object files. When we had our makefile working, we then proceeded to debug the rest our code such as the member functions of the classes we had previously made. We tested everything out, initially using a smaller subgraph (which was a part of the bigger graph we make using the subreddit hyperlinks) and then with the entire reddit hyperlink graph. Once this task was done, each pair started working on their assigned algorithm and traversal. We researched and wrote the code for the BFS traversal, page rank algorithm and dijkstra's algorithm. This time, instead of debugging the code after writing it all, we decided to debug as we wrote each of the parts. Along with debugging, tests were also written for each of the components and they were executed to make sure that all our code passes each of the tests. Lastly, all the members started working on the final project report. We first made an outline of everything that should be included in the report and started off with writing about the dataset, topic and goals of the project. 

**Week 6 (December 12 - 13)**

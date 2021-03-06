Caleb Kong, calebk3
Aarushi Biswas, abiswas7
Kartik Mehra, kartikm3
Lyuxing He, lyuxing2

CS 225: Runtime Terror 4
Group Final Project Proposal


Project Topic: Reddit HyperLink Network

Given public Reddit data for 2.5 years - Jan 2014 to April 2017 - the nodes of our graph will be the subreddit pages and the edges will be 
the hyperlinks connecting every subreddit. The weight will be the sentiment of the source towards the target: -1 if it is negative and 1 if 
it is positive or neutral.

Leading Question: How is the Reddit community connected (i.e. what are common interests of Reddit users), and what are the most popular subreddit 
pages? Our project will be a more general tool that focuses on providing statistics and visual info about the data, that the user can then analyze.

Dataset acquisition and Processing 
Dataset: http://snap.stanford.edu/data/soc-RedditHyperlinks.html
This dataset is a tsv file i.e. a tab separated values file. We will try to use split on the tab space to get the columns in the dataset. The important 
columns are the source subreddit and the target subreddit, which will describe the hyperlinks between pages. There is also a “post label” column, 
which describes the sentiment toward the current subreddit, be it positive, negative, or neutral. If we have enough time, we could also use this data 
to see which topics on Reddit everyone enjoys and hates.
There could be some issues in spelling in the source/target subreddit titles, and there could be some obscure subreddits as well that can be omitted. 
We might use something like a strncmp() in order to simplify our data processing, because it would eliminate outliers in the data.


Graph Algorithms 
Page rank
i. We will try to implement the page rank algorithm as this will allow us to rank how important a certain reddit page is and rank them in order how 
frequently they are visited.
ii. With regards to how the function signature will look it will need to have a parameter which tells us the damping factor.
iii. The PageRank algorithms is bounded by O(n+m). That’s because to update the page rank value of each vertex, all edges need to be visited in the 
    worst case scenario Either n or m can dominate the runtime.


BFS
i. We will try to implement a BFS traversal as this is useful in building Dijkstra’s shortest path algorithm. Dijkstra’s algorithm is basically just BFS, 
but with a priority queue, so it makes sense to use BFS over DFS.
ii. The time complexity of BFS will be O(n).

Dijkstra’s Shortest Path
i. We will use this to see how to go from one subreddit to another subreddit using the least amount of hyperlink connections.
ii. Dijkstra’s function signature will take in our graph and also the source node from which to find the shortest path to other nodes.
iii. Since we are also incorporating page rank, it follows that we will be using weighted paths. For example, if we have a higher damping factor, we will 
have a lower weight, since there is a decreased probability that the user will get to that subreddit.
iv. The algorithm needs to first set all vertices with appropriate distances (zero or infinity), which takes O(n) time complexity. As each edge will be visited 
by adding and popping corresponding vertices into the priority queue, this part will take O(mlog(n)) time complexity. Therefore, the overall time complexity 
will be O(n + mlog(n)).



Timeline 

Our proposed timeline is as follows: 

Identifying the tsv parsing algorithm or library 
Cleaning up and normalizing the raw data, preprocess data (Nov 14)
Using the processed data, create a graph using one of the following graph implementation methods: edge list, adjacency matrix or adjacency list. 
Implement BFS traversal (Nov 21)
Implement Dijkstra’s Shortest Path algorithm using the DFS traversal implemented previously (Nov 28)
Research and implement Page Rank Algorithm (Dec 5)
Research libraries to get a visual graph output from the Page rank algorithm. (Dec 12)

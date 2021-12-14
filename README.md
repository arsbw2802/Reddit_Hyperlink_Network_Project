# CS225 Final Project 

## Group Members 
* Aarushi Biswas (NetID: abiswas7)
* Kartik Mehra (NetID: kartikm3)
* Caleb Kong (NetID: calebk3)
* Lyuxing He (NetID: lyuxing2)

## Introduction

- The Dataset used for this project is the [Reddit Hyperlink Network dataset](http://snap.stanford.edu/data/soc-RedditHyperlinks.html) which came from the Stanford dataset collection.
- The dataset contains target and source nodes which are connected with edges which have sentiments as weights. BFS is used to list out all the subreddit hyperlinks connected to a chosen subreddit. Djikstra's shortest path is used as a means to find whether they can go from current subreddit to their desired subreddit, and if yes, provide an estimation of how well they might feel about their desired subreddit. Lastly, Page Rank is used to determine the page rank value of any chosen subreddit. 

## Documentation 
- [Team Contract](https://github-dev.cs.illinois.edu/cs225-fa21/calebk3-abiswas7-lyuxing2-kartikm3/blob/BFS/documents/teamcontract.md)
- [Project Proposal](https://github-dev.cs.illinois.edu/cs225-fa21/calebk3-abiswas7-lyuxing2-kartikm3/blob/BFS/final_proposal.md)
- [Development Log](https://github-dev.cs.illinois.edu/cs225-fa21/calebk3-abiswas7-lyuxing2-kartikm3/blob/BFS/documents/Development_log.MD)
- Final Report

## Project Demo 

## Instructions 

### How to run the program 

In order to run the program and get user input, run the following commands:
- Run `make clean` and then `make` to create the executable of the program to be run. 
- Run `./reddit` to start the program executable created.
- The user will be asked to choose between two sub datasets: the reddit_title and reddit_body. This is because each post has a title and body. The hyperlinks can be present in either and hence there is a dataset provided for each. 
- Once the user has chosen the dataset, they will be presented with three options. The user should enter `1` for the BFS traversal, `2` for the Djikstra's shortest path output and `3` for the Page Rank output. 
- If the user chooses option 1, they will be prompted to enter an integer between 0 and 8820. The integer corresponds to a subreddit depending on the Unique_ID map being used in our program which is used as the starting vertex for the BFS. The traversal will then be printed on the screen with both the subreddit names along with their unique_IDs. Please note that there will be some subreddits with no outgoing edges (which is what is used in the BFS) and hence will have no connections.
- If the user chooses option 2, they will be prompted to enter 2 integers. Similar to the BFS, the integers are the Unique IDs corresponsing to subreddits. The first integer is used as the starting node which is used in the Djikstra's shortest path which returns a vector of distances. The second subreddit input is used as a index in the vector to output what the shortest distance between the two chosen subreddits is given that there is a way to go to the target subreddit from the source. Please note, that the 'distance' returned by the Djikstra algorithm provides an estimation of how well they might feel about their desired subreddit. The lower the estimation is, the more enjoyable the user might feel about the destination subreddit.  
- If the user chooses option 3, they will be prompted to enter 2 integers. The first integer is the accuracy factor used in the Page Rank. The second integer is the unique ID of a subreddit. The Page Rank value of this subreddit will then be displayed on the screen. The page rank value gives us the probability of visiting each subreddit within the dataset and so higher the page rank value, higher the probability of an user ending up there. The higher the accuracy factor is, the more accurate the prediction will be. Please note, that higher the accuracy factor, the more time will be taken to run the program. Hence please limit the accuracy factor to a value between 0 and 10. 

### How to run the test cases 

We have compiled a few test cases to test our algorithms and traversals which can be run by executing the following commands:
- Run `make clean && make test`. Give program will take a minute or two to create the test executable.  
- Run `./test`
- The output on the screen will inform you whether all the test cases and assertions have passed or not. There are [] test cases and [] assertions

## References 


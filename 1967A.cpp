/*
rpoblem : make longest path that a leaf to another leaf!

1. can find longest path by using DFS that path leaf to leaf  
-> What leaf do i choose to get longest path to leaf to leaf?
    -> A node that has longest path from root 
    cuz
    a node that makes diameter must be the longest leaf from a random node.
*/

#include <iostream>
#include <vector>
using namespace std;

// 1 <= n <= 10,000 && index of list starts at 1
vector< pair<int, int> > list[10001];
// check if node[index] is visited
bool check[10001] = {false};

int n=0;

//index is number of node
int DFS(int index) 
{
    if ( check[index] ) { return -9999; }
    
    //max weight at node[index]
    int sum = 0;

    check[index] = true;

    for ( int i = 0; i < list[index].size(); i++ )
    {
        int node = list[index][i].first;
        int weight = list[index][i].second;
        sum = max( sum, weight + DFS(node) );
    } 

    return sum;
}

int main() {
    
    cin >> n;

    //edge info to vector list
    for ( int i = 1; i < n; i++ ) 
    {
        int parentNode, childNode, weight;
        cin >> parentNode >> childNode >> weight;
        //for root to longest leaf
        list[parentNode].push_back( make_pair(childNode,weight) );
        //for leaf to another longest leaf
        list[childNode].push_back( make_pair(parentNode,weight) );
    }
    
    int length = 0;

    for ( int i = 1; i < n; i++ )
    {
        for ( int j = 1; j <= n; j++ ) { check[j] = false; }
        length = max( length, DFS(i) );
    }

    cout << length << endl;
    return 0;
}
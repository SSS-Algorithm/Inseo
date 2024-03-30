/*
Core of Problem : Count nodes that src -> dest (src.H < dest.H)

Manage with List ? Time Over [Denied]

Dropped


*/

#include <iostream>
#include <vector>
using namespace std;

int N, K, maxH;

//Graph_edge_info
vector<int> table[5001];
//Graph_height_info
int H[5001];
//Graph_endpoint_count
int result[5001];

//Recursive
// i is graph node number & h is height of i
int Solution(int i, int h) {
    //no more further
    if (h == maxH || table[i].empty()) return 1;
    
    int& res = result[i];
    
    //already calculated
    if (res != -1) return res;

    //calculating of node_src to node_dest - recursive
    res = 1;
    for (auto& ptr : table[i]) {
        if(h < H[ptr]) {
            res = max(res, Solution(ptr, H[ptr]) + 1);
        }
    }
    return res;
}

int main(void) {
    cin >> N >> K;
        
    for (int i = 1; i <= N; i++) {
        cin >> H[i]; 
        maxH = max(maxH, H[i]);   
    }

    for (int i = 0; i < K; i++) {
        int src, dest;
        cin >> src >> dest;

        table[src].push_back(dest);
        table[dest].push_back(src);
    }

    fill(result[0], result[5001], -1);
    for(int i = 1; i <= N; i++) {
        cout << Solution(i, H[i]) << endl;
    }

  return 0;
}
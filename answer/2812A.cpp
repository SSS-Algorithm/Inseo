/*
Core of Problem : How to maximize the answer?
   find MaxIndex between Index 1 - K
-> delete before MaxIndex
-> delete left amount of numbers 
-> Divide and Conquer I think..? 
    ㄴ> The Answer is Queue!

240317 Clear
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

deque<char> deleteIndex(string origin, deque<char> queue,int K) {
    int i = 0; 
    while ( i < origin.size() ) {
        while ( K > 0 && !queue.empty() && queue.back() < origin[i]) {
            queue.pop_back();
            K--;
        }
        queue.push_back(origin[i]);
        i++;
    }

    while(K--) { queue.pop_back(); }
    return queue;
}


int main(void) {
    int N,K;
    int result;
    cin >> N >> K;
    
    string origin;
    cin >> origin;

    deque<char> queue;

    queue = deleteIndex(origin, queue, K);
    
    for( int i = 0; i < queue.size(); i++) cout<<queue[i];
    cout<<endl;
    return 0;
}
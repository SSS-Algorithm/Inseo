/*
Strategy :
backtracking 

*/
#include <iostream>
#include <vector>
using namespace std;

int input[8];  //for input
bool visited[8] = {false}; //for backtracking 
int temp[8]; //for backtracking 
int maxresult = 0;

void Sol(int size, int curval, int P, int M) {
    //try get value unvisited
    int index;
    for(index = 0; index < size; index++) if(!visited[index]) break;
    
    //visit finished
    if(index == size) {
        maxresult = curval;
        return;
    }
    //get value & mark visited
    visited[index] = true;
    int nextval = input[index];
    
    if(M > 0 && P > 0) {
        Sol(size, curval+nextval, P-1, M);
        Sol(size, curval*nextval, P, M-1);
    }
    else if(M == 0 && P > 0) Sol(size, curval+nextval, P-1, M);
    else if(P == 0 && M > 0) Sol(size, curval*nextval, P, M-1);

    visited[index] = false;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

    //operand counts , + counts, * counts, answer
    int N, P, M;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    cin >> P >> M;
    
    //every start value in input
    for(int val : input) {
        Sol(N, val, P, M);
    }

    cout << maxresult << endl;
    return 0;
}
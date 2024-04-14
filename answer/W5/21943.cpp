/*
Strategy :
backtracking 
list? drop
defeated

*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int maxresult = 0;

void Sol(vector<int> q, int P) {
    if(P == 0) {
        int value = 1;
        while ( !q.empty() ){
            value *= q.back();
            q.pop_back();
        }
        maxresult = max(maxresult, value);
        return;
    }
    else {
        for(int i = 0; i < q.size()-1; i++) {
            for(int j = 0; j < q.size()-1-i; j++) {
                vector<int> newq(q);
                int newval = newq[i] + newq[i+j+1];

                newq.erase(newq.begin()+i);
                newq.erase(newq.begin()+i+j);
                newq.insert(newq.begin(), newval);
                Sol(newq, P-1);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

    
    vector<int> input;  //for input
    //operand counts , + counts, * counts, answer
    int N, P, M, var;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> var;
        input.push_back(var);
    }

    cin >> P >> M;

    //every start value in input
    Sol(input, P);
    
    cout << maxresult << endl;
    return 0;
}
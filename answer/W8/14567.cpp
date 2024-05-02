/*
Strategy : check constraints using Vector
1. vector[first] has elements that can get lectured after first
2. if vector's index is called, elements of vector's index must be delayed 1 semester.
3. For all index of vector, apply rule 2.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M, first, second;
    cin >> N >> M;

    int sub[N+1]; //Remember Semester 
    vector<int> pp[N+1];


    for(int i = 1; i <= N; i++) sub[i] = 1; //if no constraints only be 1st

    for(int i = 0; i < M; i++) {
        cin >> first >> second;
        
       pp[first].push_back(second);

    }

    for(int f = 1; f <= N; f++) {
        for(int s = 0; s < pp[f].size(); s++) {
            sub[ pp[f][s] ] = max(sub[ pp[f][s] ], sub[f]+1 );
        }
    }
    
    for(int i = 1; i <= N; i++) cout << sub[i] << " ";
    cout << endl;
    return 0;
}
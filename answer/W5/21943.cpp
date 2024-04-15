/*
Strategy :
backtracking 
list? drop
defeated

*/
#include <iostream>
#include <vector>
using namespace std;

int N,P,M;
int input[8];
bool v[8] = {false};
int result[15];
int maxresult = 0;

void Sol(int index, int M, int size) {
    if (M < 0) return;

    if(M == 0 && index == size) {
        int cal[size-N+1];
        int value = 0;
        int pointer = 0;
               
        for(int i = 0; i < size; i++) {
            if(result[i] == 0) {
                cal[pointer++] = value;
                value = 0;
            }
            value += result[i];
        }
        value = 1;
        for(int i = 0; i < size-N+1; i++) value *= cal[i];
        maxresult = max(maxresult, value);
    }

    if(index == 0) {
        for(int i = 0; i < N; i++) {
            v[i] = true;
            result[index] = input[i];
            Sol(index+1, M, size);
            result[index] = -1;

            result[index] = 0;
            result[index+1] = input[i];
            Sol(index+2, M-1, size);
            result[index+1] = -1;
            result[index] = -1;

            v[i] = false;
        }
    } else if(index < size) {
        int i;
        for(i = 0; i < N; i++) {
            if(v[i]) continue;

            v[i] = true;
            result[index] = input[i];
            Sol(index+1, M, size);
            result[index] = -1;

            result[index] = 0;
            result[index+1] = input[i];
            Sol(index+2, M-1, size);
            result[index+1] = -1;
            result[index] = -1;

            v[i] = false;
        }
    } else return;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

    //operand counts , + counts, * counts, answer
    int var;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }

    cin >> P >> M;

    //every start value in input
    Sol(0,M, N+M);
    
    cout << maxresult << endl;
    return 0;
}
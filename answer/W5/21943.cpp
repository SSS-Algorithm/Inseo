/*
Strategy :
make a list and calculate force <- denied
div numbersets by * counts that makes biggest
like pigeon house problem
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

    int numbers[8];
    //operand counts , + counts, * counts
    int N, P, Q, result;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    sort(numbers,numbers+N,greater<int>());

    cin >> P >> Q;

    int results[Q+1];

    for(int i = 0; i < Q + 1; i++) results[i] = 0;

    for(int k = 0; k < N; k++) {
        int index = 0;
        for(int i = 0; i < Q+1; i++) {
            if(results[index] > results[i]) index = i;
        }
        results[index] += numbers[k];
    }
    result = results[0];
    for(int i = 1; i < Q+1; i++) result *= results[i];

    cout << result << endl;
    return 0;
}
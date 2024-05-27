#include <iostream>
#include <cstring>
using namespace std;

char input[100]={'\0',};
bool v[100]={false, };

void Sol(int start, int end, int length) {
    if(start>end) return;
    int min = start;

    for (int i = start; i <= end; i++) if(input[i] < input[min]) min = i;

    v[min] = true;

    for (int i = 0; i < length; i++) {
        if (v[i]) cout << input[i];
    }
    cout << '\n';

    Sol(min+1, end, length);
    Sol(start, min-1, length);
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> input;
    int length = strlen(input);

    Sol(0, length-1, length);

    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

char input[101];
bool v[101];
int length;

void Print() {
    string tmp;
    for(int i = 0; i < length; i++) if(v[i]) cout<<input[i];
    cout<<'\n';
}

void Sol(int start, int end) {
    int min = start;
    for(int i = start; i <= end; i++) if(input[i] <= input[min]) min = i;

    v[min] = true;

    Print();

    if(min + 1 <= end) Sol(min+1, end);
    if(min - 1 >= start) Sol(start, min-1);
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> input;

    length = strlen(input);

    Sol(0, length-1);

    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

char input[100];
bool v[100] = {false, };
int length;

void Print() {
    string tmp;
    for(int i = 0; i < length; i++) if(v[i]) tmp += input[i];
    cout<<tmp;
    if(tmp != "") cout<<endl;
}

void Sol(int start, int end) {
    int min = start;
    for(int i = start; i <= end; i++) if(input[i] < input[min]) min = i;

    v[min] = true;

    Print();

    if(min + 1 <= end) Sol(min+1, end);
    if(min - 1 >= start) Sol(start, min-1);
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    cin >> str;
    memset(v, false, 100);
    memset(input, '.', 100);
    for(int i = 0; i < str.length(); i++) input[i] = str[i];
    length = str.length();

    Sol(0, str.length());
}
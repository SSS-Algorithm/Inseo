#include <iostream>
#include <vector> 
using namespace std;

int input[9][9];
vector<pair<int,int> > hole;
bool isEnd = false;

bool check(int x, int y, int value) {
    for(int i = 0; i < 9; i++) {
        if(input[i][y] == value) return false;
        if(input[x][i] == value) return false;
    }

    int partX = (x/3)*3;
    int partY = (y/3)*3;

    for(int X = partX; X < partX + 3; X++) {
        for(int Y = partY; Y < partY + 3; Y++) {
            if(input[X][Y] == value) return false;
        }
    }
    return true;
}

void Sol(int index, int size) {
    if(isEnd) return;
    if(index == size) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << input[i][j] << " ";
            }
            cout<<endl;
        }
        isEnd = true;
    }
    else {
        int x = hole[index].first;
        int y = hole[index].second;

        for(int val = 1; val <= 9; val++) {
            if(check(x, y, val)) {
                input[x][y] = val;
                Sol(index+1, size);
                input[x][y] = 0;
            }
        }
    }
    return;
}


int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int value;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> value;
            input[i][j] = value;
            if(!value) hole.push_back( make_pair(i,j) );
        }
    }

    Sol(0, hole.size());

    return 0;
}
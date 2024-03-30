#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue> 
using namespace std;

int plate[8][8];
vector< tuple<int, int> > checklist;
deque<tuple<int, int> > q;

void Input()
{
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if ( s[j] != '.') plate[i][j] = 1; 
            else plate[i][j] = 0;   
        }
    }
}

void Update() {
    for (int i = 1; i <= 7; i++ ) {
        for (int j = 0; j < 8; j++) {plate[i-1][j] = plate[i][j];}
        if (i == 7) for (int j = 0; j < 8; j++) {plate[i][j] = 0;}
    }
}

int Find()
{
    int count = 0;
    while (!q.empty()) 
    {
        if(count == 8) return 1;

        int posx, posy, x, y;
        tuple<int,int> pos = q.front();
        posx = get<0>(pos);
        posy = get<1>(pos);
        q.pop_front();

        for(auto offset : checklist) {
            x = get<0>(offset); 
            y = get<1>(offset);
            if(posx + x > 7 || posx + x < 0) continue;
            if(posy + y > 7 || posy + y < 0) continue;
            if(plate[posx + x][posy + y] == 1 || plate[posx+x][posy+y+1] == 1) continue;
            
            posx += x;
            posy += y;
            q.push_back(make_tuple(posx,posy));
            
        }
        Update();
        count+=1;
    }
    return 0;
}

int main(void) {
    int result;
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
    checklist.push_back(make_tuple(1,0));
    checklist.push_back(make_tuple(1,-1));
    checklist.push_back(make_tuple(0,-1));
    checklist.push_back(make_tuple(-1,-1));
    checklist.push_back(make_tuple(-1,0));
    checklist.push_back(make_tuple(-1,1));
    checklist.push_back(make_tuple(0,1));
    checklist.push_back(make_tuple(1,1));

    Input();
    q.push_back(make_tuple(0, 0));

    result = Find();

    cout<< result <<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue> 
using namespace std;

int plate[8][8][8];
vector< tuple<int, int> > checklist;
deque<tuple<int, int,int> > q;

void Input()
{
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if ( s[j] != '.') plate[0][i][j] = 1; 
            else plate[0][i][j] = 0;   
        }
    }
}

int Find()
{
    while (!q.empty()) 
    {
        int stack, posx, posy, x, y;
        tuple<int,int,int> pos = q.front();
        posx = get<0>(pos);
        posy = get<1>(pos);
        stack = min(get<2>(pos),7);

        q.pop_front();

        for(auto offset : checklist) {
            x = get<0>(offset); 
            y = get<1>(offset);

            if(posx + x > 7 || posx + x < 0 || posy + y > 7 || posy + y < 0) continue;
            else if(plate[stack][posx + x][posy + y] == 1 || plate[stack][posx+x-1][posy+y] == 1) continue;
            else {
                if(posx+x == 0) return 1;
                q.push_back(make_tuple(posx + x,posy + y,stack+1));
            }
        }
    }
    return 0;
}

int main(void) {
    int result;
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
    checklist.push_back(make_tuple(0,0));
    checklist.push_back(make_tuple(1,0));
    checklist.push_back(make_tuple(1,-1));
    checklist.push_back(make_tuple(0,-1));
    checklist.push_back(make_tuple(-1,-1));
    checklist.push_back(make_tuple(-1,0));
    checklist.push_back(make_tuple(-1,1));
    checklist.push_back(make_tuple(0,1));
    checklist.push_back(make_tuple(1,1));

    Input();

    for (int cnt = 1; cnt < 8; cnt++) {
        for (int i = 6; i >= 0; i-- ) {
            for (int j = 0; j < 8; j++) {plate[cnt][i+1][j] = plate[cnt-1][i][j];}
            if (i == 0) for (int j = 0; j < 8; j++) {plate[cnt][i][j] = 0;}
        }
    }

    q.push_back(make_tuple(7, 0, 0));

    result = Find();

    cout<< result <<endl;

    return 0;
}
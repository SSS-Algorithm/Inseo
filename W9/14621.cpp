#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = -1; //MST distance
vector< pair<int, pair<int,int>> > r; //index:<src,dest>
bool visited[1001] = {false,}; //remember visited node
int root[1001]; //remember root of subtree

int Find(int x) {
    if(x == root[x]) return x;
    else return Find(root[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) root[y] = x;
    else root[x] = y;
}

int Sol(int N, int M) {
    int count = 0, tmp = 0;

    for(int i = 0; i < r.size(); i++) {

        int dist = r[i].first;
        int src = r[i].second.first;
        int dest = r[i].second.second;

        if(Find(src) != Find(dest)) {
            tmp += dist;
            Union(src, dest);
            visited[src] = true;
            visited[dest] = true;
            count += 1;
        }
    }
    return result = count == N-1 ? tmp : -1;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    char input[N+1]; //univ M/F check

    for(int i = 1; i <= N; i++) {
        cin >> input[i];
        root[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int src, dest, dist;
        cin >> src >> dest >> dist;

        if(input[src] == input[dest]) continue;

        r.push_back( {dist, {src, dest}} );
    }

    sort(r.begin(), r.end());

    cout << Sol(N, M) << endl;
    
    return 0;
}
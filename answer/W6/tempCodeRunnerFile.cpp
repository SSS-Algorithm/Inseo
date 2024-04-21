/*
Strategy :


*/
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
    //current count, count to set, length of road 
    int N, M, L, result = 9999;

    vector<int> road;

    cin >> N >> M >> L;
    int input[N+2];
    input[0] = 0;
    input[1] = L;

    if(N != 0) {
        for(int i = 0; i < N; i++) {
            cin >> input[i+2];
        }
    }
    
    int i,j;
    for(i = 1; i < N+1; i++) {
        int minindex=i;
        for(j = i; j < N+2; j++){
            if(input[minindex] > input[j]) minindex = j;
        }
        int tmp = input[minindex];
        input[minindex] = input[i];
        input[i] = tmp;
    }
    
    for(int i = 0; i < N+2; i++) road.push_back(input[i]);
    for(int i = 0; i < road.size(); i++) cout<<road[i]<<" ";
    cout <<endl;
    int start = 1, end = L-1;
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        int count=0;
        for(int i = 0; i < road.size()-1; i++) {
            int dist = road[i+1] - road[i];

            int cnt = dist / mid;
            if(cnt > 0) {
                if(dist%mid == 0) count += cnt-1;
                else count += cnt;
            }
        }

        if(count > M) start = mid + 1;
        else {
            end = mid - 1;
            result = min(result,mid);
        }
    }

    cout << result << endl;
    return 0;
}
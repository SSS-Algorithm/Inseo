#include <iostream>

using namespace std;
int N, K;
int table[5001][5001];
int H[5001];
int result[5001];
int main(void) {
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> H[i];    

	for (int i = 0; i < K; i++) {
		int src, dest;
		cin >> src >> dest;

		if (H[src] < H[dest]) table[dest][src] = 1;
		else table[src][dest] = 1;
	}

	for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || H[i] >= H[j]) continue;
				for(int k=1; k <= N; k++) {
					result[i] = max(result[i], table[i][k]+table[k][j]+1);
				}
			}
	}

    for (int i = 1; i <= N; i++) {   
	    cout << result[i] << endl;
    }

  return 0;
}

#include <iostream>
using namespace std;

int N;
int arr[20][20];

int coin(int x, int y) {
    int cnt=0;

    for(int i=x-1; i<x+2; i++) {
        for(int j=y-1; j<y+2; j++) {
            if (arr[i][j]==1) {
                cnt++;
            } else {
                continue;
            }
        }
    }

    return cnt;
}

int main() {
    int c, max = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<N-1; i++) {
        for(int j=1; j<N-1; j++) {
            c=coin(i, j);
            if (c>max) {
                max=c;
            }
        }
    }

    cout << c;
    return 0;
}
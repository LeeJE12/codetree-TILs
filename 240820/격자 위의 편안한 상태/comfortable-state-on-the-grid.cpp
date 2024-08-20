#include <iostream>
using namespace std;

//U, R, D, L
int dr[4]={-1, 0, 1, 0};
int dc[4]={0, 1, 0, -1};

int N, M, r, c;
int arr[101][101]={};

bool InRange(int r, int c) {
    return (1<=r && r<=N && 1<=c && c<=N);
}

bool Peace(int r, int c) {
    int cnt=0;
    for (int i=0; i<4; i++) {
        int nr = r+dr[i], nc = c+dc[i];
        if (InRange(nr, nc) && (arr[nr][nc]==1)) {
            cnt ++;
        }
    }

    if (cnt == 3) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N >> M;

    while(M>0) {
        M--;
        cin >> r >> c;

        if (InRange(r, c)) {
            arr[r][c] = 1;

            if (Peace(r, c)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }        
    }


    return 0;
}
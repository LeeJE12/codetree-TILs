#include <iostream>
using namespace std;

//U, R, D, L
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int N, K;
int x=1, y=0, dir=1, cnt=0;
char arr[1001][1001];

bool InRange(int x, int y) {
    return (1<=x && x<=N && 1<=y && y<=N);
}

int main() {
    cin >> N;
    int max=2*N;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> K;

    while(K>0) {
        K--;
        int r = x + dx[dir]; int c = y + dy[dir];
        if(InRange(r, c)) {
            x=r; y=c;
        } else {
            dir = (dir+1)%4;
        }
    }

    dir = (dir+1)%4;

    while (max>0) {
        max--;
        
        if(arr[x][y]=='/') {
            if (dir == 0) {
                dir = 1;
            } else if (dir == 1) {
                dir = 0;
            } else if (dir == 2) {
                dir = 3;
            } else {
                dir = 2;
            }
        } else {
            if (dir == 0) {
                dir = 3;
            } else if (dir == 1) {
                dir = 2;
            } else if (dir == 2) {
                dir = 1;
            } else {
                dir = 0;
            }
        }
        
        if (InRange(x, y)) {
            cnt++;
            x += dx[dir]; y += dy[dir];
        } else {
            cout << cnt;
            return 0;
        }
    }

    cout << cnt;

    return 0;
}
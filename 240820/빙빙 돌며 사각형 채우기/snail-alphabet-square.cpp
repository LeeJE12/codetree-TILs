#include <iostream>
using namespace std;

// R, D, L, U 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n,m;
int x=1, y=1, dir=0;
char arr[101][101] = {};

bool InRange(int x, int y) {
    return (1<=x && x<=n && 1<=y && y<=m);
}

int main() {
    cin >> n >> m;
    int max = n*m;

    arr[1][1] = 65;
    for (int i=2; i<=max; i++) {
        int nx = x + dx[dir], ny = y + dy[dir];

        if(!InRange(nx, ny) || (arr[nx][ny]!=0)) {
            dir = (dir+1)%4;
            i--;
        } else {
            x = nx; y = ny;
            arr[x][y]=64+(i%64);
        }
    }

    for(int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
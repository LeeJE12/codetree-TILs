#include <iostream>
using namespace std;

// D, R, U, L
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n,m;
int x=1, y=1, dir=0;
int arr[101][101] = {};

bool InRange(int x, int y) {
    return (1<=x && x<=n && 1<=y && y<=m);
}

int main() {
    cin >> n >> m;
    int max = n*m;

    arr[1][1] = 1;
    for (int i=2; i<=max; i++) {
        int nx = x + dx[dir], ny = y + dy[dir];

        if(InRange(nx, ny) && (arr[nx][ny]!=0)) {
            x = nx; y = ny;
        } else {
            dir = (dir+1)%4;
            i--;
        }
    }

    for(int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
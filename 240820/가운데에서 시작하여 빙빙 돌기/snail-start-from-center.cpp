#include <iostream>
using namespace std;

// R U L D
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int n, dir=2;
int arr[101][101];

bool InRange(int x, int y) {
    return (1<=x && x<=n && 1<=y && y<=n);
}

int main() {
    cin >> n;
    //int x = (n/2)+1, y = x;
    int x=n, y=n;
    int max = n*n;

    //cout << "x: " << x << ", y: " << y << endl;

    arr[x][y] = max;
    while(max>1) {
        max--;
        int nx= x+dx[dir], ny= y+dy[dir];

        if (!InRange(nx, ny) || (arr[nx][ny]!=0)) {
            dir = (dir+3)%4;
            max++;
        } else {
            x = nx; y = ny;
            arr[x][y] = max;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
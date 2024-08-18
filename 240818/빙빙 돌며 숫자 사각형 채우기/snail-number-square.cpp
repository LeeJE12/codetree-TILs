#include <iostream>
#define DIR 4
using namespace std;

int n, m;
int x=0, y=0, dir = 1;

//U, R, D, L
int dx[DIR] = {-1, 0, 1, 0};
int dy[DIR] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return (0<=x && x<m && 0<=y && y<n);
}

int main() {
    cin >> n >> m;
    int a[n][m] = {};
    int num = n*m;

    a[x][y] = 1;

    for(int i=2; i<=num; i++) {
        int nx = x + dx[dir], ny = y + dy[dir];

        if(!InRange(nx, ny) || a[nx][ny] != 0) {
            dir = (dir + 1) % 4;
        }

        x += dx[dir]; y += dy[dir];
        a[x][y] = i;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
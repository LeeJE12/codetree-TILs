#include <iostream>
#define DIR 4
using namespace std;

int n;

bool InRange(int x, int y) {
    return (0<=x && x<n && 0<=y && y<n);
}

int main() {
    cin >> n;
    int a[n][n];

    int dx[DIR] = {-1, 0, 1, 0};
    int dy[DIR] = {0, 1, 0, -1};

    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            cin >> a[x][y];
        }
    }

    int cnt=0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            int cnt_xy=0;
            for (int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if (InRange(nx, ny) && a[nx][ny]==1) {
                    cnt_xy++;
                }
            }
            if (cnt_xy >= 3) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
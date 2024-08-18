#include <iostream>
#define DIR 4
using namespace std;

int n, t, dir;

//U, R, D, L
int dr[DIR] = {-1, 0, 1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool InRange(int r, int c) {
    return (1<=r && r<=n && 1<=c && c<=n);
}

void Direction(char d) {
    if (d=='U') {
        dir = 0;
    } else if (d=='R') {
        dir = 1;
    } else if (d=='D') {
        dir = 2;
    } else {
        dir = 3;
    }
}

int main() {
    cin >> n >> t;
    int a[n][n];

    int r, c; char d;
    cin >> r >> c >> d;

    Direction(d);
    while (t>0) {
        int nr = r, nc = c;
        nr += dr[dir];
        nc += dc[dir];

        if (InRange(nr, nc)) {
            r = nr; c = nc;
        } else {
            if (d=='U') { d='D'; }
            else if (d=='D') { d='U'; }
            else if (d=='R') { d='L'; }
            else if (d=='L') { d='R'; }

            Direction(d);
        }

        t--;
    }

    cout << r << " " << c;
    return 0;
}
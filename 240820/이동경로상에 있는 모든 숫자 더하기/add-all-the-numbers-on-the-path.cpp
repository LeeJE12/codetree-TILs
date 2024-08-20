#include <iostream>
#include <string>
using namespace std;

// U, R, D, L
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int N, T, sum=0, dir=0;
int arr[100][100]={};
string st;

bool InRange(int x, int y) {
    return (1<=x && x<=N && 1<=y && y<=N);
}

int main() {
    cin >> N >> T >> st;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }

    int x = (N/2)+1, y = x;

    sum += arr[x][y];
    for (int i=0; i<T; i++) {
        //cout << "this str is " << st[i] << endl;
        if(st[i]=='L') {
            dir = (dir+3)%4;
        } else if(st[i]=='R') {
            dir = (dir+1)%4;
        } else {
            //cout << "forward" << endl;
            //cout << "now in (" << x << "," << y << ")  ";
            int nx = x+ dx[dir], ny = y+ dy[dir];
            if(InRange(nx, ny)) {
                x=nx; y=ny;
                sum += arr[x][y];

                //cout << "x: "<<x<<", y: "<<y<<" "<<arr[x][y] << " in arr " << endl;
            } else {
                continue;
            }
        }
    }

    cout << sum;

    return 0;
}
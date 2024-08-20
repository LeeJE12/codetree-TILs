#include <iostream>
using namespace std;

//U, R, D, L
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int N, K, x=1, y=1;
int dir, cnt=0;
char arr[1001][1001];

bool InRange(int x, int y) {
    return (1<=x && x<=N && 1<=y && y<=N);
}

void Kdirection (int K, int N) {
    int k = K/N -1;

    if (k==0) {
        dir = 2;
    } else if (k==1) {
        dir = 3;
    } else if (k==2) {
        dir = 0;
    } else {
        dir = 1;
    }
}

int main() {
    cin >> N;
    int max=2*N;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }
/*
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
*/
    cin >> K;
    //Kdirection(K, N);

    int sx=1, sy=0, sdir=1;
    while(K>0) {
        K--;
        int r = sx + dx[sdir]; int c = sy + dy[sdir];
        if(InRange(r, c)) {
            sx=r; sy=c;
        } else {
            sdir = (sdir+1)%4;
        }

        //cout << "sx : " << sx << " sy : " << sy << endl ;
    }

    sdir = (sdir+1)%4;

    while (max>0) {
        max--;
        
        if(arr[sx][sy]=='/') {
            if (sdir == 0) {
                sdir = 1;
            } else if (sdir == 1) {
                sdir = 0;
            } else if (sdir == 2) {
                sdir = 3;
            } else {
                sdir = 2;
            }
        } else {
            if (sdir == 0) {
                sdir = 3;
            } else if (sdir == 1) {
                sdir = 2;
            } else if (sdir == 2) {
                sdir = 1;
            } else {
                sdir = 0;
            }
        }
        
        if (InRange(sx, sy)) {
            cnt++;
            sx += dx[sdir]; sy += dy[sdir];
            //cout << "cnt: " << cnt << " 좌표: (" << sx << ", " << sy << ")" << endl;
        } else {
            cout << cnt;
            return 0;
        }
    }

    cout << cnt;

    return 0;
}
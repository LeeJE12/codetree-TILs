#include <iostream>
using namespace std;

//W, S, N, E
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int N, dir;
char d; int m;

int x=0, y=0, cnt=0;

int main() {
    cin >> N;
    while(N--) {
        cin >> d >> m;

        if (d=='W') {
            dir=0;
        } else if (d=='S') {
            dir=1;
        } else if (d=='N') {
            dir=2;
        } else {
            dir=3;
        }

        while(m>0) {
            x += dx[dir]; y+= dy[dir];
            cnt++;
            
            if ((x==0) && (y==0)) {
                cout << cnt;
                return 0;
            }
            m--;
        }
    }

    cout << -1;

    return 0;
}
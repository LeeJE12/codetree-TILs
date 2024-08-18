#include <iostream>
using namespace std;

//N, E, S, W
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

string st;
int len, i=0, dir=0;
int x=0, y=0;

int main() {
    cin >> st;
    len = st.length();

    while (i<len) {
        char c = st[i];

        if (c=='L') {
            dir = (dir+3)%4;
        } else if (c=='R') {
            dir = (dir+1)%4;
        } else if (c=='F') {
            x += dx[dir]; y += dy[dir];
        }

        i++;

        if ((x==0) && (y==0)) {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;

    return 0;
}
#include <iostream>
#define DIR 4

using namespace std;

int main() {
    int dx[DIR] = {0, 1, 0, -1};
    int dy[DIR] = {1, 0, -1, 0};
    int dir=0;

    string st;
    cin >> st;
    int len = st.length();
    int i=0, x=0, y=0;

    while (len--) {
        char c=st[i];
        if (c=='L') {
            dir = (dir+3)%4;
        } else if (c=='R') {
            dir = (dir+1)%4;
        } else if (c=='F') {
            x += dx[dir];
            y += dy[dir];
        }
        i++;
    }

    cout << x << " " << y;

    return 0;
}
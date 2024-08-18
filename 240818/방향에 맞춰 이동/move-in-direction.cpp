#include <iostream>
using namespace std;

int main() {
    int N, x=0, y=0;
    cin >> N;
    while(N--) {
        char dir; int dis;
        cin >> dir >> dis;
        if (dir=='W') {
            x-=dis;
        } else if (dir=='S') {
            y-=dis;
        } else if (dir=='N') {
            y+=dis;
        } else {
            x+=dis;
        }
    }
    cout << x << " " << y;
    return 0;
}
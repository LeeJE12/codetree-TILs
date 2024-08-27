#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[20][20];

bool Counter(int x1, int y1, int x2, int y2) {
    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            if(arr[i][j] < 1) {
                return false;
            }
        }
    }
    return true;
}

int Rect(int x, int y) {
    int maxSquare;

    for(int i=x; i<n; i++) {
        for(int j=y; j<m; j++) {
            if(Counter(x, y, i, j)) {
                int square = (i-x+1) * (j-y+1);
                maxSquare = max(maxSquare, square);
            } else {
                break;
            }
        }
    }

    return maxSquare;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int mS=-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            mS= max(mS, Rect(i, j));
        }
    }

    cout << mS;
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[5][5];

bool RectOverlap(int x1, int y1, int x2, int y2, int nx1, int ny1, int nx2, int ny2) {
    return !(x2 < nx1 || nx2 < x1 || y2 < ny1 || ny2 < y1);
}


int Counter(int x1, int y1, int x2, int y2) {
    int cnt=0;
    for (int i=x1; i<=x2; i++) {
        for (int j=y1; j<=y2; j++) {
            cnt += arr[i][j];
        }
    }
    return cnt;
}

int SecondRect(int x1, int y1, int x2, int y2) {
    int cnt = -25000;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    if (!RectOverlap(x1, y1, x2, y2, i, j, k, l)) {
                        cnt = max(cnt, Counter(i, j, k, l));
                    }
                }
            }
        }
    }

    return cnt;
}

int FirstRect(int x, int y){
    int cnt, ans = -25000;

    for(int i = x; i < n; i++) {
        for(int j = y; j < m; j++) {
            cnt = Counter(x, y, i, j) + SecondRect(x, y, i, j);

            if (ans != cnt) {
                //cout << "x, y, i, j 는 차례대로 " << x << ", " << y << ", " << i << ", " << j << ", " << endl;
                //cout << "  counter: " << Counter(x, y, i, j) << ", secondRect: " << SecondRect(x, y, i, j) << endl;
                //cout << "  cnt: " << cnt << ", ans: " << ans << endl;
            }
            ans = max(ans, cnt);
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;

    int maxNum=-25000;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            //if (maxNum != FirstRect(i, j)) {
            //cout << i << ", " << j << "에서 다음과 같이 달랐습니다. " << maxNum << ", " << FirstRect(i, j) << endl;
            
            maxNum = max(maxNum, FirstRect(i, j));
        }
    }

    cout << maxNum;

    return 0;
}
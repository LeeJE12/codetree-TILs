#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string T;
    cin >> T;

    int len = T.length();

    string word[n]={};

    int cnt = 1;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<len; j++) {
            if (T[j] == str[j]) {
                continue;
            } else {
                cnt--;
                break;
            }
        }

        word[cnt] = str;
        cnt++;
    }
    
    sort(word, word+cnt);


    cout << word[k];

    return 0;
}
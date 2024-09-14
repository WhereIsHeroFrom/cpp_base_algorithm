#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int hash[256] = { 0 };
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        hash[s[i]]++;
    }
    int maxc = 0;
    char ret[256];
    int retSize = 0;

    for (char c = 'A'; c <= 'Z'; c++) {
        if (hash[c] > maxc) {
            maxc = hash[c];
            retSize = 0;
            ret[retSize++] = c;
        }
        else if (hash[c] == maxc) {
            ret[retSize++] = c;
        }
    }
    ret[retSize] = '\0';
    cout << ret << endl;


    return 0;
}
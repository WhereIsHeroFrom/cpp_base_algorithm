#include <iostream>
#include <string>
using namespace std;

string s, t;

int main()
{
    cin >> s;
    cin >> t;
    int n = s.size();
    int ret = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != t[i]) {
            s[i] = (s[i] == 'o' ? '*' : 'o');
            s[i + 1] = (s[i + 1] == 'o' ? '*' : 'o');
            ++ret;
        }
    }
    cout << ret << endl;
    return 0;
}
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    cin >> s;
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            break;
        }
        i += 1;
        j -= 1;
    }
    if (i >= j) {
        cout << "Y" << endl;
    }
    else {
        cout << "N" << endl;
    }

    return 0;
}
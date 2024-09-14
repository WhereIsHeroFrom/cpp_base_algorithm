#include <iostream>
#include <cstring>
using namespace std;

char s[1000];

int main()
{
    cin.getline(s, 101, '\n');
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i += 1;
        j -= 1;
    }
    cout << s << endl;
    return 0;
}
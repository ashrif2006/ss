#include <iostream>
using namespace std;

string charDependentN = "ABCDEFGHIJKLMNO";
string pattern(int n)
{
    string res = "";
    if (n == 1)
    {
        return "A";
    }
    res = pattern(n - 1) ;
    return res + charDependentN[n - 1] + res;
}

int main()
{
    int n;
    cin >> n;
    if(n<=0 || n>15)
    {
        return 0;
    }
    cout << pattern(n);

    return 0;
}
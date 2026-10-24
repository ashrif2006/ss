#include <iostream>
#include <vector>
using namespace std;


int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int totalXOR = 0;
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            totalXOR ^= a;
        }
        if(n%2!=0)
        {
            cout << totalXOR << endl;
        }
        else if(n%2==0 && totalXOR==0)
        {
            cout << 0 << endl;
        }
        else 
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
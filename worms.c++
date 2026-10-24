#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a , int target){
    int left = 0;
    int right = a.size() - 1;
    int res = -1;
    while(left <= right){
        int mid = left + (right - left) /2;
        if(a[mid] >=target){
            res = mid;
            right = mid -1;
        }
        else{
            left = mid +1;
        }
    }
    return res;
}               

int main ()
{
   int n;
   cin >> n;
   vector<int> calcSum(n); 
   for (int i = 0; i < n; i++)
   {
        int a;
        cin >> a;
        if(i==0)
        {
            calcSum[i] = a;
        }
        else
        {
            calcSum[i] = calcSum[i-1] + a;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << binarySearch(calcSum, x) + 1 << endl;
    }

    return 0;
}
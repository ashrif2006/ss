#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& a , int target){
    int left = 0;
    int right = a.size() - 1;
    int ans =0;
    while(left <= right){
        int mid = left + (right - left) /2;
        if(a[mid] <=target){
            ans = mid +1;
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << binarySearch(a, x) << endl;
    }
    

    return 0;
}
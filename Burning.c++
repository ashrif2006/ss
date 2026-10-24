/*
    1. أنا بحل إيه أصلًا؟
عندي رقمين:
- n: عدد السطور اللي لازم أكتبها على الأقل.
- k: معامل تقليل عدد السطور كل مرة.
أنا بختار رقم اسمه v، وده عدد السطور اللي هكتبها في البداية.
بعد كده، كل مرة بقسم عدد السطور السابق على k باستخدام Integer Division، يعني بنتجاهل الجزء العشري.
مثلًا لو v = 54 و k = 9:
المرة	عدد السطور
الأولى	54
الثانية	54 / 9 = 6
الثالثة	6 / 9 = 0
المجموع	60
لو المطلوب n = 59، يبقى 54 كفاية؛ لأن مجموع السطور 60.
لكن هل فيه رقم أصغر من 54 يكفي؟ نجرب 53:
\[
53+\lfloor 53/9\rfloor=53+5=58
\]

مش كفاية! إذن الإجابة هي 54.
هدفنا مش مجرد نلاقي رقم يحقق الشرط؛ هدفنا نلاقي أصغر رقم يحققه.
*/
#include <iostream>
#include <vector>
using namespace std;

bool check(int v, int n, int k)
{
    long long sum = 0;
    while (v > 0)
    {
        sum += v;
        v /= k;
    }
    return sum >= n;
}

int binarySearch(int k, int n)
{
    int left = 1;
    int right = n;
    int res = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, n, k))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << binarySearch(k, n) << endl;

    return 0;
}
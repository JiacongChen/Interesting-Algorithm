#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;

double w[N];

int main()
{
    double c;
    int n;
    cout << "请输入载重量c及古董个数n： " << endl;
    cin >> c >> n;
    cout << "请输入每个古董的重量，用空格分开： " << endl;
    for( int i=0 ; i<n ; i++ )
    {
        cin >> w[i];
    }
    sort(w, w+n);
    double temp = 0.0;
    int ans = 0;
    for( int i=0 ; i<n ; i++ )
    {
        temp += w[i];
        if(temp <= c)
            ans ++;
        else
            break;
    }
    cout << "能装入的古董最大数量为Ans = ";
    cout << ans << endl;
    return 0;
}
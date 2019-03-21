#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1000005;

struct three
{
    double w;
    double v;
    double p;
}s[M];

bool cmp(three a, three b)
{
    return a.p > b.p;
}

int main()
{
    int n;
    double m;
    cout << "请输入宝物数量n及毛驴的承载能力m： " << endl;
    cin >> n >> m;
    cout << "请输入每个宝物的重量和价值，用空格分开： " << endl;
    for( int i=0 ; i<n ; i++ )
    {
        cin >> s[i].w >> s[i].v;
        s[i].p = s[i].v / s[i].w;
    }
    sort(s, s+n, cmp);
    double sum = 0.0;
    for( int i=0 ; i<n ; i++ )
    {
        if( m>s[i].w )
        {
            m -= s[i].w;
            sum += s[i].v;
        }
        else
        {
            sum += m*s[i].p;
            break;
        }
    }
    cout << "装入宝物的最大价值Maximum value = " << sum << endl;
    return 0;
}

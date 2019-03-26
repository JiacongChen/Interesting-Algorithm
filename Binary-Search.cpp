#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int M = 10000;
int x, n, i;
int s[M];
int BinarySearch(int n, int s[], int x)
{
    int low = 0, high = n-1;
    while( low<=high )
    {
        int middle = ( low + high ) / 2;
        if( x==s[middle] )
        {
            return middle;
        }
        else if( x<s[middle] )
        {
            high = middle - 1;

        }
        else
        {
            low = middle + 1;
        } 
    }
    return -1;
}

int main()
{
    cout << "请输入数列中的元素个数n为： ";
    while( cin>>n )
    {
        cout << "请依次输入数列中的元素： ";
        for( i=0 ; i<n ; i++ )
        {
            cin >> s[i];
        }
        sort(s, s+n);
        cout << "排序后的数组为： ";
        for( i=0 ; i<n ; i++ )
        {
            cout << s[i] << " ";
        }
        cout << endl;
        cout << "请输入要查找的元素： ";
        cin >> x;
        i = BinarySearch(n, s, x);
        if( i==-1 )
        {
            cout << "该数组中没有要查找的元素！" << endl;
        }
        else
        {
            cout << "要查找的元素在第" << i+1 << "位" << endl;
        }
    }
    return 0;
}
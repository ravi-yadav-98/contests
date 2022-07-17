#include <bits/stdc++.h>
using namespace std;
/*
Print all the perfect square numbers <=N
ex: N = 20
output: 1,4,9,16
*/
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        float n;
        cin >> n;
        for(int i =1; i<=n; i++)
        {
            //if(sqrt(i) == (int)sqrt(i))
            if(floor(sqrt(i)) == ceil(sqrt(i)))
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        
    }

  return 0;
}
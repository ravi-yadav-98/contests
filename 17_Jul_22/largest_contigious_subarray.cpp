#include <bits/stdc++.h>
using namespace std;
/*
Given an array find the maximum sub array which has contigious elements
ex: 
input: [4,2,3,1,4,6,9]
output: 4 
[4,2,3,1]
*/

vector<int> contigious_max_SubArray(vector<int> arr)
{
    int cnt =0;
    int ix, iy;
    vector<int> ans;
    for(int i =0; i<arr.size()-1; i++)
    {
        int mini = arr[i];
        int maxi = arr[i];
        unordered_set<int> cd;
        cd.insert(arr[i]);
        for(int j =i+1; j<arr.size(); j++)
        {
            if(cd.find(arr[j]) != cd.end())
            {
                break;
            }
            cd.insert(arr[j]);
            mini = min(mini, arr[j]);
            maxi = max(maxi, arr[j]);
            if((maxi - mini) == (j-i))
            {
                int len = j-i+1;

                if(len > cnt)
                {
                   
                    
                    cnt = len;
                    ix = i;
                    iy = j;
                }
            }
        }
       
    }
     for(int i =ix; i<=iy; i++)
    {
        ans.push_back(arr[i]);
    }
        
    return ans;
}
int main(void)
{
    vector<int> arr = {11,13, 12, 4,2,43,1,51,6,9};
    vector<int> res = contigious_max_SubArray(arr);
    for(int a: res)
    {
        cout<<a<<" ";
    }

    
  return 0;
}
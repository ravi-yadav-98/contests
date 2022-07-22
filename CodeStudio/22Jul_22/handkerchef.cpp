#include <bits/stdc++.h>
using namespace std;
/*
You are given 'N' handkerchief and array 'A' consisting of non-negative integers where each element denotes the area of a handkerchief. you can create any number of stacks and put a handkerchief of area 'X' on any of the stacks if and only if the stack is empty or the handkerchief present at the top of the stack has an area strictly greater than 'X'.
Return the minimum number of stacks required so that all handkerchiefs are placed on some stack.
For Example:-
Let 'N' = 5, 'A' = [2, 5, 1, 5, 2] .
The answer is 2.
First stack:- [2, 5] (From top to bottom).
Second stack:- [1, 2, 5] (From top to bottom).
*/


/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the size of the array.
*/

int handkerChief(vector<int> &v){
    int n = v.size();

    // Creating a hashmap 'occ' with [key,value] pair as [integer,integer] for storing the occurrences.

    unordered_map<int, int> occ;

    for (int i = 0; i < n; i++){
        occ[v[i]]++;
    }

    // Creating variable 'mxValue' to store our answer.

    int mxValue = 0;

    for (auto i : occ){
        mxValue = max(mxValue, i.second);
    }

    // We our returning our answer here.

    return mxValue;
}
int main(void)
{

    vector<int> v = {2, 5, 1, 5, 2};
    cout<<handkerChief(v);
  return 0;
}
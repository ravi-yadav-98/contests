#include <bits/stdc++.h>
using namespace std;
/*
Minimum Palidrome:

You are given a string ‘S’ consisting of lowercase English characters. You need to create the minimum number of palindromic strings of length greater than 1 from ‘S’.
The characters you choose in a string need not be contiguous, and each character from ‘S’ needs to be present exactly once in any of the newly created palindromic strings.
If it’s impossible to create the strings in the above way, return the integer -1; otherwise, return the minimum number of palindromic strings of length greater than 1 that can be formed.
Example :
‘S’ = “abacaa”
We can create the strings “aba” and “aca”. Hence, the answer is 2.
*/

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the string 'S'.

*/


int minimumPalindromes(int n, string s) {

    // The array 'f' stores the frequency of each character.
    vector<int> f(26);

    // Iterate over all the characters.
    for (char c: s) {

        // Increase the frequency of character by 1.
        f[c - 'a']++;
    }

    // 'cnt' stores the number of characters which have odd frequency.
    int cnt = 0;

    // Iterate over all the characters possible.
    for (int i = 0; i < 26; ++i) {

        // If the frequency is odd.
        if (f[i] % 2) {

            // Increment 'cnt' by 1.
            cnt++;
        }
    }

    if (cnt > (n - cnt) / 2) {

        // Impossible to form the strings. Hence, return -1.
        return -1;
    }

    // If all the characters are of even frequency.
    if (cnt == 0) {

        // We need at least 1 string to keep all the even characters.
        return 1;
    }

    // Return the frequency of odd characters.
    return cnt;
}



int main(void)
{
    string s = "abacaa";
    int n = 6;
    cout<<minimumPalindromes(n, s)<<endl;
  return 0;
}
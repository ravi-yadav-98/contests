#include <bits/stdc++.h>
using namespace std;
/*
There are ‘N’ workers, and each worker has a skill level. The skill levels of the workers are given in array ‘A’. As the workers support each other, the skill level of all the workers in a group becomes equal to the maximum skill level of any worker in that group.
You want to group the workers such that the sum of the skill levels of all the workers is the maximum possible. There is no restriction on the number of groups.
But there is a catch. The workers in any group should be consecutive in the array, and each worker should be present in exactly one group. Also, a group can have at most ‘K’ workers.
Your task is to determine the maximum possible sum of skill levels of all the workers you can achieve by optimally forming groups.
*/


/*
    Time Complexity: O(2 ^ N)
    Space Complexity: O(N)

    where 'N' denotes the number of workers.
*/

/*
 * A helper function that recursively finds the answer.
 */
int maximumSkillSumHelper(int i, int k, vector<int> &a) {

    // If all the workers are grouped.
    if (i == -1) {

        // Return 0.
        return 0;
    }

    // 'ma' stores the maximum skill level in the current group.
    // 'res' stores the answer till the current index 'i'.
    int ma = a[i], res = 0;

    // Iterate over the workers which we include in the current group.
    for (int j = i; j >= max(i - k + 1, 0); --j) {

        // Update the maximum skill level.
        ma = max(ma, a[j]);

        // Calculate the result if the last group consists of workers between ['j', 'i'].
        res = max(res, ma * (i - j + 1) + maximumSkillSumHelper(j - 1, k, a));
    }

    // Return the result till the current index 'i'.
    return res;
}

int maximumSkillSum(int n, int k, vector<int> &a) {

    // Call the helper function for the last index 'n - 1'.
    return maximumSkillSumHelper(n - 1, k, a);
}

int main(void)
{

    int n = 3;
    int k =1;
    vector<int> v = {4,5,3};
    cout<<maximumSkillSum(n, k, v);
  return 0;
}
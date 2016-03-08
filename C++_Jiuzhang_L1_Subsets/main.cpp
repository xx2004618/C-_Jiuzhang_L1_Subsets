//
//  main.cpp
//  C++_Jiuzhang_L1_Subsets
//
//  Created by Xiao Xiang on 16/3/7.
//  Copyright © 2016年 Xiang Xiao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        vector<int> path;
        helper(nums, result, path, 0);
        return result;
    }
    void helper(vector<int> nums, vector<vector<int>> &result, vector<int> path, int index){
        result.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            helper(nums, result, path, i + 1);
            path.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

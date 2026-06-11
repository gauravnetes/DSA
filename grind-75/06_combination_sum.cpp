#include <vector>

using namespace std; 

class Solution {
public:
    void backtrack(vector<int> &candidates, int idx, int target, vector<vector<int>> &res, vector<int> &combination) {
        if(idx >= candidates.size() || target < 0) 
            return; 
        if(target == 0) {
            res.push_back(combination); 
            return; 
        } 

        combination.push_back(candidates[idx]); 

        // take 
        backtrack(candidates, idx, target - candidates[idx], res, combination); 

        combination.pop_back(); 

        // skip 
        backtrack(candidates, idx+1, target, res, combination); 
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> combination; 

        backtrack(candidates, 0, target, res, combination); 

        return res; 
    }
};
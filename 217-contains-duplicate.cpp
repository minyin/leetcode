#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (0==nums.size()) return false;
        for(int i=0;i<(nums.size()-1);i++){
        	if (nums[i] == nums[i+1]){
        		return true;
        	}
        }
        return false;
    }
    bool ifcontainsDuplicate(vector<int>& nums) {
        if (0==nums.size()) return false;        
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(set.end() == set.find(nums[i])){
                set.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
	vector<int> v;
	int a[10] = {1,2,3,4,5,0};
	for(int i=0;i<6;i++){
		v.push_back(a[i]);
	}
	Solution s1;
	cout << s1.containsDuplicate(v) << endl;
    cout << s1.ifcontainsDuplicate(v) << endl;    
}
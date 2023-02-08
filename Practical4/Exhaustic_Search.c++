#include<bits/stdc++.h>
using namespace std;

void exhaustive_search(vector<int>& nums, int target) { // Function to perform exhaustive search
  for (int i = 0; i < nums.size(); i++) { //iterate through first loop
    for (int j = i + 1; j < nums.size(); j++) { //iterate through second loop
      if (nums[i] + nums[j] == target) { //if targer found return index
        cout << "Pair found at index " << i << " and " << j << endl;
        return;
      }
    }
  }
  cout << "Pair not found" << endl;
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  exhaustive_search(nums, target);

  return 0;
}

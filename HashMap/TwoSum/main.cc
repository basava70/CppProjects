/**
 * Copyright Seshadri Basava 2023
 * Code for Two Sum
 * Written on July 14
 *
 * */

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twosum(std::vector<int> &arr, int target) {
    std::vector<int> answer(2);
    std::vector<int> hash_map(10, -1);
    for (int i = 0; i < arr.size(); i++) {
      if (hash_map[arr[i]] == -1)
        hash_map[target - arr[i]] = i;
      else {
        answer[0] = hash_map[arr[i]];
        answer[1] = i;
        break;
      }
    }
    return answer;
  }
};

int main() {
  Solution solution;
  std::vector<int> ans{2, 7, 11, 15};
  int target = 9;
  std::vector<int> answer = solution.twosum(ans, target);
  std::cout << "answer = " << answer[0] << " " << answer[1] << std::endl;

  return 0;
}

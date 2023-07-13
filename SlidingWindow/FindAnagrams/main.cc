/*
 * This program is part of Sliding window practise exercise.
 * C++ Program to find all anagrams of a given pattern
 * p in a given string s
 * constraints: lower case letter, 1 <= s.length, p.length <= 3*100000
 *
 */
#include <iostream>
#include <string>
#include <vector>

class Solution {

public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    int s_len = s.length();
    int p_len = p.length();

    if (s_len < p_len)
      return {};

    std::vector<int> freq_p(26, 0);
    std::vector<int> window(26, 0);

    for (int i = 0; i < p_len; i++) {
      freq_p[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    std::vector<int> ans;
    if (freq_p == window)
      ans.push_back(0);

    for (int i = p_len; i < s_len; i++) {
      window[s[i] - 'a']++;
      window[s[i - p_len] - 'a']--;
      if (freq_p == window)
        ans.push_back(i - p_len + 1);
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {

  std::string s, p;
  std::cout << "Enter the full string" << std::endl;
  std::cin >> s;
  std::cout << "Enter the pattern" << std::endl;
  std::cin >> p;

  std::vector<int> answer;

  Solution solution;
  answer = solution.findAnagrams(s, p);
  std::cout << "Answer : [ ";
  for (int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << " ";
  std::cout << "]" << std::endl;
}

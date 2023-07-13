/*
 * This program is part of Sliding window practise exercise.
 * C++ Program to find minimum window containing all characters
 * of the given string p
 * constraints: lower case and upper case letters, 1 <= s.length, p.length <=
 * 1000000
 *
 */
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

// template <typename S>
// std::ostream &operator<<(std::ostream &os, const std::vector<S> &vector) {
//   // Printing all the elements
//   // using <<
//   for (auto element : vector) {
//     os << element << " ";
//   }
//   return os;
// }
//
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::vector<int> map(128, 0);

    for (auto c : t)
      map[c]++;

    std::cout << " map [A] : " << map[65] << std::endl;
    std::cout << " map [B] : " << map[66] << std::endl;
    std::cout << " map [C] : " << map[67] << std::endl;
    std::cout << " map [D] : " << map[68] << std::endl;
    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;

    while (end < s.size()) {
      std::cout << " ************************************ " << std::endl;
      std::cout << "s[" << end << "] = " << s[end] << std::endl;
      std::cout << "map[" << s[end] << "] = " << map[s[end]] << std::endl;
      if (map[s[end++]]-- > 0)
        counter--; // in t
                   //
      std::cout << " ==================================== " << std::endl;
      std::cout << "counter = " << counter << std::endl;
      std::cout << " map [A] : " << map[65] << std::endl;
      std::cout << " map [B] : " << map[66] << std::endl;
      std::cout << " map [C] : " << map[67] << std::endl;
      std::cout << " ==================================== " << std::endl;

      while (counter == 0) { // valid
        std::cout << " ********** counter == 0 loop begin ************** "
                  << std::endl;
        if (end - begin < d)
          d = end - (head = begin);
        std::cout << " s[" << begin << "] = " << s[begin] << std::endl;
        std::cout << "map[" << s[begin] << "] = " << map[s[begin]] << std::endl;
        if (map[s[begin++]]++ == 0) {
          std::cout << " ***** in maps[begin+++]++ == 0 loop **** "
                    << std::endl;
          counter++; // make it invalid
          std::cout << "map[" << s[begin - 1] << "] = " << map[s[begin - 1]]
                    << std::endl;
          std::cout << "counter = " << counter << std::endl;
        }
        std::cout << " ********** counter == 0 loop end ************** "
                  << std::endl;
      }
      std::cout << " ************************************ " << std::endl;
    }
    return d == INT_MAX ? "" : s.substr(head, d);
  }
};

int main(int argc, char *argv[]) {
  std::string s, t;
  // std::cout << "Enter the full string" << std::endl;
  // std::cin >> s;
  s = "ADOBECODEBANC";
  t = "ABC";
  // std::cout << "Enter the pattern" << std::endl;
  // std::cin >> p;
  int a = 2;
  if (a-- > 1)
    std::cout << "a-- > 1" << std::endl;
  if (a-- > 0)
    std::cout << "a-- > 0" << std::endl;
  std::cout << " a = " << a << std::endl;
  if (a++ == 0)
    std::cout << "a++ == 0" << std::endl;
  std::cout << " a = " << a << std::endl;
  Solution solution;
  std::string answer = solution.minWindow(s, t);
  std::cout << "Output :" << answer << std::endl;
}

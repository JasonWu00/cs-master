#include <vector>

std::vector<int> digitCount(std::vector<int> input) {
  int ones = 0;
  int tens = 0;
  int others = 0;
  for (int i = 0; i < vector.size(); i++) {
    if (vector[i] < 10 && vector[i] > -10) {
      ones++;
    }
    else if (vector[i] < 100 && vector[i] > -100) {
      tens++;
    }
    else {
      others++;
    }
  }
  std::vector<int> output;
  output.push_back(ones);
  output.push_back(tens);
  output.push_back(others);
  return output;
}

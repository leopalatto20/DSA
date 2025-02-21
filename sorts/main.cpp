#include "Nums.h"
#include <ctime>
#include <iostream>

int main() {
  srand(time(nullptr));
  Nums nums;
  nums.createNums(200);
  nums.generateNums();
  nums.displayNums();

  std::cout << std::endl;
  nums.bubbleSort();
  nums.displayNums();

  return 0;
}

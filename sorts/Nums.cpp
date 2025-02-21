#include "Nums.h"
#include <iostream>
#include <new>

/* initialize the array and size as nulls, because we dont have a way to halt
 * the constructor if there is not enough memory for the new array */
Nums::Nums() : nums(nullptr), size(0) {}

Nums::~Nums() { deleteNums(); }

/* separate function called in the destructor, it can also be used to delete the
 * array to create a new one without having to create a new object */
void Nums::deleteNums() {
  if (!nums)
    return;
  delete[] nums;
  this->nums = nullptr;
  size = 0;
}

/* this method creates an empty array with an specified size, it validates the
 * pointer created and asigns the new size of the array so it can be passed to
 * the sorts */
bool Nums::createNums(unsigned int size) {
  if (nums)
    deleteNums();
  this->nums = new (std::nothrow) int[size];
  if (!nums)
    return false;
  this->size = size;
  return true;
}

/* this is where the numbers are now generated, it is in a separate function to
 * that we can reuse it without having to delete and create new arrays */
void Nums::generateNums() {
  for (unsigned int i = 0; i < size; i++) {
    nums[i] = rand() % 100;
  }
}

void Nums::displayNums() {
  for (unsigned int i = 0; i < size; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}

/* self made method to swap numbers to make the sorts more legible */
void Nums::swap(int &num1, int &num2) {
  int tmp = num2;
  num2 = num1;
  num1 = tmp;
}

void matar(unsigned int hola) { std::cout << hola << "fortnite" << std::endl; }
/*optimized bubble sort, after each iteration the last number is automatically
 * the biggest one,*/
/*so we dont need to reach that number anymore*/
void Nums::bubbleSort() {
  for (unsigned int i = 0; i < size - 1; i++) {
    for (unsigned int j = 0; j < size - 1;
         j++) { // iterate until the second to last biggest number of that
                // iteration
      if (nums[j] > nums[j + 1])
        swap(nums[j], nums[j + 1]);
    }
  }
}

void Nums::insertionSort() {
  for (int i = 1; i < size; i++) {
    int index = i - 1;
    int temp = nums[i];
    while (index >= 0 && nums[index] > temp) {
      nums[index + 1] = nums[index];
      index--;
    }
    nums[index + 1] = temp;
  }
}

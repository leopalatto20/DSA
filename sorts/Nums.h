#pragma once

class Nums {
private:
  int *nums;
  unsigned int size;
  void swap(int &num1, int &num2);

public:
  Nums();
  ~Nums();
  void deleteNums();
  bool createNums(unsigned int size);
  void generateNums();
  void displayNums();
  void bubbleSort();
  void insertionSort();
};

#include <iostream>

#include "multiply.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Invalid command line arguments" << std::endl;
  }
  Multiplier m = Multiplier(std::string(argv[1]), std::string(argv[2]));
  m.readInput();
  m.printMatrix(m.mMatrixA);
  m.printMatrix(m.mMatrixB);
  m.multiply();
  m.printMatrix(m.mOutputMatrix);

  return 0;
}
#include <fstream>
#include <iostream>

#include "matrix.h"

int main(int argc, char *argv[]) {
  // Makes sure all necessary files are supplied
  if (argc != 4) {
    std::cerr << "Invalid command line arguments" << std::endl;
    exit(3);
  }
  // Creates matrices
  Matrix m1 = Matrix(std::string(argv[1]));
  Matrix m2 = Matrix(std::string(argv[2]));
  Matrix m3 = m1 * m2;

  // Outputs results
  std::ofstream outFile = std::ofstream(std::string(argv[3]));
  if (!outFile) {
    std::cerr << "Invalid output file. (something may be wrong, this file "
                 "should be created)"
              << std::endl;
    exit(0);
  }

  outFile << "Matrix 1:" << std::endl
          << m1 << std::endl
          << "Matrix 2:" << std::endl
          << m2 << std::endl
          << "Matrix 1 * Matrix 2:" << std::endl
          << m3 << std::endl;

  std::cout << "Multiplication successful! (Check output file)." << std::endl;

  return 0;
}
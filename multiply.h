#pragma once

#include <vector>

struct Multiplier {
  Multiplier(std::string input, std::string output);

  void printMatrix(std::vector<std::vector<int> >& matrix);

  void multiply();

  void readInput();

  int mColA;
  int mRowA;
  int mColB;
  int mRowB;

  std::string mInput;
  std::string mOutput;

  std::vector<std::vector<int> > mMatrixA;
  std::vector<std::vector<int> > mMatrixB;
  std::vector<std::vector<int> > mOutputMatrix;
};

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "multiply.h"

Multiplier::Multiplier(std::string input, std::string output)
    : mInput(input), mOutput(output) {
  std::ofstream outFile;
  outFile.open(mOutput, std::ofstream::out | std::ofstream::trunc);
  outFile.close();
}

void Multiplier::printMatrix(std::vector<std::vector<int> >& matrix) {
  std::ofstream outFile(mOutput, std::ios_base::app);
  if (!outFile) {
    std::cerr << "Invalid output file." << std::endl;
    exit(3);
  }

  for (std::vector<int> i : matrix) {
    for (int j : i) {
      outFile.fill(' ');
      outFile.width(3);
      outFile << j << " ";
    }
    outFile << std::endl;
  }
  outFile << std::endl;
  outFile.close();
}

void Multiplier::multiply() {
  mOutputMatrix =
      std::vector<std::vector<int> >(mColA, std::vector<int>(mRowB, 0));

  for (int i = 0; i < mColA; i++) {
    for (int j = 0; j < mRowB; j++) {
      mOutputMatrix[i][j] = 0;

      for (int k = 0; k < mColB; k++) {
        mOutputMatrix[i][j] += mMatrixA[i][k] * mMatrixB[k][j];
      }
    }
  }
}

void Multiplier::readInput() {
  std::ifstream inFile(mInput);
  if (!inFile) {
    std::cerr << "Invalid input file." << std::endl;
    exit(0);
  }

  inFile >> mRowA;
  inFile >> mColA;
  inFile >> mRowB;
  inFile >> mColB;

  if (mColA != mRowB) {
    std::cerr << "Matrices cannot be multiplied." << std::endl;
    exit(1);
  }

  mMatrixA = std::vector<std::vector<int> >(mColA, std::vector<int>(mRowA, 0));
  mMatrixB = std::vector<std::vector<int> >(mColB, std::vector<int>(mRowB, 0));
  for (int i = 0; i < mColA; ++i) {
    for (int j = 0; j < mRowA; ++j) {
      inFile >> mMatrixA[i][j];
    }
  }
  for (int i = 0; i < mColB; ++i) {
    for (int j = 0; j < mRowB; ++j) {
      inFile >> mMatrixB[i][j];
    }
  }
}
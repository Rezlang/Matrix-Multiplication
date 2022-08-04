#include "matrix.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

Matrix::Matrix(const std::string& input) {
  std::ifstream inFile(input);
  if (!inFile) {
    std::cerr << "Invalid input file." << std::endl;
    exit(0);
  }

  inFile >> mCols;
  inFile >> mRows;
  // create data vector with specified sizes
  mData = std::vector<std::vector<int> >(mRows, std::vector<int>(mCols, 0));
  // populate data vector
  for (int i = 0; i < mRows; ++i) {
    for (int j = 0; j < mCols; ++j) {
      inFile >> mData[i][j];
    }
  }
}

// Populates member variables
Matrix::Matrix(std::vector<std::vector<int> >& inputGrid)
    : mData(std::move(inputGrid)),
      mRows(inputGrid.size()),
      mCols(inputGrid[0].size()) {}

Matrix Matrix::operator*(Matrix b) const {
  // checks to see if multiplication is valid
  if (mCols != b.mRows) {
    std::cerr << "Matrices cannot be multiplied." << std::endl;
    exit(1);
  }
  std::vector<std::vector<int> > outputGrid(mRows,
                                            std::vector<int>(b.mCols, 0));
// Populates output data
#pragma omp parallel for
  for (int i = 0; i < mRows; i++) {
    for (int j = 0; j < b.mCols; j++) {
      outputGrid[i][j] = 0;

      for (int k = 0; k < b.mRows; k++) {
        outputGrid[i][j] += mData[i][k] * b.mData[k][j];
      }
    }
  }

  return Matrix(outputGrid);
}

// Output operator overload
std::ostream& operator<<(std::ostream& out, const Matrix& m) {
  for (std::vector<int> column : m.mData) {
    for (int num : column) {
      out.fill(' ');
      out.width(3);
      out << num << " ";
    }
    out << std::endl;
  }
  return out;
}
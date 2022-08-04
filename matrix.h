#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Matrix {
  // Constructor to read in data
  Matrix(const std::string& input);

  // Constructor for previously created matrix data
  Matrix(std::vector<std::vector<int> >& inputGrid);

  // * Operator overload
  Matrix operator*(Matrix b) const;

  // Output operator overload
  friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

  // Member Variables
  int mCols;
  int mRows;
  std::vector<std::vector<int> > mData;
};
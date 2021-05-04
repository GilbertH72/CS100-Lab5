#include "spreadsheet.cpp"

#include "gtest/gtest.h"

#include "select_contains_test.hpp"
#include "select_not_test.hpp"
#include "select_or_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

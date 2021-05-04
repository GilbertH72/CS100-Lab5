#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"

#include "spreadsheet.cpp"
#include "select_contains.hpp"

TEST(ContainsTest, FirstColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    Select* test = new Select_Contains(&sheet, "First", "Jesse");
    EXPECT_EQ(test->select(&sheet, 1), true);
}

TEST(ContainsTest, LastColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    Select* test = new Select_Contains(&sheet, "Last", "Doe");
    EXPECT_EQ(test->select(&sheet, 0), true);
}

TEST(ContainsTest, AgeColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    Select* test = new Select_Contains(&sheet, "Age", "23");
    EXPECT_EQ(test->select(&sheet, 1), true);
}

TEST(ContainsTest, MajorColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    Select* test = new Select_Contains(&sheet, "Major", "Civil Engineering");
    EXPECT_EQ(test->select(&sheet, 0), true);
}

TEST(ContainsTest, FirstColumnFalse) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    Select* test = new Select_Contains(&sheet, "First", "Derek");
    EXPECT_EQ(test->select(&sheet, 1), false);
}


#endif

#ifndef __SELECT_NOT_TEST_HPP__
#define __SELECT_NOT_TEST_HPP__

#include "gtest/gtest.h"

#include "spreadsheet.hpp"
#include "select_not.hpp"

TEST(NotTest, FirstColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First", "Jesse")));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jane Doe 25 Civil Engineering \n");
}

TEST(NotTest, LastColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Last", "Doe")));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jesse James 23 Business \n");
}

TEST(NotTest, AgeColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Age", "23")));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jane Doe 25 Civil Engineering \n");
}

TEST(NotTest, MajorColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "Major", "Civil Engineering")));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jesse James 23 Business \n");
}

TEST(NotTest, FirstColumnFalse) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Not(new Select_Contains(&sheet, "First", "Derek")));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jane Doe 25 Civil Engineering \nJesse James 23 Business \n");
}

#endif


#ifndef __SELECT_CONTAINS_TEST_HPP__
#define __SELECT_CONTAINS_TEST_HPP__

#include "gtest/gtest.h"

#include "spreadsheet.hpp"
#include "select_contains.hpp"

TEST(ContainsTest, FirstColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Contains(&sheet, "First", "Jesse"));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jesse James 23 Business \n");
}

TEST(ContainsTest, LastColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Contains(&sheet, "Last", "Doe"));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jane Doe 25 Civil Engineering \n");
}

TEST(ContainsTest, AgeColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Contains(&sheet, "Age", "23"));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jesse James 23 Business \n");
}

TEST(ContainsTest, MajorColumn) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection(new Select_Contains(&sheet, "Major", "Civil Engineering"));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "Jane Doe 25 Civil Engineering \n");
}

TEST(ContainsTest, FirstColumnFalse) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Jane", "Doe", "25", "Civil Engineering"});
    sheet.add_row({"Jesse", "James", "23", "Business"});
    sheet.set_selection( new Select_Contains(&sheet, "First", "Derek"));
    std::stringstream out;
    sheet.print_selection(out);
    EXPECT_EQ(out.str(), "");
}


#endif

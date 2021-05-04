#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__

#include "gtest/gtest.h"
#include "select_and.hpp"
#include "spreadsheet.hpp"
#include "select_contains.hpp"

TEST(Select_And_Test, EvalualteAnd) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "Grade" });
   sheet.add_row({ "John", "Smith", "Sophomore" });
   sheet.add_row({ "Jesse", "James", "Junior" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "John"), 
      new Select_Contains(&sheet, "Last", "Smith")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "John Smith Sophomore \n");
}

TEST(Select_And_Test, Evaluate2And) {
   Spreadsheet sheet;
   sheet.set_column_names({ "Name","Species","Age", "Legs" });
   sheet.add_row({ "Tucker","dog","3","4" });
   sheet.add_row({ "Daisy","dog","4","4" });
   sheet.add_row({ "Patches","cat","2","4" });
   sheet.add_row({ "Lily","fish","1","0" });
   sheet.add_row({ "Tweety","bird","2","2" });
   sheet.add_row({ "Tucker","hamster","2","4" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "Species", "dog"),
      new Select_And(new Select_Contains(&sheet, "Age", "3"), new Select_Contains(&sheet, "Name", "Tucker"))));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Tucker dog 3 4 \n");
}

TEST(Select_And_Test, AndNothing) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "MonthOfBirth" });
   sheet.add_row({ "Orlean", "Lazaro", "10" });
   sheet.add_row({ "Carl", "Evans", "5" });
   sheet.add_row({ "Harold", "Jankins", "12" });
   sheet.add_row({ "Mat", "Huntar", "5" });
   sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "z"),
      new Select_Contains(&sheet, "Last", "q")));
   std::stringstream out;
   sheet.print_selection(out);
   EXPECT_EQ(out.str(), "");
}

#endif // //__SELECT_AND_TEST_HPP__

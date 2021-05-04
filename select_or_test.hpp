#ifndef __SELECT_OR_TEST_HPP__
#define __SELECT_OR_TEST_HPP__

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "select_or.hpp"
#include "select_contains.hpp"

TEST(Select_Or_Test, EvalualteOr) {
   Spreadsheet sheet;
   sheet.set_column_names({ "Name","Species","Age", "Legs" });
   sheet.add_row({ "Tucker","dog","3","4" });
   sheet.add_row({ "Daisy","dog","4","4" });
   sheet.add_row({ "Patches","cat","2","4" });
   sheet.add_row({ "Lily","fish","1","0" });
   sheet.add_row({ "Tweety","bird","2","2" });

   sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "Species", "cat"), new Select_Contains(&sheet, "Age", "3")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Tucker dog 3 4 \nPatches cat 2 4 \n");
}

TEST(Select_Or_Test, CertainOrParameters) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First","Last","Age","Major" });
   sheet.add_row({ "Amanda","Andrews","22","business" });
   sheet.add_row({ "Brian","Becker","21","computer science" });
   sheet.add_row({ "Carol","Conners","21","computer science" });
   sheet.add_row({ "Joe","Jackson","21","mathematics" });
   sheet.add_row({ "Sarah","Summers","21","computer science" });
   sheet.add_row({ "Diane","Dole","20","computer engineering" });
   sheet.add_row({ "David","Dole","22","electrical engineering" });
   sheet.add_row({ "Dominick","Dole","22","communications" });
   sheet.add_row({ "George","Genius","9","astrophysics" });
   sheet.set_selection(new Select_Or(
      new Select_Contains(&sheet, "Major", "engineering"),
      new Select_Contains(&sheet, "Last", "Dole")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "Diane Dole 20 computer engineering \nDavid Dole 22 electrical engineering \nDominick Dole 22 communications \n");
}

TEST(Select_Or_Test, EvaluateOrNothing) {
   Spreadsheet sheet;
   sheet.set_column_names({ "First", "Last", "MonthOfBirth" });
   sheet.add_row({ "Orlean", "Lazaro", "10" });
   sheet.add_row({ "Carl", "Evans", "5" });
   sheet.add_row({ "Harold", "Jenkins", "12" });
   sheet.add_row({ "Mat", "Hunter", "5" });
   sheet.set_selection(new Select_Or(new Select_Contains(&sheet, "MonthOfBirth", "4"),
      new Select_Contains(&sheet, "First", "s")));
   std::stringstream out;
   sheet.print_selection(out);

   EXPECT_EQ(out.str(), "");
}

#endif // __SELECT_OR_TEST_HPP__

#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"
#include "spreadsheet.hpp"

class Select_Or : public Select
{
protected:
   Select* sPtr1 = nullptr;
   Select* sPtr2 = nullptr;

public:
   Select_Or(Select* obj1, Select* obj2)
   {
      this->sPtr1 = obj1;
      this->sPtr2 = obj2;
   }

   ~Select_Or()
   {
      delete sPtr1;
      delete sPtr2;
   }

   virtual bool select(const Spreadsheet* sheet, int row) const
   {
      if (sPtr1->select(sheet, row) == true || sPtr2->select(sheet, row) == true) return true;
      return false;
   }

};

#endif //__SELECT_OR_HPP__

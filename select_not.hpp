#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"

class Select_Not : public Select {
protected: // Protected or Private
    Select* sPtr1;
public:
    Select_Not(Select* selectObj1)
    {
        sPtr1 = selectObj1;
    }

    ~Select_Not()
    {  
        delete sPtr1;
    }  

    bool select(const Spreadsheet* sheet, int row) const
    {
        if (!sPtr1->select(sheet, row))
	    return true;

	return false;    
    }

};

#endif //__SELECT_NOT_HPP__

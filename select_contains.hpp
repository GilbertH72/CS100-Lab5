#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include <cstring>
#include "select.hpp"

class Select_Contains : public Select
{
protected:
    std::string column;
    std::string name;
public:
    Select_Contains(const Spreadsheet* sheet, std::string column, std::string name) {
	this->column = column;
	this->name = name;
    }

    // Return true if the specified row should be selected.
    bool select(const Spreadsheet* sheet, int row) const {
	if (sheet->cell_data(row, sheet->get_column_by_name(column)) == name)
	    return true;
	
	return false;
    }
};

#endif

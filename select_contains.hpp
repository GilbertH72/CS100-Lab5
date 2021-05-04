#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include <cstring>
#include "select.hpp"

class Select_Contains : public Select {
protected:
	int column;
	std::string subStr;
public:
	Select_Contains(const Spreadsheet* sheet, const std::string& name, const std::string& query) {
		column = sheet->get_column_by_name(name);
		this->subStr = query;
	}
	virtual bool select(const Spreadsheet* sheet, int row) const {
		return (sheet->cell_data(row, column).find(subStr) != std::string::npos) ? true : false;
	}
};

#endif

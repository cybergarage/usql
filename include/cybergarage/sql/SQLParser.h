#ifndef CG_SQLPARSER_H
#define CG_SQLPARSER_H

#include <string>

namespace uSQL {

class SQLParser {

public:

	SQLParser();

	virtual bool parse(const std::string &queryString) = 0;
};

}

#endif

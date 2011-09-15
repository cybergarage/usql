#ifndef CG_SQL92PARSER_H
#define CG_SQL92PARSER_H

#include <cybergarage/sql/SQLParser.h>

namespace uSQL {

class SQL92Parser : public SQLParser {

public:

	SQL92Parser();

	bool parse(const std::string &queryString);
};

}

#endif

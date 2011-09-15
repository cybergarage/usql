#ifndef CG_GQLPARSER_H
#define CG_GQLPARSER_H

#include <cybergarage/sql/SQLParser.h>

namespace uSQL {

class GQLParser  : public SQLParser {

public:

	GQLParser();

	bool parse(const std::string &queryString);
};

}

#endif

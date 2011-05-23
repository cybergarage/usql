#include <string>

class SQLParser {
public:
	SQLParser();

	bool parse(const std::string &queryString);
};

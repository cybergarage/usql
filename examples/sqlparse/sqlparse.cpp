/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
///////////////////////////////////////////////////////////////////////////////
//
//  A mini XML-like parser
//
//  [ JDG March 25, 2007 ]   spirit2
//
///////////////////////////////////////////////////////////////////////////////
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace cybergarage
{
    namespace fusion = boost::fusion;
    namespace phoenix = boost::phoenix;
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    ///////////////////////////////////////////////////////////////////////////
    //  Our mini XML tree representation
    ///////////////////////////////////////////////////////////////////////////
    struct sql;

    typedef
        boost::variant<
            boost::recursive_wrapper<sql>
          , std::string
        >
    sql_node;

    struct sql
    {
        std::string name;                           // tag name
        std::vector<sql_node> children;        // children
    };
}

// We need to tell fusion about our sql struct
// to make it a first-class fusion citizen
BOOST_FUSION_ADAPT_STRUCT(
    cybergarage::sql,
    (std::string, name)
    (std::vector<cybergarage::sql_node>, children)
)

namespace cybergarage
{
    ///////////////////////////////////////////////////////////////////////////
    //  Print out the mini sql tree
    ///////////////////////////////////////////////////////////////////////////
    int const tabsize = 4;

    void tab(int indent)
    {
        for (int i = 0; i < indent; ++i)
            std::cout << ' ';
    }

    struct sql_printer
    {
        sql_printer(int indent = 0)
          : indent(indent)
        {
        }

        void operator()(sql const& sql) const;

        int indent;
    };

    struct sql_node_printer : boost::static_visitor<>
    {
        sql_node_printer(int indent = 0)
          : indent(indent)
        {
        }

        void operator()(sql const& sql) const
        {
            sql_printer(indent+tabsize)(sql);
        }

        void operator()(std::string const& text) const
        {
            tab(indent+tabsize);
            std::cout << "text: \"" << text << '"' << std::endl;
        }

        int indent;
    };

    void sql_printer::operator()(sql const& sql) const
    {
        tab(indent);
        std::cout << "tag: " << sql.name << std::endl;
        tab(indent);
        std::cout << '{' << std::endl;

        BOOST_FOREACH(sql_node const& node, sql.children)
        {
            boost::apply_visitor(sql_node_printer(indent), node);
        }

        tab(indent);
        std::cout << '}' << std::endl;
    }

    ///////////////////////////////////////////////////////////////////////////
    //  Our mini XML grammar definition
    ///////////////////////////////////////////////////////////////////////////
    //[tutorial_sql3_grammar
    template <typename Iterator>
    struct sql_grammar
      : qi::grammar<Iterator, sql(), qi::locals<std::string>, ascii::space_type>
    {
        sql_grammar()
          : sql_grammar::base_type(sql, "sql")
        {
            using qi::lit;
            using qi::lexeme;
            using qi::on_error;
            using qi::fail;
            using ascii::char_;
            using ascii::string;
            using namespace qi::labels;

            using phoenix::construct;
            using phoenix::val;

            text %= lexeme[+(char_ - '<')];
            node %= sql | text;

            start_tag %=
                    '<'
                >>  !lit('/')
                >   lexeme[+(char_ - '>')]
                >   '>'
            ;

            end_tag =
                    "</"
                >   string(_r1)
                >   '>'
            ;

            sql %=
                    start_tag[_a = _1]
                >   *node
                >   end_tag(_a)
            ;

            sql.name("sql");
            node.name("node");
            text.name("text");
            start_tag.name("start_tag");
            end_tag.name("end_tag");

            on_error<fail>
            (
                sql
              , std::cout
                    << val("Error! Expecting ")
                    << _4                               // what failed?
                    << val(" here: \"")
                    << construct<std::string>(_3, _2)   // iterators to error-pos, end
                    << val("\"")
                    << std::endl
            );
        }

        qi::rule<Iterator, sql(), qi::locals<std::string>, ascii::space_type> sql;
        qi::rule<Iterator, sql_node(), ascii::space_type> node;
        qi::rule<Iterator, std::string(), ascii::space_type> text;
        qi::rule<Iterator, std::string(), ascii::space_type> start_tag;
        qi::rule<Iterator, void(std::string), ascii::space_type> end_tag;
    };
    //]
}

///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    char const* filename;
    if (argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        std::cerr << "Error: No input file provided." << std::endl;
        return 1;
    }

    std::ifstream in(filename, std::ios_base::in);

    if (!in)
    {
        std::cerr << "Error: Could not open input file: "
            << filename << std::endl;
        return 1;
    }

    std::string storage; // We will read the contents here.
    in.unsetf(std::ios::skipws); // No white space skipping!
    std::copy(
        std::istream_iterator<char>(in),
        std::istream_iterator<char>(),
        std::back_inserter(storage));

    typedef cybergarage::sql_grammar<std::string::const_iterator> sql_grammar;
    sql_grammar sql; // Our grammar
    cybergarage::sql ast; // Our tree

    using boost::spirit::ascii::space;
    std::string::const_iterator iter = storage.begin();
    std::string::const_iterator end = storage.end();
    bool r = phrase_parse(iter, end, sql, space, ast);

    if (r && iter == end)
    {
        std::cout << "-------------------------\n";
        std::cout << "Parsing succeeded\n";
        std::cout << "-------------------------\n";
        cybergarage::sql_printer printer;
        printer(ast);
        return 0;
    }
    else
    {
        std::cout << "-------------------------\n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------\n";
        return 1;
    }
}



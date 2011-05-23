/*
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include "SqlEngineTestCase.h"

int main( int argc, char* argv[] )
{
  // Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that colllects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener( &result );        

  // Add a listener that print dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener( &progress );      

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
  runner.run( controller );

  // Print test in a compiler compatible format.
  CPPUNIT_NS::CompilerOutputter outputter( &result, std::cerr );
  outputter.write(); 

  return result.wasSuccessful() ? 0 : 1;
}
*/

/*
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace client
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    
    ///////////////////////////////////////////////////////////////////////////
    //  Our number list parser
    ///////////////////////////////////////////////////////////////////////////
    //[tutorial_numlist1
    template <typename Iterator>
    bool parse_numbers(Iterator first, Iterator last)
    {
        using qi::double_;
        using qi::phrase_parse;
        using ascii::space;
        
        bool r = phrase_parse(
                              first,                          // < start iterator >
                              last,                           // < end iterator >
                              double_ >> *(',' >> double_),   // < the parser >
                              space                           // < the skip-parser >
                              );
        if (first != last) // fail if we did not get a full match
            return false;
        return r;
    }
    //]
}

////////////////////////////////////////////////////////////////////////////
//  Main program
////////////////////////////////////////////////////////////////////////////
int
main()
{
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "\t\tA comma separated list parser for Spirit...\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";
    
    std::cout << "Give me a comma separated list of numbers.\n";
    std::cout << "Type [q or Q] to quit\n\n";
    
    std::string str;
    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;
        
        if (client::parse_numbers(str.begin(), str.end()))
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << str << " Parses OK: " << std::endl;
        }
        else
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }
    
    std::cout << "Bye... :-) \n\n";
    return 0;
}

*/

/*=============================================================================
 Copyright (c) 2001-2010 Joel de Guzman
 
 Distributed under the Boost Software License, Version 1.0. (See accompanying
 file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 =============================================================================*/
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

#include <iostream>

// Presented are various ways to attach semantic actions
//  * Using plain function pointer
//  * Using simple function object
//  * Using boost.bind with a plain function
//  * Using boost.bind with a member function
//  * Using boost.lambda

//[tutorial_semantic_action_functions
namespace client
{
    namespace qi = boost::spirit::qi;
    
    // A plain function
    void print(int const& i)
    {
        std::cout << i << std::endl;
    }
    
    // A member function
    struct writer
    {
        void print(int const& i) const
        {
            std::cout << i << std::endl;
        }
    };
    
    // A function object
    struct print_action
    {
        void operator()(int const& i, qi::unused_type, qi::unused_type) const
        {
            std::cout << i << std::endl;
        }
    };
}
//]

int main()
{
    using boost::spirit::qi::int_;
    using boost::spirit::qi::parse;
    using client::print;
    using client::writer;
    using client::print_action;
    
    { // example using plain function
        
        char const *first = "{42}", *last = first + std::strlen(first);
        //[tutorial_attach_actions1
        parse(first, last, '{' >> int_[&print] >> '}');
        //]
    }
    
    { // example using simple function object
        
        char const *first = "{43}", *last = first + std::strlen(first);
        //[tutorial_attach_actions2
        parse(first, last, '{' >> int_[print_action()] >> '}');
        //]
    }
    
    { // example using boost.bind with a plain function
        
        char const *first = "{44}", *last = first + std::strlen(first);
        //[tutorial_attach_actions3
        parse(first, last, '{' >> int_[boost::bind(&print, _1)] >> '}');
        //]
    }
    
    { // example using boost.bind with a member function
        
        char const *first = "{44}", *last = first + std::strlen(first);
        //[tutorial_attach_actions4
        writer w;
        parse(first, last, '{' >> int_[boost::bind(&writer::print, &w, _1)] >> '}');
        //]
    }
    
    { // example using boost.lambda
        
        namespace lambda = boost::lambda;
        char const *first = "{45}", *last = first + std::strlen(first);
        using lambda::_1;
        //[tutorial_attach_actions5
        parse(first, last, '{' >> int_[std::cout << _1 << '\n'] >> '}');
        //]
    }
    
    return 0;
}

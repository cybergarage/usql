
// Generated from SQL92.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace uSQL::ANTLR4 {


class  SQL92Lexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASTERISK = 8, SINGLE_EQ = 9, DOUBLE_EQ = 10, OP_LT = 11, LE = 12, GT = 13, 
    GE = 14, NOTEQ = 15, AND = 16, OR = 17, COMMA = 18, SEMICOLON = 19, 
    ALL = 20, ANCESTOR = 21, AS = 22, ASC = 23, ASYNC = 24, BY = 25, CREATE = 26, 
    COLLECTION = 27, CURRENT_DATE = 28, CURRENT_TIME = 29, CURRENT_TIMESTAMP = 30, 
    DESC = 31, DELETE = 32, DISTINCT = 33, DROP = 34, EACH = 35, EXCEPT = 36, 
    FLATTEN = 37, FROM = 38, GROUP = 39, HAVING = 40, IN = 41, COLLECTION_INDEX = 42, 
    INSERT = 43, INTERSECT = 44, INTO = 45, IS = 46, LIMIT = 47, NIL = 48, 
    OFFSET = 49, OPTIONS = 50, ORDER = 51, SELECT = 52, SET = 53, SHOW = 54, 
    SYNC = 55, USE = 56, UNION = 57, UPDATE = 58, WHERE = 59, VALUE = 60, 
    VALUES = 61, TRUE = 62, FALSE = 63, WS = 64, ID = 65, NUMBER = 66, FLOAT = 67, 
    STRING = 68
  };

  SQL92Lexer(antlr4::CharStream *input);
  ~SQL92Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace uSQL::ANTLR4

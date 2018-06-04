
// Generated from SQL92.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace uSQL::ANTLR4 {


class  SQL92Parser : public antlr4::Parser {
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

  enum {
    RuleQueries = 0, RuleStatement = 1, RuleShow_stmt = 2, RuleUse_stmt = 3, 
    RuleCreate_collection_stmt = 4, RuleDrop_collection_stmt = 5, RuleCreate_index_stmt = 6, 
    RuleDrop_index_stmt = 7, RuleSelect_stmt = 8, RuleSelect_core = 9, RuleResult_column_section = 10, 
    RuleFrom_section = 11, RuleTable_name = 12, RuleData_source = 13, RuleGrouping_section = 14, 
    RuleHaving_section = 15, RuleSorting_section = 16, RuleSorting_item = 17, 
    RuleSorting_specification = 18, RuleLimit_section = 19, RuleOffset_section = 20, 
    RuleInsert_stmt = 21, RuleInsert_columns_section = 22, RuleInsert_values_section = 23, 
    RuleUpdate_stmt = 24, RuleProperty_section = 25, RuleDelete_stmt = 26, 
    RuleExpression = 27, RuleExpression_list = 28, RuleExpression_literal = 29, 
    RuleExpression_literal_value = 30, RuleExpression_dictionary = 31, RuleDictionary_literal = 32, 
    RuleExpression_array = 33, RuleArray_literal = 34, RuleExpression_logic_operator = 35, 
    RuleExpression_binary_operator = 36, RuleExpression_function = 37, RuleFunction_name = 38, 
    RuleFunction_value = 39, RuleExpression_operator = 40, RuleBinary_operator = 41, 
    RuleLogical_operator = 42, RuleProperty_literal = 43, RuleInteger_literal = 44, 
    RuleReal_literal = 45, RuleString_literal = 46, RuleTrue_literal = 47, 
    RuleFalse_literal = 48, RuleSync_operator = 49, RuleCompound_operator = 50, 
    RuleCondition_operator = 51, RuleProperty = 52, RuleValue = 53, RuleName = 54, 
    RuleCollection_section = 55, RuleCollection_name = 56, RuleColumn_section = 57, 
    RuleIndex_section = 58, RuleIndex_name = 59, RuleWhere_section = 60
  };

  SQL92Parser(antlr4::TokenStream *input);
  ~SQL92Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class QueriesContext;
  class StatementContext;
  class Show_stmtContext;
  class Use_stmtContext;
  class Create_collection_stmtContext;
  class Drop_collection_stmtContext;
  class Create_index_stmtContext;
  class Drop_index_stmtContext;
  class Select_stmtContext;
  class Select_coreContext;
  class Result_column_sectionContext;
  class From_sectionContext;
  class Table_nameContext;
  class Data_sourceContext;
  class Grouping_sectionContext;
  class Having_sectionContext;
  class Sorting_sectionContext;
  class Sorting_itemContext;
  class Sorting_specificationContext;
  class Limit_sectionContext;
  class Offset_sectionContext;
  class Insert_stmtContext;
  class Insert_columns_sectionContext;
  class Insert_values_sectionContext;
  class Update_stmtContext;
  class Property_sectionContext;
  class Delete_stmtContext;
  class ExpressionContext;
  class Expression_listContext;
  class Expression_literalContext;
  class Expression_literal_valueContext;
  class Expression_dictionaryContext;
  class Dictionary_literalContext;
  class Expression_arrayContext;
  class Array_literalContext;
  class Expression_logic_operatorContext;
  class Expression_binary_operatorContext;
  class Expression_functionContext;
  class Function_nameContext;
  class Function_valueContext;
  class Expression_operatorContext;
  class Binary_operatorContext;
  class Logical_operatorContext;
  class Property_literalContext;
  class Integer_literalContext;
  class Real_literalContext;
  class String_literalContext;
  class True_literalContext;
  class False_literalContext;
  class Sync_operatorContext;
  class Compound_operatorContext;
  class Condition_operatorContext;
  class PropertyContext;
  class ValueContext;
  class NameContext;
  class Collection_sectionContext;
  class Collection_nameContext;
  class Column_sectionContext;
  class Index_sectionContext;
  class Index_nameContext;
  class Where_sectionContext; 

  class  QueriesContext : public antlr4::ParserRuleContext {
  public:
    QueriesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QueriesContext* queries();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Show_stmtContext *show_stmt();
    Use_stmtContext *use_stmt();
    Create_collection_stmtContext *create_collection_stmt();
    Create_index_stmtContext *create_index_stmt();
    Drop_collection_stmtContext *drop_collection_stmt();
    Drop_index_stmtContext *drop_index_stmt();
    Select_stmtContext *select_stmt();
    Insert_stmtContext *insert_stmt();
    Update_stmtContext *update_stmt();
    Delete_stmtContext *delete_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Show_stmtContext : public antlr4::ParserRuleContext {
  public:
    Show_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHOW();
    Collection_sectionContext *collection_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Show_stmtContext* show_stmt();

  class  Use_stmtContext : public antlr4::ParserRuleContext {
  public:
    Use_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    Collection_sectionContext *collection_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Use_stmtContext* use_stmt();

  class  Create_collection_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_collection_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *COLLECTION();
    Collection_sectionContext *collection_section();
    antlr4::tree::TerminalNode *OPTIONS();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Create_collection_stmtContext* create_collection_stmt();

  class  Drop_collection_stmtContext : public antlr4::ParserRuleContext {
  public:
    Drop_collection_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *COLLECTION();
    Collection_sectionContext *collection_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Drop_collection_stmtContext* drop_collection_stmt();

  class  Create_index_stmtContext : public antlr4::ParserRuleContext {
  public:
    Create_index_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *COLLECTION_INDEX();
    Index_sectionContext *index_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Create_index_stmtContext* create_index_stmt();

  class  Drop_index_stmtContext : public antlr4::ParserRuleContext {
  public:
    Drop_index_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *COLLECTION_INDEX();
    Index_sectionContext *index_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Drop_index_stmtContext* drop_index_stmt();

  class  Select_stmtContext : public antlr4::ParserRuleContext {
  public:
    Select_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_coreContext *select_core();
    Sorting_sectionContext *sorting_section();
    Limit_sectionContext *limit_section();
    Offset_sectionContext *offset_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Select_stmtContext* select_stmt();

  class  Select_coreContext : public antlr4::ParserRuleContext {
  public:
    SQL92Parser::Result_column_sectionContext *columnSection = nullptr;;
    SQL92Parser::From_sectionContext *fromSection = nullptr;;
    SQL92Parser::Where_sectionContext *whereSection = nullptr;;
    SQL92Parser::Grouping_sectionContext *groupSection = nullptr;;
    SQL92Parser::Having_sectionContext *havingSection = nullptr;;
    Select_coreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    From_sectionContext *from_section();
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *ALL();
    Result_column_sectionContext *result_column_section();
    Where_sectionContext *where_section();
    Grouping_sectionContext *grouping_section();
    Having_sectionContext *having_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Select_coreContext* select_core();

  class  Result_column_sectionContext : public antlr4::ParserRuleContext {
  public:
    Result_column_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASTERISK();
    std::vector<Column_sectionContext *> column_section();
    Column_sectionContext* column_section(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Result_column_sectionContext* result_column_section();

  class  From_sectionContext : public antlr4::ParserRuleContext {
  public:
    From_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    std::vector<Table_nameContext *> table_name();
    Table_nameContext* table_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  From_sectionContext* from_section();

  class  Table_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_sourceContext *data_source();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Table_nameContext* table_name();

  class  Data_sourceContext : public antlr4::ParserRuleContext {
  public:
    Data_sourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Collection_nameContext *collection_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Data_sourceContext* data_source();

  class  Grouping_sectionContext : public antlr4::ParserRuleContext {
  public:
    Grouping_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *BY();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Grouping_sectionContext* grouping_section();

  class  Having_sectionContext : public antlr4::ParserRuleContext {
  public:
    Having_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HAVING();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Having_sectionContext* having_section();

  class  Sorting_sectionContext : public antlr4::ParserRuleContext {
  public:
    Sorting_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<Sorting_itemContext *> sorting_item();
    Sorting_itemContext* sorting_item(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sorting_sectionContext* sorting_section();

  class  Sorting_itemContext : public antlr4::ParserRuleContext {
  public:
    Sorting_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyContext *property();
    Sorting_specificationContext *sorting_specification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sorting_itemContext* sorting_item();

  class  Sorting_specificationContext : public antlr4::ParserRuleContext {
  public:
    Sorting_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *DESC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sorting_specificationContext* sorting_specification();

  class  Limit_sectionContext : public antlr4::ParserRuleContext {
  public:
    Limit_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIMIT();
    std::vector<Expression_literalContext *> expression_literal();
    Expression_literalContext* expression_literal(size_t i);
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Limit_sectionContext* limit_section();

  class  Offset_sectionContext : public antlr4::ParserRuleContext {
  public:
    Offset_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OFFSET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Offset_sectionContext* offset_section();

  class  Insert_stmtContext : public antlr4::ParserRuleContext {
  public:
    Insert_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *INTO();
    Collection_sectionContext *collection_section();
    Insert_values_sectionContext *insert_values_section();
    Sync_operatorContext *sync_operator();
    Insert_columns_sectionContext *insert_columns_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Insert_stmtContext* insert_stmt();

  class  Insert_columns_sectionContext : public antlr4::ParserRuleContext {
  public:
    Insert_columns_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Column_sectionContext *> column_section();
    Column_sectionContext* column_section(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Insert_columns_sectionContext* insert_columns_section();

  class  Insert_values_sectionContext : public antlr4::ParserRuleContext {
  public:
    Insert_values_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALUE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *VALUES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Insert_values_sectionContext* insert_values_section();

  class  Update_stmtContext : public antlr4::ParserRuleContext {
  public:
    Update_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UPDATE();
    Collection_sectionContext *collection_section();
    antlr4::tree::TerminalNode *SET();
    std::vector<Property_sectionContext *> property_section();
    Property_sectionContext* property_section(size_t i);
    Sync_operatorContext *sync_operator();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    Where_sectionContext *where_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Update_stmtContext* update_stmt();

  class  Property_sectionContext : public antlr4::ParserRuleContext {
  public:
    Property_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyContext *property();
    antlr4::tree::TerminalNode *SINGLE_EQ();
    Expression_literalContext *expression_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Property_sectionContext* property_section();

  class  Delete_stmtContext : public antlr4::ParserRuleContext {
  public:
    Delete_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *FROM();
    Collection_sectionContext *collection_section();
    Sync_operatorContext *sync_operator();
    Where_sectionContext *where_section();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delete_stmtContext* delete_stmt();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_listContext *expression_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Expression_listContext : public antlr4::ParserRuleContext {
  public:
    Expression_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_literalContext *expression_literal();
    Expression_functionContext *expression_function();
    std::vector<Expression_binary_operatorContext *> expression_binary_operator();
    Expression_binary_operatorContext* expression_binary_operator(size_t i);
    std::vector<Expression_logic_operatorContext *> expression_logic_operator();
    Expression_logic_operatorContext* expression_logic_operator(size_t i);
    std::vector<Expression_arrayContext *> expression_array();
    Expression_arrayContext* expression_array(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Expression_dictionaryContext *> expression_dictionary();
    Expression_dictionaryContext* expression_dictionary(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_listContext* expression_list();

  class  Expression_literalContext : public antlr4::ParserRuleContext {
  public:
    Expression_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_literal_valueContext *expression_literal_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_literalContext* expression_literal();

  class  Expression_literal_valueContext : public antlr4::ParserRuleContext {
  public:
    Expression_literal_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_literalContext *property_literal();
    Integer_literalContext *integer_literal();
    Real_literalContext *real_literal();
    String_literalContext *string_literal();
    True_literalContext *true_literal();
    False_literalContext *false_literal();
    antlr4::tree::TerminalNode *NIL();
    antlr4::tree::TerminalNode *CURRENT_TIME();
    antlr4::tree::TerminalNode *CURRENT_DATE();
    antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_literal_valueContext* expression_literal_value();

  class  Expression_dictionaryContext : public antlr4::ParserRuleContext {
  public:
    Expression_dictionaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Expression_literalContext *expression_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_dictionaryContext* expression_dictionary();

  class  Dictionary_literalContext : public antlr4::ParserRuleContext {
  public:
    Dictionary_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    Expression_literalContext *expression_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dictionary_literalContext* dictionary_literal();

  class  Expression_arrayContext : public antlr4::ParserRuleContext {
  public:
    Expression_arrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_literalContext *expression_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_arrayContext* expression_array();

  class  Array_literalContext : public antlr4::ParserRuleContext {
  public:
    Array_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_literalContext *expression_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_literalContext* array_literal();

  class  Expression_logic_operatorContext : public antlr4::ParserRuleContext {
  public:
    Expression_logic_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_operatorContext *logical_operator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_logic_operatorContext* expression_logic_operator();

  class  Expression_binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Expression_binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_operatorContext *expression_operator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_binary_operatorContext* expression_binary_operator();

  class  Expression_functionContext : public antlr4::ParserRuleContext {
  public:
    Expression_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Function_valueContext *function_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_functionContext* expression_function();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_nameContext* function_name();

  class  Function_valueContext : public antlr4::ParserRuleContext {
  public:
    Function_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *ASTERISK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Function_valueContext* function_value();

  class  Expression_operatorContext : public antlr4::ParserRuleContext {
  public:
    Expression_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expression_literalContext *> expression_literal();
    Expression_literalContext* expression_literal(size_t i);
    Binary_operatorContext *binary_operator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_operatorContext* expression_operator();

  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SINGLE_EQ();
    antlr4::tree::TerminalNode *DOUBLE_EQ();
    antlr4::tree::TerminalNode *OP_LT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *NOTEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Logical_operatorContext : public antlr4::ParserRuleContext {
  public:
    Logical_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logical_operatorContext* logical_operator();

  class  Property_literalContext : public antlr4::ParserRuleContext {
  public:
    Property_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Property_literalContext* property_literal();

  class  Integer_literalContext : public antlr4::ParserRuleContext {
  public:
    Integer_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Integer_literalContext* integer_literal();

  class  Real_literalContext : public antlr4::ParserRuleContext {
  public:
    Real_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Real_literalContext* real_literal();

  class  String_literalContext : public antlr4::ParserRuleContext {
  public:
    String_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  String_literalContext* string_literal();

  class  True_literalContext : public antlr4::ParserRuleContext {
  public:
    True_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  True_literalContext* true_literal();

  class  False_literalContext : public antlr4::ParserRuleContext {
  public:
    False_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  False_literalContext* false_literal();

  class  Sync_operatorContext : public antlr4::ParserRuleContext {
  public:
    Sync_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYNC();
    antlr4::tree::TerminalNode *ASYNC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sync_operatorContext* sync_operator();

  class  Compound_operatorContext : public antlr4::ParserRuleContext {
  public:
    Compound_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *INTERSECT();
    antlr4::tree::TerminalNode *EXCEPT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_operatorContext* compound_operator();

  class  Condition_operatorContext : public antlr4::ParserRuleContext {
  public:
    Condition_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SINGLE_EQ();
    antlr4::tree::TerminalNode *DOUBLE_EQ();
    antlr4::tree::TerminalNode *OP_LT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *NOTEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Condition_operatorContext* condition_operator();

  class  PropertyContext : public antlr4::ParserRuleContext {
  public:
    PropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PropertyContext* property();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValueContext* value();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NameContext* name();

  class  Collection_sectionContext : public antlr4::ParserRuleContext {
  public:
    Collection_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Collection_nameContext *collection_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Collection_sectionContext* collection_section();

  class  Collection_nameContext : public antlr4::ParserRuleContext {
  public:
    Collection_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    String_literalContext *string_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Collection_nameContext* collection_name();

  class  Column_sectionContext : public antlr4::ParserRuleContext {
  public:
    Column_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *AS();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Column_sectionContext* column_section();

  class  Index_sectionContext : public antlr4::ParserRuleContext {
  public:
    Index_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Index_nameContext *index_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Index_sectionContext* index_section();

  class  Index_nameContext : public antlr4::ParserRuleContext {
  public:
    Index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    String_literalContext *string_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Index_nameContext* index_name();

  class  Where_sectionContext : public antlr4::ParserRuleContext {
  public:
    Where_sectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Where_sectionContext* where_section();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace uSQL::ANTLR4


// Generated from SQL92.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SQL92Parser.h"


namespace uSQL::ANTLR4 {

/**
 * This interface defines an abstract listener for a parse tree produced by SQL92Parser.
 */
class  SQL92Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterQueries(SQL92Parser::QueriesContext *ctx) = 0;
  virtual void exitQueries(SQL92Parser::QueriesContext *ctx) = 0;

  virtual void enterStatement(SQL92Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(SQL92Parser::StatementContext *ctx) = 0;

  virtual void enterShow_stmt(SQL92Parser::Show_stmtContext *ctx) = 0;
  virtual void exitShow_stmt(SQL92Parser::Show_stmtContext *ctx) = 0;

  virtual void enterUse_stmt(SQL92Parser::Use_stmtContext *ctx) = 0;
  virtual void exitUse_stmt(SQL92Parser::Use_stmtContext *ctx) = 0;

  virtual void enterCreate_collection_stmt(SQL92Parser::Create_collection_stmtContext *ctx) = 0;
  virtual void exitCreate_collection_stmt(SQL92Parser::Create_collection_stmtContext *ctx) = 0;

  virtual void enterDrop_collection_stmt(SQL92Parser::Drop_collection_stmtContext *ctx) = 0;
  virtual void exitDrop_collection_stmt(SQL92Parser::Drop_collection_stmtContext *ctx) = 0;

  virtual void enterCreate_index_stmt(SQL92Parser::Create_index_stmtContext *ctx) = 0;
  virtual void exitCreate_index_stmt(SQL92Parser::Create_index_stmtContext *ctx) = 0;

  virtual void enterDrop_index_stmt(SQL92Parser::Drop_index_stmtContext *ctx) = 0;
  virtual void exitDrop_index_stmt(SQL92Parser::Drop_index_stmtContext *ctx) = 0;

  virtual void enterSelect_stmt(SQL92Parser::Select_stmtContext *ctx) = 0;
  virtual void exitSelect_stmt(SQL92Parser::Select_stmtContext *ctx) = 0;

  virtual void enterSelect_core(SQL92Parser::Select_coreContext *ctx) = 0;
  virtual void exitSelect_core(SQL92Parser::Select_coreContext *ctx) = 0;

  virtual void enterResult_column_section(SQL92Parser::Result_column_sectionContext *ctx) = 0;
  virtual void exitResult_column_section(SQL92Parser::Result_column_sectionContext *ctx) = 0;

  virtual void enterFrom_section(SQL92Parser::From_sectionContext *ctx) = 0;
  virtual void exitFrom_section(SQL92Parser::From_sectionContext *ctx) = 0;

  virtual void enterTable_name(SQL92Parser::Table_nameContext *ctx) = 0;
  virtual void exitTable_name(SQL92Parser::Table_nameContext *ctx) = 0;

  virtual void enterData_source(SQL92Parser::Data_sourceContext *ctx) = 0;
  virtual void exitData_source(SQL92Parser::Data_sourceContext *ctx) = 0;

  virtual void enterGrouping_section(SQL92Parser::Grouping_sectionContext *ctx) = 0;
  virtual void exitGrouping_section(SQL92Parser::Grouping_sectionContext *ctx) = 0;

  virtual void enterHaving_section(SQL92Parser::Having_sectionContext *ctx) = 0;
  virtual void exitHaving_section(SQL92Parser::Having_sectionContext *ctx) = 0;

  virtual void enterSorting_section(SQL92Parser::Sorting_sectionContext *ctx) = 0;
  virtual void exitSorting_section(SQL92Parser::Sorting_sectionContext *ctx) = 0;

  virtual void enterSorting_item(SQL92Parser::Sorting_itemContext *ctx) = 0;
  virtual void exitSorting_item(SQL92Parser::Sorting_itemContext *ctx) = 0;

  virtual void enterSorting_specification(SQL92Parser::Sorting_specificationContext *ctx) = 0;
  virtual void exitSorting_specification(SQL92Parser::Sorting_specificationContext *ctx) = 0;

  virtual void enterLimit_section(SQL92Parser::Limit_sectionContext *ctx) = 0;
  virtual void exitLimit_section(SQL92Parser::Limit_sectionContext *ctx) = 0;

  virtual void enterOffset_section(SQL92Parser::Offset_sectionContext *ctx) = 0;
  virtual void exitOffset_section(SQL92Parser::Offset_sectionContext *ctx) = 0;

  virtual void enterInsert_stmt(SQL92Parser::Insert_stmtContext *ctx) = 0;
  virtual void exitInsert_stmt(SQL92Parser::Insert_stmtContext *ctx) = 0;

  virtual void enterInsert_columns_section(SQL92Parser::Insert_columns_sectionContext *ctx) = 0;
  virtual void exitInsert_columns_section(SQL92Parser::Insert_columns_sectionContext *ctx) = 0;

  virtual void enterInsert_values_section(SQL92Parser::Insert_values_sectionContext *ctx) = 0;
  virtual void exitInsert_values_section(SQL92Parser::Insert_values_sectionContext *ctx) = 0;

  virtual void enterUpdate_stmt(SQL92Parser::Update_stmtContext *ctx) = 0;
  virtual void exitUpdate_stmt(SQL92Parser::Update_stmtContext *ctx) = 0;

  virtual void enterProperty_section(SQL92Parser::Property_sectionContext *ctx) = 0;
  virtual void exitProperty_section(SQL92Parser::Property_sectionContext *ctx) = 0;

  virtual void enterDelete_stmt(SQL92Parser::Delete_stmtContext *ctx) = 0;
  virtual void exitDelete_stmt(SQL92Parser::Delete_stmtContext *ctx) = 0;

  virtual void enterExpression(SQL92Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SQL92Parser::ExpressionContext *ctx) = 0;

  virtual void enterExpression_list(SQL92Parser::Expression_listContext *ctx) = 0;
  virtual void exitExpression_list(SQL92Parser::Expression_listContext *ctx) = 0;

  virtual void enterExpression_literal(SQL92Parser::Expression_literalContext *ctx) = 0;
  virtual void exitExpression_literal(SQL92Parser::Expression_literalContext *ctx) = 0;

  virtual void enterExpression_literal_value(SQL92Parser::Expression_literal_valueContext *ctx) = 0;
  virtual void exitExpression_literal_value(SQL92Parser::Expression_literal_valueContext *ctx) = 0;

  virtual void enterExpression_dictionary(SQL92Parser::Expression_dictionaryContext *ctx) = 0;
  virtual void exitExpression_dictionary(SQL92Parser::Expression_dictionaryContext *ctx) = 0;

  virtual void enterDictionary_literal(SQL92Parser::Dictionary_literalContext *ctx) = 0;
  virtual void exitDictionary_literal(SQL92Parser::Dictionary_literalContext *ctx) = 0;

  virtual void enterExpression_array(SQL92Parser::Expression_arrayContext *ctx) = 0;
  virtual void exitExpression_array(SQL92Parser::Expression_arrayContext *ctx) = 0;

  virtual void enterArray_literal(SQL92Parser::Array_literalContext *ctx) = 0;
  virtual void exitArray_literal(SQL92Parser::Array_literalContext *ctx) = 0;

  virtual void enterExpression_logic_operator(SQL92Parser::Expression_logic_operatorContext *ctx) = 0;
  virtual void exitExpression_logic_operator(SQL92Parser::Expression_logic_operatorContext *ctx) = 0;

  virtual void enterExpression_binary_operator(SQL92Parser::Expression_binary_operatorContext *ctx) = 0;
  virtual void exitExpression_binary_operator(SQL92Parser::Expression_binary_operatorContext *ctx) = 0;

  virtual void enterExpression_function(SQL92Parser::Expression_functionContext *ctx) = 0;
  virtual void exitExpression_function(SQL92Parser::Expression_functionContext *ctx) = 0;

  virtual void enterFunction_name(SQL92Parser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(SQL92Parser::Function_nameContext *ctx) = 0;

  virtual void enterFunction_value(SQL92Parser::Function_valueContext *ctx) = 0;
  virtual void exitFunction_value(SQL92Parser::Function_valueContext *ctx) = 0;

  virtual void enterExpression_operator(SQL92Parser::Expression_operatorContext *ctx) = 0;
  virtual void exitExpression_operator(SQL92Parser::Expression_operatorContext *ctx) = 0;

  virtual void enterBinary_operator(SQL92Parser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(SQL92Parser::Binary_operatorContext *ctx) = 0;

  virtual void enterLogical_operator(SQL92Parser::Logical_operatorContext *ctx) = 0;
  virtual void exitLogical_operator(SQL92Parser::Logical_operatorContext *ctx) = 0;

  virtual void enterProperty_literal(SQL92Parser::Property_literalContext *ctx) = 0;
  virtual void exitProperty_literal(SQL92Parser::Property_literalContext *ctx) = 0;

  virtual void enterInteger_literal(SQL92Parser::Integer_literalContext *ctx) = 0;
  virtual void exitInteger_literal(SQL92Parser::Integer_literalContext *ctx) = 0;

  virtual void enterReal_literal(SQL92Parser::Real_literalContext *ctx) = 0;
  virtual void exitReal_literal(SQL92Parser::Real_literalContext *ctx) = 0;

  virtual void enterString_literal(SQL92Parser::String_literalContext *ctx) = 0;
  virtual void exitString_literal(SQL92Parser::String_literalContext *ctx) = 0;

  virtual void enterTrue_literal(SQL92Parser::True_literalContext *ctx) = 0;
  virtual void exitTrue_literal(SQL92Parser::True_literalContext *ctx) = 0;

  virtual void enterFalse_literal(SQL92Parser::False_literalContext *ctx) = 0;
  virtual void exitFalse_literal(SQL92Parser::False_literalContext *ctx) = 0;

  virtual void enterSync_operator(SQL92Parser::Sync_operatorContext *ctx) = 0;
  virtual void exitSync_operator(SQL92Parser::Sync_operatorContext *ctx) = 0;

  virtual void enterCompound_operator(SQL92Parser::Compound_operatorContext *ctx) = 0;
  virtual void exitCompound_operator(SQL92Parser::Compound_operatorContext *ctx) = 0;

  virtual void enterCondition_operator(SQL92Parser::Condition_operatorContext *ctx) = 0;
  virtual void exitCondition_operator(SQL92Parser::Condition_operatorContext *ctx) = 0;

  virtual void enterProperty(SQL92Parser::PropertyContext *ctx) = 0;
  virtual void exitProperty(SQL92Parser::PropertyContext *ctx) = 0;

  virtual void enterValue(SQL92Parser::ValueContext *ctx) = 0;
  virtual void exitValue(SQL92Parser::ValueContext *ctx) = 0;

  virtual void enterName(SQL92Parser::NameContext *ctx) = 0;
  virtual void exitName(SQL92Parser::NameContext *ctx) = 0;

  virtual void enterCollection_section(SQL92Parser::Collection_sectionContext *ctx) = 0;
  virtual void exitCollection_section(SQL92Parser::Collection_sectionContext *ctx) = 0;

  virtual void enterCollection_name(SQL92Parser::Collection_nameContext *ctx) = 0;
  virtual void exitCollection_name(SQL92Parser::Collection_nameContext *ctx) = 0;

  virtual void enterColumn_section(SQL92Parser::Column_sectionContext *ctx) = 0;
  virtual void exitColumn_section(SQL92Parser::Column_sectionContext *ctx) = 0;

  virtual void enterIndex_section(SQL92Parser::Index_sectionContext *ctx) = 0;
  virtual void exitIndex_section(SQL92Parser::Index_sectionContext *ctx) = 0;

  virtual void enterIndex_name(SQL92Parser::Index_nameContext *ctx) = 0;
  virtual void exitIndex_name(SQL92Parser::Index_nameContext *ctx) = 0;

  virtual void enterWhere_section(SQL92Parser::Where_sectionContext *ctx) = 0;
  virtual void exitWhere_section(SQL92Parser::Where_sectionContext *ctx) = 0;


};

}  // namespace uSQL::ANTLR4

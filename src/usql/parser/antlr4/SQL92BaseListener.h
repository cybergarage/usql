
// Generated from SQL92.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SQL92Listener.h"


namespace uSQL::ANTLR4 {

/**
 * This class provides an empty implementation of SQL92Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SQL92BaseListener : public SQL92Listener {
public:

  virtual void enterQueries(SQL92Parser::QueriesContext * /*ctx*/) override { }
  virtual void exitQueries(SQL92Parser::QueriesContext * /*ctx*/) override { }

  virtual void enterStatement(SQL92Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(SQL92Parser::StatementContext * /*ctx*/) override { }

  virtual void enterShow_stmt(SQL92Parser::Show_stmtContext * /*ctx*/) override { }
  virtual void exitShow_stmt(SQL92Parser::Show_stmtContext * /*ctx*/) override { }

  virtual void enterUse_stmt(SQL92Parser::Use_stmtContext * /*ctx*/) override { }
  virtual void exitUse_stmt(SQL92Parser::Use_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_collection_stmt(SQL92Parser::Create_collection_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_collection_stmt(SQL92Parser::Create_collection_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_collection_stmt(SQL92Parser::Drop_collection_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_collection_stmt(SQL92Parser::Drop_collection_stmtContext * /*ctx*/) override { }

  virtual void enterCreate_index_stmt(SQL92Parser::Create_index_stmtContext * /*ctx*/) override { }
  virtual void exitCreate_index_stmt(SQL92Parser::Create_index_stmtContext * /*ctx*/) override { }

  virtual void enterDrop_index_stmt(SQL92Parser::Drop_index_stmtContext * /*ctx*/) override { }
  virtual void exitDrop_index_stmt(SQL92Parser::Drop_index_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_stmt(SQL92Parser::Select_stmtContext * /*ctx*/) override { }
  virtual void exitSelect_stmt(SQL92Parser::Select_stmtContext * /*ctx*/) override { }

  virtual void enterSelect_core(SQL92Parser::Select_coreContext * /*ctx*/) override { }
  virtual void exitSelect_core(SQL92Parser::Select_coreContext * /*ctx*/) override { }

  virtual void enterResult_column_section(SQL92Parser::Result_column_sectionContext * /*ctx*/) override { }
  virtual void exitResult_column_section(SQL92Parser::Result_column_sectionContext * /*ctx*/) override { }

  virtual void enterFrom_section(SQL92Parser::From_sectionContext * /*ctx*/) override { }
  virtual void exitFrom_section(SQL92Parser::From_sectionContext * /*ctx*/) override { }

  virtual void enterTable_name(SQL92Parser::Table_nameContext * /*ctx*/) override { }
  virtual void exitTable_name(SQL92Parser::Table_nameContext * /*ctx*/) override { }

  virtual void enterData_source(SQL92Parser::Data_sourceContext * /*ctx*/) override { }
  virtual void exitData_source(SQL92Parser::Data_sourceContext * /*ctx*/) override { }

  virtual void enterGrouping_section(SQL92Parser::Grouping_sectionContext * /*ctx*/) override { }
  virtual void exitGrouping_section(SQL92Parser::Grouping_sectionContext * /*ctx*/) override { }

  virtual void enterHaving_section(SQL92Parser::Having_sectionContext * /*ctx*/) override { }
  virtual void exitHaving_section(SQL92Parser::Having_sectionContext * /*ctx*/) override { }

  virtual void enterSorting_section(SQL92Parser::Sorting_sectionContext * /*ctx*/) override { }
  virtual void exitSorting_section(SQL92Parser::Sorting_sectionContext * /*ctx*/) override { }

  virtual void enterSorting_item(SQL92Parser::Sorting_itemContext * /*ctx*/) override { }
  virtual void exitSorting_item(SQL92Parser::Sorting_itemContext * /*ctx*/) override { }

  virtual void enterSorting_specification(SQL92Parser::Sorting_specificationContext * /*ctx*/) override { }
  virtual void exitSorting_specification(SQL92Parser::Sorting_specificationContext * /*ctx*/) override { }

  virtual void enterLimit_section(SQL92Parser::Limit_sectionContext * /*ctx*/) override { }
  virtual void exitLimit_section(SQL92Parser::Limit_sectionContext * /*ctx*/) override { }

  virtual void enterOffset_section(SQL92Parser::Offset_sectionContext * /*ctx*/) override { }
  virtual void exitOffset_section(SQL92Parser::Offset_sectionContext * /*ctx*/) override { }

  virtual void enterInsert_stmt(SQL92Parser::Insert_stmtContext * /*ctx*/) override { }
  virtual void exitInsert_stmt(SQL92Parser::Insert_stmtContext * /*ctx*/) override { }

  virtual void enterInsert_columns_section(SQL92Parser::Insert_columns_sectionContext * /*ctx*/) override { }
  virtual void exitInsert_columns_section(SQL92Parser::Insert_columns_sectionContext * /*ctx*/) override { }

  virtual void enterInsert_values_section(SQL92Parser::Insert_values_sectionContext * /*ctx*/) override { }
  virtual void exitInsert_values_section(SQL92Parser::Insert_values_sectionContext * /*ctx*/) override { }

  virtual void enterUpdate_stmt(SQL92Parser::Update_stmtContext * /*ctx*/) override { }
  virtual void exitUpdate_stmt(SQL92Parser::Update_stmtContext * /*ctx*/) override { }

  virtual void enterProperty_section(SQL92Parser::Property_sectionContext * /*ctx*/) override { }
  virtual void exitProperty_section(SQL92Parser::Property_sectionContext * /*ctx*/) override { }

  virtual void enterDelete_stmt(SQL92Parser::Delete_stmtContext * /*ctx*/) override { }
  virtual void exitDelete_stmt(SQL92Parser::Delete_stmtContext * /*ctx*/) override { }

  virtual void enterExpression(SQL92Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SQL92Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterExpression_list(SQL92Parser::Expression_listContext * /*ctx*/) override { }
  virtual void exitExpression_list(SQL92Parser::Expression_listContext * /*ctx*/) override { }

  virtual void enterExpression_literal(SQL92Parser::Expression_literalContext * /*ctx*/) override { }
  virtual void exitExpression_literal(SQL92Parser::Expression_literalContext * /*ctx*/) override { }

  virtual void enterExpression_literal_value(SQL92Parser::Expression_literal_valueContext * /*ctx*/) override { }
  virtual void exitExpression_literal_value(SQL92Parser::Expression_literal_valueContext * /*ctx*/) override { }

  virtual void enterExpression_dictionary(SQL92Parser::Expression_dictionaryContext * /*ctx*/) override { }
  virtual void exitExpression_dictionary(SQL92Parser::Expression_dictionaryContext * /*ctx*/) override { }

  virtual void enterDictionary_literal(SQL92Parser::Dictionary_literalContext * /*ctx*/) override { }
  virtual void exitDictionary_literal(SQL92Parser::Dictionary_literalContext * /*ctx*/) override { }

  virtual void enterExpression_array(SQL92Parser::Expression_arrayContext * /*ctx*/) override { }
  virtual void exitExpression_array(SQL92Parser::Expression_arrayContext * /*ctx*/) override { }

  virtual void enterArray_literal(SQL92Parser::Array_literalContext * /*ctx*/) override { }
  virtual void exitArray_literal(SQL92Parser::Array_literalContext * /*ctx*/) override { }

  virtual void enterExpression_logic_operator(SQL92Parser::Expression_logic_operatorContext * /*ctx*/) override { }
  virtual void exitExpression_logic_operator(SQL92Parser::Expression_logic_operatorContext * /*ctx*/) override { }

  virtual void enterExpression_binary_operator(SQL92Parser::Expression_binary_operatorContext * /*ctx*/) override { }
  virtual void exitExpression_binary_operator(SQL92Parser::Expression_binary_operatorContext * /*ctx*/) override { }

  virtual void enterExpression_function(SQL92Parser::Expression_functionContext * /*ctx*/) override { }
  virtual void exitExpression_function(SQL92Parser::Expression_functionContext * /*ctx*/) override { }

  virtual void enterFunction_name(SQL92Parser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(SQL92Parser::Function_nameContext * /*ctx*/) override { }

  virtual void enterFunction_value(SQL92Parser::Function_valueContext * /*ctx*/) override { }
  virtual void exitFunction_value(SQL92Parser::Function_valueContext * /*ctx*/) override { }

  virtual void enterExpression_operator(SQL92Parser::Expression_operatorContext * /*ctx*/) override { }
  virtual void exitExpression_operator(SQL92Parser::Expression_operatorContext * /*ctx*/) override { }

  virtual void enterBinary_operator(SQL92Parser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(SQL92Parser::Binary_operatorContext * /*ctx*/) override { }

  virtual void enterLogical_operator(SQL92Parser::Logical_operatorContext * /*ctx*/) override { }
  virtual void exitLogical_operator(SQL92Parser::Logical_operatorContext * /*ctx*/) override { }

  virtual void enterProperty_literal(SQL92Parser::Property_literalContext * /*ctx*/) override { }
  virtual void exitProperty_literal(SQL92Parser::Property_literalContext * /*ctx*/) override { }

  virtual void enterInteger_literal(SQL92Parser::Integer_literalContext * /*ctx*/) override { }
  virtual void exitInteger_literal(SQL92Parser::Integer_literalContext * /*ctx*/) override { }

  virtual void enterReal_literal(SQL92Parser::Real_literalContext * /*ctx*/) override { }
  virtual void exitReal_literal(SQL92Parser::Real_literalContext * /*ctx*/) override { }

  virtual void enterString_literal(SQL92Parser::String_literalContext * /*ctx*/) override { }
  virtual void exitString_literal(SQL92Parser::String_literalContext * /*ctx*/) override { }

  virtual void enterTrue_literal(SQL92Parser::True_literalContext * /*ctx*/) override { }
  virtual void exitTrue_literal(SQL92Parser::True_literalContext * /*ctx*/) override { }

  virtual void enterFalse_literal(SQL92Parser::False_literalContext * /*ctx*/) override { }
  virtual void exitFalse_literal(SQL92Parser::False_literalContext * /*ctx*/) override { }

  virtual void enterSync_operator(SQL92Parser::Sync_operatorContext * /*ctx*/) override { }
  virtual void exitSync_operator(SQL92Parser::Sync_operatorContext * /*ctx*/) override { }

  virtual void enterCompound_operator(SQL92Parser::Compound_operatorContext * /*ctx*/) override { }
  virtual void exitCompound_operator(SQL92Parser::Compound_operatorContext * /*ctx*/) override { }

  virtual void enterCondition_operator(SQL92Parser::Condition_operatorContext * /*ctx*/) override { }
  virtual void exitCondition_operator(SQL92Parser::Condition_operatorContext * /*ctx*/) override { }

  virtual void enterProperty(SQL92Parser::PropertyContext * /*ctx*/) override { }
  virtual void exitProperty(SQL92Parser::PropertyContext * /*ctx*/) override { }

  virtual void enterValue(SQL92Parser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(SQL92Parser::ValueContext * /*ctx*/) override { }

  virtual void enterName(SQL92Parser::NameContext * /*ctx*/) override { }
  virtual void exitName(SQL92Parser::NameContext * /*ctx*/) override { }

  virtual void enterCollection_section(SQL92Parser::Collection_sectionContext * /*ctx*/) override { }
  virtual void exitCollection_section(SQL92Parser::Collection_sectionContext * /*ctx*/) override { }

  virtual void enterCollection_name(SQL92Parser::Collection_nameContext * /*ctx*/) override { }
  virtual void exitCollection_name(SQL92Parser::Collection_nameContext * /*ctx*/) override { }

  virtual void enterColumn_section(SQL92Parser::Column_sectionContext * /*ctx*/) override { }
  virtual void exitColumn_section(SQL92Parser::Column_sectionContext * /*ctx*/) override { }

  virtual void enterIndex_section(SQL92Parser::Index_sectionContext * /*ctx*/) override { }
  virtual void exitIndex_section(SQL92Parser::Index_sectionContext * /*ctx*/) override { }

  virtual void enterIndex_name(SQL92Parser::Index_nameContext * /*ctx*/) override { }
  virtual void exitIndex_name(SQL92Parser::Index_nameContext * /*ctx*/) override { }

  virtual void enterWhere_section(SQL92Parser::Where_sectionContext * /*ctx*/) override { }
  virtual void exitWhere_section(SQL92Parser::Where_sectionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace uSQL::ANTLR4

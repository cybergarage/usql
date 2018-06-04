
// Generated from SQL92.g4 by ANTLR 4.7.1


#include "SQL92Listener.h"

#include "SQL92Parser.h"


using namespace antlrcpp;
using namespace uSQL::ANTLR4;
using namespace antlr4;

SQL92Parser::SQL92Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SQL92Parser::~SQL92Parser() {
  delete _interpreter;
}

std::string SQL92Parser::getGrammarFileName() const {
  return "SQL92.g4";
}

const std::vector<std::string>& SQL92Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SQL92Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- QueriesContext ------------------------------------------------------------------

SQL92Parser::QueriesContext::QueriesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQL92Parser::StatementContext *> SQL92Parser::QueriesContext::statement() {
  return getRuleContexts<SQL92Parser::StatementContext>();
}

SQL92Parser::StatementContext* SQL92Parser::QueriesContext::statement(size_t i) {
  return getRuleContext<SQL92Parser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::QueriesContext::SEMICOLON() {
  return getTokens(SQL92Parser::SEMICOLON);
}

tree::TerminalNode* SQL92Parser::QueriesContext::SEMICOLON(size_t i) {
  return getToken(SQL92Parser::SEMICOLON, i);
}


size_t SQL92Parser::QueriesContext::getRuleIndex() const {
  return SQL92Parser::RuleQueries;
}

void SQL92Parser::QueriesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueries(this);
}

void SQL92Parser::QueriesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueries(this);
}

SQL92Parser::QueriesContext* SQL92Parser::queries() {
  QueriesContext *_localctx = _tracker.createInstance<QueriesContext>(_ctx, getState());
  enterRule(_localctx, 0, SQL92Parser::RuleQueries);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    statement();
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::SEMICOLON) {
      setState(123);
      match(SQL92Parser::SEMICOLON);
      setState(124);
      statement();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SQL92Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Show_stmtContext* SQL92Parser::StatementContext::show_stmt() {
  return getRuleContext<SQL92Parser::Show_stmtContext>(0);
}

SQL92Parser::Use_stmtContext* SQL92Parser::StatementContext::use_stmt() {
  return getRuleContext<SQL92Parser::Use_stmtContext>(0);
}

SQL92Parser::Create_collection_stmtContext* SQL92Parser::StatementContext::create_collection_stmt() {
  return getRuleContext<SQL92Parser::Create_collection_stmtContext>(0);
}

SQL92Parser::Create_index_stmtContext* SQL92Parser::StatementContext::create_index_stmt() {
  return getRuleContext<SQL92Parser::Create_index_stmtContext>(0);
}

SQL92Parser::Drop_collection_stmtContext* SQL92Parser::StatementContext::drop_collection_stmt() {
  return getRuleContext<SQL92Parser::Drop_collection_stmtContext>(0);
}

SQL92Parser::Drop_index_stmtContext* SQL92Parser::StatementContext::drop_index_stmt() {
  return getRuleContext<SQL92Parser::Drop_index_stmtContext>(0);
}

SQL92Parser::Select_stmtContext* SQL92Parser::StatementContext::select_stmt() {
  return getRuleContext<SQL92Parser::Select_stmtContext>(0);
}

SQL92Parser::Insert_stmtContext* SQL92Parser::StatementContext::insert_stmt() {
  return getRuleContext<SQL92Parser::Insert_stmtContext>(0);
}

SQL92Parser::Update_stmtContext* SQL92Parser::StatementContext::update_stmt() {
  return getRuleContext<SQL92Parser::Update_stmtContext>(0);
}

SQL92Parser::Delete_stmtContext* SQL92Parser::StatementContext::delete_stmt() {
  return getRuleContext<SQL92Parser::Delete_stmtContext>(0);
}


size_t SQL92Parser::StatementContext::getRuleIndex() const {
  return SQL92Parser::RuleStatement;
}

void SQL92Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void SQL92Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

SQL92Parser::StatementContext* SQL92Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, SQL92Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(130);
      show_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(131);
      use_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(132);
      create_collection_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(133);
      create_index_stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(134);
      drop_collection_stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(135);
      drop_index_stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(136);
      select_stmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(137);
      insert_stmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(138);
      update_stmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(139);
      delete_stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Show_stmtContext ------------------------------------------------------------------

SQL92Parser::Show_stmtContext::Show_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Show_stmtContext::SHOW() {
  return getToken(SQL92Parser::SHOW, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Show_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}


size_t SQL92Parser::Show_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleShow_stmt;
}

void SQL92Parser::Show_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_stmt(this);
}

void SQL92Parser::Show_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_stmt(this);
}

SQL92Parser::Show_stmtContext* SQL92Parser::show_stmt() {
  Show_stmtContext *_localctx = _tracker.createInstance<Show_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, SQL92Parser::RuleShow_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(SQL92Parser::SHOW);
    setState(143);
    collection_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Use_stmtContext ------------------------------------------------------------------

SQL92Parser::Use_stmtContext::Use_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Use_stmtContext::USE() {
  return getToken(SQL92Parser::USE, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Use_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}


size_t SQL92Parser::Use_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleUse_stmt;
}

void SQL92Parser::Use_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUse_stmt(this);
}

void SQL92Parser::Use_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUse_stmt(this);
}

SQL92Parser::Use_stmtContext* SQL92Parser::use_stmt() {
  Use_stmtContext *_localctx = _tracker.createInstance<Use_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, SQL92Parser::RuleUse_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(SQL92Parser::USE);
    setState(146);
    collection_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_collection_stmtContext ------------------------------------------------------------------

SQL92Parser::Create_collection_stmtContext::Create_collection_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Create_collection_stmtContext::CREATE() {
  return getToken(SQL92Parser::CREATE, 0);
}

tree::TerminalNode* SQL92Parser::Create_collection_stmtContext::COLLECTION() {
  return getToken(SQL92Parser::COLLECTION, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Create_collection_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}

tree::TerminalNode* SQL92Parser::Create_collection_stmtContext::OPTIONS() {
  return getToken(SQL92Parser::OPTIONS, 0);
}

SQL92Parser::ExpressionContext* SQL92Parser::Create_collection_stmtContext::expression() {
  return getRuleContext<SQL92Parser::ExpressionContext>(0);
}


size_t SQL92Parser::Create_collection_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleCreate_collection_stmt;
}

void SQL92Parser::Create_collection_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_collection_stmt(this);
}

void SQL92Parser::Create_collection_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_collection_stmt(this);
}

SQL92Parser::Create_collection_stmtContext* SQL92Parser::create_collection_stmt() {
  Create_collection_stmtContext *_localctx = _tracker.createInstance<Create_collection_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, SQL92Parser::RuleCreate_collection_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(SQL92Parser::CREATE);
    setState(149);
    match(SQL92Parser::COLLECTION);
    setState(150);
    collection_section();
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::OPTIONS) {
      setState(151);
      match(SQL92Parser::OPTIONS);
      setState(152);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_collection_stmtContext ------------------------------------------------------------------

SQL92Parser::Drop_collection_stmtContext::Drop_collection_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Drop_collection_stmtContext::DROP() {
  return getToken(SQL92Parser::DROP, 0);
}

tree::TerminalNode* SQL92Parser::Drop_collection_stmtContext::COLLECTION() {
  return getToken(SQL92Parser::COLLECTION, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Drop_collection_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}


size_t SQL92Parser::Drop_collection_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleDrop_collection_stmt;
}

void SQL92Parser::Drop_collection_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_collection_stmt(this);
}

void SQL92Parser::Drop_collection_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_collection_stmt(this);
}

SQL92Parser::Drop_collection_stmtContext* SQL92Parser::drop_collection_stmt() {
  Drop_collection_stmtContext *_localctx = _tracker.createInstance<Drop_collection_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, SQL92Parser::RuleDrop_collection_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(SQL92Parser::DROP);
    setState(156);
    match(SQL92Parser::COLLECTION);
    setState(157);
    collection_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_index_stmtContext ------------------------------------------------------------------

SQL92Parser::Create_index_stmtContext::Create_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Create_index_stmtContext::CREATE() {
  return getToken(SQL92Parser::CREATE, 0);
}

tree::TerminalNode* SQL92Parser::Create_index_stmtContext::COLLECTION_INDEX() {
  return getToken(SQL92Parser::COLLECTION_INDEX, 0);
}

SQL92Parser::Index_sectionContext* SQL92Parser::Create_index_stmtContext::index_section() {
  return getRuleContext<SQL92Parser::Index_sectionContext>(0);
}


size_t SQL92Parser::Create_index_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleCreate_index_stmt;
}

void SQL92Parser::Create_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_index_stmt(this);
}

void SQL92Parser::Create_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_index_stmt(this);
}

SQL92Parser::Create_index_stmtContext* SQL92Parser::create_index_stmt() {
  Create_index_stmtContext *_localctx = _tracker.createInstance<Create_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, SQL92Parser::RuleCreate_index_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(SQL92Parser::CREATE);
    setState(160);
    match(SQL92Parser::COLLECTION_INDEX);
    setState(161);
    index_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_index_stmtContext ------------------------------------------------------------------

SQL92Parser::Drop_index_stmtContext::Drop_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Drop_index_stmtContext::DROP() {
  return getToken(SQL92Parser::DROP, 0);
}

tree::TerminalNode* SQL92Parser::Drop_index_stmtContext::COLLECTION_INDEX() {
  return getToken(SQL92Parser::COLLECTION_INDEX, 0);
}

SQL92Parser::Index_sectionContext* SQL92Parser::Drop_index_stmtContext::index_section() {
  return getRuleContext<SQL92Parser::Index_sectionContext>(0);
}


size_t SQL92Parser::Drop_index_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleDrop_index_stmt;
}

void SQL92Parser::Drop_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_index_stmt(this);
}

void SQL92Parser::Drop_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_index_stmt(this);
}

SQL92Parser::Drop_index_stmtContext* SQL92Parser::drop_index_stmt() {
  Drop_index_stmtContext *_localctx = _tracker.createInstance<Drop_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, SQL92Parser::RuleDrop_index_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(SQL92Parser::DROP);
    setState(164);
    match(SQL92Parser::COLLECTION_INDEX);
    setState(165);
    index_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

SQL92Parser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Select_coreContext* SQL92Parser::Select_stmtContext::select_core() {
  return getRuleContext<SQL92Parser::Select_coreContext>(0);
}

SQL92Parser::Sorting_sectionContext* SQL92Parser::Select_stmtContext::sorting_section() {
  return getRuleContext<SQL92Parser::Sorting_sectionContext>(0);
}

SQL92Parser::Limit_sectionContext* SQL92Parser::Select_stmtContext::limit_section() {
  return getRuleContext<SQL92Parser::Limit_sectionContext>(0);
}

SQL92Parser::Offset_sectionContext* SQL92Parser::Select_stmtContext::offset_section() {
  return getRuleContext<SQL92Parser::Offset_sectionContext>(0);
}


size_t SQL92Parser::Select_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleSelect_stmt;
}

void SQL92Parser::Select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_stmt(this);
}

void SQL92Parser::Select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_stmt(this);
}

SQL92Parser::Select_stmtContext* SQL92Parser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, SQL92Parser::RuleSelect_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    select_core();
    setState(169);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ORDER) {
      setState(168);
      sorting_section();
    }
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::LIMIT) {
      setState(171);
      limit_section();
    }
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::OFFSET) {
      setState(174);
      offset_section();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

SQL92Parser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Select_coreContext::SELECT() {
  return getToken(SQL92Parser::SELECT, 0);
}

SQL92Parser::From_sectionContext* SQL92Parser::Select_coreContext::from_section() {
  return getRuleContext<SQL92Parser::From_sectionContext>(0);
}

tree::TerminalNode* SQL92Parser::Select_coreContext::DISTINCT() {
  return getToken(SQL92Parser::DISTINCT, 0);
}

tree::TerminalNode* SQL92Parser::Select_coreContext::ALL() {
  return getToken(SQL92Parser::ALL, 0);
}

SQL92Parser::Result_column_sectionContext* SQL92Parser::Select_coreContext::result_column_section() {
  return getRuleContext<SQL92Parser::Result_column_sectionContext>(0);
}

SQL92Parser::Where_sectionContext* SQL92Parser::Select_coreContext::where_section() {
  return getRuleContext<SQL92Parser::Where_sectionContext>(0);
}

SQL92Parser::Grouping_sectionContext* SQL92Parser::Select_coreContext::grouping_section() {
  return getRuleContext<SQL92Parser::Grouping_sectionContext>(0);
}

SQL92Parser::Having_sectionContext* SQL92Parser::Select_coreContext::having_section() {
  return getRuleContext<SQL92Parser::Having_sectionContext>(0);
}


size_t SQL92Parser::Select_coreContext::getRuleIndex() const {
  return SQL92Parser::RuleSelect_core;
}

void SQL92Parser::Select_coreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_core(this);
}

void SQL92Parser::Select_coreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_core(this);
}

SQL92Parser::Select_coreContext* SQL92Parser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 18, SQL92Parser::RuleSelect_core);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(SQL92Parser::SELECT);
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ALL

    || _la == SQL92Parser::DISTINCT) {
      setState(178);
      _la = _input->LA(1);
      if (!(_la == SQL92Parser::ALL

      || _la == SQL92Parser::DISTINCT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQL92Parser::T__0)
      | (1ULL << SQL92Parser::T__2)
      | (1ULL << SQL92Parser::T__4)
      | (1ULL << SQL92Parser::ASTERISK)
      | (1ULL << SQL92Parser::CURRENT_DATE)
      | (1ULL << SQL92Parser::CURRENT_TIME)
      | (1ULL << SQL92Parser::CURRENT_TIMESTAMP)
      | (1ULL << SQL92Parser::NIL)
      | (1ULL << SQL92Parser::TRUE)
      | (1ULL << SQL92Parser::FALSE))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (SQL92Parser::ID - 65))
      | (1ULL << (SQL92Parser::NUMBER - 65))
      | (1ULL << (SQL92Parser::FLOAT - 65))
      | (1ULL << (SQL92Parser::STRING - 65)))) != 0)) {
      setState(181);
      dynamic_cast<Select_coreContext *>(_localctx)->columnSection = result_column_section();
    }

    setState(184);
    dynamic_cast<Select_coreContext *>(_localctx)->fromSection = from_section();
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::WHERE) {
      setState(185);
      dynamic_cast<Select_coreContext *>(_localctx)->whereSection = where_section();
    }
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::GROUP) {
      setState(188);
      dynamic_cast<Select_coreContext *>(_localctx)->groupSection = grouping_section();
    }
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::HAVING) {
      setState(191);
      dynamic_cast<Select_coreContext *>(_localctx)->havingSection = having_section();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_column_sectionContext ------------------------------------------------------------------

SQL92Parser::Result_column_sectionContext::Result_column_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Result_column_sectionContext::ASTERISK() {
  return getToken(SQL92Parser::ASTERISK, 0);
}

std::vector<SQL92Parser::Column_sectionContext *> SQL92Parser::Result_column_sectionContext::column_section() {
  return getRuleContexts<SQL92Parser::Column_sectionContext>();
}

SQL92Parser::Column_sectionContext* SQL92Parser::Result_column_sectionContext::column_section(size_t i) {
  return getRuleContext<SQL92Parser::Column_sectionContext>(i);
}


size_t SQL92Parser::Result_column_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleResult_column_section;
}

void SQL92Parser::Result_column_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult_column_section(this);
}

void SQL92Parser::Result_column_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult_column_section(this);
}

SQL92Parser::Result_column_sectionContext* SQL92Parser::result_column_section() {
  Result_column_sectionContext *_localctx = _tracker.createInstance<Result_column_sectionContext>(_ctx, getState());
  enterRule(_localctx, 20, SQL92Parser::RuleResult_column_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::ASTERISK: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        match(SQL92Parser::ASTERISK);
        break;
      }

      case SQL92Parser::T__0:
      case SQL92Parser::T__2:
      case SQL92Parser::T__4:
      case SQL92Parser::CURRENT_DATE:
      case SQL92Parser::CURRENT_TIME:
      case SQL92Parser::CURRENT_TIMESTAMP:
      case SQL92Parser::NIL:
      case SQL92Parser::TRUE:
      case SQL92Parser::FALSE:
      case SQL92Parser::ID:
      case SQL92Parser::NUMBER:
      case SQL92Parser::FLOAT:
      case SQL92Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(195);
        column_section();
        setState(200);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQL92Parser::COMMA) {
          setState(196);
          match(SQL92Parser::COMMA);
          setState(197);
          column_section();
          setState(202);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- From_sectionContext ------------------------------------------------------------------

SQL92Parser::From_sectionContext::From_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::From_sectionContext::FROM() {
  return getToken(SQL92Parser::FROM, 0);
}

std::vector<SQL92Parser::Table_nameContext *> SQL92Parser::From_sectionContext::table_name() {
  return getRuleContexts<SQL92Parser::Table_nameContext>();
}

SQL92Parser::Table_nameContext* SQL92Parser::From_sectionContext::table_name(size_t i) {
  return getRuleContext<SQL92Parser::Table_nameContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::From_sectionContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::From_sectionContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}


size_t SQL92Parser::From_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleFrom_section;
}

void SQL92Parser::From_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFrom_section(this);
}

void SQL92Parser::From_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFrom_section(this);
}

SQL92Parser::From_sectionContext* SQL92Parser::from_section() {
  From_sectionContext *_localctx = _tracker.createInstance<From_sectionContext>(_ctx, getState());
  enterRule(_localctx, 22, SQL92Parser::RuleFrom_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(SQL92Parser::FROM);
    setState(206);
    table_name();
    setState(212);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::COMMA) {
      setState(208);
      match(SQL92Parser::COMMA);
      setState(209);
      table_name();
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

SQL92Parser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Data_sourceContext* SQL92Parser::Table_nameContext::data_source() {
  return getRuleContext<SQL92Parser::Data_sourceContext>(0);
}


size_t SQL92Parser::Table_nameContext::getRuleIndex() const {
  return SQL92Parser::RuleTable_name;
}

void SQL92Parser::Table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_name(this);
}

void SQL92Parser::Table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_name(this);
}

SQL92Parser::Table_nameContext* SQL92Parser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 24, SQL92Parser::RuleTable_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    data_source();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Data_sourceContext ------------------------------------------------------------------

SQL92Parser::Data_sourceContext::Data_sourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Collection_nameContext* SQL92Parser::Data_sourceContext::collection_name() {
  return getRuleContext<SQL92Parser::Collection_nameContext>(0);
}


size_t SQL92Parser::Data_sourceContext::getRuleIndex() const {
  return SQL92Parser::RuleData_source;
}

void SQL92Parser::Data_sourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterData_source(this);
}

void SQL92Parser::Data_sourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitData_source(this);
}

SQL92Parser::Data_sourceContext* SQL92Parser::data_source() {
  Data_sourceContext *_localctx = _tracker.createInstance<Data_sourceContext>(_ctx, getState());
  enterRule(_localctx, 26, SQL92Parser::RuleData_source);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    collection_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Grouping_sectionContext ------------------------------------------------------------------

SQL92Parser::Grouping_sectionContext::Grouping_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Grouping_sectionContext::GROUP() {
  return getToken(SQL92Parser::GROUP, 0);
}

tree::TerminalNode* SQL92Parser::Grouping_sectionContext::BY() {
  return getToken(SQL92Parser::BY, 0);
}

std::vector<SQL92Parser::ExpressionContext *> SQL92Parser::Grouping_sectionContext::expression() {
  return getRuleContexts<SQL92Parser::ExpressionContext>();
}

SQL92Parser::ExpressionContext* SQL92Parser::Grouping_sectionContext::expression(size_t i) {
  return getRuleContext<SQL92Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::Grouping_sectionContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::Grouping_sectionContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}


size_t SQL92Parser::Grouping_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleGrouping_section;
}

void SQL92Parser::Grouping_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrouping_section(this);
}

void SQL92Parser::Grouping_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrouping_section(this);
}

SQL92Parser::Grouping_sectionContext* SQL92Parser::grouping_section() {
  Grouping_sectionContext *_localctx = _tracker.createInstance<Grouping_sectionContext>(_ctx, getState());
  enterRule(_localctx, 28, SQL92Parser::RuleGrouping_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(SQL92Parser::GROUP);
    setState(220);
    match(SQL92Parser::BY);
    setState(221);
    expression();
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::COMMA) {
      setState(222);
      match(SQL92Parser::COMMA);
      setState(223);
      expression();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Having_sectionContext ------------------------------------------------------------------

SQL92Parser::Having_sectionContext::Having_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Having_sectionContext::HAVING() {
  return getToken(SQL92Parser::HAVING, 0);
}

SQL92Parser::ExpressionContext* SQL92Parser::Having_sectionContext::expression() {
  return getRuleContext<SQL92Parser::ExpressionContext>(0);
}


size_t SQL92Parser::Having_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleHaving_section;
}

void SQL92Parser::Having_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHaving_section(this);
}

void SQL92Parser::Having_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHaving_section(this);
}

SQL92Parser::Having_sectionContext* SQL92Parser::having_section() {
  Having_sectionContext *_localctx = _tracker.createInstance<Having_sectionContext>(_ctx, getState());
  enterRule(_localctx, 30, SQL92Parser::RuleHaving_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(SQL92Parser::HAVING);
    setState(230);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sorting_sectionContext ------------------------------------------------------------------

SQL92Parser::Sorting_sectionContext::Sorting_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Sorting_sectionContext::ORDER() {
  return getToken(SQL92Parser::ORDER, 0);
}

tree::TerminalNode* SQL92Parser::Sorting_sectionContext::BY() {
  return getToken(SQL92Parser::BY, 0);
}

std::vector<SQL92Parser::Sorting_itemContext *> SQL92Parser::Sorting_sectionContext::sorting_item() {
  return getRuleContexts<SQL92Parser::Sorting_itemContext>();
}

SQL92Parser::Sorting_itemContext* SQL92Parser::Sorting_sectionContext::sorting_item(size_t i) {
  return getRuleContext<SQL92Parser::Sorting_itemContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::Sorting_sectionContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::Sorting_sectionContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}


size_t SQL92Parser::Sorting_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleSorting_section;
}

void SQL92Parser::Sorting_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSorting_section(this);
}

void SQL92Parser::Sorting_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSorting_section(this);
}

SQL92Parser::Sorting_sectionContext* SQL92Parser::sorting_section() {
  Sorting_sectionContext *_localctx = _tracker.createInstance<Sorting_sectionContext>(_ctx, getState());
  enterRule(_localctx, 32, SQL92Parser::RuleSorting_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(SQL92Parser::ORDER);
    setState(233);
    match(SQL92Parser::BY);
    setState(234);
    sorting_item();
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::COMMA) {
      setState(235);
      match(SQL92Parser::COMMA);
      setState(236);
      sorting_item();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sorting_itemContext ------------------------------------------------------------------

SQL92Parser::Sorting_itemContext::Sorting_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::PropertyContext* SQL92Parser::Sorting_itemContext::property() {
  return getRuleContext<SQL92Parser::PropertyContext>(0);
}

SQL92Parser::Sorting_specificationContext* SQL92Parser::Sorting_itemContext::sorting_specification() {
  return getRuleContext<SQL92Parser::Sorting_specificationContext>(0);
}


size_t SQL92Parser::Sorting_itemContext::getRuleIndex() const {
  return SQL92Parser::RuleSorting_item;
}

void SQL92Parser::Sorting_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSorting_item(this);
}

void SQL92Parser::Sorting_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSorting_item(this);
}

SQL92Parser::Sorting_itemContext* SQL92Parser::sorting_item() {
  Sorting_itemContext *_localctx = _tracker.createInstance<Sorting_itemContext>(_ctx, getState());
  enterRule(_localctx, 34, SQL92Parser::RuleSorting_item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    property();
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ASC

    || _la == SQL92Parser::DESC) {
      setState(243);
      sorting_specification();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sorting_specificationContext ------------------------------------------------------------------

SQL92Parser::Sorting_specificationContext::Sorting_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Sorting_specificationContext::ASC() {
  return getToken(SQL92Parser::ASC, 0);
}

tree::TerminalNode* SQL92Parser::Sorting_specificationContext::DESC() {
  return getToken(SQL92Parser::DESC, 0);
}


size_t SQL92Parser::Sorting_specificationContext::getRuleIndex() const {
  return SQL92Parser::RuleSorting_specification;
}

void SQL92Parser::Sorting_specificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSorting_specification(this);
}

void SQL92Parser::Sorting_specificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSorting_specification(this);
}

SQL92Parser::Sorting_specificationContext* SQL92Parser::sorting_specification() {
  Sorting_specificationContext *_localctx = _tracker.createInstance<Sorting_specificationContext>(_ctx, getState());
  enterRule(_localctx, 36, SQL92Parser::RuleSorting_specification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (!(_la == SQL92Parser::ASC

    || _la == SQL92Parser::DESC)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Limit_sectionContext ------------------------------------------------------------------

SQL92Parser::Limit_sectionContext::Limit_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Limit_sectionContext::LIMIT() {
  return getToken(SQL92Parser::LIMIT, 0);
}

std::vector<SQL92Parser::Expression_literalContext *> SQL92Parser::Limit_sectionContext::expression_literal() {
  return getRuleContexts<SQL92Parser::Expression_literalContext>();
}

SQL92Parser::Expression_literalContext* SQL92Parser::Limit_sectionContext::expression_literal(size_t i) {
  return getRuleContext<SQL92Parser::Expression_literalContext>(i);
}

tree::TerminalNode* SQL92Parser::Limit_sectionContext::COMMA() {
  return getToken(SQL92Parser::COMMA, 0);
}


size_t SQL92Parser::Limit_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleLimit_section;
}

void SQL92Parser::Limit_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLimit_section(this);
}

void SQL92Parser::Limit_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLimit_section(this);
}

SQL92Parser::Limit_sectionContext* SQL92Parser::limit_section() {
  Limit_sectionContext *_localctx = _tracker.createInstance<Limit_sectionContext>(_ctx, getState());
  enterRule(_localctx, 38, SQL92Parser::RuleLimit_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(SQL92Parser::LIMIT);
    setState(252);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(249);
      expression_literal();
      setState(250);
      match(SQL92Parser::COMMA);
      break;
    }

    }
    setState(254);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Offset_sectionContext ------------------------------------------------------------------

SQL92Parser::Offset_sectionContext::Offset_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Offset_sectionContext::OFFSET() {
  return getToken(SQL92Parser::OFFSET, 0);
}


size_t SQL92Parser::Offset_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleOffset_section;
}

void SQL92Parser::Offset_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOffset_section(this);
}

void SQL92Parser::Offset_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOffset_section(this);
}

SQL92Parser::Offset_sectionContext* SQL92Parser::offset_section() {
  Offset_sectionContext *_localctx = _tracker.createInstance<Offset_sectionContext>(_ctx, getState());
  enterRule(_localctx, 40, SQL92Parser::RuleOffset_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(SQL92Parser::OFFSET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_stmtContext ------------------------------------------------------------------

SQL92Parser::Insert_stmtContext::Insert_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Insert_stmtContext::INSERT() {
  return getToken(SQL92Parser::INSERT, 0);
}

tree::TerminalNode* SQL92Parser::Insert_stmtContext::INTO() {
  return getToken(SQL92Parser::INTO, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Insert_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}

SQL92Parser::Insert_values_sectionContext* SQL92Parser::Insert_stmtContext::insert_values_section() {
  return getRuleContext<SQL92Parser::Insert_values_sectionContext>(0);
}

SQL92Parser::Sync_operatorContext* SQL92Parser::Insert_stmtContext::sync_operator() {
  return getRuleContext<SQL92Parser::Sync_operatorContext>(0);
}

SQL92Parser::Insert_columns_sectionContext* SQL92Parser::Insert_stmtContext::insert_columns_section() {
  return getRuleContext<SQL92Parser::Insert_columns_sectionContext>(0);
}


size_t SQL92Parser::Insert_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleInsert_stmt;
}

void SQL92Parser::Insert_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_stmt(this);
}

void SQL92Parser::Insert_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_stmt(this);
}

SQL92Parser::Insert_stmtContext* SQL92Parser::insert_stmt() {
  Insert_stmtContext *_localctx = _tracker.createInstance<Insert_stmtContext>(_ctx, getState());
  enterRule(_localctx, 42, SQL92Parser::RuleInsert_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ASYNC

    || _la == SQL92Parser::SYNC) {
      setState(258);
      sync_operator();
    }
    setState(261);
    match(SQL92Parser::INSERT);
    setState(262);
    match(SQL92Parser::INTO);
    setState(263);
    collection_section();
    setState(265);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::T__0) {
      setState(264);
      insert_columns_section();
    }
    setState(267);
    insert_values_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_columns_sectionContext ------------------------------------------------------------------

SQL92Parser::Insert_columns_sectionContext::Insert_columns_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQL92Parser::Column_sectionContext *> SQL92Parser::Insert_columns_sectionContext::column_section() {
  return getRuleContexts<SQL92Parser::Column_sectionContext>();
}

SQL92Parser::Column_sectionContext* SQL92Parser::Insert_columns_sectionContext::column_section(size_t i) {
  return getRuleContext<SQL92Parser::Column_sectionContext>(i);
}


size_t SQL92Parser::Insert_columns_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleInsert_columns_section;
}

void SQL92Parser::Insert_columns_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_columns_section(this);
}

void SQL92Parser::Insert_columns_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_columns_section(this);
}

SQL92Parser::Insert_columns_sectionContext* SQL92Parser::insert_columns_section() {
  Insert_columns_sectionContext *_localctx = _tracker.createInstance<Insert_columns_sectionContext>(_ctx, getState());
  enterRule(_localctx, 44, SQL92Parser::RuleInsert_columns_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(SQL92Parser::T__0);
    setState(270);
    column_section();
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::COMMA) {
      setState(271);
      match(SQL92Parser::COMMA);
      setState(272);
      column_section();
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(278);
    match(SQL92Parser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_values_sectionContext ------------------------------------------------------------------

SQL92Parser::Insert_values_sectionContext::Insert_values_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Insert_values_sectionContext::VALUE() {
  return getToken(SQL92Parser::VALUE, 0);
}

SQL92Parser::ExpressionContext* SQL92Parser::Insert_values_sectionContext::expression() {
  return getRuleContext<SQL92Parser::ExpressionContext>(0);
}

tree::TerminalNode* SQL92Parser::Insert_values_sectionContext::VALUES() {
  return getToken(SQL92Parser::VALUES, 0);
}


size_t SQL92Parser::Insert_values_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleInsert_values_section;
}

void SQL92Parser::Insert_values_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_values_section(this);
}

void SQL92Parser::Insert_values_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_values_section(this);
}

SQL92Parser::Insert_values_sectionContext* SQL92Parser::insert_values_section() {
  Insert_values_sectionContext *_localctx = _tracker.createInstance<Insert_values_sectionContext>(_ctx, getState());
  enterRule(_localctx, 46, SQL92Parser::RuleInsert_values_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(284);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::VALUE: {
        enterOuterAlt(_localctx, 1);
        setState(280);
        match(SQL92Parser::VALUE);
        setState(281);
        expression();
        break;
      }

      case SQL92Parser::VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(282);
        match(SQL92Parser::VALUES);
        setState(283);
        expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmtContext ------------------------------------------------------------------

SQL92Parser::Update_stmtContext::Update_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Update_stmtContext::UPDATE() {
  return getToken(SQL92Parser::UPDATE, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Update_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}

tree::TerminalNode* SQL92Parser::Update_stmtContext::SET() {
  return getToken(SQL92Parser::SET, 0);
}

std::vector<SQL92Parser::Property_sectionContext *> SQL92Parser::Update_stmtContext::property_section() {
  return getRuleContexts<SQL92Parser::Property_sectionContext>();
}

SQL92Parser::Property_sectionContext* SQL92Parser::Update_stmtContext::property_section(size_t i) {
  return getRuleContext<SQL92Parser::Property_sectionContext>(i);
}

SQL92Parser::Sync_operatorContext* SQL92Parser::Update_stmtContext::sync_operator() {
  return getRuleContext<SQL92Parser::Sync_operatorContext>(0);
}

std::vector<tree::TerminalNode *> SQL92Parser::Update_stmtContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::Update_stmtContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}

SQL92Parser::Where_sectionContext* SQL92Parser::Update_stmtContext::where_section() {
  return getRuleContext<SQL92Parser::Where_sectionContext>(0);
}


size_t SQL92Parser::Update_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleUpdate_stmt;
}

void SQL92Parser::Update_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt(this);
}

void SQL92Parser::Update_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt(this);
}

SQL92Parser::Update_stmtContext* SQL92Parser::update_stmt() {
  Update_stmtContext *_localctx = _tracker.createInstance<Update_stmtContext>(_ctx, getState());
  enterRule(_localctx, 48, SQL92Parser::RuleUpdate_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ASYNC

    || _la == SQL92Parser::SYNC) {
      setState(286);
      sync_operator();
    }
    setState(289);
    match(SQL92Parser::UPDATE);
    setState(290);
    collection_section();
    setState(291);
    match(SQL92Parser::SET);
    setState(292);
    property_section();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQL92Parser::COMMA) {
      setState(293);
      match(SQL92Parser::COMMA);
      setState(294);
      property_section();
      setState(299);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::WHERE) {
      setState(300);
      where_section();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_sectionContext ------------------------------------------------------------------

SQL92Parser::Property_sectionContext::Property_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::PropertyContext* SQL92Parser::Property_sectionContext::property() {
  return getRuleContext<SQL92Parser::PropertyContext>(0);
}

tree::TerminalNode* SQL92Parser::Property_sectionContext::SINGLE_EQ() {
  return getToken(SQL92Parser::SINGLE_EQ, 0);
}

SQL92Parser::Expression_literalContext* SQL92Parser::Property_sectionContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}


size_t SQL92Parser::Property_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleProperty_section;
}

void SQL92Parser::Property_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_section(this);
}

void SQL92Parser::Property_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_section(this);
}

SQL92Parser::Property_sectionContext* SQL92Parser::property_section() {
  Property_sectionContext *_localctx = _tracker.createInstance<Property_sectionContext>(_ctx, getState());
  enterRule(_localctx, 50, SQL92Parser::RuleProperty_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    property();
    setState(304);
    match(SQL92Parser::SINGLE_EQ);
    setState(305);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmtContext ------------------------------------------------------------------

SQL92Parser::Delete_stmtContext::Delete_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Delete_stmtContext::DELETE() {
  return getToken(SQL92Parser::DELETE, 0);
}

tree::TerminalNode* SQL92Parser::Delete_stmtContext::FROM() {
  return getToken(SQL92Parser::FROM, 0);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::Delete_stmtContext::collection_section() {
  return getRuleContext<SQL92Parser::Collection_sectionContext>(0);
}

SQL92Parser::Sync_operatorContext* SQL92Parser::Delete_stmtContext::sync_operator() {
  return getRuleContext<SQL92Parser::Sync_operatorContext>(0);
}

SQL92Parser::Where_sectionContext* SQL92Parser::Delete_stmtContext::where_section() {
  return getRuleContext<SQL92Parser::Where_sectionContext>(0);
}


size_t SQL92Parser::Delete_stmtContext::getRuleIndex() const {
  return SQL92Parser::RuleDelete_stmt;
}

void SQL92Parser::Delete_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt(this);
}

void SQL92Parser::Delete_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt(this);
}

SQL92Parser::Delete_stmtContext* SQL92Parser::delete_stmt() {
  Delete_stmtContext *_localctx = _tracker.createInstance<Delete_stmtContext>(_ctx, getState());
  enterRule(_localctx, 52, SQL92Parser::RuleDelete_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::ASYNC

    || _la == SQL92Parser::SYNC) {
      setState(307);
      sync_operator();
    }
    setState(310);
    match(SQL92Parser::DELETE);
    setState(311);
    match(SQL92Parser::FROM);
    setState(312);
    collection_section();
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::WHERE) {
      setState(313);
      where_section();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SQL92Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_listContext* SQL92Parser::ExpressionContext::expression_list() {
  return getRuleContext<SQL92Parser::Expression_listContext>(0);
}


size_t SQL92Parser::ExpressionContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression;
}

void SQL92Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SQL92Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SQL92Parser::ExpressionContext* SQL92Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 54, SQL92Parser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    expression_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

SQL92Parser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_literalContext* SQL92Parser::Expression_listContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}

SQL92Parser::Expression_functionContext* SQL92Parser::Expression_listContext::expression_function() {
  return getRuleContext<SQL92Parser::Expression_functionContext>(0);
}

std::vector<SQL92Parser::Expression_binary_operatorContext *> SQL92Parser::Expression_listContext::expression_binary_operator() {
  return getRuleContexts<SQL92Parser::Expression_binary_operatorContext>();
}

SQL92Parser::Expression_binary_operatorContext* SQL92Parser::Expression_listContext::expression_binary_operator(size_t i) {
  return getRuleContext<SQL92Parser::Expression_binary_operatorContext>(i);
}

std::vector<SQL92Parser::Expression_logic_operatorContext *> SQL92Parser::Expression_listContext::expression_logic_operator() {
  return getRuleContexts<SQL92Parser::Expression_logic_operatorContext>();
}

SQL92Parser::Expression_logic_operatorContext* SQL92Parser::Expression_listContext::expression_logic_operator(size_t i) {
  return getRuleContext<SQL92Parser::Expression_logic_operatorContext>(i);
}

std::vector<SQL92Parser::Expression_arrayContext *> SQL92Parser::Expression_listContext::expression_array() {
  return getRuleContexts<SQL92Parser::Expression_arrayContext>();
}

SQL92Parser::Expression_arrayContext* SQL92Parser::Expression_listContext::expression_array(size_t i) {
  return getRuleContext<SQL92Parser::Expression_arrayContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::Expression_listContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::Expression_listContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}

std::vector<SQL92Parser::Expression_dictionaryContext *> SQL92Parser::Expression_listContext::expression_dictionary() {
  return getRuleContexts<SQL92Parser::Expression_dictionaryContext>();
}

SQL92Parser::Expression_dictionaryContext* SQL92Parser::Expression_listContext::expression_dictionary(size_t i) {
  return getRuleContext<SQL92Parser::Expression_dictionaryContext>(i);
}


size_t SQL92Parser::Expression_listContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_list;
}

void SQL92Parser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void SQL92Parser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}

SQL92Parser::Expression_listContext* SQL92Parser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 56, SQL92Parser::RuleExpression_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(318);
      expression_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(319);
      expression_function();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(320);
      expression_binary_operator();
      setState(326);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQL92Parser::AND

      || _la == SQL92Parser::OR) {
        setState(321);
        expression_logic_operator();
        setState(322);
        expression_binary_operator();
        setState(328);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(329);
      match(SQL92Parser::T__0);
      setState(330);
      expression_array();
      setState(335);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQL92Parser::COMMA) {
        setState(331);
        match(SQL92Parser::COMMA);
        setState(332);
        expression_array();
        setState(337);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(338);
      match(SQL92Parser::T__1);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(340);
      match(SQL92Parser::T__2);

      setState(341);
      expression_dictionary();
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQL92Parser::COMMA) {
        setState(342);
        match(SQL92Parser::COMMA);
        setState(343);
        expression_dictionary();
        setState(348);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(349);
      match(SQL92Parser::T__3);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(351);
      match(SQL92Parser::T__4);
      setState(352);
      expression_array();
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SQL92Parser::COMMA) {
        setState(353);
        match(SQL92Parser::COMMA);
        setState(354);
        expression_array();
        setState(359);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(360);
      match(SQL92Parser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_literalContext ------------------------------------------------------------------

SQL92Parser::Expression_literalContext::Expression_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_literal_valueContext* SQL92Parser::Expression_literalContext::expression_literal_value() {
  return getRuleContext<SQL92Parser::Expression_literal_valueContext>(0);
}


size_t SQL92Parser::Expression_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_literal;
}

void SQL92Parser::Expression_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_literal(this);
}

void SQL92Parser::Expression_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_literal(this);
}

SQL92Parser::Expression_literalContext* SQL92Parser::expression_literal() {
  Expression_literalContext *_localctx = _tracker.createInstance<Expression_literalContext>(_ctx, getState());
  enterRule(_localctx, 58, SQL92Parser::RuleExpression_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    expression_literal_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_literal_valueContext ------------------------------------------------------------------

SQL92Parser::Expression_literal_valueContext::Expression_literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Property_literalContext* SQL92Parser::Expression_literal_valueContext::property_literal() {
  return getRuleContext<SQL92Parser::Property_literalContext>(0);
}

SQL92Parser::Integer_literalContext* SQL92Parser::Expression_literal_valueContext::integer_literal() {
  return getRuleContext<SQL92Parser::Integer_literalContext>(0);
}

SQL92Parser::Real_literalContext* SQL92Parser::Expression_literal_valueContext::real_literal() {
  return getRuleContext<SQL92Parser::Real_literalContext>(0);
}

SQL92Parser::String_literalContext* SQL92Parser::Expression_literal_valueContext::string_literal() {
  return getRuleContext<SQL92Parser::String_literalContext>(0);
}

SQL92Parser::True_literalContext* SQL92Parser::Expression_literal_valueContext::true_literal() {
  return getRuleContext<SQL92Parser::True_literalContext>(0);
}

SQL92Parser::False_literalContext* SQL92Parser::Expression_literal_valueContext::false_literal() {
  return getRuleContext<SQL92Parser::False_literalContext>(0);
}

tree::TerminalNode* SQL92Parser::Expression_literal_valueContext::NIL() {
  return getToken(SQL92Parser::NIL, 0);
}

tree::TerminalNode* SQL92Parser::Expression_literal_valueContext::CURRENT_TIME() {
  return getToken(SQL92Parser::CURRENT_TIME, 0);
}

tree::TerminalNode* SQL92Parser::Expression_literal_valueContext::CURRENT_DATE() {
  return getToken(SQL92Parser::CURRENT_DATE, 0);
}

tree::TerminalNode* SQL92Parser::Expression_literal_valueContext::CURRENT_TIMESTAMP() {
  return getToken(SQL92Parser::CURRENT_TIMESTAMP, 0);
}


size_t SQL92Parser::Expression_literal_valueContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_literal_value;
}

void SQL92Parser::Expression_literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_literal_value(this);
}

void SQL92Parser::Expression_literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_literal_value(this);
}

SQL92Parser::Expression_literal_valueContext* SQL92Parser::expression_literal_value() {
  Expression_literal_valueContext *_localctx = _tracker.createInstance<Expression_literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 60, SQL92Parser::RuleExpression_literal_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(366);
        property_literal();
        break;
      }

      case SQL92Parser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(367);
        integer_literal();
        break;
      }

      case SQL92Parser::FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(368);
        real_literal();
        break;
      }

      case SQL92Parser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(369);
        string_literal();
        break;
      }

      case SQL92Parser::TRUE: {
        enterOuterAlt(_localctx, 5);
        setState(370);
        true_literal();
        break;
      }

      case SQL92Parser::FALSE: {
        enterOuterAlt(_localctx, 6);
        setState(371);
        false_literal();
        break;
      }

      case SQL92Parser::NIL: {
        enterOuterAlt(_localctx, 7);
        setState(372);
        match(SQL92Parser::NIL);
        break;
      }

      case SQL92Parser::CURRENT_TIME: {
        enterOuterAlt(_localctx, 8);
        setState(373);
        match(SQL92Parser::CURRENT_TIME);
        break;
      }

      case SQL92Parser::CURRENT_DATE: {
        enterOuterAlt(_localctx, 9);
        setState(374);
        match(SQL92Parser::CURRENT_DATE);
        break;
      }

      case SQL92Parser::CURRENT_TIMESTAMP: {
        enterOuterAlt(_localctx, 10);
        setState(375);
        match(SQL92Parser::CURRENT_TIMESTAMP);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_dictionaryContext ------------------------------------------------------------------

SQL92Parser::Expression_dictionaryContext::Expression_dictionaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::NameContext* SQL92Parser::Expression_dictionaryContext::name() {
  return getRuleContext<SQL92Parser::NameContext>(0);
}

SQL92Parser::Expression_literalContext* SQL92Parser::Expression_dictionaryContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}


size_t SQL92Parser::Expression_dictionaryContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_dictionary;
}

void SQL92Parser::Expression_dictionaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_dictionary(this);
}

void SQL92Parser::Expression_dictionaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_dictionary(this);
}

SQL92Parser::Expression_dictionaryContext* SQL92Parser::expression_dictionary() {
  Expression_dictionaryContext *_localctx = _tracker.createInstance<Expression_dictionaryContext>(_ctx, getState());
  enterRule(_localctx, 62, SQL92Parser::RuleExpression_dictionary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    name();
    setState(379);
    match(SQL92Parser::T__6);
    setState(380);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dictionary_literalContext ------------------------------------------------------------------

SQL92Parser::Dictionary_literalContext::Dictionary_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::NameContext* SQL92Parser::Dictionary_literalContext::name() {
  return getRuleContext<SQL92Parser::NameContext>(0);
}

SQL92Parser::Expression_literalContext* SQL92Parser::Dictionary_literalContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}


size_t SQL92Parser::Dictionary_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleDictionary_literal;
}

void SQL92Parser::Dictionary_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionary_literal(this);
}

void SQL92Parser::Dictionary_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionary_literal(this);
}

SQL92Parser::Dictionary_literalContext* SQL92Parser::dictionary_literal() {
  Dictionary_literalContext *_localctx = _tracker.createInstance<Dictionary_literalContext>(_ctx, getState());
  enterRule(_localctx, 64, SQL92Parser::RuleDictionary_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    name();
    setState(383);
    match(SQL92Parser::T__6);
    setState(384);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_arrayContext ------------------------------------------------------------------

SQL92Parser::Expression_arrayContext::Expression_arrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_literalContext* SQL92Parser::Expression_arrayContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}


size_t SQL92Parser::Expression_arrayContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_array;
}

void SQL92Parser::Expression_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_array(this);
}

void SQL92Parser::Expression_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_array(this);
}

SQL92Parser::Expression_arrayContext* SQL92Parser::expression_array() {
  Expression_arrayContext *_localctx = _tracker.createInstance<Expression_arrayContext>(_ctx, getState());
  enterRule(_localctx, 66, SQL92Parser::RuleExpression_array);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_literalContext ------------------------------------------------------------------

SQL92Parser::Array_literalContext::Array_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_literalContext* SQL92Parser::Array_literalContext::expression_literal() {
  return getRuleContext<SQL92Parser::Expression_literalContext>(0);
}


size_t SQL92Parser::Array_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleArray_literal;
}

void SQL92Parser::Array_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_literal(this);
}

void SQL92Parser::Array_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_literal(this);
}

SQL92Parser::Array_literalContext* SQL92Parser::array_literal() {
  Array_literalContext *_localctx = _tracker.createInstance<Array_literalContext>(_ctx, getState());
  enterRule(_localctx, 68, SQL92Parser::RuleArray_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_logic_operatorContext ------------------------------------------------------------------

SQL92Parser::Expression_logic_operatorContext::Expression_logic_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Logical_operatorContext* SQL92Parser::Expression_logic_operatorContext::logical_operator() {
  return getRuleContext<SQL92Parser::Logical_operatorContext>(0);
}


size_t SQL92Parser::Expression_logic_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_logic_operator;
}

void SQL92Parser::Expression_logic_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_logic_operator(this);
}

void SQL92Parser::Expression_logic_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_logic_operator(this);
}

SQL92Parser::Expression_logic_operatorContext* SQL92Parser::expression_logic_operator() {
  Expression_logic_operatorContext *_localctx = _tracker.createInstance<Expression_logic_operatorContext>(_ctx, getState());
  enterRule(_localctx, 70, SQL92Parser::RuleExpression_logic_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    logical_operator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_binary_operatorContext ------------------------------------------------------------------

SQL92Parser::Expression_binary_operatorContext::Expression_binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Expression_operatorContext* SQL92Parser::Expression_binary_operatorContext::expression_operator() {
  return getRuleContext<SQL92Parser::Expression_operatorContext>(0);
}


size_t SQL92Parser::Expression_binary_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_binary_operator;
}

void SQL92Parser::Expression_binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_binary_operator(this);
}

void SQL92Parser::Expression_binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_binary_operator(this);
}

SQL92Parser::Expression_binary_operatorContext* SQL92Parser::expression_binary_operator() {
  Expression_binary_operatorContext *_localctx = _tracker.createInstance<Expression_binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 72, SQL92Parser::RuleExpression_binary_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    expression_operator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_functionContext ------------------------------------------------------------------

SQL92Parser::Expression_functionContext::Expression_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Expression_functionContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}

SQL92Parser::Function_valueContext* SQL92Parser::Expression_functionContext::function_value() {
  return getRuleContext<SQL92Parser::Function_valueContext>(0);
}


size_t SQL92Parser::Expression_functionContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_function;
}

void SQL92Parser::Expression_functionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_function(this);
}

void SQL92Parser::Expression_functionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_function(this);
}

SQL92Parser::Expression_functionContext* SQL92Parser::expression_function() {
  Expression_functionContext *_localctx = _tracker.createInstance<Expression_functionContext>(_ctx, getState());
  enterRule(_localctx, 74, SQL92Parser::RuleExpression_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(SQL92Parser::ID);
    setState(395);
    match(SQL92Parser::T__0);
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQL92Parser::T__0)
      | (1ULL << SQL92Parser::T__2)
      | (1ULL << SQL92Parser::T__4)
      | (1ULL << SQL92Parser::ASTERISK)
      | (1ULL << SQL92Parser::CURRENT_DATE)
      | (1ULL << SQL92Parser::CURRENT_TIME)
      | (1ULL << SQL92Parser::CURRENT_TIMESTAMP)
      | (1ULL << SQL92Parser::NIL)
      | (1ULL << SQL92Parser::TRUE)
      | (1ULL << SQL92Parser::FALSE))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (SQL92Parser::ID - 65))
      | (1ULL << (SQL92Parser::NUMBER - 65))
      | (1ULL << (SQL92Parser::FLOAT - 65))
      | (1ULL << (SQL92Parser::STRING - 65)))) != 0)) {
      setState(396);
      function_value();
    }
    setState(399);
    match(SQL92Parser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

SQL92Parser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Function_nameContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}


size_t SQL92Parser::Function_nameContext::getRuleIndex() const {
  return SQL92Parser::RuleFunction_name;
}

void SQL92Parser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void SQL92Parser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}

SQL92Parser::Function_nameContext* SQL92Parser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 76, SQL92Parser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(SQL92Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_valueContext ------------------------------------------------------------------

SQL92Parser::Function_valueContext::Function_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQL92Parser::ExpressionContext *> SQL92Parser::Function_valueContext::expression() {
  return getRuleContexts<SQL92Parser::ExpressionContext>();
}

SQL92Parser::ExpressionContext* SQL92Parser::Function_valueContext::expression(size_t i) {
  return getRuleContext<SQL92Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SQL92Parser::Function_valueContext::COMMA() {
  return getTokens(SQL92Parser::COMMA);
}

tree::TerminalNode* SQL92Parser::Function_valueContext::COMMA(size_t i) {
  return getToken(SQL92Parser::COMMA, i);
}

tree::TerminalNode* SQL92Parser::Function_valueContext::ASTERISK() {
  return getToken(SQL92Parser::ASTERISK, 0);
}


size_t SQL92Parser::Function_valueContext::getRuleIndex() const {
  return SQL92Parser::RuleFunction_value;
}

void SQL92Parser::Function_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_value(this);
}

void SQL92Parser::Function_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_value(this);
}

SQL92Parser::Function_valueContext* SQL92Parser::function_value() {
  Function_valueContext *_localctx = _tracker.createInstance<Function_valueContext>(_ctx, getState());
  enterRule(_localctx, 78, SQL92Parser::RuleFunction_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::T__0:
      case SQL92Parser::T__2:
      case SQL92Parser::T__4:
      case SQL92Parser::CURRENT_DATE:
      case SQL92Parser::CURRENT_TIME:
      case SQL92Parser::CURRENT_TIMESTAMP:
      case SQL92Parser::NIL:
      case SQL92Parser::TRUE:
      case SQL92Parser::FALSE:
      case SQL92Parser::ID:
      case SQL92Parser::NUMBER:
      case SQL92Parser::FLOAT:
      case SQL92Parser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(403);
        expression();
        setState(408);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQL92Parser::COMMA) {
          setState(404);
          match(SQL92Parser::COMMA);
          setState(405);
          expression();
          setState(410);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SQL92Parser::ASTERISK: {
        enterOuterAlt(_localctx, 2);
        setState(411);
        match(SQL92Parser::ASTERISK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_operatorContext ------------------------------------------------------------------

SQL92Parser::Expression_operatorContext::Expression_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQL92Parser::Expression_literalContext *> SQL92Parser::Expression_operatorContext::expression_literal() {
  return getRuleContexts<SQL92Parser::Expression_literalContext>();
}

SQL92Parser::Expression_literalContext* SQL92Parser::Expression_operatorContext::expression_literal(size_t i) {
  return getRuleContext<SQL92Parser::Expression_literalContext>(i);
}

SQL92Parser::Binary_operatorContext* SQL92Parser::Expression_operatorContext::binary_operator() {
  return getRuleContext<SQL92Parser::Binary_operatorContext>(0);
}


size_t SQL92Parser::Expression_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleExpression_operator;
}

void SQL92Parser::Expression_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_operator(this);
}

void SQL92Parser::Expression_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_operator(this);
}

SQL92Parser::Expression_operatorContext* SQL92Parser::expression_operator() {
  Expression_operatorContext *_localctx = _tracker.createInstance<Expression_operatorContext>(_ctx, getState());
  enterRule(_localctx, 80, SQL92Parser::RuleExpression_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    expression_literal();
    setState(415);
    binary_operator();
    setState(416);
    expression_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

SQL92Parser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::SINGLE_EQ() {
  return getToken(SQL92Parser::SINGLE_EQ, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::DOUBLE_EQ() {
  return getToken(SQL92Parser::DOUBLE_EQ, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::OP_LT() {
  return getToken(SQL92Parser::OP_LT, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::LE() {
  return getToken(SQL92Parser::LE, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::GT() {
  return getToken(SQL92Parser::GT, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::GE() {
  return getToken(SQL92Parser::GE, 0);
}

tree::TerminalNode* SQL92Parser::Binary_operatorContext::NOTEQ() {
  return getToken(SQL92Parser::NOTEQ, 0);
}


size_t SQL92Parser::Binary_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleBinary_operator;
}

void SQL92Parser::Binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_operator(this);
}

void SQL92Parser::Binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_operator(this);
}

SQL92Parser::Binary_operatorContext* SQL92Parser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 82, SQL92Parser::RuleBinary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQL92Parser::SINGLE_EQ)
      | (1ULL << SQL92Parser::DOUBLE_EQ)
      | (1ULL << SQL92Parser::OP_LT)
      | (1ULL << SQL92Parser::LE)
      | (1ULL << SQL92Parser::GT)
      | (1ULL << SQL92Parser::GE)
      | (1ULL << SQL92Parser::NOTEQ))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_operatorContext ------------------------------------------------------------------

SQL92Parser::Logical_operatorContext::Logical_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Logical_operatorContext::AND() {
  return getToken(SQL92Parser::AND, 0);
}

tree::TerminalNode* SQL92Parser::Logical_operatorContext::OR() {
  return getToken(SQL92Parser::OR, 0);
}


size_t SQL92Parser::Logical_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleLogical_operator;
}

void SQL92Parser::Logical_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_operator(this);
}

void SQL92Parser::Logical_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_operator(this);
}

SQL92Parser::Logical_operatorContext* SQL92Parser::logical_operator() {
  Logical_operatorContext *_localctx = _tracker.createInstance<Logical_operatorContext>(_ctx, getState());
  enterRule(_localctx, 84, SQL92Parser::RuleLogical_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    _la = _input->LA(1);
    if (!(_la == SQL92Parser::AND

    || _la == SQL92Parser::OR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_literalContext ------------------------------------------------------------------

SQL92Parser::Property_literalContext::Property_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Property_literalContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}


size_t SQL92Parser::Property_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleProperty_literal;
}

void SQL92Parser::Property_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_literal(this);
}

void SQL92Parser::Property_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_literal(this);
}

SQL92Parser::Property_literalContext* SQL92Parser::property_literal() {
  Property_literalContext *_localctx = _tracker.createInstance<Property_literalContext>(_ctx, getState());
  enterRule(_localctx, 86, SQL92Parser::RuleProperty_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    match(SQL92Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_literalContext ------------------------------------------------------------------

SQL92Parser::Integer_literalContext::Integer_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Integer_literalContext::NUMBER() {
  return getToken(SQL92Parser::NUMBER, 0);
}


size_t SQL92Parser::Integer_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleInteger_literal;
}

void SQL92Parser::Integer_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_literal(this);
}

void SQL92Parser::Integer_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_literal(this);
}

SQL92Parser::Integer_literalContext* SQL92Parser::integer_literal() {
  Integer_literalContext *_localctx = _tracker.createInstance<Integer_literalContext>(_ctx, getState());
  enterRule(_localctx, 88, SQL92Parser::RuleInteger_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(SQL92Parser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Real_literalContext ------------------------------------------------------------------

SQL92Parser::Real_literalContext::Real_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Real_literalContext::FLOAT() {
  return getToken(SQL92Parser::FLOAT, 0);
}


size_t SQL92Parser::Real_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleReal_literal;
}

void SQL92Parser::Real_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_literal(this);
}

void SQL92Parser::Real_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_literal(this);
}

SQL92Parser::Real_literalContext* SQL92Parser::real_literal() {
  Real_literalContext *_localctx = _tracker.createInstance<Real_literalContext>(_ctx, getState());
  enterRule(_localctx, 90, SQL92Parser::RuleReal_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(SQL92Parser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_literalContext ------------------------------------------------------------------

SQL92Parser::String_literalContext::String_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::String_literalContext::STRING() {
  return getToken(SQL92Parser::STRING, 0);
}


size_t SQL92Parser::String_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleString_literal;
}

void SQL92Parser::String_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_literal(this);
}

void SQL92Parser::String_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_literal(this);
}

SQL92Parser::String_literalContext* SQL92Parser::string_literal() {
  String_literalContext *_localctx = _tracker.createInstance<String_literalContext>(_ctx, getState());
  enterRule(_localctx, 92, SQL92Parser::RuleString_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(SQL92Parser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- True_literalContext ------------------------------------------------------------------

SQL92Parser::True_literalContext::True_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::True_literalContext::TRUE() {
  return getToken(SQL92Parser::TRUE, 0);
}


size_t SQL92Parser::True_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleTrue_literal;
}

void SQL92Parser::True_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrue_literal(this);
}

void SQL92Parser::True_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrue_literal(this);
}

SQL92Parser::True_literalContext* SQL92Parser::true_literal() {
  True_literalContext *_localctx = _tracker.createInstance<True_literalContext>(_ctx, getState());
  enterRule(_localctx, 94, SQL92Parser::RuleTrue_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(SQL92Parser::TRUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- False_literalContext ------------------------------------------------------------------

SQL92Parser::False_literalContext::False_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::False_literalContext::FALSE() {
  return getToken(SQL92Parser::FALSE, 0);
}


size_t SQL92Parser::False_literalContext::getRuleIndex() const {
  return SQL92Parser::RuleFalse_literal;
}

void SQL92Parser::False_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFalse_literal(this);
}

void SQL92Parser::False_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFalse_literal(this);
}

SQL92Parser::False_literalContext* SQL92Parser::false_literal() {
  False_literalContext *_localctx = _tracker.createInstance<False_literalContext>(_ctx, getState());
  enterRule(_localctx, 96, SQL92Parser::RuleFalse_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(SQL92Parser::FALSE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sync_operatorContext ------------------------------------------------------------------

SQL92Parser::Sync_operatorContext::Sync_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Sync_operatorContext::SYNC() {
  return getToken(SQL92Parser::SYNC, 0);
}

tree::TerminalNode* SQL92Parser::Sync_operatorContext::ASYNC() {
  return getToken(SQL92Parser::ASYNC, 0);
}


size_t SQL92Parser::Sync_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleSync_operator;
}

void SQL92Parser::Sync_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSync_operator(this);
}

void SQL92Parser::Sync_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSync_operator(this);
}

SQL92Parser::Sync_operatorContext* SQL92Parser::sync_operator() {
  Sync_operatorContext *_localctx = _tracker.createInstance<Sync_operatorContext>(_ctx, getState());
  enterRule(_localctx, 98, SQL92Parser::RuleSync_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    _la = _input->LA(1);
    if (!(_la == SQL92Parser::ASYNC

    || _la == SQL92Parser::SYNC)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_operatorContext ------------------------------------------------------------------

SQL92Parser::Compound_operatorContext::Compound_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Compound_operatorContext::UNION() {
  return getToken(SQL92Parser::UNION, 0);
}

tree::TerminalNode* SQL92Parser::Compound_operatorContext::ALL() {
  return getToken(SQL92Parser::ALL, 0);
}

tree::TerminalNode* SQL92Parser::Compound_operatorContext::INTERSECT() {
  return getToken(SQL92Parser::INTERSECT, 0);
}

tree::TerminalNode* SQL92Parser::Compound_operatorContext::EXCEPT() {
  return getToken(SQL92Parser::EXCEPT, 0);
}


size_t SQL92Parser::Compound_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleCompound_operator;
}

void SQL92Parser::Compound_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_operator(this);
}

void SQL92Parser::Compound_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_operator(this);
}

SQL92Parser::Compound_operatorContext* SQL92Parser::compound_operator() {
  Compound_operatorContext *_localctx = _tracker.createInstance<Compound_operatorContext>(_ctx, getState());
  enterRule(_localctx, 100, SQL92Parser::RuleCompound_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(442);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::UNION: {
        enterOuterAlt(_localctx, 1);
        setState(436);
        match(SQL92Parser::UNION);
        setState(438);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SQL92Parser::ALL) {
          setState(437);
          match(SQL92Parser::ALL);
        }
        break;
      }

      case SQL92Parser::INTERSECT: {
        enterOuterAlt(_localctx, 2);
        setState(440);
        match(SQL92Parser::INTERSECT);
        break;
      }

      case SQL92Parser::EXCEPT: {
        enterOuterAlt(_localctx, 3);
        setState(441);
        match(SQL92Parser::EXCEPT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_operatorContext ------------------------------------------------------------------

SQL92Parser::Condition_operatorContext::Condition_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::SINGLE_EQ() {
  return getToken(SQL92Parser::SINGLE_EQ, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::DOUBLE_EQ() {
  return getToken(SQL92Parser::DOUBLE_EQ, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::OP_LT() {
  return getToken(SQL92Parser::OP_LT, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::LE() {
  return getToken(SQL92Parser::LE, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::GT() {
  return getToken(SQL92Parser::GT, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::GE() {
  return getToken(SQL92Parser::GE, 0);
}

tree::TerminalNode* SQL92Parser::Condition_operatorContext::NOTEQ() {
  return getToken(SQL92Parser::NOTEQ, 0);
}


size_t SQL92Parser::Condition_operatorContext::getRuleIndex() const {
  return SQL92Parser::RuleCondition_operator;
}

void SQL92Parser::Condition_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition_operator(this);
}

void SQL92Parser::Condition_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition_operator(this);
}

SQL92Parser::Condition_operatorContext* SQL92Parser::condition_operator() {
  Condition_operatorContext *_localctx = _tracker.createInstance<Condition_operatorContext>(_ctx, getState());
  enterRule(_localctx, 102, SQL92Parser::RuleCondition_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SQL92Parser::SINGLE_EQ)
      | (1ULL << SQL92Parser::DOUBLE_EQ)
      | (1ULL << SQL92Parser::OP_LT)
      | (1ULL << SQL92Parser::LE)
      | (1ULL << SQL92Parser::GT)
      | (1ULL << SQL92Parser::GE)
      | (1ULL << SQL92Parser::NOTEQ))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

SQL92Parser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::PropertyContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}


size_t SQL92Parser::PropertyContext::getRuleIndex() const {
  return SQL92Parser::RuleProperty;
}

void SQL92Parser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void SQL92Parser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}

SQL92Parser::PropertyContext* SQL92Parser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 104, SQL92Parser::RuleProperty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(446);
    match(SQL92Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

SQL92Parser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::ValueContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}


size_t SQL92Parser::ValueContext::getRuleIndex() const {
  return SQL92Parser::RuleValue;
}

void SQL92Parser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void SQL92Parser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

SQL92Parser::ValueContext* SQL92Parser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 106, SQL92Parser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(SQL92Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SQL92Parser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::NameContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}


size_t SQL92Parser::NameContext::getRuleIndex() const {
  return SQL92Parser::RuleName;
}

void SQL92Parser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void SQL92Parser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}

SQL92Parser::NameContext* SQL92Parser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 108, SQL92Parser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    match(SQL92Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collection_sectionContext ------------------------------------------------------------------

SQL92Parser::Collection_sectionContext::Collection_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Collection_nameContext* SQL92Parser::Collection_sectionContext::collection_name() {
  return getRuleContext<SQL92Parser::Collection_nameContext>(0);
}


size_t SQL92Parser::Collection_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleCollection_section;
}

void SQL92Parser::Collection_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollection_section(this);
}

void SQL92Parser::Collection_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollection_section(this);
}

SQL92Parser::Collection_sectionContext* SQL92Parser::collection_section() {
  Collection_sectionContext *_localctx = _tracker.createInstance<Collection_sectionContext>(_ctx, getState());
  enterRule(_localctx, 110, SQL92Parser::RuleCollection_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    collection_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collection_nameContext ------------------------------------------------------------------

SQL92Parser::Collection_nameContext::Collection_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Collection_nameContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}

SQL92Parser::String_literalContext* SQL92Parser::Collection_nameContext::string_literal() {
  return getRuleContext<SQL92Parser::String_literalContext>(0);
}


size_t SQL92Parser::Collection_nameContext::getRuleIndex() const {
  return SQL92Parser::RuleCollection_name;
}

void SQL92Parser::Collection_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollection_name(this);
}

void SQL92Parser::Collection_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollection_name(this);
}

SQL92Parser::Collection_nameContext* SQL92Parser::collection_name() {
  Collection_nameContext *_localctx = _tracker.createInstance<Collection_nameContext>(_ctx, getState());
  enterRule(_localctx, 112, SQL92Parser::RuleCollection_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(456);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(454);
        match(SQL92Parser::ID);
        break;
      }

      case SQL92Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(455);
        string_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_sectionContext ------------------------------------------------------------------

SQL92Parser::Column_sectionContext::Column_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::ExpressionContext* SQL92Parser::Column_sectionContext::expression() {
  return getRuleContext<SQL92Parser::ExpressionContext>(0);
}

tree::TerminalNode* SQL92Parser::Column_sectionContext::AS() {
  return getToken(SQL92Parser::AS, 0);
}

SQL92Parser::NameContext* SQL92Parser::Column_sectionContext::name() {
  return getRuleContext<SQL92Parser::NameContext>(0);
}


size_t SQL92Parser::Column_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleColumn_section;
}

void SQL92Parser::Column_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_section(this);
}

void SQL92Parser::Column_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_section(this);
}

SQL92Parser::Column_sectionContext* SQL92Parser::column_section() {
  Column_sectionContext *_localctx = _tracker.createInstance<Column_sectionContext>(_ctx, getState());
  enterRule(_localctx, 114, SQL92Parser::RuleColumn_section);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    expression();
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQL92Parser::AS) {
      setState(459);
      match(SQL92Parser::AS);
      setState(460);
      name();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_sectionContext ------------------------------------------------------------------

SQL92Parser::Index_sectionContext::Index_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQL92Parser::Index_nameContext* SQL92Parser::Index_sectionContext::index_name() {
  return getRuleContext<SQL92Parser::Index_nameContext>(0);
}


size_t SQL92Parser::Index_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleIndex_section;
}

void SQL92Parser::Index_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_section(this);
}

void SQL92Parser::Index_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_section(this);
}

SQL92Parser::Index_sectionContext* SQL92Parser::index_section() {
  Index_sectionContext *_localctx = _tracker.createInstance<Index_sectionContext>(_ctx, getState());
  enterRule(_localctx, 116, SQL92Parser::RuleIndex_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    index_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_nameContext ------------------------------------------------------------------

SQL92Parser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Index_nameContext::ID() {
  return getToken(SQL92Parser::ID, 0);
}

SQL92Parser::String_literalContext* SQL92Parser::Index_nameContext::string_literal() {
  return getRuleContext<SQL92Parser::String_literalContext>(0);
}


size_t SQL92Parser::Index_nameContext::getRuleIndex() const {
  return SQL92Parser::RuleIndex_name;
}

void SQL92Parser::Index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_name(this);
}

void SQL92Parser::Index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_name(this);
}

SQL92Parser::Index_nameContext* SQL92Parser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 118, SQL92Parser::RuleIndex_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(467);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQL92Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(465);
        match(SQL92Parser::ID);
        break;
      }

      case SQL92Parser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(466);
        string_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Where_sectionContext ------------------------------------------------------------------

SQL92Parser::Where_sectionContext::Where_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQL92Parser::Where_sectionContext::WHERE() {
  return getToken(SQL92Parser::WHERE, 0);
}

SQL92Parser::ExpressionContext* SQL92Parser::Where_sectionContext::expression() {
  return getRuleContext<SQL92Parser::ExpressionContext>(0);
}


size_t SQL92Parser::Where_sectionContext::getRuleIndex() const {
  return SQL92Parser::RuleWhere_section;
}

void SQL92Parser::Where_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_section(this);
}

void SQL92Parser::Where_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQL92Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_section(this);
}

SQL92Parser::Where_sectionContext* SQL92Parser::where_section() {
  Where_sectionContext *_localctx = _tracker.createInstance<Where_sectionContext>(_ctx, getState());
  enterRule(_localctx, 120, SQL92Parser::RuleWhere_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    match(SQL92Parser::WHERE);
    setState(470);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SQL92Parser::_decisionToDFA;
atn::PredictionContextCache SQL92Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SQL92Parser::_atn;
std::vector<uint16_t> SQL92Parser::_serializedATN;

std::vector<std::string> SQL92Parser::_ruleNames = {
  "queries", "statement", "show_stmt", "use_stmt", "create_collection_stmt", 
  "drop_collection_stmt", "create_index_stmt", "drop_index_stmt", "select_stmt", 
  "select_core", "result_column_section", "from_section", "table_name", 
  "data_source", "grouping_section", "having_section", "sorting_section", 
  "sorting_item", "sorting_specification", "limit_section", "offset_section", 
  "insert_stmt", "insert_columns_section", "insert_values_section", "update_stmt", 
  "property_section", "delete_stmt", "expression", "expression_list", "expression_literal", 
  "expression_literal_value", "expression_dictionary", "dictionary_literal", 
  "expression_array", "array_literal", "expression_logic_operator", "expression_binary_operator", 
  "expression_function", "function_name", "function_value", "expression_operator", 
  "binary_operator", "logical_operator", "property_literal", "integer_literal", 
  "real_literal", "string_literal", "true_literal", "false_literal", "sync_operator", 
  "compound_operator", "condition_operator", "property", "value", "name", 
  "collection_section", "collection_name", "column_section", "index_section", 
  "index_name", "where_section"
};

std::vector<std::string> SQL92Parser::_literalNames = {
  "", "'('", "')'", "'{'", "'}'", "'['", "']'", "':'", "'*'", "'='", "'=='", 
  "'<'", "'<='", "'>'", "'>='", "'!='", "", "", "','", "';'"
};

std::vector<std::string> SQL92Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "ASTERISK", "SINGLE_EQ", "DOUBLE_EQ", 
  "OP_LT", "LE", "GT", "GE", "NOTEQ", "AND", "OR", "COMMA", "SEMICOLON", 
  "ALL", "ANCESTOR", "AS", "ASC", "ASYNC", "BY", "CREATE", "COLLECTION", 
  "CURRENT_DATE", "CURRENT_TIME", "CURRENT_TIMESTAMP", "DESC", "DELETE", 
  "DISTINCT", "DROP", "EACH", "EXCEPT", "FLATTEN", "FROM", "GROUP", "HAVING", 
  "IN", "COLLECTION_INDEX", "INSERT", "INTERSECT", "INTO", "IS", "LIMIT", 
  "NIL", "OFFSET", "OPTIONS", "ORDER", "SELECT", "SET", "SHOW", "SYNC", 
  "USE", "UNION", "UPDATE", "WHERE", "VALUE", "VALUES", "TRUE", "FALSE", 
  "WS", "ID", "NUMBER", "FLOAT", "STRING"
};

dfa::Vocabulary SQL92Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SQL92Parser::_tokenNames;

SQL92Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x46, 0x1db, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x80, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x83, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x8f, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x9c, 0xa, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xac, 
    0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0xaf, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0xb2, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb6, 0xa, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xb9, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbd, 0xa, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xc0, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc3, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xc9, 0xa, 0xc, 0xc, 0xc, 
    0xe, 0xc, 0xcc, 0xb, 0xc, 0x5, 0xc, 0xce, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd5, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xd8, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe3, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xe6, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xf0, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xf3, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0xf7, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xff, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x5, 0x17, 0x106, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x10c, 0xa, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x114, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x117, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x11f, 0xa, 0x19, 
    0x3, 0x1a, 0x5, 0x1a, 0x122, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x12a, 0xa, 0x1a, 0xc, 0x1a, 
    0xe, 0x1a, 0x12d, 0xb, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x130, 0xa, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x5, 0x1c, 0x137, 
    0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x13d, 
    0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x147, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x14a, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x7, 0x1e, 0x150, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x153, 0xb, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 
    0x1e, 0x15b, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x15e, 0xb, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 
    0x166, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x169, 0xb, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x5, 0x1e, 0x16d, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x17b, 0xa, 0x20, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x190, 
    0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x7, 0x29, 0x199, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 
    0x19c, 0xb, 0x29, 0x3, 0x29, 0x5, 0x29, 0x19f, 0xa, 0x29, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 
    0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1b9, 0xa, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1bd, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 
    0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x1cb, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x1d0, 0xa, 0x3b, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x1d6, 0xa, 0x3d, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x2, 0x2, 0x3f, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x2, 0x7, 0x4, 
    0x2, 0x16, 0x16, 0x23, 0x23, 0x4, 0x2, 0x19, 0x19, 0x21, 0x21, 0x3, 
    0x2, 0xb, 0x11, 0x3, 0x2, 0x12, 0x13, 0x4, 0x2, 0x1a, 0x1a, 0x39, 0x39, 
    0x2, 0x1db, 0x2, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x4, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8, 0x93, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x16, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd9, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x22, 0xea, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0x26, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x28, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x102, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x30, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x121, 0x3, 0x2, 0x2, 0x2, 0x34, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x136, 0x3, 0x2, 0x2, 0x2, 0x38, 0x13e, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x40, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x184, 0x3, 0x2, 0x2, 0x2, 0x46, 0x186, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x188, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1a0, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x1a8, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1ac, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1b0, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x64, 0x1b4, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1be, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1c2, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x1ca, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x76, 0x1d1, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x1d7, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x81, 0x5, 0x4, 0x3, 0x2, 0x7d, 0x7e, 0x7, 0x15, 
    0x2, 0x2, 0x7e, 0x80, 0x5, 0x4, 0x3, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x3, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x8f, 0x5, 0x6, 0x4, 0x2, 0x85, 0x8f, 
    0x5, 0x8, 0x5, 0x2, 0x86, 0x8f, 0x5, 0xa, 0x6, 0x2, 0x87, 0x8f, 0x5, 
    0xe, 0x8, 0x2, 0x88, 0x8f, 0x5, 0xc, 0x7, 0x2, 0x89, 0x8f, 0x5, 0x10, 
    0x9, 0x2, 0x8a, 0x8f, 0x5, 0x12, 0xa, 0x2, 0x8b, 0x8f, 0x5, 0x2c, 0x17, 
    0x2, 0x8c, 0x8f, 0x5, 0x32, 0x1a, 0x2, 0x8d, 0x8f, 0x5, 0x36, 0x1c, 
    0x2, 0x8e, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x91, 0x7, 0x38, 0x2, 0x2, 0x91, 0x92, 0x5, 0x70, 0x39, 
    0x2, 0x92, 0x7, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x3a, 0x2, 0x2, 
    0x94, 0x95, 0x5, 0x70, 0x39, 0x2, 0x95, 0x9, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x7, 0x1c, 0x2, 0x2, 0x97, 0x98, 0x7, 0x1d, 0x2, 0x2, 0x98, 0x9b, 
    0x5, 0x70, 0x39, 0x2, 0x99, 0x9a, 0x7, 0x34, 0x2, 0x2, 0x9a, 0x9c, 0x5, 
    0x38, 0x1d, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x24, 0x2, 
    0x2, 0x9e, 0x9f, 0x7, 0x1d, 0x2, 0x2, 0x9f, 0xa0, 0x5, 0x70, 0x39, 0x2, 
    0xa0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x1c, 0x2, 0x2, 0xa2, 
    0xa3, 0x7, 0x2c, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x76, 0x3c, 0x2, 0xa4, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x24, 0x2, 0x2, 0xa6, 0xa7, 0x7, 
    0x2c, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x76, 0x3c, 0x2, 0xa8, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xab, 0x5, 0x14, 0xb, 0x2, 0xaa, 0xac, 0x5, 0x22, 0x12, 
    0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xae, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 0x5, 0x28, 0x15, 0x2, 0xae, 
    0xad, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x2a, 0x16, 0x2, 0xb1, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xb3, 0xb5, 0x7, 0x36, 0x2, 0x2, 0xb4, 0xb6, 0x9, 0x2, 0x2, 
    0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x16, 0xc, 0x2, 0xb8, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 
    0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x18, 0xd, 0x2, 0xbb, 0xbd, 0x5, 
    0x7a, 0x3e, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x5, 0x1e, 0x10, 
    0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x5, 0x20, 0x11, 0x2, 0xc2, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xce, 0x7, 0xa, 0x2, 0x2, 0xc5, 0xca, 0x5, 
    0x74, 0x3b, 0x2, 0xc6, 0xc7, 0x7, 0x14, 0x2, 0x2, 0xc7, 0xc9, 0x5, 0x74, 
    0x3b, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xce, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x28, 0x2, 0x2, 0xd0, 0xd1, 0x5, 
    0x1a, 0xe, 0x2, 0xd1, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x14, 
    0x2, 0x2, 0xd3, 0xd5, 0x5, 0x1a, 0xe, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd8, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x1c, 0xf, 0x2, 0xda, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x72, 0x3a, 0x2, 0xdc, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x29, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x1b, 
    0x2, 0x2, 0xdf, 0xe4, 0x5, 0x38, 0x1d, 0x2, 0xe0, 0xe1, 0x7, 0x14, 0x2, 
    0x2, 0xe1, 0xe3, 0x5, 0x38, 0x1d, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x2a, 0x2, 0x2, 0xe8, 0xe9, 0x5, 
    0x38, 0x1d, 0x2, 0xe9, 0x21, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x35, 
    0x2, 0x2, 0xeb, 0xec, 0x7, 0x1b, 0x2, 0x2, 0xec, 0xf1, 0x5, 0x24, 0x13, 
    0x2, 0xed, 0xee, 0x7, 0x14, 0x2, 0x2, 0xee, 0xf0, 0x5, 0x24, 0x13, 0x2, 
    0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf6, 0x5, 
    0x6a, 0x36, 0x2, 0xf5, 0xf7, 0x5, 0x26, 0x14, 0x2, 0xf6, 0xf5, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x9, 0x3, 0x2, 0x2, 0xf9, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfe, 0x7, 0x31, 0x2, 0x2, 0xfb, 0xfc, 0x5, 0x3c, 0x1f, 0x2, 
    0xfc, 0xfd, 0x7, 0x14, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x5, 0x3c, 0x1f, 0x2, 0x101, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x33, 0x2, 0x2, 0x103, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x5, 0x64, 0x33, 0x2, 0x105, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x7, 0x2d, 0x2, 0x2, 0x108, 0x109, 
    0x7, 0x2f, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x70, 0x39, 0x2, 0x10a, 0x10c, 
    0x5, 0x2e, 0x18, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
    0x5, 0x30, 0x19, 0x2, 0x10e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
    0x7, 0x3, 0x2, 0x2, 0x110, 0x115, 0x5, 0x74, 0x3b, 0x2, 0x111, 0x112, 
    0x7, 0x14, 0x2, 0x2, 0x112, 0x114, 0x5, 0x74, 0x3b, 0x2, 0x113, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 
    0x7, 0x4, 0x2, 0x2, 0x119, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 
    0x3e, 0x2, 0x2, 0x11b, 0x11f, 0x5, 0x38, 0x1d, 0x2, 0x11c, 0x11d, 0x7, 
    0x3f, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x38, 0x1d, 0x2, 0x11e, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x122, 0x5, 0x64, 0x33, 0x2, 0x121, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x124, 0x7, 0x3c, 0x2, 0x2, 0x124, 0x125, 0x5, 0x70, 
    0x39, 0x2, 0x125, 0x126, 0x7, 0x37, 0x2, 0x2, 0x126, 0x12b, 0x5, 0x34, 
    0x1b, 0x2, 0x127, 0x128, 0x7, 0x14, 0x2, 0x2, 0x128, 0x12a, 0x5, 0x34, 
    0x1b, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 
    0x2, 0x2, 0x12e, 0x130, 0x5, 0x7a, 0x3e, 0x2, 0x12f, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x132, 0x5, 0x6a, 0x36, 0x2, 0x132, 0x133, 0x7, 0xb, 0x2, 
    0x2, 0x133, 0x134, 0x5, 0x3c, 0x1f, 0x2, 0x134, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x135, 0x137, 0x5, 0x64, 0x33, 0x2, 0x136, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x139, 0x7, 0x22, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x28, 0x2, 
    0x2, 0x13a, 0x13c, 0x5, 0x70, 0x39, 0x2, 0x13b, 0x13d, 0x5, 0x7a, 0x3e, 
    0x2, 0x13c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x37, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x5, 0x3a, 0x1e, 
    0x2, 0x13f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x140, 0x16d, 0x5, 0x3c, 0x1f, 
    0x2, 0x141, 0x16d, 0x5, 0x4c, 0x27, 0x2, 0x142, 0x148, 0x5, 0x4a, 0x26, 
    0x2, 0x143, 0x144, 0x5, 0x48, 0x25, 0x2, 0x144, 0x145, 0x5, 0x4a, 0x26, 
    0x2, 0x145, 0x147, 0x3, 0x2, 0x2, 0x2, 0x146, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x147, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 
    0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x7, 0x3, 0x2, 
    0x2, 0x14c, 0x151, 0x5, 0x44, 0x23, 0x2, 0x14d, 0x14e, 0x7, 0x14, 0x2, 
    0x2, 0x14e, 0x150, 0x5, 0x44, 0x23, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x153, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x154, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x4, 0x2, 
    0x2, 0x155, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x5, 0x2, 
    0x2, 0x157, 0x15c, 0x5, 0x40, 0x21, 0x2, 0x158, 0x159, 0x7, 0x14, 0x2, 
    0x2, 0x159, 0x15b, 0x5, 0x40, 0x21, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x15b, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x6, 0x2, 
    0x2, 0x160, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x7, 0x2, 
    0x2, 0x162, 0x167, 0x5, 0x44, 0x23, 0x2, 0x163, 0x164, 0x7, 0x14, 0x2, 
    0x2, 0x164, 0x166, 0x5, 0x44, 0x23, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x169, 0x3, 0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x8, 0x2, 
    0x2, 0x16b, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x140, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x141, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x142, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x16c, 0x161, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x5, 0x3e, 0x20, 0x2, 0x16f, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x17b, 0x5, 0x58, 0x2d, 0x2, 0x171, 0x17b, 0x5, 0x5a, 0x2e, 0x2, 
    0x172, 0x17b, 0x5, 0x5c, 0x2f, 0x2, 0x173, 0x17b, 0x5, 0x5e, 0x30, 0x2, 
    0x174, 0x17b, 0x5, 0x60, 0x31, 0x2, 0x175, 0x17b, 0x5, 0x62, 0x32, 0x2, 
    0x176, 0x17b, 0x7, 0x32, 0x2, 0x2, 0x177, 0x17b, 0x7, 0x1f, 0x2, 0x2, 
    0x178, 0x17b, 0x7, 0x1e, 0x2, 0x2, 0x179, 0x17b, 0x7, 0x20, 0x2, 0x2, 
    0x17a, 0x170, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x172, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x173, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x174, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 
    0x17b, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x6e, 0x38, 0x2, 
    0x17d, 0x17e, 0x7, 0x9, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0x3c, 0x1f, 0x2, 
    0x17f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x5, 0x6e, 0x38, 0x2, 
    0x181, 0x182, 0x7, 0x9, 0x2, 0x2, 0x182, 0x183, 0x5, 0x3c, 0x1f, 0x2, 
    0x183, 0x43, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x5, 0x3c, 0x1f, 0x2, 
    0x185, 0x45, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x5, 0x3c, 0x1f, 0x2, 
    0x187, 0x47, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x5, 0x56, 0x2c, 0x2, 
    0x189, 0x49, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x52, 0x2a, 0x2, 
    0x18b, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x43, 0x2, 0x2, 
    0x18d, 0x18f, 0x7, 0x3, 0x2, 0x2, 0x18e, 0x190, 0x5, 0x50, 0x29, 0x2, 
    0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 
    0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x4, 0x2, 0x2, 
    0x192, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x7, 0x43, 0x2, 0x2, 
    0x194, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x195, 0x19a, 0x5, 0x38, 0x1d, 0x2, 
    0x196, 0x197, 0x7, 0x14, 0x2, 0x2, 0x197, 0x199, 0x5, 0x38, 0x1d, 0x2, 
    0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x19d, 0x19f, 0x7, 0xa, 0x2, 0x2, 0x19e, 0x195, 0x3, 0x2, 0x2, 0x2, 
    0x19e, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
    0x1a1, 0x5, 0x3c, 0x1f, 0x2, 0x1a1, 0x1a2, 0x5, 0x54, 0x2b, 0x2, 0x1a2, 
    0x1a3, 0x5, 0x3c, 0x1f, 0x2, 0x1a3, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
    0x1a5, 0x9, 0x4, 0x2, 0x2, 0x1a5, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 
    0x9, 0x5, 0x2, 0x2, 0x1a7, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 
    0x43, 0x2, 0x2, 0x1a9, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 
    0x44, 0x2, 0x2, 0x1ab, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 
    0x45, 0x2, 0x2, 0x1ad, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 
    0x46, 0x2, 0x2, 0x1af, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 
    0x40, 0x2, 0x2, 0x1b1, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 
    0x41, 0x2, 0x2, 0x1b3, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x9, 
    0x6, 0x2, 0x2, 0x1b5, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b8, 0x7, 0x3b, 
    0x2, 0x2, 0x1b7, 0x1b9, 0x7, 0x16, 0x2, 0x2, 0x1b8, 0x1b7, 0x3, 0x2, 
    0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1bd, 0x3, 0x2, 
    0x2, 0x2, 0x1ba, 0x1bd, 0x7, 0x2e, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 0x26, 
    0x2, 0x2, 0x1bc, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 
    0x2, 0x2, 0x1bc, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x1bf, 0x9, 0x4, 0x2, 0x2, 0x1bf, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x7, 0x43, 0x2, 0x2, 0x1c1, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x43, 0x2, 0x2, 0x1c3, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x1c4, 0x1c5, 0x7, 0x43, 0x2, 0x2, 0x1c5, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x1c6, 0x1c7, 0x5, 0x72, 0x3a, 0x2, 0x1c7, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x1c8, 0x1cb, 0x7, 0x43, 0x2, 0x2, 0x1c9, 0x1cb, 0x5, 0x5e, 0x30, 0x2, 
    0x1ca, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
    0x1cb, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 0x5, 0x38, 0x1d, 0x2, 
    0x1cd, 0x1ce, 0x7, 0x18, 0x2, 0x2, 0x1ce, 0x1d0, 0x5, 0x6e, 0x38, 0x2, 
    0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1d0, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x78, 0x3d, 0x2, 
    0x1d2, 0x77, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d6, 0x7, 0x43, 0x2, 0x2, 
    0x1d4, 0x1d6, 0x5, 0x5e, 0x30, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
    0x1d8, 0x7, 0x3d, 0x2, 0x2, 0x1d8, 0x1d9, 0x5, 0x38, 0x1d, 0x2, 0x1d9, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x81, 0x8e, 0x9b, 0xab, 0xae, 0xb1, 
    0xb5, 0xb8, 0xbc, 0xbf, 0xc2, 0xca, 0xcd, 0xd6, 0xe4, 0xf1, 0xf6, 0xfe, 
    0x105, 0x10b, 0x115, 0x11e, 0x121, 0x12b, 0x12f, 0x136, 0x13c, 0x148, 
    0x151, 0x15c, 0x167, 0x16c, 0x17a, 0x18f, 0x19a, 0x19e, 0x1b8, 0x1bc, 
    0x1ca, 0x1cf, 0x1d5, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SQL92Parser::Initializer SQL92Parser::_init;

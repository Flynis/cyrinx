add_clang_library(typo
  TypoContext.cpp
  TypoVisitor.cpp
  TypoAction.cpp

  DEPENDS
  searcher
  text

  LINK_LIBS
  clangAST
  clangBasic
  clangDriver
  clangFrontend
  clangRewriteFrontend
  clangSerialization
  clangStaticAnalyzerFrontend
  )
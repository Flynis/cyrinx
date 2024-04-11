add_clang_library(typo
  TypoContext.cpp
  TypoVisitor.cpp
  TypoAction.cpp

  LINK_LIBS
  searcher
  text
  clangAST
  clangBasic
  clangDriver
  clangFrontend
  clangRewriteFrontend
  clangSerialization
  clangStaticAnalyzerFrontend
  )
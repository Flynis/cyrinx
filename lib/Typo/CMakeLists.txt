add_clang_library(typo
  TypoVisitor.cpp
  TypoAction.cpp
  )

target_include_directories(typo PRIVATE .)

clang_target_link_libraries(typo
  PRIVATE
  clangAST
  clangBasic
  clangDriver
  clangFrontend
  clangRewriteFrontend
  clangSerialization
  clangStaticAnalyzerFrontend
  )
add_clang_library(searcher
  Dictionary.cpp
  BitapSearcher.cpp
  )

target_include_directories(searcher PRIVATE .)
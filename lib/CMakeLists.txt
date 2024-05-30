set( LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  Option
  Support
  )

add_subdirectory(Searcher)
add_subdirectory(Text)
add_subdirectory(Typo)

add_clang_tool(cyrinx
  OptionParser.cpp
  cyrinx.cpp
  )

clang_target_link_libraries(cyrinx
  PRIVATE
  typo
  clangFrontend
  clangTooling
  clangToolingSyntax
  )
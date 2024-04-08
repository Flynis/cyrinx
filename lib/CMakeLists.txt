set( LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  Option
  Support
  )

add_subdirectory(Searcher)
add_subdirectory(Typo)

add_clang_tool(cyrinx
  cyrinx.cpp
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

clang_target_link_libraries(cyrinx
  PRIVATE
  searcher
  typo

  clangFrontend
  clangTooling
  clangToolingSyntax
  )
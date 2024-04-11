#ifndef CYRINX_OPTION_PARSER_H
#define CYRINX_OPTION_PARSER_H
 
#include "clang/Tooling/CompilationDatabase.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Error.h"
 
namespace cyrinx {

class OptionParser {

std::unique_ptr<clang::tooling::CompilationDatabase> compilations;

std::vector<std::string> sourcePathList;

public:
  static llvm::Expected<OptionParser>
  create(int &argc, const char **argv, llvm::cl::OptionCategory &category);
 
  clang::tooling::CompilationDatabase &getCompilations() { return *compilations; }
 
  const std::vector<std::string> &getSourcePathList() const {
    return sourcePathList;
  }

  static const char *const HelpMessage;
 
private:
  OptionParser() = default;
 
  llvm::Error init(int &argc, const char **argv, llvm::cl::OptionCategory &category);
};
 
}  // namespace cyrinx
 
#endif // CYRINX_OPTION_PARSER_H
#include "cyrinx/OptionParser.h"

#include "llvm/Support/CommandLine.h"

using namespace clang::tooling;
using namespace cyrinx;
using namespace llvm;
using namespace std;

const char *const OptionParser::HelpMessage =
    "\n"
    "<source0> ... specify the paths of source files.\n"
    "\tFor example, to run cyrinx on all files in a subtree of the\n"
    "\tsource tree, use:\n"
    "\n"
    "\t  find path/in/subtree -name '*.cpp'|xargs cyrinx\n"
    "\n"
    "\n";
 
Error OptionParser::init(int &argc, const char **argv, cl::OptionCategory &category) {
  static cl::list<std::string> sourcePaths(
      cl::Positional, cl::desc("<source0> [... <sourceN>]"),
      cl::cat(category), cl::sub(cl::SubCommand::getAll()));
 
  cl::ResetAllOptionOccurrences();
  cl::HideUnrelatedOptions(category);
 
  string errorMessage;
  raw_string_ostream os(errorMessage);
  // Stop initializing if command-line option parsing failed.
  if (!cl::ParseCommandLineOptions(argc, argv, "", &os)) {
    os.flush();
    return make_error<StringError>(errorMessage, inconvertibleErrorCode());
  }

  sourcePathList = sourcePaths;
  compilations.reset(
          new FixedCompilationDatabase(".", vector<string>()));

  return Error::success();
}
 
Expected<OptionParser> OptionParser::create(
    int &argc, const char **argv, cl::OptionCategory &category) {
  OptionParser parser;
  Error err = parser.init(argc, argv, category);
  if (err) {
    return std::move(err);
  }
  return std::move(parser);
}
 
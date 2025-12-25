#include <iostream>

#include <unistd.h>

#include <CLI/CLI.hpp>

#include <bad/bad.hpp>

#include "cmd/attach.hpp"
#include "cmd/launch.hpp"

namespace {

using namespace bad::cli;

void setup(CLI::App &app) {
  cmd::attach::setup(app);
  cmd::launch::setup(app);
}

} // namespace

int main(int argc, const char **argv) {
  std::cout << bad::get_message() << std::endl;

  CLI::App app{"BAD debugger."};
  setup(app);

  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    return app.exit(e);
  }
  return 0;
}

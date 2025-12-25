#ifndef BAD_CLI_COMMANDS_ATTACH_HPP
#define BAD_CLI_COMMANDS_ATTACH_HPP

#include <CLI/CLI.hpp>

namespace bad::cli::cmd::attach {

struct Config {
  int pid;
};

void run(const Config &config);
void setup(CLI::App &app);

} // namespace bad::cli::cmd::attach

#endif //  BAD_CLI_COMMANDS_ATTACH_HPP

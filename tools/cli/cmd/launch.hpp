#ifndef BAD_CLI_COMMANDS_LAUNCH_HPP
#define BAD_CLI_COMMANDS_LAUNCH_HPP

#include <filesystem>

#include <CLI/CLI.hpp>

namespace bad::cli::cmd::launch {

struct Config {
  std::filesystem::path program_path;
};

void run(const Config &config);
void setup(CLI::App &app);

} // namespace bad::cli::cmd::launch

#endif //  BAD_CLI_COMMANDS_LAUNCH_HPP

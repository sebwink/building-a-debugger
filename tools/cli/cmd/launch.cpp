#include "launch.hpp"

namespace bad::cli::cmd::launch {

void run(const Config &config) {
  std::cout << "LAUNCH" << std::endl;
  std::cout << "PROGRAM: " << config.program_path << std::endl;
}

void setup(CLI::App &app) {
  auto config = std::make_shared<Config>();
  auto cmd = app.add_subcommand("launch", "Launch a program.");
  cmd->add_option("program_path", config->program_path,
                  "Path of program to launch.")
      ->required();
  cmd->callback([config]() { run(*config); });
}

} // namespace bad::cli::cmd::launch

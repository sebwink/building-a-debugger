#include "attach.hpp"

namespace bad::cli::cmd::attach {

void run(const Config &config) {
  std::cout << "ATTACH" << std::endl;
  std::cout << "PID: " << config.pid << std::endl;
}

void setup(CLI::App &app) {
  auto config = std::make_shared<Config>();
  auto cmd = app.add_subcommand("attach", "Attach to a running process.");
  cmd->add_option("-p,--pid", config->pid, "Identifier of running process.")
      ->required();
  cmd->callback([config]() { run(*config); });
}

} // namespace bad::cli::cmd::attach

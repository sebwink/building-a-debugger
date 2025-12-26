#include "attach.hpp"

#include <cstdio>

#include <sys/ptrace.h>
#include <sys/wait.h>

namespace bad::cli::cmd::attach {

void run(const Config &config) {
  std::cout << "ATTACH" << std::endl;
  std::cout << "PID: " << config.pid << std::endl;
  if (ptrace(PTRACE_ATTACH, config.pid, /*addr=*/nullptr, /*data=*/nullptr) <
      0) {
    std::perror(&"Could not attach to process with PID "[config.pid]);
  }

  int wait_status;
  int options = 0;
  if (waitpid(config.pid, &wait_status, options) < 0) {
    std::perror("waitpid failed");
  }
}

void setup(CLI::App &app) {
  auto config = std::make_shared<Config>();
  auto cmd = app.add_subcommand("attach", "Attach to a running process.");
  cmd->add_option("-p,--pid", config->pid, "Identifier of running process.")
      ->required();
  cmd->callback([config]() { run(*config); });
}

} // namespace bad::cli::cmd::attach

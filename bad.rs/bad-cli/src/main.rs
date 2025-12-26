use clap::Parser;
use libbad::get_message;

mod cli;
mod cmd;

fn main() -> anyhow::Result<()> {
    // Print welcome message (matches C++ main.cpp line 24)
    println!("{}", get_message());

    // Parse CLI arguments
    let cli = cli::Cli::parse();

    // Dispatch to appropriate command
    match cli.command {
        cli::Command::Attach { pid } => {
            let config = cmd::attach::Config { pid };
            cmd::attach::run(&config)?;
        }
        cli::Command::Launch { program_path } => {
            let config = cmd::launch::Config { program_path };
            cmd::launch::run(&config)?;
        }
    }

    Ok(())
}

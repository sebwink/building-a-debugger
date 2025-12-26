use clap::{Parser, Subcommand};
use std::path::PathBuf;

/// BAD debugger.
#[derive(Parser, Debug)]
#[command(name = "bad")]
#[command(about = "BAD debugger.", long_about = None)]
pub struct Cli {
    #[command(subcommand)]
    pub command: Command,
}

#[derive(Subcommand, Debug)]
pub enum Command {
    /// Attach to a running process.
    Attach {
        /// Identifier of running process.
        #[arg(short = 'p', long = "pid", required = true)]
        pid: i32,
    },
    /// Launch a program.
    Launch {
        /// Path of program to launch.
        #[arg(required = true)]
        program_path: PathBuf,
    },
}

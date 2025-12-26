use std::path::PathBuf;

pub struct Config {
    pub program_path: PathBuf,
}

pub fn run(config: &Config) -> anyhow::Result<()> {
    println!("LAUNCH");
    println!("PROGRAM: {}", config.program_path.display());
    Ok(())
}

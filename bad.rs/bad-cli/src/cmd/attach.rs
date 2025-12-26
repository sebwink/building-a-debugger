pub struct Config {
    pub pid: i32,
}

pub fn run(config: &Config) -> anyhow::Result<()> {
    println!("ATTACH");
    println!("PID: {}", config.pid);
    Ok(())
}

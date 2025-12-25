# bad.rs

Rust port of the libbad C++ library.

## Building a Debugger

This is a minimal library and CLI tool, ported from the original C++ implementation (v0.0.42).

### Structure

- `libbad/`: Core library crate
- `bad-cli/`: Command-line interface binary

### Building

```bash
cargo build --release
```

### Running

```bash
cargo run --bin bad
# Or after building:
./target/release/bad
```

### Testing

```bash
cargo test --workspace
```

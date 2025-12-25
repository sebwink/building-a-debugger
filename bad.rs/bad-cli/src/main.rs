//! BAD command-line interface
//!
//! Simple CLI that prints the BAD. message.

use libbad::get_message;

fn main() {
    println!("{}", get_message());
}

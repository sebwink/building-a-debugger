//! libbad - Building a debugger
//!
//! Rust port of the C++ libbad library.

mod messages;

/// Returns the BAD. message.
pub fn get_message() -> &'static str {
    messages::get_message()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_message() {
        assert_eq!(get_message(), "BAD.");
    }
}

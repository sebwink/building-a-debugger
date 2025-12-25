//! Internal messages module

/// Returns the BAD. message.
///
/// Internal implementation. External users should call the public
/// `get_message()` function from the crate root.
pub(crate) fn get_message() -> &'static str {
    "BAD."
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_messages_get_message() {
        assert_eq!(get_message(), "BAD.");
    }
}

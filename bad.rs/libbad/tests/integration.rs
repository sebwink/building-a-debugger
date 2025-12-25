//! Integration tests mirroring the C++ Catch2 tests

use libbad::get_message;

#[test]
fn check_message() {
    let expected_message = "BAD.";
    let message = get_message();
    assert_eq!(message, expected_message);
}

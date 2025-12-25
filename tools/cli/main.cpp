#include <iostream>

#include <dbg/dbg.hpp>

int main() {
  std::cout << dbg::get_message() << std::endl;
  return 0;
}

#include "messages.hpp"
#include <dbg/dbg.hpp>

namespace dbg {

std::string get_message() { return dbg::messages::get_message(); }

} // namespace dbg

#include <pybind11/pybind11.h>
#include <uuid.hpp>

#include <string>

namespace py = pybind11;


std::string encode_base58(std::string input) {
  auto id = UUID::parse(input);
  return UUID::base58_encode(id, UUID::Endianness::Big);
}

std::string decode_base58(std::string id) {
  return UUID::serialize(UUID::base58_decode(id, UUID::Endianness::Big));
}

std::string generate() {
  return UUID::generate_string();
}

std::string generate_base58() {
  return UUID::generate_base58();
}


PYBIND11_MODULE(guid, m) {
    m.doc() = "UUID utility";

    m.def("encode_base58",   &encode_base58,   "base58 encode a UUID");
    m.def("decode_base58",   &decode_base58,   "base58 decode a UUID");
    m.def("generate",        &generate,        "generate a UUID");
    m.def("generate_base58", &generate_base58, "generate a base58-encoded UUID");    
}

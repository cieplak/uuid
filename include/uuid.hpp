#pragma  once

#include <boost/uuid/uuid.hpp>
#include <string>

namespace UUID {

    typedef boost::uuids::uuid uuid;

    enum Endianness {
        Big, Little
    };

    uuid parse(std::string sid);

    std::string serialize(uuid id);

    uuid base58_decode(std::string encoded, Endianness endianness);

    std::string base58_encode(uuid id, Endianness endianness);

    uuid generate();

    std::string generate_string();

    std::string generate_base58();

}

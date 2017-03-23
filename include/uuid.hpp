#include <boost/uuid/uuid.hpp>
#include <string>

namespace UUID {

    typedef boost::uuids::uuid uuid;

    uuid parse(std::string sid);

    std::string serialize(uuid id);

    uuid base58_decode(std::string encoded);

    std::string base58_encode(uuid id);

    uuid generate();

    std::string generate_string();

    std::string generate_base58();

}

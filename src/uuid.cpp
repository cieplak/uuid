#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "uuid.hpp"

namespace UUID {

    using namespace std;
    using namespace boost::uuids;
    using namespace boost::multiprecision;

    const char base58_alphabet[59] = "123456789abcdefghijkmnopqrstuvwxyzABCDEFGHJKLMNPQRSTUVWXYZ";

    uint32_t char_index(char c)
    {
        const char* match = std::find(begin(base58_alphabet), end(base58_alphabet), c);
        uint32_t i = (match - base58_alphabet);
        return i;
    }

    array<unsigned char, 16> to_bytes(uuid id)
    {
        array<unsigned char, 16> uuid_data { 0 };
        for (uint8_t i = 0; i < 16; i++)
            uuid_data[i] = id.data[i];
        return uuid_data;
    }

    uint128_t bytes_to_uint128(array<unsigned char, 16> bytes) {
        uint128_t id      = 0;
        uint128_t operand = 0;
        for (unsigned short i = 0; i < 16; i++) {
           operand = bytes[i];
           operand = operand << (8 * i);
           id += operand;
        }
        return id;
    }

    uint128_t to_uint128(uuid id) {
        array<unsigned char, 16> bytes { to_bytes(id) };
        uint128_t iid = bytes_to_uint128(bytes);
        return iid;
    }

    uuid base58_decode(string encoded)
    {
        uint128_t iid;
        uint128_t multiplier;
        uint128_t operand;
        uint128_t base = 58;
        uint128_t index;

        int length = encoded.length();
        for (uint8_t i = 0; i < length; i++) {
            multiplier = pow(base, i);
            operand = char_index(encoded[i]);
            operand *= multiplier;
            iid += operand;
        }
        uint8_t data[16];
        for (uint8_t i = 0; i < 16; i++)
           data[i] = static_cast<uint8_t>( (iid >> (8 * i)) & 255 );
        uuid id;
        memcpy(id.data, data, 16);
        return id;
    }

    string base58_encode(uuid id)
    {
        vector<char> chars;
        uint128_t     dividend = to_uint128(id);
        uint128_t     modulus;
        uint32_t      index;
        char          c;

        while (dividend > 58) {
            modulus = dividend % 58;
            index = static_cast<uint32_t>(modulus);
            c = base58_alphabet[index];
            chars.push_back(c);
            dividend /= 58;
        }
        if (dividend > 0) {
            index = static_cast<uint32_t>(dividend);
            c = base58_alphabet[index];
            chars.push_back(c);
        }
        string encoded = string(chars.begin(), chars.end());
        return encoded;
    }

    uuid parse(string sid) {
        return boost::lexical_cast<uuid>(sid);
    }

    string serialize(uuid id) {
        return boost::lexical_cast<string>(id);
    }

    uuid generate() {
        return boost::uuids::random_generator()();
    }

    string generate_string() {
        return serialize(generate());
    }

    string generate_base58() {
        return base58_encode(generate());
    }
}

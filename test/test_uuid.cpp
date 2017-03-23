#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "uuid.hpp"

#include <string>

using namespace std;

TEST_CASE( "Test Base58 UUID Encoding and Decoding ") {

    UUID::uuid  id   = UUID::generate();
    string      sid  = UUID::base58_encode(id);
    UUID::uuid  id2  = UUID::base58_decode(sid);
    string      sid2 = UUID::base58_encode(id2);

    REQUIRE(  id == id2  );
    REQUIRE( sid == sid2 );

}

TEST_CASE(" Test Generate UUID String ") {

    string     sid     = UUID::generate_string();
    UUID::uuid id      = UUID::parse(sid);
    string     encoded = UUID::base58_encode(id);
    UUID::uuid decoded = UUID::base58_decode(encoded);
    REQUIRE( id == decoded );

}

TEST_CASE(" Test Parse ") {

    UUID::uuid  id = UUID::parse("3978cc9e-caaf-4db9-b67f-e3cc354d4e66");
    string     sid = UUID::base58_encode(id);

    REQUIRE( sid == "HJPLHqb96NXab4vASYXHCd");

}

TEST_CASE(" Test Parse 2 ") {

    UUID::uuid  id = UUID::parse("74e5ed3a-9714-4d4a-b080-f84b204856b0");
    string     sid = UUID::base58_encode(id);

    REQUIRE( sid == "Jn1ct2N3CM5dXhAG9oAWLn");

}

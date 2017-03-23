# uuid

Command line tool and C++ library for working with UUIDs.

## Command Line Usage

```

Usage:

   ./bin/uuid [-h] [base58] [encode <UUID>] [decode <BASE58>

Examples:

   # Output usage information
   ./bin/uuid -h

   # Generate a UUID
   ./bin/uuid

   # Generate a base58-encoded UUID
   ./bin/uuid base58
   ./bin/uuid b58

   # Convert a UUID to a base58-encoded UUID
   ./bin/uuid encode 42cc29d0-4f99-4d4f-841f-af1052a0678f

   # Convert a base58-encoded UUID to a UUID
   ./bin/uuid decode 6yMBfeG7aghLQAzzX1JgZk

```

## C++ Library Interface

```c++

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

```

## Building and Testing

Built and tested on FreeBSD with Clang, Boost and BSD Make.

```
make tests
make
```

#include "uuid.hpp"

#include <boost/algorithm/string/join.hpp>

#include <iostream>
#include <string>
#include <vector>

void usage(char* cmd) {
    fprintf(stderr,
	    "\nUsage:\n\n"
	    "   %s [-h] [base58] [encode <UUID>] [decode <BASE58>\n\n"
	    "Examples:\n\n"
	    "   # Output usage information\n"
	    "   %s -h\n\n"
	    "   # Generate a UUID\n"
	    "   %s \n\n"
	    "   # Generate a base58-encoded UUID\n"
	    "   %s base58\n"
	    "   %s b58\n\n"
	    "   # Convert a UUID to a base58-encoded UUID\n"
	    "   %s encode 42cc29d0-4f99-4d4f-841f-af1052a0678f\n\n"
	    "   # Convert a base58-encoded UUID to a UUID\n"
	    "   %s decode 6yMBfeG7aghLQAzzX1JgZk\n\n",
	    cmd, cmd, cmd, cmd, cmd, cmd, cmd);

    exit(1);
}

int main(int argc, char** argv) {

  // No args
  if (argc == 1)
  {
    std::cout << UUID::generate_string() << std::endl;
  }

  // One argument
  else if (argc == 2)
  {
    auto command = argv[1];

    if (strcmp(command, "-h") == 0)
      usage(argv[0]);

    else if (strcmp(command, "base58") == 0 || strcmp(command, "b58") == 0)
      std::cout << UUID::generate_base58() << std::endl;

    else
      std::cout << "Unknown command: " << command << std::endl;
  }

  // Multiple arguments
  else {
    std::vector<std::string> args(argv + 2, argv + argc);
    auto command  = argv[1];
    auto argument = boost::algorithm::join(args, " ");

    if (strcmp(command, "encode") == 0)
    {
      auto id = UUID::parse(argument);
      std::cout << UUID::base58_encode(id) << std::endl;
    }
    else if (strcmp(command, "decode") == 0)
    {
      auto id = UUID::base58_decode(argument);
      std::cout << UUID::base58_encode(id) << std::endl;
    }
    else {
      std::cout << "Unknown command: " << command  << std::endl;
      std::cout << "Argument was: "    << argument << std::endl;
    }
  }
  return 0;
}

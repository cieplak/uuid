INCLUDES = -I /usr/local/include -I include
DOWNLOAD = fetch

default: cli

all: tests cli

cli:
	c++ -std=c++1z $(INCLUDES) src/uuid.cpp src/cli.cpp -o bin/uuid

cli-debug:
	c++ -g -std=c++1z $(INCLUDES) src/uuid.cpp src/cli.cpp -o bin/uuid

download_test_deps:
	cd test
	$(DOWNLOAD) https://github.com/philsquared/Catch/releases/download/v1.7.0/catch.hpp

tests: download_test_deps
	c++ -std=c++1z -I . $(INCLUDES) src/uuid.cpp test/test_uuid.cpp -o bin/tests
	./bin/tests

clean:
	rm bin/uuid
	rm bin/tests
	rm test/catch.hpp

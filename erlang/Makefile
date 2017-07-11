INCLUDES = -I /usr/local/include -I /usr/local/lib/erlang/usr/include

default: uuid_nif

uuid_nif:
	c++ -std=c++1z $(INCLUDES) uuid.cpp uuid_nif.cpp -fpic -shared -o ../priv/uuid.so

INCLUDES = -I /usr/local/include -I ../include -I pybind/include
DOWNLOAD = fetch

default: py3

py3:
	c++ -fPIC -O3 -shared -std=c++11 $(INCLUDES) `python3-config --cflags --ldflags` guid.cpp -o guid.so

py2:
	c++ -fPIC -O3 -shared -std=c++11 $(INCLUDES) `python2-config --cflags --ldflags` guid.cpp -o guid.so

download_pybind:
	git clone --depth 1 https://github.com/pybind/pybind11.git

clean:
	rm guid.so

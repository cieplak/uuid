from __future__ import print_function
import uuid
import guid


def test():
    id = uuid.uuid4()
    assert(str(id) == guid.decode_base58(guid.encode_base58(str(id))))
    print('tests pass')


if __name__ == '__main__':
    test()

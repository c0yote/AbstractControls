# Dependencies

The project uses two header only testing libraries, and it's easiest to simply `git subtree` them into a `dep/` directory.

## Setting up these dependencies:

    git subtree add --prefix dep/FakeIt https://github.com/eranpeer/FakeIt.git master --squash
    git subtree add --prefix dep/tpunitpp https://github.com/tpounds/tpunitpp.git master --squash
 
## Updating these dependencies:

    git subtree pull --prefix dep/FakeIt https://github.com/eranpeer/FakeIt.git master --squash
    git subtree pull --prefix dep/tpunitpp https://github.com/tpounds/tpunitpp.git master --squash

## Alteration

`Line 29` of `tpunit++.hpp` breaks when combined with `cstdio` which `FakeIt` uses.  This is a [reported issue](https://github.com/tpounds/tpunitpp/issues/4).

Hack around is to comment out the following:

    extern "C" int printf(const char*, ...);

and instead use:

    `#include <cstdio>`.
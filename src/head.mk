VERSION = -std=c++11
# NDEBUG = -DNDEBUG
CXX = g++
INCLUDE_DIR = -I/home/voodoo/github/Pyhttpd/src
CXXFLAGS = -Wall -Wextra -Werror -fexceptions \
		${VERSION} ${INCLUDE_DIR}
ARFLAGS = rcs

PHONY += all test clean

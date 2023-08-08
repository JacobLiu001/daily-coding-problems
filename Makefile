BUILD_DIR := ./build/
SRC_DIR := ./cpp/
CXXFLAGS = -std=c++23 -pedantic -Wall -Wextra -Wno-sign-compare

objects := $(shell find ${SRC_DIR} -type f -iname '*.cpp' | sed 's/.cpp//g')

all: $(objects)

$(objects): %: ${SRC_DIR}%.cpp
	$(CXX) $(CXXFLAGS) -o ${BUILD_DIR}$@ $<

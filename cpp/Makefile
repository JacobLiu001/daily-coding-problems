objects := $(shell find . -type f -iname '*.cpp' | sed 's/.cpp//g')

all: $(objects)

$(objects): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

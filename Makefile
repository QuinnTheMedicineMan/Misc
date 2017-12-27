CXX=g++ -O2 -std=c++11

default:: fizzbuzz

%: %.cc
	$(CXX) $< -o $@

clean:
	rm ./fizzbuzz

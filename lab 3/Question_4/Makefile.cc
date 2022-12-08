CXX := g++ -g 
q4: main.o funcs.o
	$(CXX) main.o funcs.o -o q4
main.o: main.cc
	$(CXX) -c $<
funcs.o: funcs.cc
	$(CXX) -c $<
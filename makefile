GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAM = supermercado

$(PROGRAM): cliente.o estabelecimento.o fornecedor.o produto.o main.o menu.o
	@echo "===================== COMPILANDO ====================="
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) cliente.o estabelecimento.o fornecedor.o produto.o main.o menu.o

cliente.o: src/cliente.cpp include/cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp

estabelecimento.o: src/estabelecimento.cpp include/estabelecimento.hpp
	$(GCC) $(GCC_FLAGS) -c src/estabelecimento.cpp

fornecedor.o: src/fornecedor.cpp include/fornecedor.hpp
	$(GCC) $(GCC_FLAGS) -c src/fornecedor.cpp

produto.o: src/produto.cpp include/produto.hpp
	$(GCC) $(GCC_FLAGS) -c src/produto.cpp

main.o: src/main.cpp include/menu.hpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

menu.o: src/menu.cpp include/estabelecimento.hpp include/cliente.hpp include/fornecedor.hpp
	$(GCC) $(GCC_FLAGS) -c src/menu.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)
	rm -f *.txt
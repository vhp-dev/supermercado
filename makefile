GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAM = supermercado

$(PROGRAM): cliente.o estabelecimento.o fornecedor.o produto.o main.o menu.o supermercado.o restaurante.o
	@echo "===================== COMPILANDO ====================="
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) cliente.o estabelecimento.o fornecedor.o produto.o main.o menu.o supermercado.o restaurante.o

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

menu.o: src/menu.cpp include/menu.hpp
	$(GCC) $(GCC_FLAGS) -c src/menu.cpp

supermercado.o: src/supermercado.cpp include/supermercado.hpp
	$(GCC) $(GCC_FLAGS) -c src/supermercado.cpp

restaurante.o: src/restaurante.cpp include/restaurante.hpp
	$(GCC) $(GCC_FLAGS) -c src/restaurante.cpp

clean:
	rm -f *.o
	rm $(PROGRAM)
	rm -f *.txt
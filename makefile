all:
	@echo "Compilando..."
	@g++ -Iheader src/*.cpp soil/*.c -o berzerk.bin -lglut -lGL -lGLU -w

execute: all
	@echo "Executando..."
	@./berzerk.bin

clean:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f

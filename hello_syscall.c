#include <unistd.h>   // para write e _exit

int main() {
    write(1, "Hello World!\n", 13);  // escreve na saída padrão
    _exit(0);                        // encerra o programa
}

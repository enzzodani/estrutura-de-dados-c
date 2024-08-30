#!/bin/bash

# Defina o número de pastas a serem criadas
NUM_PASTAS=10

# Loop para criar pastas e adicionar o main.c em cada uma
for i in $(seq 1 $NUM_PASTAS)
do
    # Nome da pasta no estilo Q1, Q2, etc.
    pasta="Q$i"
    
    # Crie a pasta
    mkdir "$pasta"
    
    # Crie o arquivo main.c dentro da pasta
    cat <<EOL > "$pasta/main.c"
#include <stdio.h>

int main() {

    return 0;
}
EOL
done

echo "Pastas e arquivos criados com sucesso!"


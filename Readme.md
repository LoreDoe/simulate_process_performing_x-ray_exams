# Hospital Simulation

O Hospital Simulation é um programa em C que simula o funcionamento de um hospital ao longo do tempo. O sistema representa a chegada de pacientes, a realização de exames de raio-X e a geração de relatórios médicos.

## Requisitos

- Um ambiente de desenvolvimento C (como GCC).
- Sistema operacional Unix/Linux (o código pode ser adaptado para Windows, se necessário).
- Poderá também ser utilizado um ambiente online como o Replit.

## Passo-a-Passo para Executar o Programa

Siga as etapas para executar o programa:

1. **Compilar o programa:**

   Abra um terminal no diretório onde os arquivos `hospital.c`, `hospital.h` e `main.c` estão localizados. Use o `Makefile` fornecido para compilar o programa. Basta executar o comando `make`:

   ```bash
   make
Isso compilará o programa e gerará um executável chamado hospital_simulation.

Executar o programa:

Após a compilação, você pode executar o programa usando o seguinte comando:

bash
Copy code
./hospital_simulation
Interagir com o programa:

O programa irá simular o funcionamento do hospital, exibindo métricas a cada 10 unidades de tempo. Você pode ajustar a velocidade de execução no código, alterando o valor do sleep(1) no final do arquivo hospital.c.

O programa simula a chegada de pacientes, a realização de exames de raio-X por radiologistas e a geração de relatórios com base nos resultados dos exames.

Quando você terminar de usar o programa, pressione Ctrl + C no terminal para encerrar a execução.

Limpar os arquivos temporários:

Se desejar limpar os arquivos temporários e o executável, execute o seguinte comando:

bash
Copy code
make clean
Isso removerá os arquivos temporários e o executável.

Este simulador hospitalar fornece uma visão simplificada do processo hospitalar e pode ser ajustado conforme necessário para requisitos específicos.

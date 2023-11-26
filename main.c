#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Função principal que simula o funcionamento do hospital ao longo do tempo.
void mainHospital()
{
    int totalTime = 0;  // Inicializa a variável que controla o tempo total da simulação.
    srand(time(NULL));  // Inicializa a semente para a geração de números aleatórios com base no tempo atual.

    initializeRadiologists();  // Inicializa o estado dos radiologistas.

    // Loop principal da simulação que executa enquanto o tempo total for menor que 43200 unidades de tempo (nesse caso, segundos).
    while (totalTime < 43200)
    {
        arrivalOfPatients(totalTime);  // Simula a chegada de pacientes para exames no momento atual.

        performExams(totalTime);  // Simula a realização de exames de raio-X pelos radiologistas.

        performReports(totalTime);  // Simula a geração de relatórios com base nos resultados dos exames.

        // Exibe métricas na tela a cada 10 unidades de tempo durante a simulação.
        if (totalTime % 10 == 0)
        {
            displayMetrics(totalTime);
        }

        totalTime++;  // Incrementa o tempo total da simulação.

        sleep(1);  // Adiciona uma pausa de 1 segundo entre as iterações para controlar a velocidade da simulação.
    }
}

int main()
{
    // chamada da função
    mainHospital();

    return 0;
}

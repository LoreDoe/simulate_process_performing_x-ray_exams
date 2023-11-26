#include "hospital.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Declara um array de radiologistas (estrutura Radiologist) com o tamanho MAX_RADIOLOGISTS para a simulação.
Radiologist radiologists[MAX_RADIOLOGISTS];

// Variáveis globais para manter métricas da simulação, como total de laudos, tempo total em laudos normais, número de exames após o prazo e tempo total em laudos de patologias.
int totalReports = 0;
int totalNormalReportTime = 0;
int totalExamsAfterDeadline = 0;
int totalPathologicalReportTime[5] = {0};

// Variáveis relacionadas à fila de exames a serem realizados. examQueue mantém os IDs dos pacientes aguardando exames.
int examQueue[MAX_PATIENTS];
int examQueueFront = 0, examQueueRear = -1;

// Variáveis relacionadas à lista de exames realizados. examList armazena detalhes de cada exame, e examListSize indica o número de exames na lista.
Exam examList[MAX_EXAMS];
int examListSize = 0;

// Lista de patologias com seus IDs, nomes, probabilidades e gravidades associadas.
Pathology pathologyList[] = 
{
    {1, "Normal", 0.3, 1},
    {2, "Bronquite", 0.2, 2},
    {3, "Pneumonia", 0.2, 3},
    {4, "Fratura de Fêmur", 0.15, 4},
    {5, "Apendicite", 0.15, 4},
};

// Gera um nome aleatório para os pacientes
char *generateRandomName()
{
    char *names[] = {"Amanda", "Roberto", "Carlos", "Davi", "Julia", "Francisco", "Maria", "Henrique", "Carolina", "Lazáro"};
    return names[rand() % (sizeof(names) / sizeof(names[0]))];
}

// Gera um CPF aleatório para os pacientes
char *generateRandomCPF()
{
    static char cpf[12];
    snprintf(cpf, sizeof(cpf), "%d%d%d.%d%d%d.%d%d%d-%d%d", rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10);
    return cpf;
}

// Gera uma idade aleatória para os pacientes entre 1 e 80 anos
int generateRandomAge()
{
    return rand() % 80 + 1;
}

// Escolhe uma patologia aleatória da lista
Pathology generateRandomPathology()
{
    int randomIndex = rand() % 5;
    return pathologyList[randomIndex];
}

// Gera um paciente com dados aleatórios
Patient generateRandomPatient(int id)
{
    Patient patient;
    patient.id = id;
    strcpy(patient.name, generateRandomName());
    strcpy(patient.cpf, generateRandomCPF());
    patient.age = generateRandomAge();
    return patient;
}

// Gera um exame com dados aleatórios
Exam generateRandomExam(int patientId, int timestamp)
{
    Exam exam;
    exam.patientId = patientId;
    exam.timestamp = timestamp;
    Pathology pathology = generateRandomPathology();
    strcpy(exam.condition, pathology.name);
    return exam;
}

// Inicializa o estado dos radiologistas
void initializeRadiologists()
{
    for (int i = 0; i < MAX_RADIOLOGISTS; ++i)
    {
        radiologists[i].id = i + 1;
        radiologists[i].busy = 0;
    }
}

// Simula a chegada de pacientes para exame com uma probabilidade de 20%
void arrivalOfPatients(int time)
{
    if ((rand() % 100) < 20)
    {
        int patientId = rand() % MAX_PATIENTS + 1;
        Patient patient = generateRandomPatient(patientId);
        examQueue[++examQueueRear] = patientId;

        printf("Tempo %d: Paciente %s chegou para exame.\n", time, patient.name);
    }
}

// Simula o desempenho de exames por radiologistas
void performExams(int time)
{
    for (int i = 0; i < MAX_RADIOLOGISTS; ++i)
    {
        if (!radiologists[i].busy && examQueueFront <= examQueueRear)
        {
            int patientId = examQueue[examQueueFront++];
            Exam exam = generateRandomExam(patientId, time);

            examList[examListSize++] = exam;
            radiologists[i].busy = 1;

            printf("Tempo %d: Exame de raio-X realizado para Paciente %d (%s).\n", time, patientId, exam.condition);
        }
    }
}

// Simula a geração de relatórios com base nos exames realizados
void performReports(int time)
{
    for (int i = 0; i < examListSize; ++i)
    {
        int reportDuration = rand() % 10 + 5;

        if (time - examList[i].timestamp > 7200)
        {
            totalExamsAfterDeadline++;
        }

        if (strcmp(examList[i].condition, "Normal") == 0)
        {
            totalReports++;
            totalNormalReportTime += reportDuration;
        }
        else
        {
            totalPathologicalReportTime[examList[i].condition[0] - '0'] += reportDuration;
        }

        radiologists[i].busy = 0;
    }
}

// Exibe métricas a cada 10 unidades de tempo
void displayMetrics(int time)
{
    double averageNormalReportTime = (totalReports > 0) ? ((double)totalNormalReportTime / totalReports) : 0;
    double totalReportTimePathological = 0;
    int totalPathologicalReports = 0;

    for (int i = 0; i < examListSize; ++i)
    {
        if (strcmp(examList[i].condition, "Normal") != 0)
        {
            totalReportTimePathological += totalPathologicalReportTime[examList[i].condition[0] - '0'];
            totalPathologicalReports++;
        }
    }

    double averageReportTimePathological = (totalPathologicalReports > 0) ? (totalReportTimePathological / totalPathologicalReports): 0;

    printf("---- Relatório a cada 10 unidades de tempo ----\n");
    printf("Tempo médio de laudo: %.2f unidades de tempo\n", averageNormalReportTime);
    printf("Tempo médio de laudo por patologia: %.2f unidades de tempo\n", averageReportTimePathological);
    printf("Quantidade de exames realizados após o limite de tempo estabelecido: %d\n", totalExamsAfterDeadline);
    printf("----------------------------------------------\n");

    totalReports = 0;
    totalNormalReportTime = 0;
    totalExamsAfterDeadline = 0;
    memset(totalPathologicalReportTime, 0, sizeof(totalPathologicalReportTime));

    sleep(1); // Adiciona uma pausa de 1 segundo para controlar a velocidade de execução
}

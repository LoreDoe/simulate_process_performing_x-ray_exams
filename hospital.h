#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_PATIENTS 100
#define MAX_EXAMS 100
#define MAX_RADIOLOGISTS 3

// Definição da estrutura de dados para representar um paciente
typedef struct
{
    int id;
    char name[30];
    char cpf[12];
    int age;
} Patient;

// Definição da estrutura de dados para representar uma patologia
typedef struct
{
    int id;
    char name[30];
    double probability;
    int severity;
} Pathology;

// Definição da estrutura de dados para representar um exame
typedef struct
{
    int patientId;
    int timestamp;
    char condition[30];
} Exam;

// Definição da estrutura de dados para representar um radiologista
typedef struct
{
    int id;
    int busy;
} Radiologist;

// Função para inicializar os radiologistas
void initializeRadiologists();

// Função que simula a chegada de pacientes ao hospital
void arrivalOfPatients(int time);

// Função que simula a realização de exames
void performExams(int time);

// Função que simula a realização de laudos médicos
void performReports(int time);

// Função que exibe métricas de desempenho a cada intervalo de tempo
void displayMetrics(int time);

// Função principal que executa a simulação do processo hospitalar
void mainHospital();

// Função para gerar um nome aleatório
char *generateRandomName();

// Função para gerar um CPF aleatório
char *generateRandomCPF();

// Função para gerar uma idade aleatória
int generateRandomAge();

// Função para gerar uma patologia aleatória
Pathology generateRandomPathology();

// Função para gerar um paciente com um ID específico
Patient generateRandomPatient(int id);

// Função para gerar um exame para um paciente em um determinado timestamp
Exam generateRandomExam(int patientId, int timestamp);

#endif

#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct {
    int cod;
    char nome[50];
    char utilizador[20];
    char password[20];
    float joia;
    DATA data_registo;
    char email[30];
    char pagina_web_pessoal[50];
    int telemovel;
    int numero_acessos;
    DATA data_ultimo_acesso;
} REGISTO_UTILIZADORES;

int main() {
    FILE *fp;
    REGISTO_UTILIZADORES user = {3, "EU", "johndoe", "password123", 9.99, {1, 1, 2022}, "johndoe@example.com", "johndoe.com", 123456789, 10, {1, 2, 2022}};
    REGISTO_UTILIZADORES user2 = {2, "TU TU", "johndoe", "password123", 9.99, {1, 1, 2022}, "johndoe@example.com", "johndoe.com", 123456789, 10, {1, 2, 2022}};
    REGISTO_UTILIZADORES user3 = {1, "ELE", "johndoe", "password123", 9.99, {1, 1, 2022}, "johndoe@example.com", "johndoe.com", 123456789, 10, {1, 2, 2022}};


    fp = fopen("users.dat", "wb");
    fwrite(&user, sizeof(REGISTO_UTILIZADORES), 1, fp);
    fwrite(&user2, sizeof(REGISTO_UTILIZADORES), 1, fp);
    fwrite(&user3, sizeof(REGISTO_UTILIZADORES), 1, fp);
    fclose(fp);

    return 0;
}

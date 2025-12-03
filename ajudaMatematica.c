#include <stdio.h>
#include <math.h> 
#include <locale.h>

int validar(float respostaAluno, float respostaCerta) {
    float diferenca = respostaAluno - respostaCerta;
    
    if (diferenca < 0) {
        diferenca = -diferenca;
    }
    if (diferenca < 0.1) {
        return 1;
    } else {
        return 0;
    }
}

void somarPonto(int *pontos) {
    *pontos = *pontos + 1; 
}

int main() {
    int opcao;
    int nivel = 1; 
    int pontos;
    int i;
    float n1, n2, gabarito, resposta;
    setlocale(LC_ALL, "portuguese");

    printf("=== PROJETO MATEMATICA ===\n");
    printf("Acerte 5 questoes para passar de nivel.\n");

    do {
        printf("\n--- MENU DE FASES ---\n");
        printf("Nivel Atual: %d\n", nivel);
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Exponenciacao\n");
        printf("6 - Logaritmo\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        }

        if (opcao > nivel) {
            printf("\n[ERRO] Voce ainda nao desbloqueou essa fase!\n");
            printf("Termine a fase %d primeiro.\n", nivel);
            continue; 
        }

        pontos = 0; 

        switch(opcao) {
            case 1: // SOMA
                printf("\n--- FASE 1: SOMA ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 10; n2 = 10; break;
                        case 2: n1 = 5;  n2 = 4;  break;
                        case 3: n1 = 12; n2 = 8;  break;
                        case 4: n1 = 50; n2 = 50; break;
                        case 5: n1 = 100; n2 = 25; break;
                    }
                    
                    gabarito = n1 + n2;
                    printf("%d) Quanto e %.0f + %.0f? ", i, n1, n2);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos); 
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            case 2: // SUBTRACAO
                printf("\n--- FASE 2: SUBTRACAO ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 10; n2 = 5; break;
                        case 2: n1 = 20; n2 = 10; break;
                        case 3: n1 = 5;  n2 = 2; break;
                        case 4: n1 = 15; n2 = 15; break;
                        case 5: n1 = 100; n2 = 1; break;
                    }

                    gabarito = n1 - n2;
                    printf("%d) Quanto e %.0f - %.0f? ", i, n1, n2);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos);
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            case 3: // MULTIPLICACAO
                printf("\n--- FASE 3: MULTIPLICACAO ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 2; n2 = 3; break;
                        case 2: n1 = 5; n2 = 5; break;
                        case 3: n1 = 4; n2 = 2; break;
                        case 4: n1 = 10; n2 = 2; break;
                        case 5: n1 = 1; n2 = 9; break;
                    }

                    gabarito = n1 * n2;
                    printf("%d) Quanto e %.0f x %.0f? ", i, n1, n2);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos);
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            case 4: // DIVISAO
                printf("\n--- FASE 4: DIVISAO ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 10; n2 = 2; break;
                        case 2: n1 = 12; n2 = 4; break;
                        case 3: n1 = 20; n2 = 5; break;
                        case 4: n1 = 8;  n2 = 2; break;
                        case 5: n1 = 50; n2 = 10; break;
                    }

                    gabarito = n1 / n2;
                    printf("%d) Quanto e %.0f / %.0f? ", i, n1, n2);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos);
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            case 5: // EXPONENCIACAO
                printf("\n--- FASE 5: POTENCIA ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 2; n2 = 2; break; // 2^2
                        case 2: n1 = 3; n2 = 2; break; // 3^2
                        case 3: n1 = 5; n2 = 2; break; // 5^2
                        case 4: n1 = 10; n2 = 2; break; // 10^2
                        case 5: n1 = 2; n2 = 3; break; // 2^3
                    }

                    gabarito = pow(n1, n2);
                    printf("%d) Quanto e %.0f elevado a %.0f? ", i, n1, n2);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos);
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            case 6: // LOGARITMO
                printf("\n--- FASE 6: LOGARITMO (BASE 10) ---\n");
                for(i = 1; i <= 5; i++) {
                    switch(i) {
                        case 1: n1 = 10; break;    // Log 1
                        case 2: n1 = 100; break;   // Log 2
                        case 3: n1 = 1000; break;  // Log 3
                        case 4: n1 = 1; break;     // Log 0
                        case 5: n1 = 10000; break; // Log 4
                    }

                    gabarito = log10(n1);
                    printf("%d) Qual o Log de %.0f na base 10? ", i, n1);
                    scanf("%f", &resposta);

                    if (validar(resposta, gabarito) == 1) {
                        printf("Certo!\n");
                        somarPonto(&pontos);
                    } else {
                        printf("Errado! Era %.0f\n", gabarito);
                    }
                }
                break;

            default:
                printf("Opcao invalida!\n");
        }

        if (opcao >= 1 && opcao <= 6) {
            printf("\n--- RESULTADO FINAL DA FASE ---\n");
            printf("Voce fez %d pontos de 5 possiveis.\n", pontos);

            if (pontos == 5) {
                printf("PARABENS! Fase concluida.\n");
                if (nivel == opcao && nivel < 6) {
                    nivel = nivel + 1;
                    printf(">>> PROXIMO NIVEL LIBERADO! <<<\n");
                }
            } else {
                printf("Voce precisa acertar TODAS (5) para passar de fase.\n");
            }
        }

    } while (opcao != 0);

    return 0;
}

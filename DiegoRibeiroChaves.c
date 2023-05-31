#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void manual ()
{
    int retorno;

    printf ("Manual do jogo maior soma de 3\n");
    printf ("\nEsse jogo utiliza dois dados de 6 lados. Nessa versao voce jogara contra o computador. Todos os jogadores comecam com 0 pontos. ");
    printf ("Cada partida do jogo eh composta por 4 rodadas. Para cada rodada, o jogador joga os dois dados que possui e tem 3 opcoes: ");
    printf ("\na) Marcar uma opcao na tabela ja no primeiro lancamento.\nb) Separar um dado e jogar o outro.\nc) Jogar os dois dados novamente.\n");
    printf ("\nApos o segundo lancamento, o jogador deve marcar uma posicao na tabela conforme abaixo: \n");
    printf ("\n1) FREE: 2 dados diferentes sem formar sequencia - marca a soma dos dados.\n");
    printf ("2) RANK: 2 dados em sequencia - 20 pontos.\n");
    printf ("3) DOUBLE: 2 dados iguais diferentes de 6 - 30 pontos.\n");
    printf ("4) MAX: 2 dados iguais a 6 - 50 pontos. ");
    printf ("\n\nExceto para a posicao a), se o jogador obter a pontuacao no primeiro lancamento, ganha 5 pontos extras.\n");
    printf ("\nSe os requisitos nao forem cumpridos ao marcar uma posicao, ela sera riscada, obtendo zero pontos naquela rodada.\n");
    printf ("\nSe o jogador tentar marcar uma posicao na tabela mais de uma vez na mesma partida, ele recebera zero a partir da segunda marcacao.\n");
    printf ("\nEm seguida, o computador joga. Essa alternancia ocorre 4 vezes. O vencedor sera quem obtiver a maior pontuacao ao fim das 4 rodadas. \n");
    printf ("\nAo final de cada partida (composta por 4 rodadas), a tabela sera resetada. \n");

    printf ("\nDigite 1 para retornar ao jogo: ");
    scanf ("%d", &retorno);
    if (retorno == 1)
    {
        return;
    }

}

int lancar_dado ()
{
    return rand() % 6 + 1;
}

int pontuacao_free (int d1, int d2)
{
    int pont_free;
    pont_free = d1 + d2;
    return pont_free;
}

int pontuacao_rank (int d1, int d2)
{
    int pont_rank;
    if (d1 == d2 + 1 || d1 == d2 - 1)
    {
        pont_rank = 20;
    }
    else 
    {
        pont_rank = 0;
    }
    return pont_rank;
}

int pontuacao_double (int d1, int d2)
{
    int pont_double;
    if (d1 == d2 && d1 != 6)
    {
        pont_double = 30;
    }
    else 
    {
        pont_double = 0;
    }
    return pont_double;
}

int pontuacao_max (int d1, int d2)
{
    int pont_max;
    if (d1 == d2 && d1 == 6)
    {
        pont_max = 50;
    }
    else 
    {
        pont_max = 0;
    }
    return pont_max;
}

int main ()
{
    srand(time(0));

    int limpar_tela, dado1, dado2, pont_rod, i, opcao_relancar, opcao_mar, cont, opcao_manual;
    int free, rank, doub, max, free_c, rank_c, doub_c, max_c, qtd_relancamentos = 0, nro_partida = 0, rodadas_restantes = 5, pont_total_jog = 0, pont_total_comp = 0;

    printf ("Jogo maior soma de 3\n\nDeseja ler o manual? (1 para sim, 0 para nao): ");
    scanf ("%d", &opcao_manual);
    if (opcao_manual == 1)
    {
        manual ();
    }

    for (i = 0; i < 3; i++)
    {
        nro_partida ++;
        free = 0;
        rank = 0;
        doub = 0;
        max = 0;

        free_c = 0;
        rank_c = 0;
        doub_c = 0;
        max_c = 0;
    
        for (cont = 0; cont < 4; cont++)
        {
            pont_rod = 0;
            rodadas_restantes--;

            system("clear");
            system("cls");

            printf ("\nJogo maior soma de 3\n");
            printf ("\nPartida %d\n", nro_partida);
            printf ("\nINICIO DA RODADA\n");
            printf ("\nRodadas restantes: %d\n", rodadas_restantes);
            printf ("\nPontuacao total do jogador: %d\n", pont_total_jog);
            printf ("\nPontuacao total do computador: %d\n", pont_total_comp);

            dado1 = lancar_dado ();
            dado2 = lancar_dado ();
            printf ("\nDado do jogador 1: %d\n", dado1);
            printf ("Dado do jogador 2: %d\n", dado2);
            
            printf ("\nDeseja relancar ambos os dados? (1 para sim, 0 para nao): ");
            scanf ("%d", &opcao_relancar);
            if (opcao_relancar == 1)
            {
                qtd_relancamentos = 1;
                dado1 = lancar_dado();
                dado2 = lancar_dado();
                printf ("Dado do jogador 1: %d\nDado do jogador 2: %d\n", dado1, dado2);
            }
            else if (opcao_relancar == 0)
            {
                printf ("Deseja relancar o dado 1? (1 para sim, 0 para nao): ");
                scanf ("%d", &opcao_relancar);
                if (opcao_relancar == 1)
                {
                    qtd_relancamentos = 1;
                    dado1 = lancar_dado();
                    printf ("Dado do jogador 1: %d\nDado do jogador 2: %d\n", dado1, dado2);
                }
                else
                {
                    printf ("Deseja relancar o dado 2? (1 para sim, 0 para nao): ");
                    scanf ("%d", &opcao_relancar);
                    if (opcao_relancar == 1)
                    {
                    qtd_relancamentos = 1;
                    dado2 = lancar_dado();
                    printf ("Dado do jogador 1: %d\nDado do jogador 2: %d\n", dado1, dado2);
                    }
                }
            }
            printf ("\nTABELA DE PONTUACAO\n");
            printf ("\n1) FREE: 2 dados diferentes sem formar sequencia, marca a soma dos dados.");
            printf ("\n2) RANK: 2 dados diferentes em sequencia, 20 pontos.");
            printf ("\n3) DOUBLE: 2 dados iguais, porem diferentes de 6, 30 pontos. ");
            printf ("\n4) MAX: 2 dados iguais a 6, 50 pontos. ");
            printf ("\n\nEscolha uma posicao da tabela para marcar digitando o nro correspondente (1, 2, 3 ou 4), observe que se as condicoes de marcacao nao forem cumpridas, a opcao sera riscada: ");
            scanf ("%d", &opcao_mar);

            switch (opcao_mar)
            {
                case 1: if (free == 0){
                        free = pontuacao_free (dado1, dado2);
                        pont_rod = free;
                        }
                        free = 1;
                        break;
                case 2: if (rank == 0){
                        rank = pontuacao_rank (dado1, dado2);
                        pont_rod = rank;
                        }
                        rank = 1;
                        if (qtd_relancamentos == 0)
                        {
                            pont_rod = pont_rod +5;
                        }
                        break;
                case 3: if (doub == 0){
                        doub = pontuacao_double (dado1, dado2);
                        pont_rod = doub;
                        }
                        doub = 1;
                        if (qtd_relancamentos == 0)
                        {
                            pont_rod = pont_rod +5;
                        }
                        break;
                case 4: if (max == 0){
                        max = pontuacao_max (dado1, dado2);
                        pont_rod = max;
                        }
                        max = 1;
                        if (qtd_relancamentos == 0)
                        {
                            pont_rod = pont_rod +5;
                        }
                        break;
                    
            }
            
            pont_total_jog = pont_total_jog + pont_rod;
            printf ("\nPontuacao da rodada do jogador = %d", pont_rod);
            printf ("\nPontuacao total do jogador = %d\n\n", pont_total_jog);

            //vez do computador
            
            pont_rod = 0;
            qtd_relancamentos = 0;
            
            dado1 = lancar_dado ();
            dado2 = lancar_dado ();
            printf ("Dado do computador 1: %d\nDado do computador 2: %d\n", dado1, dado2);

            //decidir reroll
            if (dado1 == 6 && dado2 != 6 && max_c != 50)
            {
                dado2 = lancar_dado ();
                qtd_relancamentos = 1;
                printf ("\nO computador decidiu relancar os dados.\n");
                printf ("Dado do computador 1 novo: %d\nDado do computador 2 novo: %d\n", dado1, dado2);
            }
            else if (dado2 == 6 && dado1 != 6 && max_c != 50)
            {
                dado1 = lancar_dado ();
                qtd_relancamentos = 1;
                printf ("\nO computador decidiu relancar os dados.\n");
                printf ("Dado do computador 1 novo: %d\nDado do computador 2 novo: %d\n", dado1, dado2);
            }
            else if (dado1 < 2 && dado2 < 2 && dado1 != dado2)
            {
                dado1 = lancar_dado ();
                dado2 = lancar_dado ();
                qtd_relancamentos = 1;
                printf ("\nO computador decidiu relancar os dados.\n");
                printf ("Dado do computador 1 novo: %d\nDado do computador 2 novo: %d\n", dado1, dado2);
            }
            else if (dado1 < 2 && dado1 != dado2 - 1 && dado1 != dado2 + 1)
            {
                dado1 = lancar_dado ();
                qtd_relancamentos = 1;
                printf ("\nO computador decidiu relancar os dados.\n");
                printf ("Dado do computador 1 novo: %d\nDado do computador 2 novo: %d\n", dado1, dado2);
            }
            else if (dado2 < 2 && dado2 != dado1 - 1 && dado2 != dado1 + 1)
            {
                dado2 = lancar_dado ();
                qtd_relancamentos = 1;
                printf ("\nO computador decidiu relancar os dados.\n");
                printf ("Dado do computador 1 novo: %d\nDado do computador 2 novo: %d\n", dado1, dado2);
            }

            //decidir onde marcar na tabela
            if (dado1 == dado2 && dado1 == 6 && max_c == 0)
            {
                max_c = pontuacao_max (dado1, dado2);
                pont_rod = max_c;
                max_c = 1;
                printf ("\nO computador marcou MAX.\n");
                if (qtd_relancamentos == 0)
                {
                    pont_rod = pont_rod +5;
                }  
            }
            else if (dado1 == dado2 && dado1 != 6 && doub_c == 0)
            {
                doub_c = pontuacao_double (dado1, dado2);
                pont_rod = doub_c;
                doub_c = 1;
                printf ("\nO computador marcou DOUBLE.\n");
                if (qtd_relancamentos == 0)
                {
                    pont_rod = pont_rod +5;
                }
            }
            else if (dado1 == dado2 - 1 || dado1 == dado2 + 1 && rank_c == 0)
            {
                rank_c = pontuacao_rank (dado1, dado2);
                pont_rod = rank_c;
                rank_c = 1;
                printf ("\nO computador marcou RANK.\n");
                if (qtd_relancamentos == 0)
                {
                    pont_rod = pont_rod +5;
                }
            }
            else if (free_c == 0)
            {
                free_c = dado1 + dado2;
                pont_rod = free_c;
                free_c = 1;
                printf ("\nO computador marcou FREE.\n");
            }
        
            pont_total_comp = pont_total_comp + pont_rod;
            printf ("\nPontuacao da rodada do computador = %d", pont_rod);
            printf ("\nPontuacao total do computador = %d\n\n", pont_total_comp);

            printf ("\nDigite 1 para limpar a tela: ");
            scanf ("%d", &limpar_tela);
            if (limpar_tela == 1)
            {
                system("clear");
                system("cls");
            }
        }
        printf ("\nFinal da partida %d.\n", nro_partida);
        rodadas_restantes = 5;
    }
    printf ("\nPontuacao final do jogador = %d\n", pont_total_jog);
    printf ("\nPontuacao final do computador = %d\n", pont_total_comp);
    
    if (pont_total_jog > pont_total_comp)
    {
        printf ("\nO jogador venceu.\n");
    }    
    else if (pont_total_jog == pont_total_comp)
    {
        printf ("\nO jogo empatou.\n");
    }
    else
    {
        printf ("\nO computador venceu.\n");
    }
    return 0;
}

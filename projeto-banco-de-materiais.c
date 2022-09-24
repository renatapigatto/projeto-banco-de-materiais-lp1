/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int opMenu = 0, exibirMenu = 1, opInvalida = 0, ;
    char clear [13] = "\e[1;1H\e[2J";
    
// procedimento mostrarMenuInicial
// menu inicial: entra em loop até opção válida chamar outra tela

    
    while (exibirMenu == 1){
        printf("\n#########################################");
        printf("\n#   B A N C O  D E  M A T E R I A I S   #");
        printf("\n#########################################");
        printf("\n#                                       #");
        printf("\n#   1-Pesquisar material                #");
        printf("\n#   2-Cadastrar material                #");
        printf("\n#   3-Sair                              #");
        printf("\n#                                       #");
        
        if(opInvalida == 0){
             printf("\n#                                       #");
        }else{
            printf("\n#            Opção inválida!            #");
        }
        
        printf("\n#########################################");
        printf("\n\nDigite a opção desejada: ");
        scanf("%d", &opMenu);
        
        switch(opMenu){
            case 1: 
                printf(clear); //limpa tela
                exibirMenu == 0;
                //mostrarMenuPesquisa;
                break;
            case 2:
                printf(clear);
                printf("Opção 2 escolhida");
                exibirMenu == 0;
                break;
            case 3:
                printf(clear);
                exibirMenu == 0;
                //mostrarMenuSair;
                break;
            default:
                printf(clear);
                opInvalida == 1;
        }
    }
    
    // procedimento mostrarMenuPesquisa
    
    char pesquisa[200]; 
    
    printf("#########################################");
    printf("#   B A N C O  D E  M A T E R I A I S   #");
    printf("#########################################");
    printf("#                                       #");
    printf("#      BUSQUE POR TÍTULO, AUTORIA,      #");
    printf("#      DISCIPLINA, ETC.                 #");
    printf("#                                       #");
    printf("#                                       #");
    printf("# Digite < para voltar                  #");
    printf("#########################################");
    printf("Digite sua busca: ");
    scanf("%s", pesquisa);
    
    switch(pesquisa){
        case '<':
            printf(clear);
            //mostrarMenuInicial;
            break;
        default:
            printf(clear);
            // fazer tela e lógica de busca
            printf("RESULTADO DA PESQUISA:")
    }
    
    // procedimento mostrarMenuSair
    
    char querSair;
    
    exibirMenu = 1
    opInvalida = 0
    
    while (exibirMenu = 1){
        printf("#########################################");
        printf("#   B A N C O  D E  M A T E R I A I S   #");
        printf("#########################################");
        printf("#                                       #");
        printf("#       Tem certeza de que deseja       #");
        printf("#       sair?                           #");
        printf("#                                       #");
        printf("#                                       #");
        
        if(opInvalida = 0){
            printf("#                                       #");
        }else{
            printf("#            Opção inválida!            #");
        }
        
        printf("#########################################");
        printf("[S/N]? ");
        scanf("%c", &querSair);
        
        switch(toupper(querSair)){
            case 'S':
                printf(clear);
                exibirMenu = 0;
                break;
            case 'N':
                printf(clear);
                exibirMenu = 0;
                //mostrarMenuInicial;
                break;
            default:
                printf(clear);
                opInvalida = 1;
        }
    }
    
    // chama menu inicial
    //mostrarMenuInicial
    
    //////////////////////////////////////////////////////////
    ////////////////////BLOCO DE AUTENTICACAO/////////////////
    //////////////////////////////////////////////////////////
    
    //procedimento lerDadosUsuario
    
    int i, usuarioRejeitado = 1;
    char usuario[100], senha[6];
    
    //usuarios[10,0] <- "gabrielhamdan"
    //usuarios[10,1] <- "123"
    
    printf("USUÁRIO: ");
    scanf("%s", usuario);
    printf("SENHA: ");
    scanf("%s", senha);
    
    for(i = 0; i<=10; i++){
        //SE usuario = usuarios[i,0] ENTAO
            //SE senha = usuarios[i,1] ENTAO
                //printf(clear)
                //usuarioRejeitado = 0
                //autenticarUsuario
    }
    
    if (usuarioRejeitado == 1){
        //rejeitarUsuario;
    }
    
    
    //procedimento autenticarUsuario
    printf("Usuário autenticado!")


    //procedimento rejeitarUsuario
    printf("Usuário ou senha inválido!")
    
}


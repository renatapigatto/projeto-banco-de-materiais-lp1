#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

int opMenu, exibirMenu, opInvalida;
char limpaTela[5], pesquisa[100];

void mostrarMenuInicial();
void mostrarMenuPesquisa();
void mostrarResultadoPesquisa();
void mostrarCadastroMateriais();
void scanPesquisa();
void mostrarMenuSair();

void mostrarMenuInicial() {
    exibirMenu = 1;
    opInvalida = 0;

    while (exibirMenu){
        printf("\n#########################################");
        printf("\n#   B A N C O  D E  M A T E R I A I S   #");
        printf("\n#########################################");
        printf("\n#                                       #");
        printf("\n#   1-Pesquisar material                #");
        printf("\n#   2-Cadastrar material                #");
        printf("\n#   3-Sair                              #");
        printf("\n#                                       #");

        if(!opInvalida){
             printf("\n#                                       #");
        }else{
            printf("\n#            Opção inválida!            #");
        }

        printf("\n#########################################");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opMenu);
        getchar();

        switch(opMenu){
            case 1:
                system(limpaTela);
                exibirMenu = 0;
                mostrarMenuPesquisa();
                break;
            case 2:
                system(limpaTela);
                mostrarCadastroMateriais();
                exibirMenu = 0;
                break;
            case 3:
                system(limpaTela);
                exibirMenu = 0;
                mostrarMenuSair();
                break;
            default:
                system(limpaTela);
                opInvalida = 1;
        }
    }
}

void mostrarMenuPesquisa() {
    printf("\n#########################################");
    printf("\n#   B A N C O  D E  M A T E R I A I S   #");
    printf("\n#########################################");
    printf("\n#                                       #");
    printf("\n#      BUSQUE POR TÍTULO, AUTORIA,      #");
    printf("\n#      DISCIPLINA, ETC.                 #");
    printf("\n#                                       #");
    printf("\n#                                       #");
    printf("\n# Digite < para voltar                  #");
    printf("\n#########################################");
    printf("\nDigite sua busca: ");
    scanPesquisa();
    //implementar lógica para limitar caracteres no scanf    
}

void mostrarResultadoPesquisa(){
    int i;
    
    printf("Você pesquisou por '%s'", pesquisa);
    printf("\n\nRESULTADOS:");
    printf("\n\nwww.%s.com.br", pesquisa);
    
    //transforma o conteúdo da variável em caracteres maiúsculos
    for(i = 0; pesquisa[i]!='\0'; i++){
        if(pesquisa[i] >= 'a' && pesquisa[i] <= 'z'){
            pesquisa[i] = pesquisa[i] -32;
      }
    }
    
    printf("\n%s", pesquisa);
    printf("\nhá 5 dias - Lorem ipsum dolor, sit amet consectetur adipisicing elit. Ipsum dicta magnam excepturi? Ipsum dicta magnam...");
    printf("\n\n---------------------------------------------");
    printf("\nAs pessoas também perguntaram:");
    printf("\n - Para que serve %s?      v", pesquisa);
    printf("\n - Exemplos de %s          v", pesquisa);
    printf("\n - Como usar %s?           v", pesquisa);
    printf("\n---------------------------------------------");
    printf("\n\nDigite uma nova busca ou < para voltar para o menu inicial: ");
    scanPesquisa();
}

//refatorado para evitar repetição nas telas de pesquisa
void scanPesquisa() {
    strncpy(pesquisa, "", sizeof(pesquisa)); //esvazia string pesquisa
    
    scanf("%[^\n]", pesquisa);
    getchar();

    if (pesquisa[0] == '<') {
        system(limpaTela);
        mostrarMenuInicial();
    } else {
        system(limpaTela);
        if (strlen(pesquisa) == 0) {
            mostrarMenuPesquisa();
        } else {
            mostrarResultadoPesquisa();
        }
    }
}

void mostrarCadastroMateriais(){
    float t = 1.5; // add uma variável para facilitar futuramente caso mude o tempo de sleep()
    
    printf("Cadastro de materias indisponível no momento.");
    printf("\n\nVocê será redirecionado para a página inicial...");
    sleep(t);
    printf("\n.");
    sleep(t);
    printf("\n.");
    sleep(t);
    printf("\n.");
    sleep(t);
    system(limpaTela);
    mostrarMenuInicial();
}

void mostrarMenuSair() {
    char querSair;
    exibirMenu = 1;
    opInvalida = 0;

    while (exibirMenu){
        printf("\n#########################################");
        printf("\n#   B A N C O  D E  M A T E R I A I S   #");
        printf("\n#########################################");
        printf("\n#                                       #");
        printf("\n#       Tem certeza de que deseja       #");
        printf("\n#       sair?                           #");
        printf("\n#                                       #");
        printf("\n#                                       #");

        if(!opInvalida){
            printf("\n#                                       #");
        }else{
            printf("\n#            Opção inválida!            #");
        }

        printf("\n#########################################");
        printf("\n[S/N]? ");
        scanf("%c", &querSair);
        getchar();

        querSair = toupper(querSair);

        if (querSair == 'S' || querSair == 'N') {
            if(querSair == 'S') {
                system(limpaTela);
                exibirMenu = 0;
            }

            if (querSair == 'N') {
                system(limpaTela);
                mostrarMenuInicial();
            }
        } else {
            system(limpaTela);
            opInvalida = 1;
        }
    }
}

int main()
{
    #ifdef _WIN32
        strncpy(limpaTela, "cls", 3);
        setlocale(LC_ALL, "Portuguese");
	#else
	    strncpy(limpaTela, "clear", 5);
	#endif

    mostrarMenuInicial();

    return 0;
}
/*

    //////////////////////////////////////////////////////////
    ////////////////////BLOCO DE AUTENTICACAO/////////////////
    //////////////////////////////////////////////////////////

    //procedimento lerDadosUsuario

    int i, usuarioRejeitado = 1;
    char usuario[100], senha[6];

    //usuarios[10,0] <- "gabrielhamdan"
    //usuarios[10,1] <- "123"

    printf("USU�RIO: ");
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
    printf("Usu�rio autenticado!");


    //procedimento rejeitarUsuario
    printf("Usu�rio ou senha inv�lido!");

}

*/
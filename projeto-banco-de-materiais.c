#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

int opMenu, exibirMenu, opInvalida, estaLogado = 0;
char limpaTela[5], pesquisa[100];
char usuarios[10][2][20], nomeUsuario[20], senhaUsuario[6];


void mostrarMenuInicial();
void mostrarMenuPesquisa();
void mostrarResultadoPesquisa();
void mostrarCadastroMateriais();
void scanPesquisa();
void mostrarTelaLogin();
void autenticarUsuario();
void cadastrarUsuario();
int verificarUsuarioExistente(void);
void validarSenha();
void mostrarMenuSair();

void mostrarMenuInicial() {
    exibirMenu = 1;
    opInvalida = 0;

    while(exibirMenu){
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
                if(estaLogado){
                    mostrarCadastroMateriais();
                }else{
                    mostrarTelaLogin();
                }
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
    strncpy(pesquisa, "", 100); //esvazia string pesquisa
    
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
    
    printf("\n\nCadastro de materias indisponível no momento.");
    printf("\n\nVocê será redirecionado para a página inicial ");
    sleep(t);
    printf(". ");
    sleep(t);
    printf(". ");
    sleep(t);
    printf(".");
    sleep(t);
    system(limpaTela);
    mostrarMenuInicial();
}

void mostrarTelaLogin(){
    
    exibirMenu = 1;
    opInvalida = 0;
    
    while(exibirMenu){
        printf("\n#########################################");
        printf("\n#   B A N C O  D E  M A T E R I A I S   #");
        printf("\n#########################################");
        printf("\n#                                       #");
        printf("\n#   1-Logar-se                          #");
        printf("\n#   2-Cadastrar-se                      #");
        printf("\n#                                       #");
        if(!opInvalida){
            printf("\n#  Digite 0 para voltar                 #");
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
                    autenticarUsuario();
                    break;
                case 2:
                    system(limpaTela);
                    exibirMenu = 0;
                    cadastrarUsuario();
                    break;
                case 0:
                    system(limpaTela);
                    exibirMenu = 0;
                    mostrarMenuInicial();
                    break;
                default:
                    system(limpaTela);
                    opInvalida = 1;
        }
    }
    
}

void cadastrarUsuario(){
    
    float t = 1.5;
    int i, usuarioValido;
    
    strcpy(usuarios[0][0], "renata");
    
    exibirMenu = 1;
    
    while(exibirMenu){
        usuarioValido = verificarUsuarioExistente();
        
        if(usuarioValido){
            exibirMenu = 0;
        }else{
            system(limpaTela);
            printf("\nUsuário existente! Tente outro nome de usuário.");
        }
    }
    
    do{
        printf("\nDigite uma senha:\n> ");
        scanf("%s", senhaUsuario);
        getchar();
    }while(senhaUsuario == "");
    
    for(i = 0; i < 10; i++){
        if(strcmp(usuarios[i][0], "") == 0){
            strcpy(usuarios[i][0], nomeUsuario);
            strcpy(usuarios[i][1], senhaUsuario);
            break;
        }
    }
    
    system(limpaTela);
    
    printf("\nUsuário cadastrado com sucesso!");
    printf("\n---------------------------------------------");
    printf("\nRedirecionando para a página de login ");
    sleep(t);
    printf(". ");
    sleep(t);
    printf(". ");
    sleep(t);
    printf(".");
    sleep(t);
    system(limpaTela);
    mostrarTelaLogin();
    
}

int verificarUsuarioExistente(void){
   
    int i, usuarioValido = 1;
    
    do{
        printf("\nDigite um nome de usuário\n> ");
        scanf("%s", nomeUsuario);
        getchar();
        if(nomeUsuario == ""){
            system(limpaTela);
        }
    }while(nomeUsuario == "");
    
    for(i = 0; i < 10; i++){
        if(strcmp(nomeUsuario, usuarios[i][0]) == 0){
            usuarioValido = 0;
            break;
        }
    }
    
    return(usuarioValido);
}

void autenticarUsuario(){
    
    int i, opcao = 0, usuarioRegistrado = 0;
    
    strcpy(usuarios[0][0], "renata");
    
    printf("\nUSUÁRIO: ");
    scanf("%s", nomeUsuario);
    getchar();
    printf("SENHA: ");
    scanf("%s", senhaUsuario);
    getchar();
    
    for(i = 0; i < 10; i++){
        if(strcmp(usuarios[i][0], nomeUsuario) == 0){
            if(strcmp(usuarios[i][1], senhaUsuario) == 0){
                sleep(1);
                printf("\n\nSeja bem-vinde, %s!", nomeUsuario);
                system(limpaTela);
                estaLogado = 1;
                usuarioRegistrado = 1;
                mostrarCadastroMateriais();
            }else{
                sleep(1);
                printf("\n\nSenha incorreta! Digite seus dados novamente.");
                system(limpaTela);
                autenticarUsuario();
            }
        }
    }
    
    if(!usuarioRegistrado){
        sleep(1);
        printf("\n\nUsuário não existe!");
        printf("\n\n---------------------------------------------");
        printf("\n1-Fazer nova tentativa de Login");
        printf("\n2-Fazer o cadastro");
        while((opcao != 1) || (opcao != 2)){
            printf("\n\nQual a opção desejada? ");
            scanf("%d", &opcao);
            if(opcao == 1){
                system(limpaTela);
                autenticarUsuario();
            }else{
                if(opcao == 2){
                    system(limpaTela);
                    cadastrarUsuario();
                }else{
                    printf("\nOpção inválida!");
                }
            }
        }
    }
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
        setlocale(LC_ALL, "pt_BR.UTF-8");
	#endif

    mostrarMenuInicial();

    return 0;
}

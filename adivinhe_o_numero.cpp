//inclui bibliotecas usadas no projeto
#include <iostream>
#include <limits>
#include <random>

void opcao_Invalida_Digitada()
{

            //limpa buffer de entrada
            std::cin.clear();

            //ignora a próxima linha
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //pede para o usuário que digitou uma opção inválida, digite uma opção válida
            std::cout << "Digite uma opção válida" << std::endl;

}

int gera_Num(int num_max)
{
    //cria uma instância da classe random_device que serve para usar a situação do hardware para gerar números aleatórios chamda rd
    std::random_device rd;

    //cria uma instancia da classe mt19937 que contém o algoritimo para gerar números aleatórios
    std::mt19937 gerador_numeros(rd());

    //define a distribuição entre 1 e 3
    std::uniform_int_distribution<> distribuicao(1,num_max);

    //armazena o número aleatório na variável opcao_pc
    int num = distribuicao(gerador_numeros);

    //retona o número gerado
    return num;
}

void mecanismo_Jogo(int num_gerado)
{



    //armazena a tentativa na variável resposta
    std::cout << "Tente advinhar o numero:" << std::endl;
    int resposta;
    std::cin >> resposta;

    if(std::cin.fail())
    {
        opcao_Invalida_Digitada();
    }
    else
    {
        if(num_gerado == resposta)
        {
            std::cout << "Voce venceu" << std::endl;
            
            //fecha o programa
            exit(0);
        }
        else if(num_gerado > resposta)
        {
            std::cout << "Numero digitado e maior" << std::endl;
            mecanismo_Jogo(num_gerado);
        }
        else
        {
            std::cout << "Numero digitado e menor" << std::endl;
            mecanismo_Jogo(num_gerado);
        }
    }


}

//função que inicia o projeto
int main()
{

    //Variável booleana que define se o jogo segue ou é interrompido
    bool continuar_jogando = true;
    
    while(continuar_jogando)
    {

        //cria menu
        std::cout << "O que deseja fazer?" << std::endl;
        std::cout << "1. Jogar" << std::endl;
        std::cout << "2. Sair" << std::endl;

        //cria variável e armazena input do usuário;
        char resposta;
        std::cin >> resposta;

        //verifica erro no input
        if(std::cin.fail() || resposta < '1' || resposta > '2')
        {

            opcao_Invalida_Digitada();

        }
        else
        {
            switch(resposta)
            {
                
                case '1':

                    //armazena na variável num_max o número máximo que a pessoa quer tentar advinhar
                    std::cout << "Digite o numero maximo que voce quer tentar advinhar" << std::endl;
                    int num_max;
                    std::cin >> num_max;
                    
                    //verifica erro no input
                    if(std::cin.fail())
                    
                    {
                        
                        opcao_Invalida_Digitada();
                
                    }
                    else
                    {
                        int num = gera_Num(num_max);
                        mecanismo_Jogo(num);

                    }

                break;
                
                case '2':
                
                    //fecha o programa
                    exit(0);
                
                break;
            
            }
        }


    }

}
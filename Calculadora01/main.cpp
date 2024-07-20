#include <iostream>
#include "Pilha.h"
#include "ValidacaoExpressoes.h"
#include <cstdlib>
using namespace std;

int main()
{
    PilhaDinamica<float> pilhaNum;
    string escolha="",entrada;
    float numero;
    //EXPLICA COMO EXECUTAR O PROGRAMA
    cout<<"Siga o passo a passo para a execucao correta do programa."<<endl;
    cout<<"Instrucoes:"<<endl;
    cout<<"insira o comando INICIO para iniciar o programa, depois"<<endl;
    cout<<"de iniciar o programa antes de executar qualquer operacao,"<<endl;
    cout<<"digite o comando ZERA para inicializar ou reiniciar a expressao aritimetica"<<endl;
    cout<<"COMANDOS!!"<<endl;
    cout<<"| INICIO | ZERA | IGUAL | FIM | PARCELAS | SOMA(valor) | SUBTRAI(valor) | DIVIDA(valor) | MULTIPLICA(valor) |"<<endl;

    cout<<"Digite: ";
    do
    {
        getline(cin,escolha);//le a escolha do usuario
        if(escolha!="INICIO" && escolha!="FIM")//verifica se é valido
            cout<<"O programa deve ser iniciado, digite o comando INICIO ou FIM para sair: ";//caso nao seja, exibe a mensagem de erro
    }
    while(escolha!="INICIO" && escolha!="FIM");
    cin.ignore(); //limpar o buffer

     if(escolha=="FIM")
    {
        cout<<"Fim do programa!!";
        return 0;//encerra o programa se a escolha for FIM
    }

    cout<<"!!PROGRAMA INICIADO!!"<<endl;

    cout<<"COMANDOS!!"<<endl;//mostra comandos a cada entrada
    cout<<"| ZERA | IGUAL | FIM | PARCELAS | SOMA(valor) | SUBTRAI(valor) | DIVIDA(valor) | MULTIPLICA(valor) |"<<endl;
    cout<<"Digite: ";
    do
    {
        getline(cin,escolha);//le a escolha do usuario
        if(escolha!="ZERA" && escolha!="FIM")//verifica se é valido
            cout<<"As expresoes devem ser inicializada, digite o comando ZERA ou FIM para sair: ";//caso nao seja, exibe a mensagem de erro
    }
    while(escolha!="ZERA" && escolha!="FIM");
    cin.ignore(); //limpar o buffer

    if(escolha=="FIM")//se a escolha for igual a FIM encerra o programa
    {
        cout<<"Fim do programa!!";
        return 0;
    }
        system("CLS");//limpando a tela
        zera(pilhaNum);//inicializar ou reinicia as expresao
        cout<<"Expressao aritimetica inicializada"<<endl;

    do
    {
        cout<<"COMANDOS!!"<<endl;//mostra os comandos a cada entrada
        cout<<"| ZERA | IGUAL | FIM | PARCELAS | SOMA(valor) | SUBTRAI(valor) | DIVIDA(valor) | MULTIPLICA(valor) |"<<endl;
        escolha="";//limpa a escolha anterior
        do
        {
            cout<<"Digite: ";
            getline(cin,entrada);// le o comando

            if(!validarEntrada(entrada))//verifica se é valido
                cout<< "Comando inválido!!!" <<endl;//mostra a mensagem de erro

        }
        while(!validarEntrada(entrada));

        separarOperacaoValor(entrada,escolha,numero);//separa o valor numerio e a parte string da entrada
        //vericar em qual dessas operacao a entrada ou escolha se encaixa, entrada serve para comandos sem parenteses ()
        if (entrada == "ZERA")
        {
            zera(pilhaNum);
            cout<<"Expressao reinicializada"<<endl;
        }
        else if (escolha == "SOMA")
            somar(pilhaNum, numero);

        else if (escolha == "SUBTRAI")
            subtrai(pilhaNum, numero);

        else if (escolha == "MULTIPLICA")
            multiplicar(pilhaNum, numero);

        else if (escolha == "DIVIDA")
            divide(pilhaNum, numero);

        else if (entrada == "PARCELAS")
            parcelas(pilhaNum);

        else if(entrada=="IGUAL")
            cout<<"{ "<<igual(pilhaNum)<<" }"<<endl;

        else if (entrada == "FIM")
            break;

        else
          cout<< "Comando inválido!!!" <<endl;

        cin.ignore(); //limpar o buffer
        system("CLS");//limpando a tela
    }
    while(entrada!="FIM");//se a entrada for fim sai do programa
    cout<<"programa finalizado!!!";
    return 0;
}
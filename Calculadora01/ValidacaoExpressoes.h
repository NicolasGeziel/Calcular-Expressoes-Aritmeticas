#ifndef VALIDACAOEXPRESSOES_H_INCLUDED
#define VALIDACAOEXPRESSOES_H_INCLUDED
#include "Pilha.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
void zera(PilhaDinamica<T> &pilha){
    T zero=0;
    criarpilha(pilha);
    empilhar(pilha,zero);
}

template<typename T>
void somar(PilhaDinamica<T>&pilha,T elemento){
        empilhar(pilha,retornaElementoTopo(pilha) + elemento);
}

template<typename T>
void subtrai(PilhaDinamica<T> &pilha,T elemento){
     empilhar(pilha,retornaElementoTopo(pilha) - elemento);
}

template<typename T>
void multiplicar(PilhaDinamica<T> &pilha,T elemento){
    empilhar(pilha,retornaElementoTopo(pilha)*elemento);
}

template<typename T>
void divide(PilhaDinamica<T> &pilha,T elemento){
    if(elemento!=0)
    {
      empilhar(pilha,retornaElementoTopo(pilha)/elemento);
    }
    else
        cout<<"Impossivel dividir por zero"<<endl;
}

template<typename T>
void parcelas(PilhaDinamica<T> pilha){
    if(numeroElemento(pilha)>2){
    int i=numeroElemento(pilha)-2;
    cout<<"{";
    while(i>0){
     cout<<retornaElemento(pilha,i);
     i--;
     if(i!=0)
        cout<<",";

      }
      cout<<"}"<<endl;
    }
    else
        cout<<"Ainda nao possui parcelas na expressao aritimetica";
}

template<typename T>
T igual(PilhaDinamica<T>pilha){
    return retornaElementoTopo(pilha);
}

template<typename T>
void fim(PilhaDinamica<T>&pilha){
    DestruirPilha(pilha);
}
template<typename T>
void separarOperacaoValor(string entrada, string& parteString, T& parteValor) {
    if(entrada=="ZERA" || entrada=="IGUAL" || entrada=="PARCELAS" || entrada=="FIM" || entrada=="INICIO")
        return;
    string numero;
    int i=0;
    for(i;i<entrada.size();i++)
    {
        if(entrada[i]=='(')
            break;
        parteString+=entrada[i];
    }
    i++;
    for(i;i<entrada.size();i++)
    {
        if(entrada[i]==')')
            break;
        numero+=entrada[i];

    }
    parteValor = stof(numero);
}
bool validarEntrada(string entrada){
    if(entrada=="")
        return false;

    if(entrada=="ZERA" || entrada=="IGUAL" || entrada=="PARCELAS" || entrada=="FIM" || entrada=="INICIO")
        return true;

    int i=0;

    for(i;i<entrada.size();i++)
    {
        if(!isalpha(entrada[i]) && entrada[i]!='(')
            return false;
        if(i==entrada.size()-1)
            return false;
        if(entrada[i]=='(')
            break;
    }
    i++;
    int ponto=0;
    if(entrada[i]=='.')
        return false;
    if(entrada[i]=='-')
        i++;

    for(i;i<entrada.size();i++)
    {
        if(!isdigit(entrada[i]) && entrada[i]!=')' && entrada[i]!='.' || ponto>1)
        {
            return false;
        }
        if(entrada[i]=='.')
            ponto++;

        if(entrada[i]==')' && i==entrada.size()-1 && isdigit(entrada[i-1]))
        {
            return true;
        }
    }
}
#endif // VALIDACAOEXPRESSOES_H_INCLUDED
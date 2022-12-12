/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listaencadeadaaula1;

/**
 *
 * @author tatiane
 */
public class ListaEncadeada {
    
    No inicio;
    No fim;
    int tam=0;
    
    void addInicio(int elemento){
        
        No novo = new No();
        novo.elemento = elemento;
        if(tam == 0){
         fim = novo;
         inicio = novo;
        }else{
            novo.prox = inicio;
            inicio = novo;
        }
        tam++;
    }

    void imprimir(){
        No aux;
        for (aux = inicio; aux != null; aux=aux.prox){
            System.out.println(" " + aux.elemento);
          
        }
    }
}

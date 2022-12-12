//José Douglas Gondim Soares, 416753


// NO

public class No {
	No prox;
	int valor;

	public No(No prox, int valor) {
		this.prox= prox;
		this.valor=valor;
	}

	public No() {
		super();
	}
	
	
}


// LISTA

package LISTAS;

public class ListaEncadeada {
	No inicio;
	No fim;
	int tam;
	
private void adicionar(int posicao, int elemento) {
	No novo = new No();
	if(tam==0) {
		inicio=novo;
		fim=novo;
	}else {
		novo.prox=inicio;
		inicio = novo;
	}
	tam++;
}
public void adicionarQualquer(int posicao, int elemento) {
	No aux = inicio;
	No aux1 = new No();
	aux1.valor = elemento;
	if(posicao==0) {
		adicionar(posicao, elemento);
	}else if(posicao>0 && posicao<tam) {
		for(int i=0; i<=posicao-1; i++) {
			aux= aux.prox;
		}
		aux.prox = aux1;		
	}
	tam++;
}

public static void main(String[] args) {
	ListaEncadeada a = new ListaEncadeada();
	a.adicionarQualquer(0, 1);
	a.adicionarQualquer(1, 10);
	a.adicionarQualquer(1, 2);
	a.adicionarQualquer(3, 5);
	for(No aux=a.inicio; aux!=null; aux=aux.prox) {
		System.out.println(aux.valor);
	}
}

}
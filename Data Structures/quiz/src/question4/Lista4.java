package question4;

public class Lista4 {
	No inicio;
	No fim;
	int tam;
	
	void addOrdenado(int elemento){
		No novo = new No();
		novo.elemento = elemento;
		
		if(tam==0) {
			inicio = novo;
		}else {
			if(novo.elemento < inicio.elemento) {
				novo.prox = inicio;
				inicio = novo;
				fim = novo;
			}else{
				No aux = inicio;
				while(aux.prox != null && novo.elemento > aux.prox.elemento) {
					aux = aux.prox;
				}
				novo.prox = aux.prox;
				aux.prox = novo;
				if(novo.prox == null) {
					fim = novo;
				}				
				
			}
		}
		tam++;
		
		
	}
	
	int remover() {
		int elemento = 0;
		if(tam>0) {
			No aux = inicio;
			for(int i=0;i<tam-1;i++) {
				aux = aux.prox;
			}
			elemento = aux.elemento;
			aux.prox = null;
			fim = aux;
			tam--;
			
		}
		return elemento;
		
	}
	
	boolean ehIgual(No aux, No aux1) {
		while((aux.prox != null && aux1.prox != null) && (aux.elemento == aux1.elemento)) {
			aux = aux.prox;
			aux1 = aux1.prox;			
		}
		if(aux.prox==null && aux1.prox==null) {
			return true;
		}
		return false;
	}
	
	void imprimir() {
		No aux = inicio;
		for(int i=0;i<tam;i++) {
			System.out.println(aux.elemento);
			aux = aux.prox;
		}
	}

}

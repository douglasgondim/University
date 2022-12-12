package BST;

public class BST {
	No raiz;

	public BST(){}

	No buscarNo(No pt, int elemento) {
		if(pt==null) {
			System.out.println("I'm null");
			return pt;
		}else if(pt.elemento==elemento) {
			System.out.println("found myself");
			return pt;
		}else {
			if(pt.esq != null && elemento < pt.elemento) {
				buscarNo(pt.esq, elemento);
			}else if(pt.dir != null && elemento > pt.elemento) {
				buscarNo(pt.dir, elemento);
			}
			System.out.println("this is me");
			return pt;
		}




	}

	void addArvore(No pt, int elemento) {
		No novo = new No(elemento);
		No encaixe = buscarNo(pt, elemento);
		System.out.println(encaixe);
		if(encaixe==null) {
			raiz = novo;
		}else {
			if(elemento > encaixe.elemento) {
				encaixe.dir = novo;
			}else {
				encaixe.esq = novo;
			}


		}
	}

	void imprimeInOrdem(No pt) {
		if(pt.esq != null) {
			imprimeInOrdem(pt.esq);
		}
		System.out.println(pt.elemento);

		if(pt.dir != null) {
			imprimeInOrdem(pt.dir);
		}

	}

	public static void main(String[] args) {
		BST t1 = new BST();
		t1.addArvore(t1.raiz, 5);
		t1.addArvore(t1.raiz, 4);
		t1.addArvore(t1.raiz, 10);
		t1.addArvore(t1.raiz, 11);
		//		t1.addArvore(t1.raiz, 1);
		t1.imprimeInOrdem(t1.raiz);
	}

}

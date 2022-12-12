package Ifood;	

public class Carrinho {
	private Comida[] comidasCompradas = new Comida[20];
	private IFood iFood;
	
	// gerador vazio de carrinho
	public Carrinho() {}
	
	
	// gerador de carrinho que o liga a um iFood
	public Carrinho(IFood iFood) {
		this.iFood = iFood;
		
	}
	
	
	// GETTERS E SETTERS----------------
	public void setComidasCompradas(Comida[] comidasCompradas) {
		this.comidasCompradas = comidasCompradas;
	}

	public void setiFood(IFood iFood) {
		this.iFood = iFood;
	}

	public IFood getiFood() {
		return iFood;
	}

	public Comida[] getComidasCompradas() {
		return comidasCompradas;
	}
	
	// GETTERS E SETTERS----------------

	// percorre todo o vetor de comidas compradas(carrinho) e retorna a soma dos preços de cada comida
	public float calcularPrecoTotalSemTaxaEntrega() {
		float precoTotal=0;
		for(int i=0;i<comidasCompradas.length-1;i++) {
			if(comidasCompradas[i] != null) {
				precoTotal += comidasCompradas[i].getPreco();
			}
		}
		return precoTotal;
		
	}
	
	
	// percorre todo o vetor de comidas compradas(carrinho) e retorna a soma dos 
	// preços de cada comida + taxa de entrega do restaurante
	public float calcularPrecoTotal() {
		float precoTotal=0;
		for(int i=0;i<comidasCompradas.length-1;i++) {
			if(comidasCompradas[i] != null) {
				precoTotal += comidasCompradas[i].getPreco();
			}
		}
		precoTotal += iFood.getTaxaEntrega();
		return precoTotal;
		
	}
	
	// percorre todo o vetor de comidas compradas(carrinho) e imprime o nome de cada comida
	public void verItens() {
		for(int i=0;i<comidasCompradas.length-1;i++) {
			if(comidasCompradas[i]!=null) {
				System.out.printf(comidasCompradas[i].getNome() + " - R$ %.2f\n", comidasCompradas[i].getPreco());
			}
		}
		System.out.printf("Total com taxa de entrega = R$ %.2f\n", this.calcularPrecoTotal());
		
	}
	
	// percorre o vetor de comidas compradas(carrinho) e retorna a primeira comida que achar com o 
	// mesmo nome do parâmetro para o menu do retaurante
	public void removerComida(String nomeComida) {
		for(int i=0;i<comidasCompradas.length-1;i++) {
			if(comidasCompradas[i] != null && comidasCompradas[i].getNome()==nomeComida) {
				iFood.getMenu().adicionarComida(comidasCompradas[i], 1);
				comidasCompradas[i] = null;
				break;
				
			}
		}
		
	}
	
	// percorre todo o vetor de comidas compradas(carrinho) e adiciona a comida passada por parâmetro
	// para o primeiro espaço vazio do vetor
	public void adicionarComida(String nomeComida) {
		for(int i=0; i<comidasCompradas.length-1;i++) {
			if(comidasCompradas[i]==null) {
				comidasCompradas[i] = iFood.getMenu().pegarComida(nomeComida);
				break;
			}
		}
		
	}

}

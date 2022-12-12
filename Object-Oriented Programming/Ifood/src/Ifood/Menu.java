package Ifood;

public class Menu {
	private Comida[] opcoes;
	
	// construtor vazio do Menu
	public Menu() {}
	
	// construtor Menu
	public Menu(int num_opcoes) {
		// cria um vetor de comidas to tamanho passado como parâmetro quando se cria um restaurante
		this.opcoes = new Comida[num_opcoes];	
		
	}
	
	// GETTERS E SETTERS----------------
	public Comida[] getOpcoes() {
		return opcoes;
	}

	public void setOpcoes(Comida[] opcoes) {
		this.opcoes = opcoes;
	}
	// GETTERS E SETTERS----------------

	
	// Imprime todas as opções do Menu 
	public void mostrarMenu() {
		System.out.println("---------------------------------Menu-----------------------------------\n" + 
				"--------------------------------------------------------------------------");
		
		for(int i=0;i<opcoes.length-1;i++) {
			if(opcoes[i] != null) {
				System.out.printf(opcoes[i].getNome() + " - R$ %.2f "  + "- " + opcoes[i].getCategoria() +
						" - " + "%.0fg\n", opcoes[i].getPreco(), opcoes[i].getPeso());
				
				System.out.println("--------------------------------------------------------------------------\n" + 
						"--------------------------------------------------------------------------");
			}
		}
	}
	
	// procura por uma comida no Menu e se achar, remove ela do menu e a retorna
	public Comida pegarComida(String nome) {
		Comida comida;
		for(int i=0;i<opcoes.length-1;i++) {
			if(opcoes[i] != null && opcoes[i].getNome() == nome) {
				comida = opcoes[i];
				opcoes[i] = null;
				return comida;				
			}
		}
		return null;
	}
	
	// mostra o menu do restaurante filtrando uma categoria de comida
	public void mostrarMenu(String categoriaComida) {
		System.out.println("---------------------------------Menu-----------------------------------\n" + 
				"--------------------------------------------------------------------------");
		
		for(int i=0;i<opcoes.length-1;i++) {
			if(opcoes[i] != null && opcoes[i].getCategoria() == categoriaComida) {
				System.out.printf(opcoes[i].getNome() + " - R$ %.2f - " + opcoes[i].getCategoria() +
						" -" + "%.0f\n", opcoes[i].getPreco(), opcoes[i].getPeso());
				
				System.out.println("--------------------------------------------------------------------------\n" + 
						"--------------------------------------------------------------------------");
			}
		}
	}
		
	
	
	// adiciona uma comida no menu em uma quantidade passada por parâmetro se a quantidade for maior que 0
	public void adicionarComida(Comida comida, int quantidade) {
		int i=0;
		while(i<opcoes.length-1 && quantidade !=0) {
			if(opcoes[i] == null) {
				opcoes[i] = comida;
				quantidade--;
			}
			i++;			
		}
		
	}
	
	
	
	
	
}

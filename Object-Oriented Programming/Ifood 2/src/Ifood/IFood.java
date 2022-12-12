package Ifood;

public class IFood {
	private float taxaEntrega;
	private Menu menu;
	
	// construtor vazio iFood
	public IFood() {}
	
	// construtor iFood
	public IFood(float taxaEntrega, int num_opcoes) {
		this.taxaEntrega = taxaEntrega;
		
		// cria um novo menu do tamanho passado como parâmetro quando se cria um restaurante
		Menu novo_menu = new Menu(num_opcoes);
		this.menu = novo_menu;
		
	}
	
	// GETTERS E SETTERS----------------
	public void setTaxaEntrega(float taxaEntrega) {
		this.taxaEntrega = taxaEntrega;
	}

	public void setMenu(Menu menu) {
		this.menu = menu;
	}

	public Menu getMenu() {
		return menu;
	}

	public float getTaxaEntrega() {
		return taxaEntrega;
	}
	// GETTERS E SETTERS----------------
	
	// cria uma nova entega com todos os itens do carrinho do cliente e se ele puder pagar retorn entrega
	public Entrega realizarEntrega(Cliente cliente) {
		Entrega entrega = new Entrega(cliente, cliente.getCarrinho());
		if(this.cobrarEntrega(cliente)) {
			return entrega;
		}
		return null;
	}
	
	// cobra o cliente e se ele puder pagar debita da conta dele com pagar carrinho
	private boolean cobrarEntrega(Cliente cliente) {
		if(cliente.pagarCarrinho()) {
			return true;
		}
		return false;
		
	}
	public void retornarComida(Carrinho carrinho) {
		for(int i=0;i<carrinho.getComidasCompradas().length-1;i++) {
			if(carrinho.getComidasCompradas()[i] != null) {
				menu.adicionarComida(carrinho.getComidasCompradas()[i], 1);
				carrinho.getComidasCompradas()[i] = null;
			}
			
		}
		
		
	}
}

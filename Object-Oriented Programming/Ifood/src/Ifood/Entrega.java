package Ifood;

public class Entrega {
	private Cliente cliente;
	private Carrinho carrinho;
	private float precoTotal;
	
	// construtor vazio entrega
	public Entrega() {}
	
	// construtor entrega
	public Entrega(Cliente cliente, Carrinho carrinho) {
		this.cliente = cliente;
		this.carrinho = carrinho;
		// calcula o preço total da entrega, total carrinho + taxa de entrega do restaurante
		this.precoTotal = carrinho.calcularPrecoTotal();
		
	}
	
	
	// GETTERS E SETTERS----------------
	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public Carrinho getCarrinho() {
		return carrinho;
	}

	public void setCarrinho(Carrinho carrinho) {
		this.carrinho = carrinho;
	}

	public void setPrecoTotal(float precoTotal) {
		this.precoTotal = precoTotal;
	}

	public float getPrecoTotal() {
		return precoTotal;
	}
	// GETTERS E SETTERS----------------

	// mostra uma entrega, Cliente + Carrinho + preço total
	public void verEntrega() {
		System.out.printf("Cliente: " + cliente.getNome() + "\nCarrinho: ");
		carrinho.verItens();
		System.out.printf("Preço Total: R$ %.2f\n\n", precoTotal);
	
		
	}

}

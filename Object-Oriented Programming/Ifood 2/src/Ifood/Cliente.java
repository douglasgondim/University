package Ifood;

public class Cliente {
	private Carrinho carrinho;
	private float dinheiro;
	private String endereco;
	private String nome;
	
	// cosntrutor vazio Cliente
	public Cliente() {}
	
	// construtor cliente
	public Cliente(float dinheiro, String endereco, String nome) {
		this.dinheiro = dinheiro;
		this.endereco = endereco;
		this.nome = nome;
		this.carrinho = null;
		
	}
	
	// GETTERS E SETTERS----------------
	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public void setCarrinho(Carrinho carrinho) {
		this.carrinho = carrinho;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setDinheiro(float dinheiro) {
		this.dinheiro = dinheiro;
	}

	public float getDinheiro() {
		return dinheiro;
	}

	public Carrinho getCarrinho() {
		return carrinho;
	}

	public String getNome() {
		return nome;
	}
	
	// GETTERS E SETTERS----------------
	
	// se o cliente tiver carrinho, e tiver dinheiro para pagalo, debita o dinheiro 
	// da conta dele e retorna true
	public boolean pagarCarrinho() {
		if(carrinho!= null) {
			if(dinheiro>=carrinho.calcularPrecoTotal()) {
				dinheiro = dinheiro - carrinho.calcularPrecoTotal();
				return true;
			}
			
		}
		return false;	
	}
	
	// pede ao restaurante para criar carrinho e o liga ao cliente que pediu
	public void obterCarrinho(Restaurante restaurante) {
		this.carrinho = restaurante.criarCarrinho();
		
	}
}

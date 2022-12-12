package Ifood;

public class CartaoDesconto {
	private float porcentagemDesconto;
	private int quantidadeUso;
	private Restaurante restaurante;
	
	// construtor vazio do cartao desconto
	public CartaoDesconto() {}
	
	// construtor cartao desconto
	public CartaoDesconto(float porcentagemDesconto, int quantidadeUso, Restaurante restaurante) {
		this.porcentagemDesconto = porcentagemDesconto;
		this.quantidadeUso = quantidadeUso;
		this.restaurante = restaurante;
	}
	
	// GETTERS E SETTERS----------------
	public void setPorcentagemDesconto(float porcentagemDesconto) {
		this.porcentagemDesconto = porcentagemDesconto;
	}

	public void setQuantidadeUso(int quantidadeUso) {
		this.quantidadeUso = quantidadeUso;
	}

	public void setRestaurante(Restaurante restaurante) {
		this.restaurante = restaurante;
	}

	public Restaurante getRestaurante() {
		return restaurante;
	}

	public float getPorcentagemDesconto() {
		return porcentagemDesconto;
	}

	public int getQuantidadeUso() {
		return quantidadeUso;
	}
	
	// GETTERS E SETTERS----------------

	
	// calcula o desconto em reais do carrinho para o cliente vip
	public float calcularDesconto(Carrinho carrinho) {
		return carrinho.calcularPrecoTotal()*(porcentagemDesconto/100);		
		
	}
	
	// decrementa o uso do cartao (gasta o credito)
	public void utilizarCartao() {
		quantidadeUso--;
	}
	
	

}

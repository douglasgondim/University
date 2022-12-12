package Ifood;

public class ClienteVip extends Cliente {
	private CartaoDesconto cartao;
	
	// construtor vazio Cliente Vip
	public ClienteVip() {}
	
	// construtor Cliente Vip
	public ClienteVip(float dinheiro, String endereco, String nome) {
		super(dinheiro, endereco, nome);
		this.cartao = null;
		
	}
	
	
	// GETTERS E SETTERS----------------
	public void setCartao(CartaoDesconto cartao) {
		this.cartao = cartao;
	}

	public CartaoDesconto getCartao() {
		return cartao;
	}
	// GETTERS E SETTERS----------------
	
	// se o cliente tiver um carrinho e um cartao, o cartao tiver credito e pertencer ao restaurante que
	// o cliente quer comprar
	// se o cliente tiver dinheiro suficiente, pagar o carrinho com o desconto do cartao e diminuir a vida do cartao
	public boolean pagarCarrinhoComCartao() {
		if(this.getCarrinho()!= null && cartao != null && cartao.getQuantidadeUso()>0 && 
				this.getCarrinho().getiFood()==cartao.getRestaurante().getiFood()) {
			if(this.getDinheiro()>= this.getCarrinho().calcularPrecoTotal() - cartao.calcularDesconto(this.getCarrinho())) {
				this.setDinheiro(this.getDinheiro() - (this.getCarrinho().calcularPrecoTotal() - cartao.calcularDesconto(this.getCarrinho())));
				cartao.utilizarCartao();
				return true;		
			}
						
		}
		return false;
		
	}
	
	// se o cliente tiver dinheiro para comprar o cartao desconto do restaurante,
	// debitar o valor do cartao no cliente e pedir ao restaurante para gerar um cartao 
	// para entao liga-lo ao cliente que solicitou
	public void comprarCartaoDesconto(Restaurante restaurante) {
		if(this.getDinheiro()>restaurante.getPrecoCartaoDesconto()) {
			this.setDinheiro(this.getDinheiro()-restaurante.getPrecoCartaoDesconto());
			this.cartao = restaurante.gerarCartaoDesconto(this);
		}
		
	}

}

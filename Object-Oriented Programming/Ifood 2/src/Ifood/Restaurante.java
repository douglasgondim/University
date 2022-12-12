package Ifood;

public class Restaurante {
	private String nome;
	private IFood iFood;
	private float dinheiro;
	private HistoricoEntregas historicoEntregas;
	private float precoCartaoDesconto;
	private int quantidadeUsoCartaoDesconto;
	private float porcentagemDescontoCartaoDesconto;
	
	// construtor vazio do resturante
	public Restaurante() {}
	
	// construtor restaurante
	// os parâmetros num_opcoes e tam_historico determinam o tamanho do vetor de opções do menu
	// e o tamanho do histórico do restaurante criado, respectivamente.
	public Restaurante(String nome, float dinheiro, float precoCartaoDesconto, int quantidadeUsoCartaoDesconto, 
			float porcentagemDescontoCartaoDesconto, int num_opcoes, float taxaEntrega, int tam_historico) {
		
		this.nome = nome;
		this.dinheiro = dinheiro;
		this.precoCartaoDesconto = precoCartaoDesconto;
		this.quantidadeUsoCartaoDesconto = quantidadeUsoCartaoDesconto;
		this.porcentagemDescontoCartaoDesconto = porcentagemDescontoCartaoDesconto;
		
		// cria novo iFood e o liga ao restaurante
		IFood novo_iFood = new IFood(taxaEntrega, num_opcoes);
		this.iFood = novo_iFood;
		
		// cria novo histórico de entregas e o liga ao restaurante
		HistoricoEntregas novo_historico = new HistoricoEntregas(tam_historico);
		this.historicoEntregas = novo_historico;
				
	}
	
	
	// GETTERS E SETTERS----------------
	public HistoricoEntregas getHistoricoEntregas() {
		return historicoEntregas;
	}

	public void setHistoricoEntregas(HistoricoEntregas historicoEntregas) {
		this.historicoEntregas = historicoEntregas;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setiFood(IFood iFood) {
		this.iFood = iFood;
	}

	public void setPrecoCartaoDesconto(float precoCartaoDesconto) {
		this.precoCartaoDesconto = precoCartaoDesconto;
	}

	public void setQuantidadeUsoCartaoDesconto(int quantidadeUsoCartaoDesconto) {
		this.quantidadeUsoCartaoDesconto = quantidadeUsoCartaoDesconto;
	}

	public void setPorcentagemDescontoCartaoDesconto(float porcentagemDescontoCartaoDesconto) {
		this.porcentagemDescontoCartaoDesconto = porcentagemDescontoCartaoDesconto;
	}

	public String getNome() {
		return nome;
	}

	public IFood getiFood() {
		return iFood;
	}

	public float getDinheiro() {
		return dinheiro;
	}

	public void setDinheiro(float dinheiro) {
		this.dinheiro = dinheiro;
	}

	public float getPrecoCartaoDesconto() {
		return precoCartaoDesconto;
	}

	public int getQuantidadeUsoCartaoDesconto() {
		return quantidadeUsoCartaoDesconto;
	}

	public float getPorcentagemDescontoCartaoDesconto() {
		return porcentagemDescontoCartaoDesconto;
	}
	
	// GETTERS E SETTERS----------------

	// cria carrinho atrelado ao iFood do restaurante e o retorna
	public Carrinho criarCarrinho() {
		Carrinho novo_carrinho = new Carrinho(iFood);
		return novo_carrinho;
		
	}
	
	// gera um cartão desconto para um cliente VIP e o retorna
	public CartaoDesconto gerarCartaoDesconto(ClienteVip clienteVip) {
		CartaoDesconto novo_cartao = new CartaoDesconto(porcentagemDescontoCartaoDesconto, quantidadeUsoCartaoDesconto,
				this);
		return novo_cartao;
			
	}
	
	// entrega a comida de um cliente, debita dele quando chama cobrarEntrega() e adiciona o valor
	// no dinheiro do restaurante. Adiciona a entrega no histórico de entregas do restaurante e então esvazia
	// o carrinho do cliente
	public void EntregarComida(Cliente cliente) {
		Entrega entrega = this.iFood.realizarEntrega(cliente);
		if(entrega != null) {
			this.dinheiro = this.dinheiro + entrega.getPrecoTotal();
			this.historicoEntregas.registrarEntrega(entrega);
			for(int i=0;i<cliente.getCarrinho().getComidasCompradas().length-1;i++) {
				cliente.getCarrinho().getComidasCompradas()[i] = null;
				
			}
			
		}
		
		
	}
	
	
}

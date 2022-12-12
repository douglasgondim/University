package uber;

public class Motorista {
	String nome;
	int posicao_inicial;
	int posicao_atual;
	float taxa_cancelamento;
	float prob_cancelamento;
	float dinheiro;
	Carro carro;
	boolean ocupado;
	float tarifa_por_km;
	int tempo_ocupado;
	
	public Motorista() {}
	
	public Motorista(String nome, int posicao_inicial, float taxa_cancelamento, float prob_cancelamento) {
		this.nome = nome;
		this.posicao_inicial = posicao_inicial;
		this.posicao_atual = posicao_inicial;
		this.taxa_cancelamento = taxa_cancelamento;
		this.prob_cancelamento = prob_cancelamento;
		this.carro = new Carro();
		this.dinheiro = 0;
		this.tarifa_por_km = 1;
		
	}
	
	private void receberPagamento(Requisicao requisicao) {
		dinheiro += (float)requisicao.getCorrida().calcularValor()*0.75;
		requisicao.getUber().receberTaxa((float)(requisicao.getCorrida().calcularValor()*0.25));
		
	}
	
	public boolean aceitarRequisicao(Requisicao requisicao) {
		if(ocupado==false && tempo_ocupado==0) {
			requisicao.gerarCorrida(requisicao, this);
			ocupado = true;
			tempo_ocupado = (int)(requisicao.getCorrida().getDuracao()/10);
			receberPagamento(requisicao);
			return true;
		}
			tempo_ocupado--;
			if(tempo_ocupado==0) {
				ocupado = false;
			}
		return false;
		
	}
	public void atualizarPosicao(Requisicao requisicao) {
		posicao_atual = requisicao.getCliente().getPonto_chegada();
		
	}
	
	public float buscarClienteDistancia(Requisicao requisicao) {
		return requisicao.getUber().getCidade().acharMenorDistancia(posicao_atual, requisicao.getCliente().getPonto_partida());
		
				
		
		
	}
	
	// ---------------------------------- INICIO GETTERS E SETTERS -----------------------------------

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getPosicao_inicial() {
		return posicao_inicial;
	}

	public void setPosicao_inicial(int posicao_inicial) {
		this.posicao_inicial = posicao_inicial;
	}

	public float getTaxa_cancelamento() {
		return taxa_cancelamento;
	}

	public void setTaxa_cancelamento(float taxa_cancelamento) {
		this.taxa_cancelamento = taxa_cancelamento;
	}

	public float getProb_cancelamento() {
		return prob_cancelamento;
	}

	public void setProb_cancelamento(float prob_cancelamento) {
		this.prob_cancelamento = prob_cancelamento;
	}

	public float getDinheiro() {
		return dinheiro;
	}

	public void setDinheiro(float dinheiro) {
		this.dinheiro = dinheiro;
	}

	public Carro getCarro() {
		return carro;
	}

	public void setCarro(Carro carro) {
		this.carro = carro;
	}

	public boolean isOcupado() {
		return ocupado;
	}

	public void setOcupado(boolean ocupado) {
		this.ocupado = ocupado;
	}

	public float getTarifa_por_km() {
		return tarifa_por_km;
	}

	public void setTarifa_por_km(float tarifa_por_km) {
		this.tarifa_por_km = tarifa_por_km;
	}

	public int getPosicao_atual() {
		return posicao_atual;
	}

	public void setPosicao_atual(int posicao_atual) {
		this.posicao_atual = posicao_atual;
	}
	
	
	// ---------------------------------- FIM GETTERS E SETTERS -----------------------------------
	
	

}

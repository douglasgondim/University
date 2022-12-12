package uber;

public class Corrida {
	public static long corrida_id_count = 0;
	private long id;
	private Requisicao requisicao;
	private Motorista motorista;
	private float valor;
	private float duracao;
	private float distancia_Km;
	private float tempo_busca_cliente;
	
	
	public Corrida() {}
	
	public Corrida(Requisicao requisicao, Motorista motorista) {
		this.requisicao = requisicao;
		this.motorista = motorista;
		calcularDistanciaKm();
		calcularTempoCorrida();
		calcularTempoBuscaCliente();
		this.tempo_busca_cliente = 
		this.id = corrida_id_count;
		corrida_id_count++;
		
	}
	
	public float calcularValor() {
		this.valor = distancia_Km*motorista.getTarifa_por_km();
		return valor;
		
	}
	private void calcularTempoCorrida() {
		this.duracao = ((distancia_Km)/motorista.getCarro().getVelocidade())*60;
		
	}
	private void calcularDistanciaKm() {
		this.distancia_Km = requisicao.getUber().getCidade().acharMenorDistancia(requisicao.getCliente().getPonto_partida(),
				requisicao.getCliente().getPonto_chegada());
		
	}
	private void calcularTempoBuscaCliente() {
		this.tempo_busca_cliente = motorista.getCarro().getVelocidade()/motorista.buscarClienteDistancia(requisicao);
	}

	public static long getCorrida_id_count() {
		return corrida_id_count;
	}

	public static void setCorrida_id_count(long corrida_id_count) {
		Corrida.corrida_id_count = corrida_id_count;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public Requisicao getRequisicao() {
		return requisicao;
	}

	public void setRequisicao(Requisicao requisicao) {
		this.requisicao = requisicao;
	}

	public Motorista getMotorista() {
		return motorista;
	}

	public void setMotorista(Motorista motorista) {
		this.motorista = motorista;
	}

	public float getValor() {
		return valor;
	}

	public void setValor(float valor) {
		this.valor = valor;
	}

	public float getDuracao() {
		return duracao;
	}

	public void setDuracao(float duracao) {
		this.duracao = duracao;
	}

	public float getDistancia_Km() {
		return distancia_Km;
	}

	public void setDistancia_Km(float distancia_Km) {
		this.distancia_Km = distancia_Km;
	}

	public float getTempo_busca_cliente() {
		return tempo_busca_cliente;
	}

	public void setTempo_busca_cliente(float tempo_busca_cliente) {
		this.tempo_busca_cliente = tempo_busca_cliente;
	}

	

}

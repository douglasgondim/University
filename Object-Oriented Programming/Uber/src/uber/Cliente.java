package uber;

public class Cliente {
	private String nome;
	private int ponto_partida;
	private int ponto_chegada;
	private int num_tentativas;
	private boolean atendido;
	private boolean desistiu;
	
	public Cliente(){}
	
	public Cliente(String nome, int ponto_partida, int ponto_chegada){
		this.nome = nome;
		this.ponto_partida = ponto_partida;
		this.ponto_chegada = ponto_chegada;
		this.num_tentativas = 0;		
		
	}
	
	public Requisicao chamarUber(Uber uber) {
		Requisicao r1 = new Requisicao(this, uber);
		Motorista m1 = r1.acharMotorista(r1.getUber());
		if(m1 != null) {
			for(int i=0;i<uber.getMotoristas().length;i++) {
				if(uber.getMotoristas()[i].getNome()== m1.getNome()) {
					uber.getMotoristas()[i].atualizarPosicao(r1);
				}
			}
			atendido = true;
			return r1;
		}
		contarTentativas();
		
		if(num_tentativas>=2) {
			desistiu = true;
		}
		
		return r1;
		
	}
	
	public void contarTentativas() {
		num_tentativas++;
	}
	
	// ---------------------------------- INICIO GETTERS E SETTERS -----------------------------------

	public String getNome() {
		return nome;
	}

	public boolean isDesistiu() {
		return desistiu;
	}

	public void setDesistiu(boolean desistiu) {
		this.desistiu = desistiu;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getPonto_partida() {
		return ponto_partida;
	}

	public void setPonto_partida(int ponto_partida) {
		this.ponto_partida = ponto_partida;
	}

	public int getPonto_chegada() {
		return ponto_chegada;
	}

	public void setPonto_chegada(int ponto_chegada) {
		this.ponto_chegada = ponto_chegada;
	}

	public int getNum_tentativas() {
		return num_tentativas;
	}

	public void setNum_tentativas(int num_tentativas) {
		this.num_tentativas = num_tentativas;
	}

	public boolean isAtendido() {
		return atendido;
	}

	public void setAtendido(boolean atendido) {
		this.atendido = atendido;
	}
	
	// ---------------------------------- FIM GETTERS E SETTERS -----------------------------------
	

}

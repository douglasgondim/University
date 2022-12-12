package uber;

public class Requisicao {
	public long requisicao_id_count;
	private long id;
	private Cliente cliente;
	private Uber uber;
	private Corrida corrida;
	
	public Requisicao() {}
	
	public Requisicao(Cliente cliente, Uber uber) {
		this.cliente = cliente;
		this.uber = uber;
		this.id = requisicao_id_count;
		requisicao_id_count++;
		
	}
	
	public Motorista acharMotorista(Uber uber) {
		Motorista m1;
		Motorista m2;
		Motorista m3;
		

		m1 = uber.getMotoristas()[0];
		m2 = uber.getMotoristas()[0];
		m3 = uber.getMotoristas()[0];
		for(int j=0;j<uber.getMotoristas().length;j++ ) {
			if(uber.cidade.acharMenorDistancia(cliente.getPonto_partida(), uber.getMotoristas()[j].getPosicao_atual()) <= 
					uber.cidade.acharMenorDistancia(cliente.getPonto_partida(), m1.getPosicao_atual())) {
				m3 = m2;
				m2 = m1;
				m1 = uber.getMotoristas()[j];
				
			}
			
		}
		
		for(int i=0;i<uber.getMotoristas().length;i++) {
			if(uber.getMotoristas()[i].getNome()== m1.getNome()) {
				if(uber.getMotoristas()[i].aceitarRequisicao(this)) {
					return uber.getMotoristas()[i];
				}
				break;
				
			}
			
		}
		
		for(int i=0;i<uber.getMotoristas().length;i++) {
			if(uber.getMotoristas()[i].getNome()== m2.getNome()) {
				if(uber.getMotoristas()[i].aceitarRequisicao(this)) {
					return uber.getMotoristas()[i];
				}
				break;
				
			}
			
		}
		
		for(int i=0;i<uber.getMotoristas().length;i++) {
			if(uber.getMotoristas()[i].getNome()== m3.getNome()) {
				if(uber.getMotoristas()[i].aceitarRequisicao(this)) {
					return uber.getMotoristas()[i];
				}
				break;
				
			}
			
		}

		return null;	
		
		
	}
	
	public void gerarCorrida(Requisicao requisicao, Motorista motorista) {
		corrida = new Corrida(requisicao, motorista);
		
	}
	
	
	
	// ---------------------------------- INICIO GETTERS E SETTERS -----------------------------------

	public long getRequisicao_id_count() {
		return requisicao_id_count;
	}

	public void setRequisicao_id_count(long requisicao_id_count) {
		this.requisicao_id_count = requisicao_id_count;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public Uber getUber() {
		return uber;
	}

	public void setUber(Uber uber) {
		this.uber = uber;
	}

	public Corrida getCorrida() {
		return corrida;
	}

	public void setCorrida(Corrida corrida) {
		this.corrida = corrida;
	}
	
	
	
	
	
	
	
	// ---------------------------------- FIM GETTERS E SETTERS -----------------------------------
}

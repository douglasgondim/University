package Ifood;

public class HistoricoEntregas {
	private Entrega[] entregas;
	
	// construtor vazio Historico Entregas
	public HistoricoEntregas() {}
	
	// construtor Historico Entregas
	public HistoricoEntregas(int tam_historico) {
		// gera um novo histórico de entregas do tamanho passado como parâmetro quando se constroi um restaurante
		this.entregas = new Entrega[tam_historico];
		
	}
	
	
	// GETTERS E SETTERS----------------
	public Entrega[] getEntregas() {
		return entregas;
	}

	public void setEntregas(Entrega[] entregas) {
		this.entregas = entregas;
	}
	// GETTERS E SETTERS----------------
	
	// mostra todas as entregas no histórico
	public void mostrarEntregas() {
		for(int i=0; i<entregas.length-1;i++) {
			if(entregas[i]!= null) {
				entregas[i].verEntrega();
			}
		}
		
	}
	
	// se houver espaço no vetor de entregas, registrar uma entrega
	public void registrarEntrega(Entrega entrega) {
		for(int i=0;i<entregas.length-1;i++) {
			if(entregas[i]==null) {
				entregas[i] = entrega;
				break;
			}
		}
		
	}

}

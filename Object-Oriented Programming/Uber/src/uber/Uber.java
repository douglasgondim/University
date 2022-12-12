package uber;

public class Uber {
	Motorista[] motoristas;
	Cliente[] clientes;
	Cidade cidade;
	float dinheiro;
	
	
	public Uber() {
		criarCidade();
		lerArquivoClientes();
		lerArquivoMotoristas();
		this.dinheiro = 0;
	}
	
	public void receberTaxa(float taxa) {
		dinheiro += taxa;
		
	}
	private void criarCidade() {
		Cidade c1 = new Cidade();
		this.cidade = c1;
		
	}
	private void lerArquivoClientes() {
		LerArquivo leitor = new LerArquivo();
		leitor.abrirArquivoClientes();
		this.clientes = leitor.lerArquivoCliente();
		leitor.fecharArquivo();
	}
	
	private void lerArquivoMotoristas() {
		LerArquivo leitor = new LerArquivo();
		leitor.abrirArquivoMotoristas();
		this.motoristas = leitor.lerArquivoMotorista();
		leitor.fecharArquivo();
	}
	
	// ---------------------------------- INICIO GETTERS E SETTERS -----------------------------------


	public Motorista[] getMotoristas() {
		return motoristas;
	}

	public void setMotoristas(Motorista[] motoristas) {
		this.motoristas = motoristas;
	}

	public Cliente[] getClientes() {
		return clientes;
	}

	public void setClientes(Cliente[] clientes) {
		this.clientes = clientes;
	}

	public float getDinheiro() {
		return dinheiro;
	}

	public void setDinheiro(float dinheiro) {
		this.dinheiro = dinheiro;
	}

	public Cidade getCidade() {
		return cidade;
	}

	public void setCidade(Cidade cidade) {
		this.cidade = cidade;
	}
	
	
	// ---------------------------------- FIM GETTERS E SETTERS -----------------------------------

		
	}

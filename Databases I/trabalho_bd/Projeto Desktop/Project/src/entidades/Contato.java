package entidades;

public class Contato {
	private int pk_contato;
	private String endereco, cidade, estado, telefone, cep;
	
	public int getPk_contato() {
		return pk_contato;
	}
	public String getCep() {
		return cep;
	}
	public String getTelefone() {
		return telefone;
	}
	public String getEndereco() {
		return endereco;
	}
	public String getCidade() {
		return cidade;
	}
	public String getEstado() {
		return estado;
	}
	
	public void setPk_contato(int pk_contato) {
		this.pk_contato = pk_contato;
	}
	public void setCep(String cep) {
		this.cep = cep;
	}
	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	public void setCidade(String cidade) {
		this.cidade = cidade;
	}
	public void setEstado(String estado) {
		this.estado = estado;
	}	
	
}
package entidades;

public class Editora {
	private int pk_codigo;
	private String nome, contato, cnpj;
	
	public int getPk_codigo() {
		return pk_codigo;
	}
	public String getNome() {
		return nome;
	}
	public String getContato() {
		return contato;
	}
	public String getCnpj() {
		return cnpj;
	}
	
	public void setPk_codigo(int pk_codigo) {
		this.pk_codigo = pk_codigo;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public void setContato(String contato) {
		this.contato = contato;
	}
	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}
		
}

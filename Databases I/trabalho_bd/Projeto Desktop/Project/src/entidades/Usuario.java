package entidades;

public class Usuario {
	private String nome, foto;
	private String cpf, rg, fk_email;
	private int pk_id, fk_contato, limite_livro;
	
	public String getNome() {
		return nome;
	}
	public String getFoto() {
		return foto;
	}
	public String getCpf() {
		return cpf;
	}
	public String getRg() {
		return rg;
	}
	public int getPk_id() {
		return pk_id;
	}
	public String getFk_email() {
		return fk_email;
	}
	public int getFk_contato() {
		return fk_contato;
	}
	public int getLimite_livro() {
		return limite_livro;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	public void setFoto(String foto) {
		this.foto = foto;
	}
	public void setCpf(String cpf) {
		this.cpf = cpf;
	}
	public void setRg(String rg) {
		this.rg = rg;
	}
	public void setPk_id(int pk_id) {
		this.pk_id = pk_id;
	}
	public void setFk_email(String fk_email) {
		this.fk_email = fk_email;
	}
	public void setFk_contato(int fk_contato) {
		this.fk_contato = fk_contato;
	}
	public void setLimite_livro(int limite_livro) {
		this.limite_livro = limite_livro;
	}
	
}

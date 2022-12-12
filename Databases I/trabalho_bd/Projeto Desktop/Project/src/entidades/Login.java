package entidades;

public class Login {
	private String pk_email, senha;
	private boolean nivel;
	
	public String getSenha() {
		return senha;
	}
	public boolean isNivel() {
		return nivel;
	}
	public String getPk_email() {
		return pk_email;
	}
	
	public void setSenha(String senha) {
		this.senha = senha;
	}
	public void setNivel(Boolean nivel) {
		this.nivel = nivel;
	}
	public void setEmail(String pk_email) {
		this.pk_email = pk_email;
	}	
	
}

package entidades;

public class Exemplar {
	private String estado;
	private int pk_cod_exemp, fk_cod_livro, edicao, ano;
	private boolean disp;
	
	public String getEstado() {
		return estado;
	}
	public int getPk_cod_exemp() {
		return pk_cod_exemp;
	}
	public int getFk_cod_livro() {
		return fk_cod_livro;
	}
	public int getEdicao() {
		return edicao;
	}
	public int getAno() {
		return ano;
	}
	public boolean isDisp() {
		return disp;
	}
	
	public void setEstado(String estado) {
		this.estado = estado;
	}
	public void setPk_cod_exemp(int pk_cod_exemp) {
		this.pk_cod_exemp = pk_cod_exemp;
	}
	public void setFk_cod_livro(int fk_cod_livro) {
		this.fk_cod_livro = fk_cod_livro;
	}
	public void setEdicao(int edicao) {
		this.edicao = edicao;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	public void setDisp(boolean disp) {
		this.disp = disp;
	}
	
}

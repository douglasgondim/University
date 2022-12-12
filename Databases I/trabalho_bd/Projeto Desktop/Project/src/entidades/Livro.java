package entidades;

public class Livro {
	private int pk_cod_livro, fk_id_autor, fk_id_editora, num_pags, qtd_exemp, ano_publicacao;
	private String titulo, genero, capa, sumario, pais, palavras_chave;
	public int getPk_cod_livro() {
		return pk_cod_livro;
	}
	public int getFk_id_autor() {
		return fk_id_autor;
	}
	public int getFk_id_editora() {
		return fk_id_editora;
	}
	public int getNum_pags() {
		return num_pags;
	}
	public int getQtd_exemp() {
		return qtd_exemp;
	}
	public String getTitulo() {
		return titulo;
	}
	public String getGenero() {
		return genero;
	}
	public String getCapa() {
		return capa;
	}
	public String getSumario() {
		return sumario;
	}
	public String getPais() {
		return pais;
	}
	public String getPalavras_chave() {
		return palavras_chave;
	}
	public int getAno_publicacao() {
		return ano_publicacao;
	}
	
	public void setPk_cod_livro(int pk_cod_livro) {
		this.pk_cod_livro = pk_cod_livro;
	}
	public void setFk_id_autor(int fk_id_autor) {
		this.fk_id_autor = fk_id_autor;
	}
	public void setFk_id_editora(int fk_id_editora) {
		this.fk_id_editora = fk_id_editora;
	}
	public void setNum_pags(int num_pags) {
		this.num_pags = num_pags;
	}
	public void setQtd_exemp(int qtd_exemp) {
		this.qtd_exemp = qtd_exemp;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public void setGenero(String genero) {
		this.genero = genero;
	}
	public void setCapa(String capa) {
		this.capa = capa;
	}
	public void setSumario(String sumario) {
		this.sumario = sumario;
	}
	public void setPais(String pais) {
		this.pais = pais;
	}
	public void setPalavras_chave(String palavras_chave) {
		this.palavras_chave = palavras_chave;
	}
	public void setAno_publicacao(int ano_publicacao) {
		this.ano_publicacao = ano_publicacao;
	}
	
}

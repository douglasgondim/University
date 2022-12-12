package entidades;

public class Autor {
	private int pk_id_autor;
	private String nome, biografia, foto;
	
	public int getId_autor() {
		return pk_id_autor;
	}
	public String getNome() {
		return nome;
	}
	public String getBiografia() {
		return biografia;
	}
	public String getFoto() {
		return foto;
	}
		
	public void setId_autor(int pk_id_autor) {
		this.pk_id_autor = pk_id_autor;
	}
	public void setNome(String nome) {
		if(nome != null) {
			this.nome = nome;
		}
	}
	public void setBiografia(String biografia) {
		if(biografia != null) {
			this.biografia = biografia;
		}
	}
	public void setFoto(String foto) {
		if(foto != null) {
			this.foto = foto;
		}
	}
	
}

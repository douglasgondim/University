package entidades;

import java.util.*;

public class Reserva {
	private int pk_codigo, fk_id_usuario, fk_cod_livro;
	private Date data_limite;
	private boolean disponivel;
	
	public int getPk_codigo() {
		return pk_codigo;
	}
	public int getFk_id_usuario() {
		return fk_id_usuario;
	}
	public int getFk_cod_livro() {
		return fk_cod_livro;
	}
	public Date getData_limite() {
		return data_limite;
	}
	public boolean isDisponivel() {
		return disponivel;
	}
	
	public void setPk_codigo(int pk_codigo) {
		this.pk_codigo = pk_codigo;
	}
	public void setFk_id_usuario(int fk_id_usuario) {
		this.fk_id_usuario = fk_id_usuario;
	}
	public void setFk_cod_livro(int fk_cod_livro) {
		this.fk_cod_livro = fk_cod_livro;
	}
	public void setData_limite(Date data_limite) {
		this.data_limite = data_limite;
	}
	public void setDisponivel(boolean disponivel) {
		this.disponivel = disponivel;
	}
	
}

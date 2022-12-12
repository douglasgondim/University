package entidades;

import java.util.*;

public class Emprestimo {
	private int pk_codigo, fk_cod_exemp, fk_id_usuario, fk_id_bibliotecario;
	private Date data_retirada;
	
	public int getPk_codigo() {
		return pk_codigo;
	}
	public int getFk_cod_exemp() {
		return fk_cod_exemp;
	}
	public int getFk_id_usuario() {
		return fk_id_usuario;
	}
	public int getFk_id_bibliotecario() {
		return fk_id_bibliotecario;
	}
	public Date getData_retirada() {
		return data_retirada;
	}
	
	public void setPk_codigo(int pk_codigo) {
		this.pk_codigo = pk_codigo;
	}
	public void setFk_cod_exemp(int fk_cod_exemp) {
		this.fk_cod_exemp = fk_cod_exemp;
	}
	public void setFk_id_usuario(int fk_id_usuario) {
		this.fk_id_usuario = fk_id_usuario;
	}
	public void setFk_id_bibliotecario(int fk_id_bibliotecario) {
		this.fk_id_bibliotecario = fk_id_bibliotecario;
	}
	public void setData_retirada(Date data_retirada) {
		this.data_retirada = data_retirada;
	}
	
}

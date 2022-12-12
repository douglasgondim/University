package entidades;

import java.util.*;

public class Devolucao {
	private int pk_codigo, fk_cod_emp, fk_cod_exemp, fk_id_bibliotecario;
	private float multa;
	private Date data_limite, data_devolucao;
	
	public int getPk_codigo() {
		return pk_codigo;
	}
	public int getFk_cod_emp() {
		return fk_cod_emp;
	}
	public int getFk_cod_exemp() {
		return fk_cod_exemp;
	}
	public int getFk_id_bibliotecario() {
		return fk_id_bibliotecario;
	}
	public float getMulta() {
		return multa;
	}
	public Date getData_limite() {
		return data_limite;
	}
	public Date getData_devolucao() {
		return data_devolucao;
	}
	
	public void setPk_codigo(int pk_codigo) {
		this.pk_codigo = pk_codigo;
	}
	public void setFk_cod_emp(int fk_cod_emp) {
		this.fk_cod_emp = fk_cod_emp;
	}
	public void setFk_cod_exemp(int fk_cod_exemp) {
		this.fk_cod_exemp = fk_cod_exemp;
	}
	public void setFk_id_bibliotecario(int fk_id_bibliotecario) {
		this.fk_id_bibliotecario = fk_id_bibliotecario;
	}
	public void setMulta(float multa) {
		this.multa = multa;
	}
	public void setData_limite(Date data_limite) {
		this.data_limite = data_limite;
	}
	public void setData_devolucao(Date data_devolucao) {
		this.data_devolucao = data_devolucao;
	}
	
}

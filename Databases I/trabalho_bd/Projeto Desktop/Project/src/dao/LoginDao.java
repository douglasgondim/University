package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import entidades.Login;

public class LoginDao {
	public void insert(Login l) {
		String sql = "INSERT INTO Login (pk_email, senha, nivel) VALUES (?, ?, ?)";
		
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, l.getPk_email());
			usr.setString(2, l.getSenha());
			usr.setBoolean(3, l.isNivel());
			
			usr.execute();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public boolean verificar(String nome, String senha, int nivel) {	
		String sql = "SELECT * FROM Login WHERE pk_email = ? AND senha = ?";
		boolean n = false;
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, nome);
			usr.setString(2, senha);
			
			ResultSet rs = usr.executeQuery();
			
			if(nivel == 1) {
				if(rs.next() && rs.getInt("nivel") == 1) {
					n = true;
				}				
			}else {
				if(rs.next()) {
					n = true;
				}
			}
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return n;
	}
	
	public boolean verifEmail(String email) {
		String sql = "SELECT * FROM Login WHERE pk_email = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, email);
			
			ResultSet rs = usr.executeQuery();

			if (rs.next()) {
				return true;
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return false;
	}
	
}

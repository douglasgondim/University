package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import entidades.Contato;

public class ContatoDao {
	public void insert(Contato c) {
		String sql = "INSERT INTO Contato (telefone, endereco, cidade, estado, cep) VALUES (?, ?, ?, ?, ?)";
		
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, c.getTelefone());
			usr.setString(2, c.getEndereco());
			usr.setString(3, c.getCidade());
			usr.setString(4, c.getEstado());
			usr.setString(5, c.getCep());			
			
			usr.execute();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public int buscar(Contato c) {
		String sql = "SELECT pk_contato FROM Contato WHERE telefone = ? AND endereco = ? AND cidade = ? AND estado = ? AND cep = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, c.getTelefone());
			usr.setString(2, c.getEndereco());
			usr.setString(3, c.getCidade());
			usr.setString(4, c.getEstado());
			usr.setString(5, c.getCep());
			
			ResultSet rs = usr.executeQuery();
			
			if(rs.next()) {
				return rs.getInt("pk_contato");
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return 0;
	}
}

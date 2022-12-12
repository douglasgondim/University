package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import entidades.Editora;

public class EditoraDao {
	public void insert(Editora e) {
		String sql = "INSERT INTO Editora (nome, contato, cnpj) VALUES (?, ?, ?)";
		
		try {
			PreparedStatement edit = Conector.getConexao().prepareStatement(sql);
			edit.setString(1, e.getNome());
			edit.setString(2, e.getContato());
			edit.setString(3, e.getCnpj());
			
			edit.execute();
			
		} catch (SQLException exc) {
			exc.printStackTrace();
		}
		
	}
	
	public String getPk_codigo(String nome) {
		String sql = "SELECT pk_codigo FROM Editora WHERE nome LIKE ?";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setString(1, "%"+nome+"%");
			liv.execute();
			
			ResultSet rs = liv.executeQuery();
			
			if(rs.next()) {
				return String.valueOf(rs.getInt("pk_codigo"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
}

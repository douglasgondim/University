package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import entidades.Autor;

public class AutorDao {
	public void insert(Autor a) {
		String sql = "INSERT INTO Autor (nome, biografia, foto) VALUES (?, ?, ?)";
		
		try {
			PreparedStatement aut = Conector.getConexao().prepareStatement(sql);
			aut.setString(1, a.getNome());
			aut.setString(2, a.getBiografia());
			aut.setString(3, a.getFoto());
			
			aut.execute();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public String getPk_id_autor(String nome) {
		String sql = "SELECT pk_id_autor FROM Autor WHERE nome LIKE ?";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setString(1, "%"+nome+"%");						
			liv.execute();
			
			ResultSet rs = liv.executeQuery();
			
			if(rs.next()) {
				return String.valueOf(rs.getInt("pk_id_autor"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
}

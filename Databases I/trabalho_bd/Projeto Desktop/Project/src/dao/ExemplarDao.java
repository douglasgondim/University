package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import entidades.Exemplar;

public class ExemplarDao {
	public void insert(Exemplar e) {
		String sql = "INSERT INTO Exemplar (fk_cod_livro, edicao, ano, estado, disp) VALUES (?, ?, ?, ?, ?)";
		
		try {
			PreparedStatement exm = Conector.getConexao().prepareStatement(sql);
			exm.setInt(1, e.getFk_cod_livro());
			exm.setInt(2, e.getEdicao());
			exm.setInt(3, e.getAno());
			exm.setString(4, e.getEstado());
			exm.setBoolean(5, e.isDisp());
						
			exm.execute();
			
		} catch (SQLException exc) {
			exc.printStackTrace();
		}
	}
	
	public boolean dispExemplar(int pk_cod_exemp) {
		String sql = "SELECT * FROM Exemplar WHERE pk_cod_exemp = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setInt(1, pk_cod_exemp);
			
			ResultSet rs = usr.executeQuery();
			
			if(rs.next() && rs.getInt("disp") == 1) {
				return true;
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public String getPk_cod_exemp(int cod_livro) {
		String sql = "SELECT pk_cod_exemp FROM Exemplar WHERE fk_cod_livro = ? ORDER BY pk_cod_exemp DESC LIMIT 1";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setInt(1, cod_livro);
			liv.execute();
			
			ResultSet rs = liv.executeQuery();
			
			if(rs.next()) {
				return String.valueOf(rs.getInt("pk_cod_exemp"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

}

package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class DevolucaoDao {
	public void insert(int fk_cod_exemp, String id_bibliotecario) {
		String sql = "INSERT INTO Devolucao (fk_cod_exemp, data_devolucao, fk_id_bibliotecario, fk_cod_emp) VALUES (?, (SELECT CURRENT_DATE()), (SELECT pk_id FROM Usuario AS U JOIN Login AS L ON U.fk_email = L.pk_email WHERE L.pk_email = ?), (SELECT pk_codigo FROM Emprestimo WHERE fk_cod_exemp = ? ORDER BY pk_codigo DESC LIMIT 1))";
		
		try {
			PreparedStatement dev = Conector.getConexao().prepareStatement(sql);
			dev.setInt(1, fk_cod_exemp);
			dev.setString(2, id_bibliotecario);
			dev.setInt(3, fk_cod_exemp);
			
			dev.execute();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void delete() {
		
	}
	
	public void update() {
		
	}
	
	public void busca(String valor, ArrayList<Object> vec) {
		String sql = "SELECT * FROM (Devolucao as D join Emprestimo as E on D.fk_cod_emp = E.pk_codigo join Usuario as U on E.fk_id_usuario = U.pk_id join Exemplar as Ex on D.fk_cod_exemp = Ex.pk_cod_exemp join Livro as L on Ex.fk_cod_livro = L.pk_cod_livro) WHERE U.nome LIKE ? || L.titulo LIKE ? || D.pk_codigo = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, "%"+valor+"%");
			usr.setString(2, "%"+valor+"%");
			if(valor.matches("[0-9]*") && !valor.isEmpty()) {
				usr.setInt(3, Integer.parseInt(valor));
			}else {
				usr.setInt(3, 0);
			}
			
			ResultSet rs = usr.executeQuery();
			
			while(rs.next()) {
				vec.add(rs.getString("U.nome"));
				vec.add(rs.getString("L.titulo"));
				vec.add(rs.getDate("D.data_devolucao"));
				vec.add(rs.getDouble("D.multa"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public double valorMulta(int fk_cod_exemp) {
		String sql = "SELECT multa FROM Devolucao WHERE fk_cod_exemp = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setInt(1, fk_cod_exemp);
			
			ResultSet rs = usr.executeQuery();
			
			if(rs.next()) {
				return rs.getDouble("multa");
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return 0.0;
	}
	
}

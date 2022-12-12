package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class EmprestimoDao {
	public void insert(String id_usuario, int cod_exemp, String id_bibliotecario) {
		String sql = "INSERT INTO Emprestimo (fk_cod_exemp, data_retirada, fk_id_usuario, fk_id_bibliotecario) VALUES (?, CURRENT_DATE, (SELECT pk_id FROM Usuario AS U JOIN Login AS L ON U.fk_email = L.pk_email WHERE L.pk_email = ?), (SELECT pk_id FROM Usuario AS U JOIN Login AS L ON U.fk_email = L.pk_email where L.pk_email = ?))";
		
		try {
			PreparedStatement emp = Conector.getConexao().prepareStatement(sql);
			emp.setInt(1, cod_exemp);
			emp.setString(2, id_usuario);
			emp.setString(3, id_bibliotecario);
						
			emp.execute();
			
		} catch (SQLException exc) {
			exc.printStackTrace();
		}
	}
	
	public void delete() {
		
	}
	
	public void update() {
		
	}
	
	public void busca(String valor, ArrayList<Object> vec) {
		String sql = "SELECT * FROM (Emprestimo as E join Usuario as U on E.fk_id_usuario = U.pk_id join Exemplar as Ex on E.fk_cod_exemp = Ex.pk_cod_exemp join Livro as L on L.pk_cod_livro = Ex.fk_cod_livro) WHERE U.nome LIKE ? || L.titulo LIKE ? || E.pk_codigo = ?";
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
				vec.add(rs.getDate("E.data_retirada"));
				vec.add(rs.getDate("E.data_limite_devolucao"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
}

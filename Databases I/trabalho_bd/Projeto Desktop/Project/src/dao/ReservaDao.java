package dao;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import entidades.Reserva;

public class ReservaDao {
	public void insert(Reserva r) {
		String sql = "INSERT INTO Reserva (fk_id_usuario, fk_cod_livro, data_limite, disponivel) VALUES (?, ?, ?, ?)";
		
		try {
			PreparedStatement resv = Conector.getConexao().prepareStatement(sql);
			resv.setInt(1, r.getFk_id_usuario());
			resv.setInt(2, r.getFk_cod_livro());
			resv.setDate(3, (Date) r.getData_limite());
			resv.setBoolean(4, r.isDisponivel());			
			
			resv.execute();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void delete() {
		
	}
	
	public void update() {
		
	}
	
	public void busca(String valor, ArrayList<Object> vec) {
		String sql = "SELECT * FROM (Reserva as R join Usuario as U on R.fk_id_usuario = U.pk_id join Livro as L on R.fk_cod_livro = L.pk_cod_livro) WHERE U.nome LIKE ? || L.titulo LIKE ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, "%"+valor+"%");
			usr.setString(2, "%"+valor+"%");
			
			ResultSet rs = usr.executeQuery();
			
			while(rs.next()) {
				vec.add(rs.getString("U.nome"));
				vec.add(rs.getString("L.titulo"));
				vec.add(rs.getDate("R.data_limite"));
				vec.add(rs.getBoolean("R.disponivel"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
}

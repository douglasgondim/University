package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import entidades.Usuario;

public class UsuarioDao {
	public void insert(Usuario u, String fk_email,int fk_contato) {
		String sql = "INSERT INTO Usuario (nome, cpf, rg, fk_email, fk_contato, foto, limite_livro) VALUES (?, ?, ?, ?, ?, ?, ?)";
		
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, u.getNome());
			usr.setString(2, u.getCpf());
			usr.setString(3, u.getRg());
			usr.setString(4, fk_email);
			usr.setInt(5, fk_contato);
			usr.setString(6, u.getFoto());
			usr.setInt(7, u.getLimite_livro());
			
			usr.execute();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public void busca(String valor, ArrayList<Object> vec) {
		String sql = "SELECT * FROM Usuario WHERE pk_id = ? || nome LIKE ? || cpf = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			if(valor.matches("[0-9]*") && !valor.isEmpty()) {
				usr.setInt(1, Integer.parseInt(valor));
			}else {
				usr.setInt(1, 0);
			}
			usr.setString(2, "%"+valor+"%");
			if(valor.matches("[0-9]*") && !valor.isEmpty()) {
				usr.setInt(3, Integer.parseInt(valor));
			}else {
				usr.setInt(3, 0);
			}
			
			ResultSet rs = usr.executeQuery();
			
			while(rs.next()) {
				vec.add(rs.getInt("Usuario.pk_id"));
				vec.add(rs.getString("Usuario.nome"));
				vec.add(rs.getLong("Usuario.cpf"));
				vec.add(rs.getLong("Usuario.limite_livro"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public String getPk_id(String email) {
		String sql = "SELECT pk_id FROM Usuario WHERE fk_email = ?";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setString(1, email);
						
			liv.execute();
			
			ResultSet rs = liv.executeQuery();
			
			if(rs.next()) {
				return String.valueOf(rs.getInt("pk_id"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	
}

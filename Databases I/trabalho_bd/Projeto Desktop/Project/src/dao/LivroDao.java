package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import entidades.Livro;

public class LivroDao {
	public void insert(Livro l) {
		String sql = "INSERT INTO Livro (titulo, fk_id_autor, fk_id_editora, genero, capa, sumario, num_pags, pais, ano_publicacao, qtd_exemp, palavras_chave) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setString(1, l.getTitulo());
			liv.setInt(2, l.getFk_id_autor());
			liv.setInt(3, l.getFk_id_editora());
			liv.setString(4, l.getGenero());
			liv.setString(5, l.getCapa());
			liv.setString(6, l.getSumario());
			liv.setInt(7, l.getNum_pags());
			liv.setString(8, l.getPais());
			liv.setInt(9, l.getAno_publicacao());
			liv.setInt(10, l.getQtd_exemp());
			liv.setString(11, l.getPalavras_chave());
						
			liv.execute();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public String getPk_cod_livro(String titulo) {
		String sql = "SELECT pk_cod_livro FROM Livro WHERE titulo LIKE ?";
		
		try {
			PreparedStatement liv = Conector.getConexao().prepareStatement(sql);
			liv.setString(1, "%"+titulo+"%");
						
			liv.execute();
			
			ResultSet rs = liv.executeQuery();
			
			if(rs.next()) {
				return rs.getString("pk_cod_livro");
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public void busca(String valor, ArrayList<Object> vec) {
		String sql = "SELECT * FROM (Livro as L join Autor as A on L.pk_cod_livro = A.pk_id_autor join Editora as E on L.fk_id_editora = E.pk_codigo) WHERE L.titulo LIKE ? || A.nome LIKE ? || E.nome LIKE ? || L.pk_cod_livro = ?";
		try {
			PreparedStatement usr = Conector.getConexao().prepareStatement(sql);
			usr.setString(1, "%"+valor+"%");
			usr.setString(2, "%"+valor+"%");
			usr.setString(3, "%"+valor+"%");
			if(valor.matches("[0-9]*") && !valor.isEmpty()) {
				usr.setInt(4, Integer.parseInt(valor));
			}else {
				usr.setInt(4, 0);
			}
			ResultSet rs = usr.executeQuery();
			
			while(rs.next()) {
				vec.add(rs.getInt("L.pk_cod_livro"));
				vec.add(rs.getString("L.titulo"));
				vec.add(rs.getString("A.nome"));
				vec.add(rs.getString("E.nome"));
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}		
		
	}
}

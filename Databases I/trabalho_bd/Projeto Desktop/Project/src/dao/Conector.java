package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Conector {
    static String url = "jdbc:mysql://localhost/Biblioteca";
    static String usuario = "alan";
    static String senha = "sousa123";
    static Connection con;
    
    public static Connection getConexao() throws SQLException {

        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            if(con == null){
                con = DriverManager.getConnection(url,usuario,senha);
            }
            return con;
        }catch(ClassNotFoundException e){
        	System.out.println("Driver nao encontrado");
            throw new SQLException(e.getMessage());
        }
    }
}

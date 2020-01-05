package Database;

import java.io.IOException;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;

import java.sql.ResultSet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class connection_check extends HttpServlet{
	private static final long serialVersionUID = 1L;
    static final String DB_URL = "jdbc:mysql://google/fp?cloudSqlInstance=securethata:us-central1:securethata"
    		+ "&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false";
    static final String USER = "root";
    static final String PASS = "";
    
//	public static final String CREDENTIALS_STRING = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
	public Connection connection = null;
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			
			PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM Professor");
			ResultSet resultSet = preparedStatement.executeQuery();
			while(resultSet.next())
			{
				String nameString = resultSet.getString("firstname");
				response.getWriter().append(nameString);				
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
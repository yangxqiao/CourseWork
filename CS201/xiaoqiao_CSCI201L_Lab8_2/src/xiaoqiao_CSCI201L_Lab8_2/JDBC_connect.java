package xiaoqiao_CSCI201L_Lab8_2;

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


@WebServlet("/JDBC_connect")
public class JDBC_connect extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	public static final String CREDENTIALS_STRING = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
	public Connection connection = null;
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			connection = DriverManager.getConnection(CREDENTIALS_STRING);
			
			PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM Page");
			ResultSet resultSet = preparedStatement.executeQuery();
			while(resultSet.next())
			{
				String nameString = resultSet.getString("pageName");
				response.getWriter().append(nameString);				
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
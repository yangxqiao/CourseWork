package xiaoyanq_CSCI201L_Assignment3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import xiaoyanq_CSCI201L_Assignment3.bookInfo;

public class DBManager {
	// return true if can find the user
	// return false if the  user is not in the database
	public static boolean searchUser(String username)
	{
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM User WHERE username = ?";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(searchString);
			ps.setString(1, username);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this user
			// return true
			boolean foundMatch = false;
			if(rs.next())
			{
				String usernameValue = rs.getString("username");
				if(username.contentEquals(usernameValue))
				{
					return true;
				}
			}
			
			// if we get a result with no rows, return false
			if(!foundMatch)
			{
				return false;
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return false;
	}
	
	//return true if the username and password
	//match the one stored in the database
	public static boolean checkUserPassword(String username, String password)
	{
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM User WHERE username = ? AND password = ?";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(searchString);
			ps.setString(1, username);
			ps.setString(2, password);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this user
			// return true
			boolean foundMatch = false;
			if(rs.next())
			{
				String usernameValue = rs.getString("username");
				String passwordValue = rs.getString("password");
				if(password.contentEquals(passwordValue) && username.contentEquals(usernameValue))
				{
					return true;
				}
			}
			
			// if we get a result with no rows, return false
			if(!foundMatch)
			{
				return false;
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return false;
	}
	
	
	//Add new user to the database
	public static void addUser(String username, String password) {
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// Create new entry
		String newEntryString = "INSERT INTO User (username, password) VALUES (?, ?)";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(newEntryString);
			ps.setString(1, username);
			ps.setString(2, password);
			ps.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		
	}
	
	//Add new book to the database
	public static void addBook(String username, String bookname, String authorname, String publisher, String publishdate, String ISBN, String description, String image, String rating) {
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// Create new entry
		String newEntryString = "INSERT INTO Books (username, bookname, authorname, publisher, publishdate, ISBN, description, image, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(newEntryString);
			ps.setString(1, username);
			ps.setString(2, bookname);
			ps.setString(3, authorname);
			ps.setString(4, publisher);
			ps.setString(5, publishdate);
			ps.setString(6, ISBN);
			ps.setString(7, description);
			ps.setString(8, image);
			ps.setString(9, rating);
			ps.executeUpdate();
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		
	}
	

	public static void deleteBook(String username, String bookname)
	{
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		
		String deleteString = "DELETE FROM Books WHERE username = ? AND bookname = ?";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(deleteString);
			ps.setString(1, username);
			ps.setString(2, bookname);
			ps.executeUpdate();
	
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
	}
	
	//return true if the username and password
	//match the one stored in the database
	public static boolean checkBook(String username, String bookname)
	{
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM Books WHERE username = ? AND bookname = ?";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(searchString);
			ps.setString(1, username);
			ps.setString(2, bookname);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this user
			// return true
			boolean foundMatch = false;
			if(rs.next())
			{
				String usernameValue = rs.getString("username");
				String booknameValue = rs.getString("bookname");
				if(bookname.contentEquals(booknameValue) && username.contentEquals(usernameValue))
				{
					return true;
				}
			}
			
			// if we get a result with no rows, return false
			if(!foundMatch)
			{
				return false;
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connections
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return false;
	}
	
	public static ArrayList<bookInfo> getEntries(String username){
		ArrayList<bookInfo> data = new ArrayList<bookInfo>();
		
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		String getDataString = "SELECT * FROM Books WHERE username = ? ORDER BY created_at";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(getDataString);
			ps.setString(1, username);
			rs = ps.executeQuery();
			
			while(rs.next())
			{
				String usernameValue = rs.getString("username");
				String booknameValue = rs.getString("bookname");
				String authornameValue = rs.getString("authorname");
				String publisherValue = rs.getString("publisher");
				String publishdateValue = rs.getString("publishdate");
				String ISBNValue = rs.getString("ISBN");
				String descriptionValue = rs.getString("description");
				String imageValue = rs.getString("image");
				String ratingValue = rs.getString("rating");
				
				bookInfo bookentry = new bookInfo(booknameValue, authornameValue, publisherValue, publishdateValue, ISBNValue, descriptionValue, usernameValue, imageValue, ratingValue);
				data.add(bookentry);
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally {
			// Close connection
			try {
				if(rs != null)
				{
					rs.close();
				}
				if(ps != null)
				{
					ps.close();
				}
				if(conn != null)
				{
					conn.close();
				}
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return data;
	}	
	
}
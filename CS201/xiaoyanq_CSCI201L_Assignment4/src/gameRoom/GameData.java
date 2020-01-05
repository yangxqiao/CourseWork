package gameRoom;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;


public class GameData
{
	private Connection conn;
	// constructor
	public GameData(Connection conn)
	{
		this.conn = conn;
	}
	// return true if can find the user
	// return false if the  user is not in the database
	public boolean searchUser(String username)
	{
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM User WHERE username = ?";
		
		try {
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
	public boolean checkUserPassword(String username, String password)
	{
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM User WHERE username = ? AND password = ?";
		
		try {
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
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return false;
	}
	
	
	//Add new user to the database
	public void addUser(String username, String password) {
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// Create new entry
		String newEntryString = "INSERT INTO User (username, password, winNum, loseNum) VALUES (?, ?, 0, 0)";
		
		try {
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
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		
	}
	
	public Integer getNumWins(String username)
	{
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries

		String searchString = "SELECT winNum FROM User WHERE username = ?";
		
		try {
			ps = conn.prepareStatement(searchString);
			ps.setString(1, username);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this user
			// return true
			if(rs.next())
			{
				return rs.getInt("winNum");
			}

			// if we get a result with no rows, return -1
			return -1;
			
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
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return -1;
	}
	
	public Integer getNumLoses(String username)
	{
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries

		String searchString = "SELECT loseNum FROM User WHERE username = ?";
		
		try {
			ps = conn.prepareStatement(searchString);
			ps.setString(1, username);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this user
			// return true
			if(rs.next())
			{
				return rs.getInt("loseNum");
			}

			// if we get a result with no rows, return -1
			return -1;
			
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
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return -1;
	}
	
	
	public void updateRecord(String username, int winNum, int loseNum)
	{
		// Connect to database
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		String deleteString = "UPDATE User SET winNum = ?, loseNum = ? WHERE username = ?";
		try {
			ps = conn.prepareStatement(deleteString);
			ps.setInt(1, winNum);
			ps.setInt(2, loseNum);
			ps.setString(3, username);
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
			}
			catch(SQLException sqle)
			{
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
	}
}
package xiaoqiao_CSCI201L_Lab8_2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class DBManager {
	// Increment our page count
	public static void incrementPageCount(int pageId, String ipAddress, int portNum) {
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		// Gets all rows from PageVisited
		String searchString = "SELECT * FROM PageVisited WHERE pageId = ? AND portNum = ? AND ipAddress = ?";
		
		// Updates count of row
		String updateString = "UPDATE PageVisited SET count = ? WHERE pageId = ? AND portNum = ? AND ipAddress = ?";
		
		// Create new entry
		String newEntryString = "INSERT INTO PageVisited (pageId, ipAddress, portNum, count) VALUES (?, ?, ?, 1)";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(searchString);
			ps.setInt(1, pageId);
			ps.setInt(2, portNum);
			ps.setString(3, ipAddress);
			rs = ps.executeQuery();
			
			// If we get some result, it means we have already seen this page (so update count)
			// Go through result (all the rows we got back)
			boolean foundMatch = false;
			while(rs.next())
			{
				String ipAddressValue = rs.getString("ipAddress");
				int portNumValue = rs.getInt("portNum");
				int pageIdValue = rs.getInt("pageId");
				int countValue = rs.getInt("count");
				
				if(pageId == pageIdValue && ipAddressValue.equals(ipAddressValue) && portNum == portNumValue)
				{
					// We've seen this page before and we need to update the count!
					ps = conn.prepareStatement(updateString);
					ps.setInt(1, ++countValue);
					ps.setInt(2, pageId);
					ps.setInt(3, portNum);
					ps.setString(4, ipAddress);
					foundMatch = true;
				}
			}
			
			// if we get a result with no rows, we should add something to the database
			if(!foundMatch)
			{
				ps = conn.prepareStatement(newEntryString);
				ps.setInt(1, pageId);
				ps.setString(2, ipAddress);
				ps.setInt(3, portNum);
				ps.executeUpdate();
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
	}
	
	public static ArrayList<PageEntry> getEntries(){
		ArrayList<PageEntry> data = new ArrayList<PageEntry>();
		
		// Connect to database
		String jdbcUrl = "jdbc:mysql://google/Lab7?cloudSqlInstance=csci201-lab7-255501:us-central1:sql-csci201&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=test&password=password";
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		
		// SQL queries
		String getDataString = "SELECT * FROM PageVisited";
		
		try {
			conn = DriverManager.getConnection(jdbcUrl);
			ps = conn.prepareStatement(getDataString);
			rs = ps.executeQuery();
			
			while(rs.next())
			{
				String ipAddressValue = rs.getString("ipAddress");
				int portNumValue = rs.getInt("portNum");
				int pageIdValue = rs.getInt("pageId");
				int countValue = rs.getInt("count");
				
				String pageNum = pageIdValue == 1 ? "cat.jsp" : "dog.jsp";
				PageEntry pageEntry = new PageEntry(pageNum, portNumValue, countValue, ipAddressValue);
				data.add(pageEntry);
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

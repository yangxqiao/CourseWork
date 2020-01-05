package Database;

import java.sql.*;
import java.io.*;
import java.util.*;

public class DatabaseOperator1 {
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://google/fp?cloudSqlInstance=securethata:us-central1:securethata"
    		+ "&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false";
    static final String USER = "root";
    static final String PASS = "";
    
    Connection connection = null;
	PreparedStatement preparedStatement = null;
	ResultSet resultSet = null;
	
	public boolean authenticate(String username, String password) {
		
		String sql = "SELECT * FROM User WHERE userName = ?";
    	
    	try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(sql);
			preparedStatement.setString(1, username);
			resultSet = preparedStatement.executeQuery();
			
			while(resultSet.next()) {
				String correctPassword = resultSet.getString("password");
				if(password.equals(correctPassword)) {
					return true;
				}
				else {//incorrect password
					return false;
				}
			}
			
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return false;//unhandle case
	}
	
	public boolean userExist(String username) {
		String sql = "SELECT * FROM User WHERE userName = ?";
    	
    	try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(sql);
			preparedStatement.setString(1, username);
			resultSet = preparedStatement.executeQuery();
			
			if(resultSet.next()) {
				return true;//username exist
			}
			
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return false;//unhandle case
	}
	
	public boolean addUser(String username, String password) {//change to boolean to see if add successfully
		
		String insert = "INSERT INTO User (userName, password) VALUES (?,?)";
		
		try {
			//start insert
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(insert);
			preparedStatement.setString(1, username);
			preparedStatement.setString(2, password);
			preparedStatement.executeUpdate();
			return true;
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return false;
	}
	
	public double getGPA (String courseName) {//get overall GPA
		
		String select = "SELECT avgGPA, counts FROM GPA WHERE courseName = ?";
		courseName = courseNameChange(courseName);
		
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			double result = 0.0;
			int count = 0;
			while(resultSet.next()) {
				double termGPA = resultSet.getDouble("avgGPA")*resultSet.getInt("counts");
				result += termGPA;
				count += resultSet.getInt("counts");
			}
			
			return result/count;
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return -1;//unhandle case
	}

	public String getCourseTitle(String courseName) {
		
		String select = "SELECT courseTitle FROM Course WHERE courseName = ?";
		courseName = courseNameChange(courseName);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			if(resultSet.next()) {
				String title = resultSet.getString("courseTitle");
				return title;
			}
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return null;//unhandle case
	}
	
	public String getDescription (String courseName) {
		
		String select = "SELECT description FROM Course WHERE courseName = ?";
		courseName = courseNameChange(courseName);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			if(resultSet.next()) {
				String description = resultSet.getString("description");
				return description;
			}
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return null;//unhandle case
	}
	
	public ArrayList<String> getProfessors(String courseName){
		
		String select = "SELECT DISTINCT p.fname, p.lname FROM Professor p, GPA g WHERE p.professorID = g.professorID AND g.courseName = ?";
		courseName = courseNameChange(courseName);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			ArrayList<String> professors = new ArrayList<String>();
			while(resultSet.next()) {
				String fname = resultSet.getString("fname");
				String lname = resultSet.getString("lname");
				professors.add(fname+" "+lname);
			}
			return professors;
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return null;//unhandle case
		
	}
	
	public ArrayList<String> getTerms(String courseName){//form is Spring 2019
		
		String select = "SELECT DISTINCT term FROM GPA WHERE courseName = ?";
		courseName = courseNameChange(courseName);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			ArrayList<String> terms = new ArrayList<String>();
			while(resultSet.next()) {
				String term = resultSet.getString("term");
				String year = term.substring(0,4);
				String semester = term.substring(4,5);
				String weather = "";
				if(semester.equals("1")) {
					weather = "Spring";
				}
				else if(semester.equals("2")) {
					weather = "Summer";
				}
				else {
					weather = "Fall";
				}
				terms.add(year + " " + weather);
			}
			return terms;
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return null;//unhandle case
	}
	
	public boolean upload(String course, String term, String professor, String gpa, String recommend, String challenging) {
		
		//int pID = getProfessorID(professor);
		String[] pro = professor.split("\\s+");
		if (pro.length < 2) {
			return false;
		}
		String fname = pro[0].trim();
		String lname = pro[1].trim();
		String select = "SELECT * FROM GPA WHERE courseName = ? AND professorID ="
				+ "(SELECT professorID FROM Professor WHERE fname=? AND lname=?) "
				+ "AND term = ?";
		String courseName = courseNameChange(course);
		//int courseID = getCourseID(courseName);
		int recom = 0, challenge = 0;
		if(recommend.equals("yes")) {
			recom = 1;
		}
		if(challenging.equals("yes")) {
			challenge = 1;
		}
				
		try {
			double GPA = doubleTransfer(gpa);
			//System.out.println("reach upload");
			
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			preparedStatement.setString(2, fname);
			preparedStatement.setString(3, lname);
			preparedStatement.setString(4, term);
			resultSet = preparedStatement.executeQuery();
			
			boolean hasResult = false;
			while(resultSet.next()) {//already exist
				int count = resultSet.getInt("counts");
				int pChallenging = resultSet.getInt("challenging") + challenge;
				int rec = resultSet.getInt("rec") + recom;
				double avgGPA = resultSet.getDouble("avgGPA");
				avgGPA = (avgGPA * count + GPA) / (count+1);
				
				String update = "UPDATE GPA SET counts=counts+1, challenging=?,rec=?,avgGPA=?"
						+ "WHERE courseName = ? AND "
						+ "professorID = (SELECT professorID FROM Professor WHERE fname=? AND lname=?)"
						+ "AND term = ?";
				preparedStatement = connection.prepareStatement(update);
				preparedStatement.setInt(1, pChallenging);
				preparedStatement.setInt(2, rec);
				preparedStatement.setDouble(3, avgGPA);
				preparedStatement.setString(4, courseName);
				preparedStatement.setString(5, fname);
				preparedStatement.setString(6, lname);
				preparedStatement.setString(7, term);
				preparedStatement.executeUpdate();
				hasResult = true;
				return true;
			}
			if(!hasResult) {
				System.out.println("reach insert");
				String insert = "INSERT INTO GPA (courseID, professorID, courseName, term, avgGPA, counts, challenging, rec) "
						+ "VALUES ((SELECT courseID FROM Course WHERE courseName = ?),"
						+ "(SELECT professorID FROM Professor WHERE fname=? AND lname=?),?,?,?,1,?,?)";
				preparedStatement = connection.prepareStatement(insert);			
				preparedStatement.setString(1, courseName);
				preparedStatement.setString(2, fname);
				preparedStatement.setString(3, lname);
				preparedStatement.setString(4, courseName);
				preparedStatement.setString(5, term);
				preparedStatement.setDouble(6, GPA);
				preparedStatement.setInt(7, challenge);
				preparedStatement.setInt(8, recom);
				preparedStatement.executeUpdate();
			}
			return true;
		
		}catch(SQLException e) {
			e.printStackTrace();
		}catch(NumberFormatException nfe) {
			nfe.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return false;//unhandle case
    	
	}
	
	
	//helper function
	private String courseNameChange(String courseName) {
		courseName = courseName.trim();
		courseName = courseName.toUpperCase();
		return courseName;
	}
	
	private ArrayList<String> getProfessors () {//temporary

		String select = "SELECT * FROM Professor";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			resultSet = preparedStatement.executeQuery();
			ArrayList<String> professors = new ArrayList<String>();
			while(resultSet.next()) {
				professors.add(resultSet.getString("fname")+" "+resultSet.getString("lname"));
			}
			return professors;
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
		return null;
	}
	
	public int getCourseID(String courseName) {
		String select = "SELECT courseID FROM Course WHERE courseName = ?";
		courseName = courseNameChange(courseName);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, courseName);
			resultSet = preparedStatement.executeQuery();
			
			if(resultSet.next()) {
				int id = resultSet.getInt("courseID");
				return id;
			}
		
		}catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(resultSet != null) {
					resultSet.close();
				}
				if(preparedStatement!=null) {
					preparedStatement.close();
				}
				if(connection!=null) {
					connection.close();
				}
			} catch (SQLException sqle) {
				System.out.println("sqle: " + sqle.getMessage());
			}
		}
    	return -1;//unhandle case
	}
	
	private static double doubleTransfer(String transfer) throws NumberFormatException{ // transfer string to int type
		double a = 0;
		a = Double.valueOf(transfer).doubleValue();
		return a;
	}
}

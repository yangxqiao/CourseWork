package Database;

import java.sql.*;
import java.io.*;
import java.util.*;

public class DatabaseOperator2 {
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://google/fp?cloudSqlInstance=securethata:us-central1:securethata"
    		+ "&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false";
    static final String USER = "root";
    static final String PASS = "";
    
    Connection connection = null;
	PreparedStatement preparedStatement = null;
	ResultSet resultSet = null;

//	this function is used to get the professor ID with a professor name stored
	public int getProfessorID (String professor) {
		String[] pro = professor.split("\\s+");
		if (pro.length != 2) {
			return -1;
		}

		String first = pro[0];
		String last = pro[1];
		String select = "SELECT * FROM Professor WHERE fname = ? AND lname = ?";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, first);
			preparedStatement.setString(2, last);
			resultSet = preparedStatement.executeQuery();
			if(resultSet.next()) {
				int id = resultSet.getInt("professorID");
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
		return -1;
	}
	
	public String getSpecificGPA(String term, String professor, String courseName) {
		
		String select = "SELECT avgGPA FROM GPA WHERE term = ? AND professorID = ? AND courseName = ?";
		term.trim();
		courseName.trim();
		if (getProfessorID(professor) == -1) {
			return null;
		}
		int professorID = getProfessorID(professor);
				
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, term);
			preparedStatement.setInt(2, professorID);
			preparedStatement.setString(3, courseName);
			resultSet = preparedStatement.executeQuery();
			if(resultSet.next()) {
				String avgGPA = resultSet.getString("avgGPA");
				return avgGPA;
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
    	return null;
	}
	
	
	public int getRecommendRate(String professor, String courseName) {
		String select = "SELECT * FROM GPA WHERE professorID = ? AND courseName = ?";
		courseName.trim();
		if (getProfessorID(professor) == -1) {
			return -1;
		}
		int professorID = getProfessorID(professor);
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setInt(1, professorID);
			preparedStatement.setString(2, courseName);
			resultSet = preparedStatement.executeQuery();
			
			int rec = 0;
			int counts = 1;
			if(resultSet.next()) {
				rec = resultSet.getInt("rec");
				counts = resultSet.getInt("counts");
				int result = rec/counts * 100;
				return result;
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
    	return -1;
	}
	
	public int getChallenging(String professor, String courseName) {
		String select = "SELECT * FROM GPA WHERE professorID = ? AND courseName = ?";
		courseName.trim();
		if (getProfessorID(professor) == -1) {
			return -1;
		}
		int professorID = getProfessorID(professor);
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setInt(1, professorID);
			preparedStatement.setString(2, courseName);
			resultSet = preparedStatement.executeQuery();
			
			int challenging = 0;
			int counts = 1;
			if(resultSet.next()) {
				challenging= resultSet.getInt("challenging");
				counts = resultSet.getInt("counts");
				int result = challenging/counts * 100;
				return result;
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
    	return -1;
	}
	
	//course -> CS104 CourseName
	public ArrayList<String> get_All_Professor_Given_Term_And_Course(String term, String course){
		String select = "SELECT p.fname, p.lname FROM Professor p, "
				+ "GPA g WHERE g.professorID = p.professorID AND "
				+ "term = ? AND courseName = ? ";
		term.trim();
		course.trim();
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			
			preparedStatement.setString(1, term);
			preparedStatement.setString(2, course);
			resultSet = preparedStatement.executeQuery();
			ArrayList<String> result = new ArrayList<String>();
			while (resultSet.next()) {
				result.add(resultSet.getString("p.fname") + " " + resultSet.getString("p.lname"));
			}
			return result;
		}
		catch(SQLException e) {
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
		ArrayList<String> result1 = new ArrayList<String>();
		return result1;
	}
	
	public ArrayList<Double> get_All_GPA_Given_Term_And_Course(String term, String course){
		String select = "SELECT avgGPA FROM GPA WHERE term = ? AND courseName = ?";
		term.trim();
		course.trim();
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, term);
			preparedStatement.setString(2, course);
			resultSet = preparedStatement.executeQuery();
			ArrayList<Double> result = new ArrayList<Double>();
			while (resultSet.next()) {
				result.add(resultSet.getDouble("avgGPA"));
			}
			return result;
		}
		catch(SQLException e) {
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
		ArrayList<Double> result1 = new ArrayList<Double>();
		return result1;
	}

	
	public Vector<String> searchCourseByProf(String input){
		String select = "";
		String[] search = input.split("\\s+");
		String firstname = "%";
		String lastname = "%";
		int selectAgain = 0;
		Vector<String> result = new Vector<String>();
		//check if user only have one name (can be first or last) or if they have two or more
		if (search.length == 0) {
			return null;
		}
		else if (search.length == 1) {
			select = "SELECT * FROM GPA g, Professor p, Course c "
					+ "WHERE p.professorID = g.professorID AND c.courseID = g.courseID AND (p.fname LIKE ? OR "
					+ "p.lname LIKE ?) ORDER BY c.courseNumber ASC";
			firstname += search[0] + "%";
			lastname += search[0] +"%";
		}
		else {
			select = "SELECT * FROM GPA g, Professor p, Course c "
					+ "WHERE p.professorID = g.professorID AND c.courseID = g.courseID AND (p.fname LIKE ? OR "
					+ "p.lname LIKE ?) ORDER BY c.courseNumber ASC";
			firstname += search[0] + "%";
			lastname += search[1] + "%";
			selectAgain = 1;
		}
		
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, firstname);
			preparedStatement.setString(2, lastname);
			resultSet = preparedStatement.executeQuery();
			while (resultSet.next()) {
				result.add(resultSet.getString("courseName"));
			}
			if (selectAgain != 1) {
				return result;
			}
		}
		catch(SQLException e) {
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
		//run sql again when there are more than two words
		String first = "%";
		String last = "%";
		if (selectAgain == 1) {
			select = "SELECT * FROM GPA g, Professor p, Course c "
					+ "WHERE p.professorID = g.professorID AND c.courseID = g.courseID AND (p.fname LIKE ? OR "
					+ "p.lname LIKE ?) ORDER BY c.courseNumber ASC";
			first += search[1] + "%";
			last += search[0] +"%";
			try {
				connection = DriverManager.getConnection(DB_URL,USER,PASS);
				preparedStatement = connection.prepareStatement(select);
				preparedStatement.setString(1, first);
				preparedStatement.setString(2, last);
				resultSet = preparedStatement.executeQuery();
				while (resultSet.next()) {
					result.add(resultSet.getString("courseName"));
				}
				return result;
			}
			catch(SQLException e) {
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
		}
		Vector<String> result1 = new Vector<String>();
		return result1;
	}
	
	
	public Vector<String> searchCourseByCourse(String input) {
		input.trim();
		String prefix = "%";
		String number = "%";
		for (int i = 0; i < input.length(); i++) {
			if (Character.isDigit(input.charAt(i))) {
				number += input.charAt(i);
			}
			else
				prefix += input.charAt(i);
		}
		prefix += "%";
		number += "%";
		String select = "SELECT * FROM Course c WHERE prefix LIKE ? "
				+ "AND c.courseNumber LIKE ? ORDER BY c.courseNumber ASC";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(2, number);
			preparedStatement.setString(1, prefix);
			resultSet = preparedStatement.executeQuery();
			Vector<String> result = new Vector<String>();
			while (resultSet.next()) {
				result.add(resultSet.getString("courseName"));
			}
			return result;
		}
		catch(SQLException e) {
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
		Vector<String> result2 = new Vector<String>();
		return result2;
	}
	
	
	public Vector<String> getRecommendByCourse(String input){
		input.trim();
		Vector<String> searchResult = searchCourseByCourse(input);
		if (searchResult.size() == 0) {
			Vector<String> result1 = new Vector<String>();
			return result1;
		}
		String search = searchResult.get(searchResult.size() -1);
		String prefix = "";
		String number = "";
		for (int i = 0; i < search.length(); i++) {
			if (Character.isDigit(search.charAt(i))) {
				number += search.charAt(i);
			}
			else
				prefix += search.charAt(i);
		}
		String select = "SELECT * FROM Course WHERE prefix = ? AND courseNumber > ? ORDER BY courseName ASC";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);;
			preparedStatement.setString(1, prefix);
			preparedStatement.setInt(2, Integer.parseInt(number));
			resultSet = preparedStatement.executeQuery();
			Vector<String> result = new Vector<String>();
			while (resultSet.next()) {
				result.add(resultSet.getString("courseName"));
			}
			if (result.size() == 0){
				result.add("PHED 120");
				return result;
			}
			return result;
			
		}
		catch(SQLException e) {
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
		Vector<String> result2 = new Vector<String>();
		return result2;
	}
	
	public Vector<String> getRecommendByProf(String input){
		Vector<String> searchResult = searchCourseByProf(input);
		if (searchResult.size() == 0) {
			Vector<String> result1 = new Vector<String>();
			return result1;
		}
		String search = searchResult.get(searchResult.size() -1);
		String prefix = "";
		String number = "";
		for (int i = 0; i < search.length(); i++) {
			if (Character.isDigit(search.charAt(i))) {
				number += search.charAt(i);
			}
			else
				prefix += search.charAt(i);
		}
		String select = "SELECT * FROM Course WHERE prefix = ? AND courseNumber > ? ORDER BY courseName ASC";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setString(1, prefix);
			preparedStatement.setInt(2, Integer.parseInt(number));
			resultSet = preparedStatement.executeQuery();
			Vector<String> result = new Vector<String>();
			while (resultSet.next()) {
				result.add(resultSet.getString("courseName"));
			}
			if (result.size() == 0){
				result.add("PHED 120");
				return result;
			}
			return result;
			
		}
		catch(SQLException e) {
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
		Vector<String> result2 = new Vector<String>();
		return result2;
	}
}
	
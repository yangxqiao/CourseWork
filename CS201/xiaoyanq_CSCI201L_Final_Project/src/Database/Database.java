package Database;

import java.sql.*;
import java.io.*;
import java.util.*;

public class Database {
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
			if(userExist(username)) {
				return false;
			}
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
			if(count!=0) {
				return result/count;
			}
			else {
				return 0.0;
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
	
	public boolean upload(String courseid, String term, String professorid, String gpa, String recommend, String challenging) {
		
//		int pID = getProfessorID(professor);
//		String[] pro = professor.split("\\s+");
//		if (pro.length < 2) {
//			return false;
//		}
//		String fname = pro[0].trim();
//		String lname = pro[1].trim();
//		String select = "SELECT * FROM GPA WHERE courseName = ? AND professorID ="
//				+ "(SELECT professorID FROM Professor WHERE fname=? AND lname=?) "
//				+ "AND term = ?";
//		String courseName = courseNameChange(course);
		//int courseID = getCourseID(courseName);
		String select = "SELECT * FROM GPA WHERE courseID = ? AND professorID = ? AND term = ?";
		int recom = 0, challenge = 0;
		if(recommend.equals("yes")) {
			recom = 1;
		}
		if(challenging.equals("yes")) {
			challenge = 1;
		}
		int courseID = intTransfer(courseid);
		int professorID = intTransfer(professorid);
				
		try {
			double GPA = doubleTransfer(gpa);
			//System.out.println("reach upload");
			
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setInt(1, courseID);
			preparedStatement.setInt(2, professorID);
			preparedStatement.setString(3, term);
			resultSet = preparedStatement.executeQuery();
			
			boolean hasResult = false;
			while(resultSet.next()) {//already exist
				int count = resultSet.getInt("counts");
				int pChallenging = resultSet.getInt("challenging") + challenge;
				int rec = resultSet.getInt("rec") + recom;
				double avgGPA = resultSet.getDouble("avgGPA");
				avgGPA = (avgGPA * count + GPA) / (count+1);
				
				String update = "UPDATE GPA SET counts=counts+1, challenging=?,rec=?,avgGPA=?"
						+"WHERE courseID = ? "
						+ "AND professorID = ? "
						+ "AND term = ?";
				preparedStatement = connection.prepareStatement(update);
				preparedStatement.setInt(1, pChallenging);
				preparedStatement.setInt(2, rec);
				preparedStatement.setDouble(3, avgGPA);
				preparedStatement.setInt(4, courseID);
				preparedStatement.setInt(5, professorID);
				preparedStatement.setString(6, term);
				preparedStatement.executeUpdate();
				hasResult = true;
				return true;
			}
			if(!hasResult) {
				System.out.println("reach insert");
				String insert = "INSERT INTO GPA (courseID, professorID, courseName, term, avgGPA, counts, challenging, rec) "
						+ "VALUES (?,?,"//courseID profID
						+ "(SELECT courseName FROM Course WHERE courseID = ?),"//courseName
						+ "?,?,1,?,?)";//term, avgGPA, counts,challange, rec
				preparedStatement = connection.prepareStatement(insert);			
				preparedStatement.setInt(1, courseID);
				preparedStatement.setInt(2, professorID);
				preparedStatement.setInt(3, courseID);
				preparedStatement.setString(4, term);
				preparedStatement.setDouble(5, GPA);
				preparedStatement.setInt(6, challenge);
				preparedStatement.setInt(7, recom);
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
	
	public ArrayList<String[]> getProfessors () {//temporary

		String select = "SELECT * FROM Professor";
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			resultSet = preparedStatement.executeQuery();
			ArrayList<String[]> professors = new ArrayList<String[]>();
			while(resultSet.next()) {
				String[] info = new String[2];
				info[0] = resultSet.getString("professorID");
				info[1] = resultSet.getString("fname")+" "+resultSet.getString("lname");
				System.out.println(info[0] +" "+info[1]);
				professors.add(info);
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
	
	public ArrayList<String[]> getCourses() {
		
		String select = "SELECT * FROM Course";

		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			resultSet = preparedStatement.executeQuery();
			ArrayList<String[]> courses = new ArrayList<>();
			while(resultSet.next()) {
				String[] info = new String[2];
				info[0] = resultSet.getString("courseID");
				info[1] = resultSet.getString("courseName");
				System.out.println(info[0] +" "+info[1]);
				courses.add(info);
			}
			return courses;

		}catch(SQLException e) {
			e.printStackTrace();
		}
    	return null;//unhandle case
	}
	
	private static double doubleTransfer(String transfer) throws NumberFormatException{ // transfer string to int type
		double a = 0;
		a = Double.valueOf(transfer).doubleValue();
		return a;
	}
	private static int intTransfer(String transfer) throws NumberFormatException{ // transfer string to int type
		int a = 0;
		a = Integer.valueOf(transfer).intValue();
		return a;
	}
	
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
	
	public double getSpecificGPA(String term, String professor, String courseName) {
		
		term.trim();
		courseName.trim();
		courseName.trim();
		int professorID = getProfessorID(professor);

		double avgGPA = -1;		
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			String select;
			if(term==null || term.equals("")){//no term
				if(professorID == -1) {//no professor
					select = "SELECT avgGPA FROM GPA WHERE courseName = ?";
					preparedStatement = connection.prepareStatement(select);
					preparedStatement.setString(1, courseName);
				}
				else {//have professor
					select = "SELECT avgGPA FROM GPA WHERE courseName = ? AND professorID = ?";
					preparedStatement = connection.prepareStatement(select);
					preparedStatement.setString(1, courseName);
					preparedStatement.setInt(2, professorID);
				}
			}
			else {//have term
				if(professorID == -1) {//no professor
					select = "SELECT avgGPA FROM GPA WHERE courseName = ? AND term = ?";
					preparedStatement = connection.prepareStatement(select);
					preparedStatement.setString(1, courseName);
					preparedStatement.setString(2, term);
				}
				else {
					select = "SELECT avgGPA FROM GPA WHERE term = ? AND professorID = ? AND courseName = ?";
					preparedStatement = connection.prepareStatement(select);
					preparedStatement.setString(1, term);
					preparedStatement.setInt(2, professorID);
					preparedStatement.setString(3, courseName);
				}
			}
			resultSet = preparedStatement.executeQuery();
			if(resultSet.next()) {
				//String avgGPA = resultSet.getString("avgGPA");
				avgGPA = Double.parseDouble(resultSet.getString("avgGPA"));
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
    	//return null;
		return avgGPA;
	}
	
	
	public int getRecommendRate(String professor, String courseName) {
		String select = "SELECT * FROM GPA WHERE professorID = ? AND courseName = ?";
		courseName.trim();
		if (getProfessorID(professor) == -1) {
			return -1;
		}
		int professorID = getProfessorID(professor);
		int result = -1;
		try {
			connection = DriverManager.getConnection(DB_URL,USER,PASS);
			preparedStatement = connection.prepareStatement(select);
			preparedStatement.setInt(1, professorID);
			preparedStatement.setString(2, courseName);
			resultSet = preparedStatement.executeQuery();
			
			int rec = 0;
			int counts = 0;			
			
			while(resultSet.next()) {
				rec += resultSet.getInt("rec");
				counts += resultSet.getInt("counts");				
			}
			if(counts!=0) {
				result = (int)((double)rec/counts * 100);
			}
			return result;
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
    	return result;
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
				int result = (int)((double)challenging/counts * 100);
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
		Set<String> courses = new TreeSet<String>(); 
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
				courses.add(resultSet.getString("courseName"));
			} 
			if (selectAgain != 1) {
			    Iterator<String> value = courses.iterator(); 
			    while (value.hasNext()) { 
			    	result.add(value.next()); 
			    } 
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
					courses.add(resultSet.getString("courseName"));
				} 
				    Iterator<String> value = courses.iterator(); 
				    while (value.hasNext()) { 
				    	result.add(value.next()); 
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
				result.add("PHED120");
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
				result.add("PHED 120A");
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



<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.io.*" %>
<%@ page import="java.net.*" %>
<%@ page import="com.google.*" %>
<%@ page import="java.util.*" %>
<%@  page import= "Database.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%
	Database do2 = new Database();
	//authenticate test
	out.println("Testing getProfessorID");
	out.println("</br>");
	out.println(do2.getProfessorID("jeff miller"));
	out.println("</br>");
	out.println("</br>");
	if (do2.getProfessorID("jeff") != -2){
		out.println("Pass the null professor test");
	}
	else
		out.println("Not passing the null professor test");
	out.println("</br>");
	
	
	//testing the getSpecificGPA
	out.println("Testing getSpecificGPA");
	out.println("</br>");
	out.println(do2.getSpecificGPA("20191", "mark redekopp", "CSCI102"));
	out.println("</br>");	
	out.println(do2.getSpecificGPA("20191", "mar", "CSCI102"));
	out.println("</br>");
	out.println("</br>");
	
	
	//testing get recommend rate
	out.println("Testing getRecommendRate");
	out.println("</br>");
	out.println(do2.getRecommendRate("mark redekopp", "CSCI102"));
	out.println("</br>");	
	out.println(do2.getRecommendRate("mark redekopp", "CSCI103"));
	out.println("</br>");	
	out.println("</br>");
	
	//testing get challengin rate
	out.println("Testing getChallengingRate");
	out.println("</br>");
	out.println(do2.getChallenging("mark redekopp", "CSCI102"));
	out.println("</br>");	
	out.println(do2.getChallenging("mark redekopp", "CSCI103"));
	out.println("</br>");	
	out.println("</br>");

	//testing get challengin rate
	out.println("Testing getAllProfessorGivenTerm");
	out.println("</br>");
	ArrayList<String> result = do2.get_All_Professor_Given_Term_And_Course("20192", "CSCI201");
	for (int i = 0; i < result.size(); i++){
		out.println(result.get(i));
	} 
	out.println("</br>");	
	out.println("</br>");	
	out.println("</br>");

	out.println("Testing get_All_GPA_Given_Term_And_Course");
	out.println("</br>");
	ArrayList<Double> result2 = do2.get_All_GPA_Given_Term_And_Course("20192", "CSCI201");
	for (int i = 0; i < result2.size(); i++){
		out.println(result2.get(i));
	} 
	out.println("</br>");	
	out.println("</br>");
	
	ArrayList<Double> result3 = do2.get_All_GPA_Given_Term_And_Course("20194", "CSCI201");
	for (int i = 0; i < result3.size(); i++){
		out.println(result3.get(i));
	} 
	out.println("</br>");	
	out.println("</br>");
	
	out.println("Testing searchCourseByCourse");
	out.println("</br>");
	Vector<String> result4 = do2.searchCourseByCourse("CSCI201");
	for (int i = 0; i < result4.size(); i++){
		out.println(result4.get(i));
	} 
	
	out.println("</br>");	
	Vector<String> result5 = do2.searchCourseByCourse("CS201");
	for (int i = 0; i < result5.size(); i++){
		out.println(result5.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("</br>");	
	Vector<String> result6 = do2.searchCourseByCourse("CSCI10");
	for (int i = 0; i < result6.size(); i++){
		out.println(result6.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("</br>");	
	Vector<String> result7 = do2.searchCourseByCourse("CS 201");
	for (int i = 0; i < result7.size(); i++){
		out.println(result7.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("Testing searchProfByCourse");
	Vector<String> result8 = do2.searchCourseByProf("mark");
	for (int i = 0; i < result8.size(); i++){
		out.println(result8.get(i));
	} 
	out.println("</br>");
	out.println("Testing searchProfByCourse");
	Vector<String> result9 = do2.searchCourseByProf("mark redekopp");
	for (int i = 0; i < result9.size(); i++){
		out.println(result9.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("</br>");
	out.println("Testing searchProfByCourse");
	Vector<String> result10 = do2.searchCourseByProf("redekopp mark");
	for (int i = 0; i < result10.size(); i++){
		out.println(result10.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	out.println("</br>");
	out.println("Testing searchProfByCourse");
	Vector<String> result11 = do2.searchCourseByProf("rede mark");
	for (int i = 0; i < result11.size(); i++){
		out.println(result11.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	out.println("Testing searchProfByCourse");
	Vector<String> result12 = do2.searchCourseByProf("mark re");
	for (int i = 0; i < result12.size(); i++){
		out.println(result12.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("</br>");
	Vector<String> result13 = do2.getRecommendByCourse("CSCI102");
	for (int i = 0; i < result13.size(); i++){
		out.println(result13.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	out.println("</br>");
	
	out.println("Get recommend by courses");
	Vector<String> result14 = do2.getRecommendByCourse("CSCI100");
	for (int i = 0; i < result14.size(); i++){
		out.println(result14.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	Vector<String> result15 = do2.getRecommendByCourse("CSCI201");
	for (int i = 0; i < result15.size(); i++){
		out.println(result15.get(i));
	} 
	out.println("</br>");
	out.println("</br>");
	
	out.println("</br>");
	Vector<String> result16 = do2.getRecommendByProf("mark redekopp");
	for (int i = 0; i < result16.size(); i++){
		out.println(result16.get(i));
	}
	out.println("</br>");
	out.println("</br>"); 
	Vector<String> result17 = do2.getRecommendByProf("wu lala");
	for (int i = 0; i < result17.size(); i++){
		out.println(result17.get(i));
	}
	out.println("</br>");
	Vector<String> result18 = do2.getRecommendByProf("wu lala");
	for (int i = 0; i < result18.size(); i++){
		out.println(result18.get(i));
	}
	out.println("</br>");
	out.println("</br>"); 
	
	
	out.println("Testing searchProfByCourse again");
	Vector<String> result19 = do2.searchCourseByProf("mark");
	for (int i = 0; i < result19.size(); i++){
		out.println(result19.get(i));
	} 
	
%>
	
</body>
</html>
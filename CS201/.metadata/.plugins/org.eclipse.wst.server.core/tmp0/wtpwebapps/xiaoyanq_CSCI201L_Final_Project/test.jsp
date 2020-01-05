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
	DatabaseOperator1 do1 = new DatabaseOperator1();
	do1.addUser("root", "123456");
	//authenticate test
	if(!do1.authenticate("root", "1234")) {
		out.println("pass authenticate test with not correct password.");
	}
	else {
		out.println("fail authenticate test with not correct password.");
	}
	%>
	
	</br>
<%	if(do1.authenticate("root", "123456")) {
		out.println("pass authenticate test with correct password.");
	}
	else {
		out.println("fail authenticate test with correct password.");
	}
%>
</br>
<%
	//user exist test
	if(!do1.userExist("trojan")) {
		out.println("pass user not exist test.");
	}
	else {
		out.println("fail user not exist test.");
	}
%>
</br>
<%
	if(do1.userExist("root")) {
		out.println("pass user exist test.");
	}
	else {
		out.println("fail user exist test.");
	}
%>
</br>
Course title test: 
<%
	out.println(do1.getCourseTitle("CSCI201"));
%>
</br>
Course Description test:
<%
out.println(do1.getDescription("CSCI201"));
%>
<br/>
get professor test:
<%
	do1.upload("CSCI201", "20193", "olivera grujic", "4.0", "yes", "yes");
	do1.upload("CSCI201", "20191", "jeff miller", "3.7", "yes", "no");
	do1.upload("CSCI201", "20192", "jeff miller", "4.0", "no", "yes");
	ArrayList<String> professors = do1.getProfessors("CSCI201");
	for(String professor : professors){
		out.println(professor + " ");
	}
%>
</br>
get term test:
<%
	ArrayList<String> terms = do1.getTerms("CSCI201");
	for(String term : terms){
		out.println(term + " ");
	}
%>
</br>
get gpa test:
<%
	out.println(do1.getGPA("CSCI201"));
%>
</body>
</html>
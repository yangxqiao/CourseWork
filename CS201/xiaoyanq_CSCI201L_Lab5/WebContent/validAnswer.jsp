<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form name="myform" method="GET">
		<%
			String fname = request.getParameter("fname");
	 		String lname = request.getParameter("lname");
	 		String email = request.getParameter("email");
		%>
		<h1>Submitted Data</h1>
		<p>First Name:<strong><%= fname %></strong><br /></p>
		<p>Last Name:<strong><%= lname %></strong><br /></p>
		<p>Email Name:<strong><%= email %></strong><br /></p>
	</form>
</body>
</html> 
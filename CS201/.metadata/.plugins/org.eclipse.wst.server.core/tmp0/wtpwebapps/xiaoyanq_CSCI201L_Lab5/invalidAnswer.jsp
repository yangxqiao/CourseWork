<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Sample Form</title>
</head>
<body>
	<form name="myform" method="GET" action="my_servlet">
	<%
		String errorMsg = (String)request.getAttribute("errorMsg");
	%>
		First_Name <input type="text" name="fname" /><br /> 
		<p id="fname"><%= errorMsg %></p>
<%-- 		<% if(errorMsg == null){ %>
		<% document.getElementById("none").style.display = 'none'; %> --%>
		Last_Name <input type="text" name="lname" /><br />  
		<p><%= errorMsg %></p>
		Email <input type="email" name="email" /><br />
		<p><%= errorMsg %></p>
		
		<input type="submit" name="submit" value="Submit" />
		<input type="reset" name="reset" value="reset" />
	</form>
</body>
</html>	
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Register Page</title>
<link rel="stylesheet" type="text/css" href="RegisterPage.css" />


</head>
<body>

	<div id="header">
	
		<form name="myform" action="SearchServlet">
			<div id="search">
				<input id="search-button" type="submit" name="submit" value="Submit" />
				<input id="input" type="text" name="search-bar" placeholder=" Search...">
			</div>

			<div id="choice">		
				<label class="radio"> 
					<input type="radio" name="radio-button" value="Professor" id="radio1">
					Professor 
				</label>
				
				<label class="radio"> 
					<input type="radio" name="radio-button" value="Course" id="radio2"> 
					Course
				</label>
			</div>
<%
	String n = (String)session.getAttribute("login");
	if(n == "true"){ //someone logged in
%>
		<a href="LogoutServlet"><div id="right-button"> Sign out </div></a>
		<a href="Upload.jsp"><div id="left-button"> Upload GPA </div></a>
<%
	}else{
%>		
		<a href="LoginPage.jsp"><div id="right-button"> Sign In </div></a>
		<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a>
<%
	}
%>
<!-- 			<a href="LoginPage.jsp"><div id="right-button"> Sign In </div></a>
			<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a> -->
		</form>
			
			
		<div class='clear-float'></div>

	</div>
	

	<div id="main">
		<form name="regform" action="RegisterServlet">
		
			<div id="errMsg"><%=session.getAttribute("errMsg") != null ? session.getAttribute("errMsg") : "" %></div>
			
			<div class="info">
				<h3>Username</h3>
				<input id="username" type="text" name="username" /><br /> 
			</div>
			
			<div class="info">
				<h3>Password</h3>
				 <input id="password" type="text" name="password" /><br />
			</div>

			<div class="info">
				<h3>Confirm Password</h3>
				 <input id="confirm-password" type="text" name="confirm" /><br />
			</div>
			
			<div id="button">
				<input id="submit" type="submit" name="submit" value="Register" />
			</div>	

			<div class='clear-float'></div>
		</form>
	
	</div>
	
</body>
</html>
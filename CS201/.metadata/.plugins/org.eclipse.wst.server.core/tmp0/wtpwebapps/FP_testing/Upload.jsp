<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<%@ page import="Database.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Upload</title>
<style type="text/css">
	body{
		margin: 0px;
		background-color: #FFF4F4;
	}

	#header{
		height: 100px;
		background-color: #000;
		color: #D56AA0;
	}

	.clear-float{
		clear: both;
	}

	#search{
		float: left;
		line-height: 100px;
		text-align: center;
		margin-left: 10%;
	}

	#search-button{
		margin-left: 10px;
		height: 30px;
		width: 70px;
		color: #FFF;
		font-size: 13px;
		border-radius: 5px;
		background-color: #D56AA0;
	}

	#input{
		margin-left: 10px;
		height: 25px;
		width: 400px;
		font-size: 13px;
		border-radius: 5px;
	}

	#choice{
		float: left;
		text-align: center;
		line-height: 100px;
		font-size: 17px;
		margin-left: 40px;
		color: #FFC7D4;
	}
	
	.radio{
		margin-right: 15px;
	}

	#left-button{
		float: right;
		line-height: 100px;
		color: #FFC7D4;
		margin-right: 50px;
	}

	#right-button{
		float: right;
		line-height: 100px;
		color: #FFC7D4;
		margin-right: 10%;
	}
</style>
</head>
<body>
<script type="text/javascript"> 
	var msg = "<%=session.getAttribute("message")%>";
	if(msg != null)
		alert(msg);
</script>
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
	String n = (String)session.getAttribute("username");
	if(n!=null){ //someone logged in
%>
		<a href="LogoutServlet"><div id="right-button"> Sign out </div></a>
		<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a>
		<!-- <a href="Upload.jsp"><div id="left-button"> Upload GPA </div></a> -->
<%
	}else{
%>		
		<a href="RegisterPage.jsp"><div id="right-button"> Register </div></a>
		<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a>
<%
	}
%>
			<!-- <a href="RegisterPage.jsp"><div id="right-button"> Register </div></a>
			<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a> -->
		</form>
			
			
		<div class='clear-float'></div>
	</div>
	
	<h3 style="text-align:center">Upload Your GPA</h3>
	<hr class="line" style="width:100%; position:relative;left:0%;"></hr>
	
	<form style="padding-left:60px;"name="upload" method="POST" action="UploadServlet">
		<h4 style="color:grey">Select a Course</h4>
		<select name="course">
		    <%
		Database db = new Database();
		ArrayList<String[]> courses = db.getCourses();
		for(String[] course : courses){
		%>
		    <option value="<%=course[0]%>"><%=course[1]%></option>
		<%
		}
		%>
  		</select>
		
		<h4 style="color:grey">Select a Term</h4>
		<select name="term">
			<%
		for(int i = 2010; i < 2021; i++){
			for(int j =1; j <= 3; j++){
				String termNumber = ""+i+j;
				String term = i+" ";
				if(j==1){ term += "Spring"; }
				else if(j==2){ term += "Summer"; }
				else if(j==3){ term += "Fall"; }
		%>
			<option value="<%= termNumber %>"><%= term %></option>
		<%
			}
		}
		%>
  		</select>
		
		<h4 style="color:grey">Professor</h4>
		<select name="professor">
			<%
		ArrayList<String[]> professors = new ArrayList<>();
		professors = db.getProfessors();
		for(String[] professor : professors){
		%>
			<option value="<%=professor[0]%>"><%=professor[1] %></option>
		<%
		}
		%>
  		</select>
  		
  		<h4 style="color:grey">Your GPA</h4>
  		<select name="gpa">
  			<option value = "4.0">4.0</option>
  			<option value = "3.7">3.7</option>
  			<option value = "3.3">3.3</option>
  			<option value = "3.0">3.0</option>
  			<option value = "2.7">2.7</option>
  			<option value = "2.3">2.3</option>
  			<option value = "2.0">2.0</option>
  			<option value = "1.7">1.7</option>
  		</select>
  		<h4 style="color:grey">Do you recommend this course with this professor?</h4>
  			<input type="radio" name="recommend" value="yes">Yes
  			<input type="radio" name="recommend" value="no">No
  		<h4 style="color:grey">Is this course challenging for you?</h4>
  			<input type="radio" name="challenging" value="yes">Yes
  			<input type="radio" name="challenging" value="no">No
  			
		<br /><br /><br />
		<input class="button" type="submit">
		
	</form>
</body>
</html>
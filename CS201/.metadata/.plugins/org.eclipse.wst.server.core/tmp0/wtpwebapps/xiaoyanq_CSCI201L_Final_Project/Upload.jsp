<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.*" %>
<%@ page import="Database.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Upload</title>

<!-- Import external CSS -->
<link rel="stylesheet" type="text/css" href="Uploadpage.css" />
<!-- Import Google Fonts -->
<link href="https://fonts.googleapis.com/css?family=Public+Sans&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Lato|Public+Sans&display=swap" rel="stylesheet">

<!-- Import JavaScript -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>

<style>
	body {
		/* background: #DEC5D2; */	    	
	}
	
	#header {
		background-image: url(images/background1.jpg);
		/* background-color: rgba(140, 140, 140, 0.2); */
	    height: 900px;
	    background-size: cover;
	    background-position: center; 
	}
	
	#topbar {
		background-color: #EFEDEF;
		color:  #7A797A;
		opacity: 0.85;
		z-index: 1;
	    top: 0;
	    width: 100%;
		position: fixed;
	}
	
	#header-left {
		float:left;
		width:980px;
	}
	
	#header-right {
		float:left;
		width:250px; 
		margin-right:0;
	}
	
    #header-right #right-button {
    	text-decoration: none;
    	color: #EA70A7;
    }

    #header-right #right-button:hover {
      	color: #7A797A;
    }
    
    #header-right #left-button {
	    text-decoration: none;
	    color: #EA70A7;
    }

    #header-right #left-button:hover {
      	color: #7A797A;
    }		
	
	html, body {
		height: 100%;
	    margin: 0;
	    padding: 0;
	}
	
	#choice{
		float: left;
		text-align: center;
		line-height: 58px;
		margin-left: 40px;
		color: #EA70A7;
		font-size: 18px;
		font-family: 'Lato', sans-serif;
	}
	
	#left-button{
		float:right;
		font-size: 18px;
		line-height: 62px;
		color: #EA70A7;
		font-family: 'Lato', sans-serif;
	}
	
	#right-button{
		float: right;
		font-size: 18px;
		line-height: 60px;
		color: #EA70A7;
		margin-left:40px;
		font-family: 'Lato', sans-serif;
	}
	
	#search{
		float: left;
		line-height: 60px;
		text-align: center;
		margin-left: 15px;
		position:relative;
	}
	
	#input {
		width: 450px;
		height: 33px;
		border-radius: 20px;
		padding-right: 30px;
	}
	
	.form-control::-webkit-input-placeholder { 
		font-family: 'Public Sans', sans-serif;
		color: #D3D3D3;
	}
	
	#search #icon {
		position: absolute;
		padding-right: 10px;
		padding-top: 22px;
		pointer-events: none;
	}
	
	#search:hover > #icon {color:#EA70A7;}
	
	#search .glyphicon {right: 0px;}
	
	.radio{
		margin-right: 15px;
		font-weight: normal;
		font-family: 'Lato', sans-serif;
	}

	#home-icon-div img {
		float: left;
		height: 35px;
		margin-top: 13px;
		margin-left: 40px;
	}
	
	.clear-float{
		clear: both;
	}
	
	#footer {
	    text-align: center;
	    background-color: #EFEDEF;
	    color: #7A797A;
	    height: 35px; 
	    position: relative;
    }

    #footer p{
	    line-height: 35px;
	    margin: 0px;
    }
    
    #main {
    	background-color: rgba(199, 169, 183, 0.6);
    	height: 74%;
		width: 100%;
		margin-right:0;
		margin-top:2%;		 	
		margin-left:0;
		margin-bottom:0;
    }
    
    h3 {
    	color: white;
    	text-shadow: 0px 2px 2px rgba(0,0,0,0.4);
    	font-size: 18px;
    	font-weight: bold;
    }
    
    .radio-class{
    	color: white;
    	text-shadow: 0px 2px 2px rgba(0,0,0,0.4);
    	font-size: 16px;
    }
    
    #placeholder {
    	height: 75px;
    }
    
    #error_msg {
    	border-left: 5px solid #cc0000;
    	color: #cc0000;
    	font-weight:bold;
    	margin-left: 16px;
    	width:390px;
    	margin-top: 25px;
    	background-color: white;
    	padding-top:5px;
    	padding-bottom: 5px;
    	font-size: 16px;
    	visibility: hidden;
    }
    
    #submit{
		height: 44px;
		width: 392px;
		font-size: 18px;
		font-weight:bold;
		margin-top: 40px;
		padding-top: 1px;
		color: white;
		border-radius: 5px;
		background-color: #D56AA0;
		font-family: 'Lato', sans-serif;
	}

</style>
<script>
	function updateError() {
		var error_msg = document.getElementById('error_msg');
		error_msg.style.visibility = 'visible';
	}
	
	function updateSuccess() {
		var error_msg = document.getElementById('error_msg');
		error_msg.style.visibility = 'visible';
		error_msg.style.color = '#36703F';
		error_msg.style.borderLeftColor = '#36703F';
	}
</script>
</head>
<body>

	<div id="header">
	<div id="topbar">
	<div id="header-left">
	
		<form id="form" class="form-inline active-pink-4" name="myform" action="SearchServlet">
		
			<div id="home-icon-div">
				<a href="Homepage.jsp"><img src="home-icon.png"></a>
			</div><!-- home icon div -->
			
			<!-- Search form -->
			<div id="search">
				<i id="icon" class="glyphicon glyphicon-search"></i>
			    <input id="input" name="search-bar" type="text" class="form-control form-control-sm mr-3 w-75" placeholder="SEARCH FOR A COURSE" />
			</div><!-- search -->

			<div id="choice">
				<label class="radio"> 
					<input type="radio" name="radio-button" value="Professor">
					Professor 
				</label><!-- radio -->
				
				<label class="radio"> 
					<input type="radio" name="radio-button" value="Course"> 
					Course
				</label><!-- radio -->
			</div><!-- choice -->
		</form><!-- myform -->
	
	</div><!-- header left -->
	
	<div id="header-right">

<%
	String n = (String)session.getAttribute("username");
	if(n!=null){ //someone logged in
%>
		<a href="LogoutServlet"><div id="right-button"> Sign out </div></a>
<%
	}else{
%>		
		<a href="LoginPage.jsp"><div id="right-button"> Sign In </div></a>
<%
	}
%>

	</div><!-- header right -->
	</div><!-- topbar -->
	<div class='clear-float'></div>

	<div id="placeholder"></div>
	
	<!-- <h3 style="text-align:center">Upload Your GPA</h3>
	<hr class="line" style="width:100%; position:relative;left:0%;"></hr> -->
	
	<div class="container" id='main'>
  		<form name="upload" action="UploadServlet">
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Select a Course</h3>
					<select name="course" class="input-field">
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
				<br />	
					
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Select a Term</h3>
					<select name="term" class="input-field">
				<%for(int i = 2010; i < 2021; i++){
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
				<br />						
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Select a Professor</h3>
					<select name="professor" class="input-field">
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
				<br />						
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>What's your GPA?</h3>
					<select name="gpa" class="input-field">
					<option value = "4.0">4.0</option>
		  			<option value = "3.7">3.7</option>
		  			<option value = "3.3">3.3</option>
		  			<option value = "3.0">3.0</option>
		  			<option value = "2.7">2.7</option>
		  			<option value = "2.3">2.3</option>
		  			<option value = "2.0">2.0</option>
		  			<option value = "1.7">1.7</option>
		  		</select>
				<br />						
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Do you recommend this course with this professor?</h3>
					<input class="radio-class" type="radio" name="recommend" value="yes"><strong class="radio-class"> Yes </strong>
  					<input class="radio-class" type="radio" name="recommend" value="no"><strong class="radio-class"> No </strong>
				<br />						
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Is this course challenging for you?</h3>
					<input type="radio" name="challenging" value="yes"><strong class="radio-class"> Yes </strong>
  					<input type="radio" name="challenging" value="no"><strong class="radio-class"> No </strong>  					
				<br />						
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="col-lg-4">
					<input id="submit" type="submit" name="submit"/>
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
		
			
		</form>
		<div class="row">
			<div class="col-lg-4"></div>
			<div class="col-lg-4" id="error_msg" style="background:#EFEDEF">
			<% if (request.getAttribute("error") != null) {%>
				Error: <%= request.getAttribute("error") != null ? request.getAttribute("error"):"" %>
				<script>
				updateError();
				</script>
			<% } 
			if (request.getAttribute("success") != null) {%>
			   		You have uploaded successfully
			   		<script>
					updateSuccess();
					</script>
			<% } %>
		    </div><!-- error-msg -->
		    <div class="col-lg-4"></div>
		</div><!-- row -->
	</div><!-- container -->
	</div><!-- header -->
	<div id="footer"> <p> Yang Qiao | Kate Hu | Blair Niu | Jessie Zhang | Mage Zhang | Irene Li &copy; 2019 </p> </div>
	
	
	
</body>
</html>
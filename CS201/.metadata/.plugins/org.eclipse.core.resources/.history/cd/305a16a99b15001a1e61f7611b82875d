<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Login Page</title>

<!-- Import external CSS -->
<link rel="stylesheet" type="text/css" href="LoginPage.css" />

<!-- Import Google Fonts -->
<link href="https://fonts.googleapis.com/css?family=Public+Sans&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Lato|Public+Sans&display=swap" rel="stylesheet">

<!-- Import JavaScript -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>

<style>	
	#header{
		background-image: url(images/background1.jpg);
	    height: 900px;
	    background-size: cover;
	    background-position: center; 
	    width: 100%;
	}
	
	#topbar{
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
		width: 80%;
		margin-right: 0;
	}
	
	#header-right {
		width: 20%;
		display: inline-block;
		margin-right:0;
		margin-left: 0;
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
		margin-right: 30px;
	}
	
	#right-button{
	 	display: inline-block; 
		float: right;
		font-size: 18px;
		line-height: 60px;
		color: #EA70A7;
		margin-left: 0px;
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
	
	#container {
		margin-left:0;
	}
	#footer
    {
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
    	height:490px;
    }
    
    h3 {
    	color: white;
    	text-shadow: 0px 2px 2px rgba(0,0,0,0.4);
    	font-size: 18px;
    	font-weight: bold;
    }
    
    #placeholder {
    	height: 130px;
    }
    
    #username, #password{
		width: 100%;
		height: 35px;
		border-radius: 5px;
		color: black;
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
		<a href="Upload.jsp"><div id="left-button"> Upload GPA </div></a>
<%
	}else{
%>		
		<a href="RegisterPage.jsp"><div id="right-button"> Register </div></a>
<%
	}
%>

	</div><!-- header right -->
	<div class='clear-float'></div>
	</div><!-- topbar -->
	
	<div id="placeholder"></div>
	
	<div class="container" id="main">	
		<form name="loginform" action="LoginServlet">
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Username</h3>
					<input id="username" type="text" name="username" /><br />
				</div>
				<div class="col-lg-4"></div>
			</div><!-- row -->
			
			<div class="row">
				<div class="col-lg-4"></div>
				<div class="info col-lg-4">
					<h3>Password</h3>
					 <input id="password" type="password" name="password" /><br />
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
			Error:
			<%= request.getAttribute("error") != null ? request.getAttribute("error"):"" %>
			<% if (request.getAttribute("error") != null) {%>
					<script>
					updateError();
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
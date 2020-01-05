<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"
%>
<%@ page import="java.util.*" %>
<%@ page import="Database.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>SeCure that A|search results</title>

<!-- Import external CSS -->
<link rel="stylesheet" type="text/css" href="searchresults.css" />

<!-- Import Google Fonts -->
<link href="https://fonts.googleapis.com/css?family=Public+Sans&display=swap" rel="stylesheet">
<link href="https://fonts.googleapis.com/css?family=Lato|Public+Sans&display=swap" rel="stylesheet">

<!-- Import JavaScript -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>

<style>	
	#header{
		height: 60px;
		background-color: #EFEDEF;
		color:  #7A797A;
		opacity: 0.85;
		z-index: 1;
	    top: 0;
	    width: 100%;
	}
	
	#header-left {
		float:left;
		width:960px;
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
	
	body{
		margin: 0px;
		background-color: #FFF4F4;
		color: #FFC7D4;
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
		margin-left: 30px;
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
		margin-left: 30px;
	}
	
	.clear-float{
		clear: both;
	}

</style>
</head>
<body>
	<div id="header">
	
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
		<a href="LoginPage.jsp"><div id="left-button"> Login </div></a> 
<%
	}
%>

	</div><!-- header right -->
	<div class='clear-float'></div>
	</div><!-- header -->
	
	<div id="results">
<%
    String input = request.getParameter("search-bar");
%>	
		<h3 id="result-title">Results for "<%= input %>"</h3><hr/>
<%
		Database db = new Database();	
		String searchby = (String)request.getAttribute("resultsby");
		Vector<String> res = new Vector<String>();
		if(searchby==null){
			System.out.println("searchby is null");//for debug
		}
		else{System.out.println("searchby "+searchby);//for debug
		if(searchby.contentEquals("Course")){
			res = db.searchCourseByCourse(input);
		}
		else{
			res = db.searchCourseByProf(input);
		}}
		if(res.size()==0){
%>
<p>No results...try again!</p>
<%
		}
		else{
		for(int i=0; i<res.size(); i++){
			String coursename = res.elementAt(i);
			String coursetitle = db.getCourseTitle(coursename);
			String coursedescription=db.getDescription(coursename);
			double gpa = db.getGPA(coursename);
			int temp = (int)(gpa*100);
			gpa = temp/100.0;
%>
		<div class="single-result">
			<div class="course-card">				
				<div class="course-id">
<%
	if(n!=null){ //someone logged in
%>
		<a href="Detail.jsp?courseName=<%=coursename%>&courseDescription=<%=coursedescription%>">
					<%=coursename %></a>
<%
	}else{ //guest, no access to details page
%>		
<!-- Trigger/Open The Modal -->
<a name="myBtn"><%=coursename %></a>
<%
	}
%>
				</div>
				
				<div class="course-title"><%=coursetitle%></div>
				<div class="course-discription">
					<p><%=coursedescription%></p>
				</div>
			</div>
			<div class="gpa">
				<div class="gpa-title">
					<!-- <strong></strong> <br /> -->
					<h3 style="margin: 0; padding: 0;">Overall GPA</h3>
				</div>
				<div class="gpa-number">
				<%if(gpa>=0){%>
					<strong><%= gpa%></strong>
				<%}else{%>
					<strong>N/A</strong>
				<%}%>
				</div>
			</div>
		</div>
		<br>
<%
		}}
%>
	</div>


	<div id="sidebar">
		<h2 id="sidebar-title">Recommended</h2>
		
<%	
		Vector<String> recomm = new Vector<String>();
		if(searchby==null){
			System.out.println("searchby is null");//for debug
		}
		else{System.out.println("searchby "+searchby);//for debug
		if(searchby.contentEquals("Course")){
			recomm = db.getRecommendByCourse(input);
		}
		else{
			recomm = db.getRecommendByProf(input);
		}}		
		if(recomm.size()==0){
%>
		<p>Nothing to recommend</p>
<%
		}
		else{
		for(int i=0; i<recomm.size(); i++){
			String coursename = recomm.elementAt(i);
			String coursetitle = db.getCourseTitle(coursename);
			String coursedescription=db.getDescription(coursename);
%>
		<div class="recommend">
		<%
	if(n!=null){ //someone logged in
%>
		<a href="Detail.jsp?courseName=<%=coursename%>&courseDescription=<%=coursedescription%>">
					<h3><%=coursename %></h3></a>
<%
	}else{ //guest, no access to details page
%>		
<!-- Trigger/Open The Modal -->
<a name="myBtn"><h3><%=coursename %></h3></a>
<%
	}
%>
			
			<p><%=coursetitle%></p>
		</div>
<%
		}}
%>

	</div>

<!-- The Modal -->
<div id="myModal" class="modal">
  <!-- Modal content -->
  <div class="modal-content">
    <span class="close">&times;</span>
    <p><strong>Please log in to view course details</strong></p>
  </div>
</div>	
<script>
// Get the modal
var modal = document.getElementById("myModal");

// Get the button that opens the modal
//var btn = document.getElementById("myBtn");
var btns = document.getElementsByName("myBtn");

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close")[0];

// When the user clicks the button, open the modal 
for(var i=0; i<btns.length; i++){
	btns[i].onclick = function() {
	  modal.style.display = "block";
	}
}

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
  modal.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}
</script>

</body>
</html>
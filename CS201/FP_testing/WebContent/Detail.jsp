<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import = "java.util.ArrayList"%>
    <%@ page import="Database.Database" %>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>Detail Page</title>
		
		<!-- Import external CSS -->
		<link rel="stylesheet" type="text/css" href="DetailPage.css" />
		
		<!-- Import Google Fonts -->
		<link href="https://fonts.googleapis.com/css?family=Public+Sans&display=swap" rel="stylesheet">
		<link href="https://fonts.googleapis.com/css?family=Lato|Public+Sans&display=swap" rel="stylesheet">
		
		<!-- Import JavaScript -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>

		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    	<script type="text/javascript">
    	
    	
    	//for debug-Jessie
    	console.log("courseName:"+"<%=request.getParameter("courseName")%>");
    	console.log("courseDescription:"+"<%=request.getParameter("courseDescription")%>");
    	
      		google.charts.load("current", {packages:['corechart']});
      		google.charts.setOnLoadCallback(drawChart);
      		
      		function drawChart(){
      			console.log("in getChartInfo()");
      			var xhttp = new XMLHttpRequest();
      			var term = document.getElementById('term-dropdown').value;
      			/* xhttp.open("GET", "chartServlet?term=" + term.options[term.selectedIndex].text + "&course=" + document.getElementById("course").value, true); */
      		 	xhttp.open("GET", "chartServlet?term=20193&course=CSCI104", true); 
      			var id = 'columnchart_values';
      			
      			xhttp.onload = function(){
       				var listProfessor = (<%=(ArrayList<String>)session.getAttribute("listProfessor") %>);
      				var listGPA = (<%=(ArrayList<Integer>)session.getAttribute("listGPA") %>); 
      				
          			var id = "columnchart_values";
          			
            		var data = google.visualization.arrayToDataTable([
              			["Professor", "GPA", { role: "style" } ],
               		 	["", 0.0, "#FFF4F4"], 
            		]);
    				
             		var colorList = ["#809BCE", "#95B8D1", "#B8E0D2", "#D6EADF", "#EAC4D5", "#E87461", "#E0C879", "#D5D887", "#A1CF6B", "#7AC74F"];
             	
           			var i;
          			var j  = listProfessor.length;
          			for (i = 0; i < j; i++) {
          				data.addRows([[listProfessor[i], listGPA[i], colorList[i]]]);
          			}
    	
           			var view = new google.visualization.DataView(data);
            		view.setColumns(
    	        	[0, 1,
    	            	{ 
    	        			calc: "stringify",
    	                	sourceColumn: 1,
    	                	type: "string",
    	                	role: "annotation" 
    	                },
    	            2]);
    	
    		        var options = {
    		        	title: "GPA of CSCI201 in Fall 2019",
    		        	width: 600,
    		        	height: 400,
    		        	bar: {groupWidth: "90%"},
    		        	legend: { position: "none" },
    		        	backgroundColor: '#FFF4F4',
    		        };
    	      		var chart = new google.visualization.ColumnChart(document.getElementById(id));
    	      		chart.draw(view, options);
      			}
      			xhttp.send();		
      		}

		</script>
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
		width:980px;
	}
	
	#header-right {
		float:left;
		width:280px;
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
		margin-right: 35px;
	}
	
	#right-button{
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
	String coursename = request.getParameter("courseName");
	String coursedescription = request.getParameter("courseDescription");
	String n = (String)session.getAttribute("username");
	if(n!=null){ //someone logged in
%>
		<a href="LogoutServlet"><div id="right-button"> Sign out </div></a>
		<a href="Upload.jsp"><div id="left-button"> Upload GPA </div></a>
<%
	}else{
%>		
		<a href="RegisterPage.jsp"><div id="right-button"> Register </div></a>
		<a href="Homepage.jsp"><div id="left-button"> Homepage </div></a>
<%
	}
%>
	</div><!-- header right -->
	<div class='clear-float'></div>
	</div><!-- header -->
	
	<div>
<%-- 		<h1 id="course"><%=request.getAttribute("courseName")%></h1>
		<h3><%=request.getAttribute("courseDescription")%></h3> --%>
		
		<h1 id="course"><%=coursename%></h1>
		<h3><%=coursedescription%></h3>
	</div>
	<hr class="line" style="width:100%; position:relative;left:0%;"></hr>
	
	<table>
		<tr>
			<td>
				<h4 style="color:grey">Term</h4>
 				<select id="term-dropdown" name="term" onchange="select(); drawChart();">
					<option value="none">Select a Term</option>
					<%				
						Database db = new Database();
						ArrayList<String> terms = (ArrayList<String>)(db.getTerms(coursename));
					if(terms==null){
						System.out.println("in details,terms:"+terms);	
					}else{
						for(int i = 0; i < terms.size(); i++){
					%>
						<option value="<%=terms.get(i)%>"><%=terms.get(i)%></option>
					<% 
						}}
					%>
		  		</select>
		  	
		  	<td>
		  		<h4 style="color:grey">Professor</h4>
 				<select name="professor" id="professor-dropdown" onchange="select()">
					<option value="none">Select a Professor</option>
					<%
						ArrayList<String> professors = (ArrayList<String>)(db.getProfessors(coursename));
					if(terms==null){
						System.out.println("in details,professors:"+terms);	
					}else{	
					for(int i = 0; i < professors.size(); i++){
					%>
						<option value="<%=professors.get(i)%>"><%=professors.get(i)%></option>
					<% 
						}}
					%>
		  		</select> 
		  	
		</tr>
	</table>
	
	<h1>The average GPA for <span id="term"></span> by <span id="professor"></span> is</h1>
	<div id="specificGPA" style="text-align:center"></div>
	<p id="challenging"></p>
	<p id="recommendRate"></p>
	
	<div id="columnchart_values"></div>
	
	<script>
		function select(){
			//console.log("in select()");			
			var term = document.getElementById("term-dropdown").value;
			var professor = document.getElementById("professor-dropdown").value;
			console.log("in jsp, term:"+term);
			console.log("in jsp, professor:"+professor);
			if(term == "none"){
 				document.getElementById("term").innerHTML = "all terms";
 			}
 			else{
 				document.getElementById("term").innerHTML = term;
 			}
 			if(professor == "none"){
 				document.getElementById("professor").innerHTML = "all professors";
 			}
 			else{
 				document.getElementById("professor").innerHTML = professor;
 			}
			
	 		var xhr = new XMLHttpRequest();
		 	xhr.open('GET',"DetailServlet?term="+term+"&professor="+professor+"&courseName="+"<%=coursename%>",false);
		 	xhr.send();
			
	 		console.log(xhr.responseText);
	 		var str = xhr.responseText;
	 		var arr = str.split(" ");
	 		if(arr[0]!=-1){
	 			document.getElementById("specificGPA").innerHTML=arr[0];
	 		}
	 		if(arr[1]!=-1){
				document.getElementById("challenging").innerHTML=arr[1]+'% of the students think this course is challenging.';
	 		}
			if(arr[2]!=-1){
				document.getElementById("recommendRate").innerHTML=arr[2]+'% of the students recommend this course with this professor.';
			}
		 	<%-- document.getElementById("specificGPA").innerHTML="<%=session.getAttribute("specificGPA") %>";
			document.getElementById("challenging").innerHTML="<%=session.getAttribute("challenging") %>"+'% of the students think the course with this professor is challenging.';
		 	document.getElementById("recommendRate").innerHTML="<%=session.getAttribute("recommendRate") %>"+ '% of the students recommend this course with this professor.';--%>		 			
		}
		
	</script>
</body>
</html>
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
	
	#main {
		margin-left:auto;
		margin-right:auto;
		width:800px;
		color:grey;
	}
	
	#course-info {
		padding-top: 20px;
	}
	
	.clear-float{
		clear: both;
	}
	
	#course-name {
		font-family: 'Lato', sans-serif;
		font-weight: bold;
		color: #336699;
	}
	
	#course-description {
		font-family: 'Lato', sans-serif;
		font-size: 18px;
	}
	
	.right-professor {
		margin-left:30px;
	}
	
	#term-div, #professor-div {
		border: 1px solid white;
		border-radius: 20px;
		text-align:center;
		background: white;
		margin-bottom: 10px;
		height: 37px;
	}
	
	#noselect {
		font-family: 'Lato', sans-serif;
		font-size: 20px;
		font-weight: bold;
	}
	
	#average {
		font-family: 'Lato', sans-serif;
		font-size: 20px;
		font-weight: bold;
	}
	
	#specificGPA {
		border-radius: 40px;
		height: 70px;
		width: 160px;
		background: #336699;
		color: #FFC7D4;
		font-family: 'Lato', sans-serif;
		font-size: 40px;
		font-weight: bold;
		margin-left: 320px;
		padding-top: 5px;
		margin-top: 20px;
	}
	
	#challenging {
		font-family: 'Lato', sans-serif;
		font-size: 20px;
		margin-top: 20px;
		font-weight: bold;
	}
	
	#recommendRate {
		font-family: 'Lato', sans-serif;
		font-size: 20px;
		font-weight: bold;
	}
	
	#columnchart_values {
		width:600px;
		height: 400px;
		margin-right: auto;
		margin-left: auto;
		margin-top: 10px;
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
	
<div id="main">
	
	<div id='course-info'>		
		<h1 id="course-name"><%=coursename%></h1>
		<h3 id='course-description'><%=coursedescription%></h3>
	</div><!-- course info -->
	<hr class="line" style="width:100%; position:relative;left:0%;"></hr>
	
	<table>
		<tr>
			<td>
				<div id='term-div'>
					<h4 style="color:#FFC7D4; font-weight:bold;">Term</h4>
				</div><!-- term div -->
 				<select id="term-dropdown" name="term" onchange="select();drawChart();">
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
		  		<div class='right-professor'>
		  		<div id='professor-div'>
		  			<h4 style="color:#FFC7D4; font-weight: bold;">Professor</h4>
		  		</div><!-- professor div -->
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
		  		</div><!-- right professor -->
		  	
		</tr>
	</table>
	
	<h1 id="noselect">Please select terms and/or professors to view details :)</h1>
	<h1 id="nodata" style="display:none;">No data available.</h1>
	<h1 id="average" style="display:none;">The average GPA for <span id="term"></span> by <span id="professor"></span> is</h1>
	<div id="specificGPA" style="text-align:center;display:none;"></div>
	<p id="challenging"></p>
	<p id="recommendRate"></p>
	
	<div id="columnchart_values"></div>
	
<script>

function select(){		
	document.getElementById("nodata").style.display="none";
	document.getElementById("challenging").style.display="none";
	document.getElementById("recommendRate").style.display="none";
	document.getElementById("average").style.display="none";
	document.getElementById("specificGPA").style.display="none";
	var term = document.getElementById("term-dropdown").value;
	var professor = document.getElementById("professor-dropdown").value;
	console.log("in jsp, term:"+term);
	console.log("in jsp, professor:"+professor);
	if(professor!="none"){
		var names = professor.split(" ");
		var fname = names[0];
		var lname = names[1];
		fname = fname[0].toUpperCase()+fname.substring(1);
		lname = lname[0].toUpperCase()+lname.substring(1); 
	} 
	
	if(term=="none" && professor=="none"){
		document.getElementById("noselect").style.display="block";
		return;
	}
	else{
		document.getElementById("noselect").style.display="none";
		document.getElementById("average").style.display="block";
		document.getElementById("specificGPA").style.display="block";
		if(term == "none"){
				document.getElementById("term").innerHTML = "all terms";
				document.getElementById("professor").innerHTML = fname+" "+lname;
			}
			else if(professor == "none"){
				document.getElementById("term").innerHTML = term;
				document.getElementById("professor").innerHTML = "all professors";
			}
			else{
				document.getElementById("challenging").style.display="block";
				document.getElementById("recommendRate").style.display="block";
				document.getElementById("term").innerHTML = term;
				document.getElementById("professor").innerHTML = fname+" "+lname;
			}
	}
	
	var xhr = new XMLHttpRequest();
 	xhr.open('GET',"DetailServlet?term="+term+"&professor="+professor+"&courseName="+"<%=coursename%>",false);
 	xhr.send();
	
		console.log(xhr.responseText);
		var str = xhr.responseText;
		var arr = str.split(" ");
		if(arr[0]!=-1){
			document.getElementById("specificGPA").innerHTML=arr[0];
			if(arr[1].trim()!=-1){
				document.getElementById("challenging").style.display="block";
				document.getElementById("challenging").innerHTML=arr[1].trim()+'% of the students think '+"<%=coursename%>"+' with '+fname+' '+lname+' is challenging.';
			}
			if (arr[2].trim() != -1) {
				document.getElementById("recommendRate").style.display = "block";
				document.getElementById("recommendRate").innerHTML = arr[2].trim()+'% of the students recommend Professor '+fname+" "+lname+'.';
			}
			if (arr[1].trim() == -1 || arr[2].trim() == -1) {
				document.getElementById("challenging").style.display = "none";
				document.getElementById("recommendRate").style.display = "none";
			}
		} else {
			document.getElementById("challenging").style.display = "none";
			document.getElementById("recommendRate").style.display = "none";
			document.getElementById("specificGPA").style.display = "none";
			document.getElementById("average").style.display = "none";
			document.getElementById("nodata").style.display = "block";
		}
	}

	google.charts.load("current", {packages :['corechart']});
	google.setOnLoadCallback(drawChart);
	var listProfessor = [];
	var listGPAstring = [];
	function drawChart() {
		console.log("in draw chart");
		var term = document.getElementById("term-dropdown").value;
		if (term != "none") {
			var chart = new google.visualization.ColumnChart(document
					.getElementById('columnchart_values'));
			var xhttp = new XMLHttpRequest();
			xhttp.open("GET", "chartServlet?term="+document.getElementById("term").innerHTML+ "&course="+"<%=request.getParameter("courseName")%>", false);
		
		xhttp.send();
		console.log("draw chart responseText:"+xhttp.responseText);
		if (xhttp.responseText!=null)
		{
			console.log("in here"+xhttp.responseText);
			var str = xhttp.responseText;
			var profandgpa = str.split("|");
			var profs = profandgpa[0];
			var gpas = profandgpa[1];
			
			listProfessor = profs.split(",");
			listGPAstring = gpas.split(",")
		} 
			var i;
			var listGPA = [];
			for(i = 0; i < listProfessor.length; i++)
			{
				
				console.log(listProfessor[i]);
				listGPA.push(parseFloat(listGPAstring[i]));
			}
				console.log("listProfessor:"+listProfessor);
				console.log("listGPA"+listGPA);
				
				var data = google.visualization.arrayToDataTable([
      			["Professor", "GPA", { role: "style" } ],
       		 	["", 0.0, "#FFF4F4"], 
    		]);
			
     		var colorList = ["#809BCE", "#95B8D1", "#B8E0D2", "#D6EADF", "#EAC4D5", "#E87461", "#E0C879", "#D5D887", "#A1CF6B", "#7AC74F"];

   			var i;
  			var j  = listProfessor.length;
  			for (i = 0; i < j; i++) {
  				console.log(listProfessor[i]);
  				console.log(listGPA[i]);
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
	        	title: "GPA of " + "<%=request.getParameter("courseName")%>" + " in " + document.getElementById("term").innerHTML,
	        	width: 600,
	        	height: 400,
	        	bar: {groupWidth: "90%"},
	        	legend: { position: "none" },
	        	backgroundColor: '#FFF4F4',
	        };
	        
	      	chart.draw(view, options);
}		 
}



</script>

</div><!-- main -->
</body>
</html>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>HomePage</title>	
		
		<style type="text/css">
			body{
				margin: 0px;
			}
			
			h1{
				margin: 0px;
			}
			
			#header{
				height: 150px;
				width: auto;
				margin: 0px;
			}
			
			.clear-float{
				clear: both;
			}
			
			#book-worm{
				height: 150px;
				width: auto;
				float: left;
			}
			
			#main{
				height: 550px;
				background-image: url("images/background.jpg");
				background-size: cover;
				background-position: center;	
			}
			
			#search{
				padding-top: 250px;
				width: 80%;
				margin-right: auto;
				margin-left: auto;
			}
			
			
			h1{
				color: white;
				
			}
			
			#search-bar{
				width: 100%;
				height: 35px;
				font-size: 20px;
				border-radius: 7px;
			}
			
			#button{
				width: 80%;
				margin: 30px auto;
			}
			
			#search-button{
				height: 40px;
				width: 70px;
				font-size: 32px;
				float: right;
			}
			
			.radio{
				color: white;
				font-size: 17px;
				margin-right: 10%;
			}
			
			#choice{
				margin: 30px auto;
				width: 80%;
				text-align: center;
			}
			
			#login{
				float: right;
				height: 150px;
				width: auto;
				/* border: 2px solid black; */
				margin-right: 30px;
				line-height: 150px;
				color: #5D5E60;
			}
			
			p{
				margin: 0px;
			}
			
			#register{
				float: right;
				height: 150px;
				width: auto;
				/* border: 2px solid black; */
				margin-right: 50px;
				line-height: 150px;
				color: #5D5E60;
			}
		</style>
		
		<script>
			function update(){
				var status = window.localStorage.getItem('status');
			
				if(status)
				{
					if(status == "succeed")
					{
						document.getElementById("login").innerHTML = "<p>Profile</p>";
						document.getElementById("register").innerHTML = "<p>Sign Out</p>";
						document.getElementById("link1").onclick = function() {
							window.localStorage.setItem('status', 'failed');
						  };
						document.getElementById("link2").href = "http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/profile.jsp";
						document.getElementById("link1").href = "http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/HomePage.jsp";
					}
					else{
						document.getElementById("login").innerHTML = "<p>Login</p>";
						document.getElementById("register").innerHTML = "<p>Register</p>";
						document.getElementById("link1").href = "http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/register.jsp";
						document.getElementById("link2").href = "http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/login.jsp";
					}
				}
			}
			
			function validate(e) {
				e.preventDefault();
				var xhttp = new XMLHttpRequest();
				var appKey = "AIzaSyBny4rBlMQ0ITH2ltQhJzQZQm3sdsZ2nNY";
				var requestUrl = "https://www.googleapis.com/books/v1/volumes?q=" 
					+ document.getElementById('search-bar').value 
					+ "&key="
					+ appKey;
				
				if(document.getElementById("radio1").checked)
				{
					requestUrl = "https://www.googleapis.com/books/v1/volumes?q=intitle:" 
						+ document.getElementById('search-bar').value 
						+ "&key="
						+ appKey;
				}
				else if(document.getElementById("radio2").checked)
				{
					requestUrl = "https://www.googleapis.com/books/v1/volumes?q=isbn:" 
						+ document.getElementById('search-bar').value 
						+ "&key="
						+ appKey;
				}
				else if(document.getElementById("radio3").checked)
				{
					requestUrl = "https://www.googleapis.com/books/v1/volumes?q=inauthor:" 
						+ document.getElementById('search-bar').value 
						+ "&key="
						+ appKey;
				}
				else if(document.getElementById("radio4").checked)
				{
					requestUrl = "https://www.googleapis.com/books/v1/volumes?q=inpublisher:" 
						+ document.getElementById('search-bar').value 
						+ "&key="
						+ appKey;
				}
					
				xhttp.open("GET", requestUrl, false);
				xhttp.onload = function(){
					const temp = JSON.parse(xhttp.responseText);
					var numItem = temp['totalItems'];
					
					if(this.status === 200 && document.getElementById('search-bar').value != "" && numItem != 0)
					{

 						if(xhttp.responseText.trim().length > 0) {

							window.localStorage.setItem('result', JSON.stringify(xhttp.responseText));
							window.localStorage.setItem('search-words', document.getElementById('search-bar').value);

							window.location.href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/SearchResults.jsp";
						}
					}
					else{
						alert("Please provide a valid information for the book that you want to search!");
					}
				}
				xhttp.send();
			}
		
		</script>
	</head>
	<body>
		<div id="header"> 
			<img id="book-worm" src="images/bookworm.png">
			
			
			<a id="link1" href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/register.jsp" ><div id="register"><p>Register</p></div></a>
			<a id="link2" href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/login.jsp" onclick=""><div id="login"><p>Login</p></div></a>
			
			<script>
				update();
			</script>
		</div>
	
		<div class='clear-float'></div>
		
		<div id="main">
			<div id="search-section">
				
				<form name="myform" method="get" onsubmit="return validate(event);">
					<div id="search">
						<h1>BookWorm: Just a Mini Program...Happy Days!</h1>
						<input id="search-bar" type="text" name="search-bar" placeholder=" Search for your favorite book!">
					</div>
					
					<div id="choice">
						
						<label class="radio"> 
							<input type="radio" name="radio-button" value="Name" id="radio1">
							Name 
						</label>
						
						<label class="radio"> 
							<input type="radio" name="radio-button" value="ISBN" id="radio2"> 
							ISBN 
						</label>
						
						<label class="radio"> 
							<input type="radio" name="radio-button" value="Author" id="radio3"> 
							Author 
						</label>
					
						<label class="radio"> 
							<input type="radio" name="radio-button" value="Publisher" id="radio4">
							Publisher 
						</label>
						
					</div>
					<div id="button">
						<input type="submit" name="submit" value="Search!" id="search-button">
					</div>
				</form>
			</div>
		</div>
	
	</body>
</html>
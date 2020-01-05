<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Sample Form</title>
	<style type="text/css">
		body{
			margin: 0px;
		}

		#header{
			height: 120px;
			width: 70%;
			margin: 10px auto;
		}

		#book-worm{
			height: 100px;
			width: auto;
			float: left;
		}

		#search-section{
			float: left;
		}

		.clear-float{
			clear: both;
		}

		#search{
			width: 300px;
			height: 120px;
			float: left;
			line-height: 120px;
			text-align: center;
			margin-left: 20px;
			margin-right: 20px;
		}

		#search-bar{
			width: 200px;
			height: 30px;
			font-size: 12px;
			border-radius: 7px;
		}

		#search-button{
			margin-left: 10px;
			height: 20px;
			background-color: #8D8D92;
		}

		#choice{
			float: left;
			text-align: center;
			height: 120px;
			line-height: 120px;
		}
		
		#caption{
			width: 80%;
			margin: auto;
		}
		
		#main{
			width: 65%;
			margin: auto;		
		}
		
		p, #search-words{
			color: #8D8D92;
		}
		
		h2, h3{
			color: #5D5E60;
		}
		
		h2{
			margin: 0px;
		}
		
		.image{
			width: 200px;
			float: left;
		}
		
		.content{
			width: 630px;
			float: right;
		}

		.all-contents{
			margin-bottom: 20px;
		}
		
				#content{
			width: 80%;
			margin-right: auto;
			margin-left: auto;
			margin-top: 50px;
		}
		
		#username, #password{
			width: 100%;
			height: 30px;
		}
		
		#submit{
			width: 100%;
			height: 40px;
			font-size: 20px;
			margin-top: 30px;
			color: white;
			background-color: #5D5E60;
			border-radius: 10px;
		}
		
	</style>
	<script>
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
	
		function val(e){
			var xhttp = new XMLHttpRequest();
			xhttp.open("GET", "login_servlet?username=" + document.loginform.username.value +
				"&password=" + document.loginform.password.value, false);
				xhttp.send();
				if (xhttp.responseText.trim().length > 0) {
					document.getElementById("errorMsg").innerHTML = xhttp.responseText;
					return false;
				}
				else{
					window.localStorage.setItem('status', 'succeed');
					window.localStorage.setItem('username', document.loginform.username.value);
					return true;
				}
		}
		
	</script>
</head>
<body>
	<div id="header">
			<a href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/HomePage.jsp"><img id="book-worm" src="images/bookworm.png"></a>
	
			<div id="search-section">
				<form name="myform" method="get" onsubmit="return validate(event);">
					<div id="search">
						<input id="search-bar" type="text" name="search-bar" placeholder=" What book is on your mind?">
						<input type="image" src="images/magnifying_glass.png" name="submit-button" id="search-button" alt="submit-button">
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
				</form>
			</div>
			
			
		<div class='clear-float'></div>

	</div>
	
	<hr> 

	<div id="content">
		<form name="loginform" method="GET" action="HomePage.jsp" onsubmit="return val(event);">
			
			<div class="info">
				<h3>Username</h3>
				<input id="username" type="text" name="username" /><br /> 
			</div>
			
			<div class="info">
				<h3>Password</h3>
				 <input id="password" type="text" name="password" /><br />
			</div>
			
			<strong><div id="errorMsg"></div></strong><br />
			
			<div id="button">
				<input id="submit" type="submit" name="submit" value="Sumbit" />
			</div>		
		</form>
	
	</div>

</body>
</html>	
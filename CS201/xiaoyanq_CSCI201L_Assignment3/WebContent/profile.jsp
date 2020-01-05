<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="xiaoyanq_CSCI201L_Assignment3.DBManager, 
    xiaoyanq_CSCI201L_Assignment3.bookInfo, 
    java.util.ArrayList"%>
    
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
		
		#profile{
			margin-top: 30px;
			width: 50px;
			float: left;
			margin-left: 40px;
		}
		
		#content{
			width: 65%;
			margin-right: auto;
			margin-left: auto;
		}
		
		#title{
			text-align: center;
			color: #5D5E60;
		}
		
		.left-col{
			width: 40%;
			float: left;
			
		}
		
		.right-col{
			margin-left: 5%;
			width: 55%;
			float: left;
		}
		
		h2, h3{
			color: #5D5E60;
		}
		
		img{
			margin-top: 10px;
		}
		
		.fav{
			
			margin-top: 10px;
			margin-bottom: 20px;
			width: 30%;
			height: 25px;	
			font-size: 16px;
		}
		
		.no-display{
			display: none;
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
		
		function update(){
			var status = window.localStorage.getItem('status');
		
			if(status)
			{
				if(status == "succeed")
				{
					document.getElementById("profile_link").href = "http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/profile.jsp";
					document.getElementById("profile").src = "images/profile.png";
				}
			}
		}
		
		function setTitle(){
			var status = window.localStorage.getItem('status');
			
			if(status)
			{
				
				if(status == "succeed")
				{
					document.getElementById('title').innerHTML = window.localStorage.getItem('username') + "'s favorites:";
				}
			}
			
		}
		
		function getData(){
			var xhttp = new XMLHttpRequest();
			xhttp.open("GET", "profile_servlet?username=" + window.localStorage.getItem('username'), false);
			xhttp.send();
		}

		
		function updateBook(button){
			var ID = button.id;
			var bookId = "book" + ID;
			var bookname = document.getElementById(bookId).innerHTML;
			var xhttp = new XMLHttpRequest();
			xhttp.open("GET", "profile_remove?bookname=" + bookname + 
				"&username=" + window.localStorage.getItem('username')
				, false);
			xhttp.send();
		}
		
		function sendDetail(image)
		{
			var imageId = image.id;	
			var image = document.getElementById(imageId).src;
			var id = imageId.substring(5);
			var bookId = "book" + id;
			var bookname = document.getElementById(bookId).innerHTML;
			var authorId = "author" + id;
			var author = document.getElementById(authorId).innerHTML;
			var publisherId = "publisher" + id;
			var publisher = document.getElementById(publisherId).innerHTML;
			var publishdateId = "publishdate" + id;
			var publishdate = document.getElementById(publishdateId).innerHTML;
			var ISBNid = "ISBN" + id;
			var ISBN = document.getElementById(ISBNid).innerHTML;
			var descriptionId = "Description" + id;
			var description = document.getElementById(descriptionId).innerHTML;
			var ratingId = "rating" + id;
			var rating  = document.getElementById(ratingId).innerHTML;

			window.localStorage.setItem('bookname', bookname);
			window.localStorage.setItem('authorname', author);
			window.localStorage.setItem('description', description);
			window.localStorage.setItem('image', image);
			window.localStorage.setItem('publisher', publisher);
			window.localStorage.setItem('publishedDate', publishdate);
			window.localStorage.setItem('ISBN13', ISBN);
			window.localStorage.setItem('averageRating', rating);
			window.location.href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/Details.jsp";
		}
		
	</script>
</head>
<body>
	<script>
		getData();
	</script>
	
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
			<a id="profile_link" href=""><img id="profile" src=""></a>
			
			<script>
				update();
			</script>
		<div class='clear-float'></div>

	</div>
	
	<hr> 
	
	<div id="content">
	
		<h1 id="title"></h1>
		
		<script>
			setTitle();
		</script>
		
		<hr>
		
		<% String username = (String) session.getAttribute("username");%>
		
		<% 	System.out.println(username);
			DBManager database = new DBManager();
			ArrayList<bookInfo> bookInfo = database.getEntries(username);
			System.out.println(bookInfo.size());
			for (int i=0; i < bookInfo.size(); i++) {
				
				String imageSrc = bookInfo.get(i).getImage();
				String bookId = "book" + String.valueOf(i);
				String imageId = "image" + String.valueOf(i);
				String publisherId = "publisher" + String.valueOf(i);
				String authorId = "author" + String.valueOf(i);
				String publishdateId = "publishdate" + String.valueOf(i);
				String ISBNid = "ISBN" + String.valueOf(i);
				String description = "Description" + String.valueOf(i);
				String ratingId = "rating" + String.valueOf(i);
				
		%>
		<div class="left-col">
			<img id=<%=imageId%> src=<%= imageSrc %> alt="Book Cover Image is unavailable but you can click me to go to the detail page, and you can also reload the page to check the functionality of the remove button" width="150" onclick="sendDetail(this)">
		</div>
		
		<div class="right-col">
			
			<h2 id=<%=bookId%>><%= bookInfo.get(i).getBookname()  %></h2>
			<h3 id=<%=authorId%>><%= bookInfo.get(i).getAuthorname()  %></h3>
		<%
				if(bookInfo.get(i).getDescription().equals(" "))
				{
		%>
			<p id=<%=description%>>Summary: No summary is available</p>
		<%
				}
				else{
		%>
			<p id=<%=description%>>Summary: <%= bookInfo.get(i).getDescription()  %></p>
		<%
				}
		%>
			<p class="no-display" id=<%=publisherId%>><%= bookInfo.get(i).getPublisher()%> </p>
			<p class="no-display" id=<%=publishdateId%>><%= bookInfo.get(i).getPublishdate()%> </p>
			<p class="no-display" id=<%=ISBNid%>><%= bookInfo.get(i).getISBN()%> </p>
			<p class="no-display" id=<%=ratingId%>><%= bookInfo.get(i).getRating()%> </p>
			
			<div class="button">
				<button class="fav" id="<%=i%>" onclick="updateBook(this)"> Remove </button>
			</div>
		</div>
		<hr>
		<div class="clear-float"> </div>
		<% 
		}	
		%>

	</div>
	

</body>
</html>	
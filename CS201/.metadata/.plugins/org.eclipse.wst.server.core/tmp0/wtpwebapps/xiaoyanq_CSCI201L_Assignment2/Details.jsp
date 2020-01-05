<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Details</title>
	<style type="text/css">
		body{
			margin: 0px;
		}

		#header{
			height: 120px;
			width: 65%;
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

		#main{
			width: 65%;
			margin: 30px auto;
					
		}
		
		img{
			width: 300px;
		}
		
		#image{
			float: left;
		}
		
		#content{
			float: left;
			width: 400px;
			padding-left: 80px;
		}
		
		h2{
			margin: 0px;	
		}
		
		#bookname, #authorname, #publisher, #publishedDate, #ISBN13{
			color: #5D5E60;
		}
		
		#authorname{
			font-style: italic; 
		}
		
		#description, #averageRating{
			color: #8D8D92;
		}

		.rating-img{
			height: 20px;
			width: auto;
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

						window.location.href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/SearchResults.jsp";
					}
				}
				else{
					alert("Please provide a valid information for the book that you want to search!");
				}
			}
			xhttp.send();
		}
		
		var f;
		(f = function(){

			var bookname = window.localStorage.getItem('bookname');
			console.log(bookname);
		})();

	</script>
	
</head>
	<body>
	
		<div id="header">
			<a href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/HomePage.jsp"><img id="book-worm" src="images/bookworm.png"></a>
	
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

		<div id='main'>
			<a href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/SearchResults.jsp"><div id='image'></div></a>
			
			<div id='content'>
				<h2 id='bookname'></h2>
				<h3 id='authorname'></h3>
				
				<p id='publisher'></p>
				<p id='publishedDate'></p>
				<p id='ISBN13'></p>
				<p id='description'></p>
				<p id='averageRating'></p>
			</div>
			
			<div class='clear-float'></div>
			
		</div>
		
		<hr>
		
		<script> 
			var imageLink = "<img src=" + window.localStorage.getItem('image') + " alt=\"Book Cover Image\">";
			document.getElementById('image').innerHTML = imageLink;
			
			document.getElementById('bookname').innerHTML = window.localStorage.getItem('bookname');
			
			if(window.localStorage.getItem('authorname') === "undefined")
			{
				document.getElementById('authorname').innerHTML = "Author: No author is available.";
			}
			else{
				document.getElementById('authorname').innerHTML = "Author: " + window.localStorage.getItem('authorname');
			}
			
			if(window.localStorage.getItem('publisher') === "undefined")
			{
				document.getElementById('publisher').innerHTML = "<i>Publisher</i>: No author is available.";
			}
			else{
				document.getElementById('publisher').innerHTML = "<i>Publisher</i>: "+ window.localStorage.getItem('publisher');
			}
			
			if(window.localStorage.getItem('publishedDate') === "undefined")
			{
				document.getElementById('publishedDate').innerHTML = "<i>Publish Date</i>: No publish date is available.";
			}
			else{
				document.getElementById('publishedDate').innerHTML = "<i>Publish Date</i>: " + window.localStorage.getItem('publishedDate');
			}
			
			if(window.localStorage.getItem('ISBN13') === "undefined")
			{
				document.getElementById('ISBN13').innerHTML = "<i>ISBN</i>: No ISBN is available.";
			}
			else{
				document.getElementById('ISBN13').innerHTML = "<i>ISBN</i>: " + window.localStorage.getItem('ISBN13');
			}
			
			if(window.localStorage.getItem('description') === "undefined")
			{
				document.getElementById('description').innerHTML = "<strong>Summary</strong>: No summary is available.";
			}
			else{
				document.getElementById('description').innerHTML = "<strong>Summary</strong>: " + window.localStorage.getItem('description');
			}
			
			if(window.localStorage.getItem('averageRating') === "undefined")
			{
				document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: Average rating is unavailable.";
			}
			else{
				var ratingNum = window.localStorage.getItem('averageRating');
				if(ratingNum == 0)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/0.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 0.5)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/0-5.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 1.0)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/1.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 1.5)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/1-5.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 2.0)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/2.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 2.5)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/2-5.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 3.0)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/3.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 3.5)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/3-5.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 4.0)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/4.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else if(ratingNum <= 4.5)
				{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/4-5.jpeg' alt='Rating Image' class='rating-img'>";
				}
				else{
					document.getElementById('averageRating').innerHTML = "<strong>Rating</strong>: <img src='images/5.jpeg' alt='Rating Image' class='rating-img'>";
				}
			}
			
		</script>
	</body>
</html>
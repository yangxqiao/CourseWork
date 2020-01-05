<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Search Results</title>
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
		
		#profile{
			margin-top: 30px;
			width: 50px;
			float: left;
			margin-left: 40px;
		}
	</style>
	<script>
		var f;
		(f = function(){
			var result = JSON.parse(window.localStorage.getItem('result'));
			const parse_result = JSON.parse(result);
			console.log(parse_result);
 			var i;
			var bookname = ['book1', 'book2', 'book3', 
				'book4', 'book5', 'book6', 'book7', 'book8', 
				'book9', 'book10'];
			var authorname = ['author1', 'author2', 'author3', 
				'author4', 'author5', 'author6', 'author7', 
				'author8', 'author9', 'author10'];
			var description = ['description1',  'description2', 
				'description3', 'description4', 'description5', 
				'description6', 'description7', 'description8', 
				'description9', 'description10'];
			var image = ['image1', 'image2', 'image3', 'image4', 
				'image5', 'image6', 'image7', 'image8',
				'image9', 'image10'];
			var numItem = parse_result['items'].length;
			localStorage.setItem('numItem', numItem);
 			for (i = 0; i < numItem; i++)
			{
				localStorage.setItem(bookname[i], parse_result['items'][i]['volumeInfo']['title']);
				localStorage.setItem(authorname[i], parse_result['items'][i]['volumeInfo']['authors']);
				localStorage.setItem(description[i], parse_result['items'][i]['volumeInfo']['description']);
				localStorage.setItem(image[i], parse_result['items'][i]['volumeInfo']['imageLinks']['thumbnail']);
			}
			
 			console.log(parse_result);
		})();
		

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
	
		
		function sendDetail(image)
		{
			var node = image.parentNode.parentNode.id;
			var result = JSON.parse(window.localStorage.getItem('result'));
			const parse_result = JSON.parse(result);
			
			window.localStorage.setItem('bookname', parse_result['items'][node-1]['volumeInfo']['title']);
			window.localStorage.setItem('authorname', parse_result['items'][node-1]['volumeInfo']['authors']);
			window.localStorage.setItem('description', parse_result['items'][node-1]['volumeInfo']['description']);
			window.localStorage.setItem('image', parse_result['items'][node-1]['volumeInfo']['imageLinks']['thumbnail']);
			window.localStorage.setItem('publisher', parse_result['items'][node-1]['volumeInfo']['publisher']);
			window.localStorage.setItem('publishedDate', parse_result['items'][node-1]['volumeInfo']['publishedDate']);
			window.localStorage.setItem('ISBN13', parse_result['items'][node-1]['volumeInfo']['industryIdentifiers'][0]['identifier']);
			window.localStorage.setItem('averageRating', parse_result['items'][node-1]['volumeInfo']['averageRating']);
			window.location.href="http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/Details.jsp";
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
			
			<a id="profile_link" href=""><img id="profile" src=""></a>
			
			<script>
				update();
			</script>
			
			<div class='clear-float'></div>
			
		</div>
	
		<hr>
	
		<div id="caption">
			<h1 id='search-words'>  </h1> 
		</div>
		
		<div id="main">
			<div id="1" class="all-contents">
				<div id='image1' class='image'> </div>

				<div class="content">
					<h2 id="book1"> </h2>
					<h3 id="author1"> </h3>
					<p id="description1"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>

			
			<div id="2" class="all-contents">
				<div id='image2' class='image'> </div>
				
				<div class="content">
					<h2 id="book2"> </h2>
					<h3 id="author2"> </h3>
					<p id="description2"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>

			
			<div id="3" class="all-contents">
				<div id='image3' class='image'> </div>
				
				<div  class="content">
					<h2 id="book3"> </h2>
					<h3 id="author3"> </h3>
					<p id="description3"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			<div id="4" class="all-contents">
				<div id='image4' class='image'> </div>
				 
				<div  class="content">
					<h2 id="book4"> </h2>
					<h3 id="author4"> </h3>
					<p id="description4"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			<div id="5" class="all-contents">
				<div id='image5' class='image'> </div>
				
				<div  class="content">
					<h2 id="book5"> </h2>
					<h3 id="author5"> </h3>
					<p id="description5"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			<div id="6" class="all-contents">
				<div id='image6' class='image'> </div>
				
				<div  class="content">
					<h2 id="book6"> </h2>
					<h3 id="author6"> </h3>
					<p id="description6"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			<div id="7" class="all-contents">
				<div id='image7' class='image'> </div>
				
				<div class="content">
					<h2 id="book7"> </h2>
					<h3 id="author7"> </h3>
					<p id="description7"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			<div id="8" class="all-contents">
				<div id='image8' class='image'> </div>
				 
				<div  class="content">
					<h2 id="book8"> </h2>
					<h3 id="author8"> </h3>
					<p id="description8"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
			
			<div id="9" class="all-contents">
				<div id='image9' class='image'> </div>
				
				<div class="content">
					<h2 id="book9"> </h2>
					<h3 id="author9"> </h3>
					<p id="description9"> </p>
				 </div>
				 
				<div class='clear-float'></div>
			</div>
			
			
			
			<div id="10" class="all-contents">
				<div id='image10' class='image'> </div>
				
				<div class="content">
					<h2 id="book10"> </h2>
					<h3 id="author10"> </h3>
					<p id="description10"> </p>
				</div>
				
				<div class='clear-float'></div>
			</div>
			
			
		</div>
		<script> 
			
			var bookname = "Results for \"" + window.localStorage.getItem('search-words') + "\"";
			document.getElementById('search-words').innerHTML = bookname;
			var i;
			var bookname = ['book1', 'book2', 'book3', 
				'book4', 'book5', 'book6', 'book7', 
				'book8', 'book9', 'book10'];
			var authorname = ['author1', 'author2', 'author3', 
				'author4', 'author5', 'author6', 'author7', 
				'author8', 'author9', 'author10'];
			var description = ['description1',  'description2', 
				'description3', 'description4', 'description5', 
				'description6', 'description7', 'description8', 
				'description9', 'description10'];
			var image = ['image1', 'image2', 'image3', 'image4', 
				'image5', 'image6', 'image7', 'image8',
				'image9', 'image10'];
			for (i = 0; i < localStorage.getItem('numItem'); i++)
			{
				document.getElementById(bookname[i]).innerHTML = localStorage.getItem(bookname[i]);
				
				if(localStorage.getItem(authorname[i]) === "undefined")
				{
					document.getElementById(authorname[i]).innerHTML = "No author is available.";
				}
				else{
					document.getElementById(authorname[i]).innerHTML = "<i>" + localStorage.getItem(authorname[i]) + "</i>";
				}

				if(localStorage.getItem(description[i]) === "undefined")
				{
					document.getElementById(description[i]).innerHTML = "No summary is available.";
				}
				else{
					document.getElementById(description[i]).innerHTML = "<strong>Summary</strong>: " + localStorage.getItem(description[i]);
				}
				
				document.getElementById(image[i]).innerHTML = "<img onclick=\'sendDetail(this)\' src=" + localStorage.getItem(image[i]) + " alt=\"Book Cover Image is unavailable\" width=\"150\">";
			} 
		</script>
	</body>
</html>
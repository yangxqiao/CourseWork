<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="ISO-8859-1">
		<title>Homepage</title>
		<meta name="viewport" content="initial-scale=1.0, user-scalable=no">
    	<meta charset="utf-8">

    	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    	<script src="https://code.jquery.com/jquery-3.1.1.min.js" crossorigin="anonymous"></script>
    	<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.css">
		
		<style>
	      #header{
	      background-image: url(images/background1.jpg);
	      font-family: "Lato";
	      height: 900px;
	      background-size: cover;
	      background-position: center;  
	      color: #FFF;    
	      }
	
	      #left-button{
	        float: right;
	        line-height: 40px;
	        font-size: 20px;
	        margin-right: 50px;
	      }
	
	      #right-button{
	        float: right;
	        line-height: 40px;
	        font-size: 20px;
	        margin-right: 5%;
	      }
	
	      .clear-float{
	        clear: both;
	      }
	    
	      h1 {
	        font-weight: 700;
	        font-size: 5em;
	      }
	
	      h3{
	        font-size: 1.5em;
	      }
	
	      #text{
	        height: 45px;
	        line-height: 45px;
	      }
	
	      .content{
	        padding-top: 20%;
	        text-align: center;
	        text-shadow: 0px 4px 3px rgba(0,0,0,0.4),
	                     0px 8px 13px rgba(0,0,0,0.1),
	                     0px 18px 23px rgba(0,0,0,0.1);
	      }
	
	      #for-header{
	          width: 400px;
	          border-top: 1px solid #f8f8f8;
	          border-bottom: 1px solid rgba(0,0,0,0.2);
	      }
	      /* Optional: Makes the sample page fill the window. */
	      html, body {
	        height: 100%;
	        margin: 0;
	        padding: 0;
	      }
	 
	      #search-bar {
	        background-color: #fff;
	        font-family: Roboto;
	        font-size: 15px;
	        font-weight: 300;
	        padding: 0 11px 0 13px;
	        text-overflow: ellipsis;
	        width: 620px;
	        height: 45px;
	      }
	
	      #footer
	      {
	        text-align: center;
	        background-color: #EFEDEF;
	        color: #7A797A;
	        height: 35px;
	      }
	
	      #footer p{
	        line-height: 35px;
	        margin: 0px;
	      }
	
	      .search{
	        box-shadow: 0 2px 6px rgba(0, 0, 0, 0.1);
	      }
	     
	      #choice{
	        font-size: 20px;
	        margin-top: 20px;
	      }
	
	      .radio-class{
	        height: 35px;
	        font-weight: 2.5em;
	      }
	
	      #top-bar{
	        background-color: #EFEDEF;
	        color: #7A797A;
	        height: 40px;
	        opacity: 0.7;
	        z-index: 1;
	        position: fixed;
	        top: 0;
	        width: 100%;
	      }
	
	      #top-bar a{
	        display: block;
	        text-decoration: none;
	        color: #EA70A7;
	      }
	
	      #top-bar a:hover {
	        color: #7A797A;
	      }		
		</style>
	</head>
	<body>
	
		<div id="header">
			<div id="top-bar">
	<%
		String n = (String)session.getAttribute("username");
		System.out.println("in homepage, session username:"+n);
		if(n!=null){ //someone logged in
	%>
			<!-- <a href="LogoutServlet"><div id="right-button"> Sign out </div></a>
			<a href="Upload.jsp"><div id="left-button"> Upload GPA </div></a> -->
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
	<!-- 		<a href="RegisterPage.jsp"><div id="right-button"> Register </div></a>
			<a href="LoginPage.jsp"><div id="left-button"> Login </div></a> -->
		
				<div class="clear-float"></div>
			</div> <!-- top-bar -->
	
		    <div class="container">
	          <div class="row">
	            <div class="col-lg-12">
	              <div class="content">
	                <h1>SeCure that A!</h1>
	                <h3><div id="text"></div></h3>
	                <hr id="for-header">
	
	                <div id="search">
	                  <form name="myform" action="SearchServlet">
	                    <div class="ui icon input">
	                      <input id="search-bar" class="controls" name="search-bar" type="text" placeholder=" Search..">
	                      <i class="search icon"></i>
	                    </div>
	                    
	                    <div id="choice" class="container">
	                      <div class="row">
	                        <div class="col-lg-3"></div>
	                        
	                        <div class="col-lg-2 radio-class">
	                          <input type="radio" name="radio-button" value="Professor"> Professor 
	                        </div>
	                        
	                        <div class="col-lg-2"></div>
	                        
	                        <div class="col-lg-2 radio-class">
	                          <input type="radio" name="radio-button" value="Course"> Course
	                        </div>
	                        
	                        <div class="col-lg-3"></div>
	                      </div>
	                    </div>
	
	                    <div class="clear-float"></div>
	                  </form>
	                </div>
	                
	                <div id="error_msg">
			    	<%= request.getAttribute("error") != null ? request.getAttribute("error"):"" %>
			    	</div>
	           
	              </div>
	            </div>
	          </div>
	        </div> <!-- container -->
		
		</div> <!-- header -->
		
		<div id="footer"> <p> Yang Qiao | Kate Hu | Blair Niu | Jessie Zhang | Mage Zhang | Irene Li &copy; 2019 </p> </div>
		
		<script>
		    // List of sentences
		    var _CONTENT = [ "Find what you're looking for", "The Best Darn Grade You Can Get", ""];
		
		    // Current sentence being processed
		    var _PART = 0;
		
		    // Character number of the current sentence being processed 
		    var _PART_INDEX = 0;
		
		    // Holds the handle returned from setInterval
		    var _INTERVAL_VAL;
		
		    // Element that holds the text
		    var _ELEMENT = document.querySelector("#text");
		
		    // Implements typing effect
		    function Type() { 
		      var text =  _CONTENT[_PART].substring(0, _PART_INDEX + 1);
		      _ELEMENT.innerHTML = text;
		      _PART_INDEX++;
		
		      // If full sentence has been displayed then start to delete the sentence after some time
		      if(text === _CONTENT[_PART]) {
		        clearInterval(_INTERVAL_VAL);
		        setTimeout(function() {
		          _INTERVAL_VAL = setInterval(Delete, 50);
		        }, 1000);
		      }
		    }
	
		    // Implements deleting effect
		    function Delete() {
		      var text =  _CONTENT[_PART].substring(0, _PART_INDEX - 1);
		      _ELEMENT.innerHTML = text;
		      _PART_INDEX--;
		
		      // If sentence has been deleted then start to display the next sentence
		      if(text === '') {
		        clearInterval(_INTERVAL_VAL);
		
		        // If last sentence then display the first one, else move to the next
		        if(_PART == (_CONTENT.length - 1))
		          _PART = 0;
		        else
		          _PART++;
		        _PART_INDEX = 0;
		
		        // Start to display the next sentence after some time
		        setTimeout(function() {
		          _INTERVAL_VAL = setInterval(Type, 100);
		        }, 200);
		      }
		    }
		
		    // Start the typing effect on load
		    _INTERVAL_VAL = setInterval(Type, 100);
		</script>
	</body>
</html>
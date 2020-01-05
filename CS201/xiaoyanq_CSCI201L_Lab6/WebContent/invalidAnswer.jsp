<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Sample Form</title>
	<script>
	
		function validate(){
			var xhttp = new XMLHttpRequest();
			xhttp.open("GET", "my_servlet?fname=" + document.myform.fname.value +
				"&lname=" + document.myform.lname.value, false);
				xhttp.send();
				if (xhttp.responseText.trim().length > 0) {
					document.getElementById("formerror").innerHTML = xhttp.responseText;
					return false;
				}
				return true;
		}
		
	</script>
</head>
<body>

	<form name="myform" method="GET" action="validAnswer.jsp" onsubmit="return validate()">
		<div id="formerror" > </div>
		First_Name <input type="text" name="fname" /><br /> 
		Last_Name <input type="text" name="lname" /><br />  
		Email <input type="email" name="email" /><br />
				
		<input type="submit" name="submit" value="Submit" />
		<input type="reset" name="reset" value="reset" />
	</form>
</body>
</html>	
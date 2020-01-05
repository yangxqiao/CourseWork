<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="xiaoqiao_CSCI201L_Lab8_2.DBManager"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Cute little dog</title>
	<style>
		img{
			width: 900px;
			height: auto;
		}
	</style>
</head>
<body>
	<%
		String ipAddress = request.getRemoteAddr();
		int portNum = request.getRemotePort();
		int pageId = 2;
		DBManager my_dog = new DBManager();
		my_dog.incrementPageCount(pageId, ipAddress, portNum);
	%>
	<a href="cat.jsp"><img src="images/dog.jpg" alt="This is a dog"></a>
</body>
</html>
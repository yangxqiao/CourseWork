<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="xiaoqiao_CSCI201L_Lab8_2.DBManager"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Cute little cat</title>
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
		int pageId = 1;
		DBManager my_cat = new DBManager();
		my_cat.incrementPageCount(pageId, ipAddress, portNum);
	%>
	<a href="dog.jsp"><img src="images/cat.jpg" alt="This is a cat"></a>
</body>
</html>
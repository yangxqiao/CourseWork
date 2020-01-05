<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="xiaoqiao_CSCI201L_Lab8_2.DBManager, 
    xiaoqiao_CSCI201L_Lab8_2.PageEntry, 
    java.util.ArrayList"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>My Stats</title>
	<style>
	
		table, th, td {
  			border: 1px solid black;
  			border-collapse: collapse;
  			padding: 15px;
  			text-align: left;
  			border-spacing: 5px;
		}
		
		table{
			width: 70%;
		}
	</style>
</head>
<body>
	<table>
	<tr>
    	<th>User IP</th>
    	<th>User Port</th>
    	<th>Page</th>
    	<th>#Visits</th>
  	</tr>
	<%
		DBManager database = new DBManager();
		ArrayList<PageEntry> pageInfo = database.getEntries();
		for (int i=0; i < pageInfo.size(); i++) {
	%>
		<tr>
			<td><%= pageInfo.get(i).getIpAddress()  %></td>
			<td><%= pageInfo.get(i).getPortNumber()  %></td>
			<td><%= pageInfo.get(i).getPageName()  %></td>
			<td><%= pageInfo.get(i).getCount()  %></td>
		</tr>
	<% 
		}
	%>
	</table>
</body>
</html>
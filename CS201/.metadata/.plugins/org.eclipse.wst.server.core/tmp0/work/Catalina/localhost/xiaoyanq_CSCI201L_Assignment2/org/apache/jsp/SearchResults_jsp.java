/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/9.0.24
 * Generated at: 2019-10-14 00:06:25 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class SearchResults_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent,
                 org.apache.jasper.runtime.JspSourceImports {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private static final java.util.Set<java.lang.String> _jspx_imports_packages;

  private static final java.util.Set<java.lang.String> _jspx_imports_classes;

  static {
    _jspx_imports_packages = new java.util.HashSet<>();
    _jspx_imports_packages.add("javax.servlet");
    _jspx_imports_packages.add("javax.servlet.http");
    _jspx_imports_packages.add("javax.servlet.jsp");
    _jspx_imports_classes = null;
  }

  private volatile javax.el.ExpressionFactory _el_expressionfactory;
  private volatile org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public java.util.Set<java.lang.String> getPackageImports() {
    return _jspx_imports_packages;
  }

  public java.util.Set<java.lang.String> getClassImports() {
    return _jspx_imports_classes;
  }

  public javax.el.ExpressionFactory _jsp_getExpressionFactory() {
    if (_el_expressionfactory == null) {
      synchronized (this) {
        if (_el_expressionfactory == null) {
          _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
        }
      }
    }
    return _el_expressionfactory;
  }

  public org.apache.tomcat.InstanceManager _jsp_getInstanceManager() {
    if (_jsp_instancemanager == null) {
      synchronized (this) {
        if (_jsp_instancemanager == null) {
          _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
        }
      }
    }
    return _jsp_instancemanager;
  }

  public void _jspInit() {
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
      throws java.io.IOException, javax.servlet.ServletException {

    if (!javax.servlet.DispatcherType.ERROR.equals(request.getDispatcherType())) {
      final java.lang.String _jspx_method = request.getMethod();
      if ("OPTIONS".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        return;
      }
      if (!"GET".equals(_jspx_method) && !"POST".equals(_jspx_method) && !"HEAD".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        response.sendError(HttpServletResponse.SC_METHOD_NOT_ALLOWED, "JSPs only permit GET, POST or HEAD. Jasper also permits OPTIONS");
        return;
      }
    }

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("<head>\n");
      out.write("\t<meta charset=\"UTF-8\">\n");
      out.write("\t<title>Search Results</title>\n");
      out.write("\t<style type=\"text/css\">\n");
      out.write("\t\tbody{\n");
      out.write("\t\t\tmargin: 0px;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#header{\n");
      out.write("\t\t\theight: 120px;\n");
      out.write("\t\t\twidth: 65%;\n");
      out.write("\t\t\tmargin: 10px auto;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#book-worm{\n");
      out.write("\t\t\theight: 100px;\n");
      out.write("\t\t\twidth: auto;\n");
      out.write("\t\t\tfloat: left;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#search-section{\n");
      out.write("\t\t\tfloat: left;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t.clear-float{\n");
      out.write("\t\t\tclear: both;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#search{\n");
      out.write("\t\t\twidth: 300px;\n");
      out.write("\t\t\theight: 120px;\n");
      out.write("\t\t\tfloat: left;\n");
      out.write("\t\t\tline-height: 120px;\n");
      out.write("\t\t\ttext-align: center;\n");
      out.write("\t\t\tmargin-left: 20px;\n");
      out.write("\t\t\tmargin-right: 20px;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#search-bar{\n");
      out.write("\t\t\twidth: 200px;\n");
      out.write("\t\t\theight: 30px;\n");
      out.write("\t\t\tfont-size: 12px;\n");
      out.write("\t\t\tborder-radius: 7px;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#search-button{\n");
      out.write("\t\t\tmargin-left: 10px;\n");
      out.write("\t\t\theight: 20px;\n");
      out.write("\t\t\tbackground-color: #8D8D92;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#choice{\n");
      out.write("\t\t\tfloat: left;\n");
      out.write("\t\t\ttext-align: center;\n");
      out.write("\t\t\theight: 120px;\n");
      out.write("\t\t\tline-height: 120px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t#caption{\n");
      out.write("\t\t\twidth: 80%;\n");
      out.write("\t\t\tmargin: auto;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t#main{\n");
      out.write("\t\t\twidth: 65%;\n");
      out.write("\t\t\tmargin: auto;\t\t\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\tp, #search-words{\n");
      out.write("\t\t\tcolor: #8D8D92;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\th2, h3{\n");
      out.write("\t\t\tcolor: #5D5E60;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\th2{\n");
      out.write("\t\t\tmargin: 0px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t.image{\n");
      out.write("\t\t\twidth: 200px;\n");
      out.write("\t\t\tfloat: left;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t.content{\n");
      out.write("\t\t\twidth: 630px;\n");
      out.write("\t\t\tfloat: right;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t.all-contents{\n");
      out.write("\t\t\tmargin-bottom: 20px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t</style>\n");
      out.write("\t<script>\n");
      out.write("\t\tvar f;\n");
      out.write("\t\t(f = function(){\n");
      out.write("\t\t\tvar result = JSON.parse(window.localStorage.getItem('result'));\n");
      out.write("\t\t\tconst parse_result = JSON.parse(result);\n");
      out.write("\t\t\tconsole.log(parse_result);\n");
      out.write(" \t\t\tvar i;\n");
      out.write("\t\t\tvar bookname = ['book1', 'book2', 'book3', \n");
      out.write("\t\t\t\t'book4', 'book5', 'book6', 'book7', 'book8', \n");
      out.write("\t\t\t\t'book9', 'book10'];\n");
      out.write("\t\t\tvar authorname = ['author1', 'author2', 'author3', \n");
      out.write("\t\t\t\t'author4', 'author5', 'author6', 'author7', \n");
      out.write("\t\t\t\t'author8', 'author9', 'author10'];\n");
      out.write("\t\t\tvar description = ['description1',  'description2', \n");
      out.write("\t\t\t\t'description3', 'description4', 'description5', \n");
      out.write("\t\t\t\t'description6', 'description7', 'description8', \n");
      out.write("\t\t\t\t'description9', 'description10'];\n");
      out.write("\t\t\tvar image = ['image1', 'image2', 'image3', 'image4', \n");
      out.write("\t\t\t\t'image5', 'image6', 'image7', 'image8',\n");
      out.write("\t\t\t\t'image9', 'image10'];\n");
      out.write("\t\t\tvar numItem = parse_result['items'].length;\n");
      out.write("\t\t\tlocalStorage.setItem('numItem', numItem);\n");
      out.write(" \t\t\tfor (i = 0; i < numItem; i++)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\tlocalStorage.setItem(bookname[i], parse_result['items'][i]['volumeInfo']['title']);\n");
      out.write("\t\t\t\tlocalStorage.setItem(authorname[i], parse_result['items'][i]['volumeInfo']['authors']);\n");
      out.write("\t\t\t\tlocalStorage.setItem(description[i], parse_result['items'][i]['volumeInfo']['description']);\n");
      out.write("\t\t\t\tlocalStorage.setItem(image[i], parse_result['items'][i]['volumeInfo']['imageLinks']['thumbnail']);\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write(" \t\t\tconsole.log(parse_result);\n");
      out.write("\t\t})();\n");
      out.write("\t\t\n");
      out.write("\n");
      out.write("\t\tfunction validate(e) {\n");
      out.write("\t\t\te.preventDefault();\n");
      out.write("\t\t\tvar xhttp = new XMLHttpRequest();\n");
      out.write("\t\t\tvar appKey = \"AIzaSyBny4rBlMQ0ITH2ltQhJzQZQm3sdsZ2nNY\";\n");
      out.write("\t\t\tvar requestUrl = \"https://www.googleapis.com/books/v1/volumes?q=\" \n");
      out.write("\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\n");
      out.write("\t\t\tif(document.getElementById(\"radio1\").checked)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=intitle:\" \n");
      out.write("\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\telse if(document.getElementById(\"radio2\").checked)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=isbn:\" \n");
      out.write("\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\telse if(document.getElementById(\"radio3\").checked)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=inauthor:\" \n");
      out.write("\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\telse if(document.getElementById(\"radio4\").checked)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=inpublisher:\" \n");
      out.write("\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\txhttp.open(\"GET\", requestUrl, false);\n");
      out.write("\t\t\txhttp.onload = function(){\n");
      out.write("\t\t\t\tconst temp = JSON.parse(xhttp.responseText);\n");
      out.write("\t\t\t\tvar numItem = temp['totalItems'];\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\tif(this.status === 200 && document.getElementById('search-bar').value != \"\" && numItem != 0)\n");
      out.write("\t\t\t\t{\n");
      out.write("\n");
      out.write("\t\t\t\t\t\tif(xhttp.responseText.trim().length > 0) {\n");
      out.write("\n");
      out.write("\t\t\t\t\t\twindow.localStorage.setItem('result', JSON.stringify(xhttp.responseText));\n");
      out.write("\t\t\t\t\t\twindow.localStorage.setItem('search-words', document.getElementById('search-bar').value);\n");
      out.write("\n");
      out.write("\t\t\t\t\t\twindow.location.href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/SearchResults.jsp\";\n");
      out.write("\t\t\t\t\t}\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse{\n");
      out.write("\t\t\t\t\talert(\"Please provide a valid information for the book that you want to search!\");\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\txhttp.send();\n");
      out.write("\t\t}\n");
      out.write("\t\n");
      out.write("\t\t\n");
      out.write("\t\tfunction sendDetail(image)\n");
      out.write("\t\t{\n");
      out.write("\t\t\tvar node = image.parentNode.parentNode.id;\n");
      out.write("\t\t\tvar result = JSON.parse(window.localStorage.getItem('result'));\n");
      out.write("\t\t\tconst parse_result = JSON.parse(result);\n");
      out.write("\t\t\t\n");
      out.write("\t\t\twindow.localStorage.setItem('bookname', parse_result['items'][node-1]['volumeInfo']['title']);\n");
      out.write("\t\t\twindow.localStorage.setItem('authorname', parse_result['items'][node-1]['volumeInfo']['authors']);\n");
      out.write("\t\t\twindow.localStorage.setItem('description', parse_result['items'][node-1]['volumeInfo']['description']);\n");
      out.write("\t\t\twindow.localStorage.setItem('image', parse_result['items'][node-1]['volumeInfo']['imageLinks']['thumbnail']);\n");
      out.write("\t\t\twindow.localStorage.setItem('publisher', parse_result['items'][node-1]['volumeInfo']['publisher']);\n");
      out.write("\t\t\twindow.localStorage.setItem('publishedDate', parse_result['items'][node-1]['volumeInfo']['publishedDate']);\n");
      out.write("\t\t\twindow.localStorage.setItem('ISBN13', parse_result['items'][node-1]['volumeInfo']['industryIdentifiers'][0]['identifier']);\n");
      out.write("\t\t\twindow.localStorage.setItem('averageRating', parse_result['items'][node-1]['volumeInfo']['averageRating']);\n");
      out.write("\t\t\twindow.location.href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/Details.jsp\";\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t</script>\n");
      out.write("\t\n");
      out.write("</head>\n");
      out.write("\t<body>\n");
      out.write("\t\n");
      out.write("\t\t<div id=\"header\">\n");
      out.write("\t\t\t<a href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/HomePage.jsp\"><img id=\"book-worm\" src=\"images/bookworm.png\"></a>\n");
      out.write("\t\n");
      out.write("\t\t\t<div id=\"search-section\">\n");
      out.write("\t\t\t\t<form name=\"myform\" method=\"get\" onsubmit=\"return validate(event);\">\n");
      out.write("\t\t\t\t\t<div id=\"search\">\n");
      out.write("\t\t\t\t\t\t<input id=\"search-bar\" type=\"text\" name=\"search-bar\" placeholder=\" What book is on your mind?\">\n");
      out.write("\t\t\t\t\t\t<input type=\"image\" src=\"images/magnifying_glass.png\" name=\"submit-button\" id=\"search-button\" alt=\"submit-button\">\n");
      out.write("\t\t\t\t\t</div>\n");
      out.write("\t\n");
      out.write("\t\t\t\t\t<div id=\"choice\">\n");
      out.write("\t\t\t\t\t\t\n");
      out.write("\t\t\t\t\t\t<label class=\"radio\"> \n");
      out.write("\t\t\t\t\t\t\t<input type=\"radio\" name=\"radio-button\" value=\"Name\" id=\"radio1\">\n");
      out.write("\t\t\t\t\t\t\tName \n");
      out.write("\t\t\t\t\t\t</label>\n");
      out.write("\t\t\t\t\t\t\n");
      out.write("\t\t\t\t\t\t<label class=\"radio\"> \n");
      out.write("\t\t\t\t\t\t\t<input type=\"radio\" name=\"radio-button\" value=\"ISBN\" id=\"radio2\"> \n");
      out.write("\t\t\t\t\t\t\tISBN \n");
      out.write("\t\t\t\t\t\t</label>\n");
      out.write("\t\t\t\t\t\t\n");
      out.write("\t\t\t\t\t\t<label class=\"radio\"> \n");
      out.write("\t\t\t\t\t\t\t<input type=\"radio\" name=\"radio-button\" value=\"Author\" id=\"radio3\"> \n");
      out.write("\t\t\t\t\t\t\tAuthor \n");
      out.write("\t\t\t\t\t\t</label>\n");
      out.write("\t\t\t\t\t\n");
      out.write("\t\t\t\t\t\t<label class=\"radio\"> \n");
      out.write("\t\t\t\t\t\t\t<input type=\"radio\" name=\"radio-button\" value=\"Publisher\" id=\"radio4\">\n");
      out.write("\t\t\t\t\t\t\tPublisher \n");
      out.write("\t\t\t\t\t\t</label>\n");
      out.write("\t\t\t\t\t\t\n");
      out.write("\t\t\t\t\t</div>\n");
      out.write("\t\t\t\t</form>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\n");
      out.write("\t\t</div>\n");
      out.write("\t\n");
      out.write("\t\t<hr>\n");
      out.write("\t\n");
      out.write("\t\t<div id=\"caption\">\n");
      out.write("\t\t\t<h1 id='search-words'>  </h1> \n");
      out.write("\t\t</div>\n");
      out.write("\t\t\n");
      out.write("\t\t<div id=\"main\">\n");
      out.write("\t\t\t<div id=\"1\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image1' class='image'> </div>\n");
      out.write("\n");
      out.write("\t\t\t\t<div class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book1\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author1\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description1\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"2\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image2' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book2\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author2\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description2\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"3\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image3' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div  class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book3\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author3\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description3\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"4\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image4' class='image'> </div>\n");
      out.write("\t\t\t\t \n");
      out.write("\t\t\t\t<div  class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book4\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author4\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description4\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"5\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image5' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div  class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book5\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author5\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description5\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"6\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image6' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div  class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book6\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author6\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description6\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"7\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image7' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book7\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author7\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description7\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"8\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image8' class='image'> </div>\n");
      out.write("\t\t\t\t \n");
      out.write("\t\t\t\t<div  class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book8\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author8\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description8\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"9\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image9' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book9\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author9\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description9\"> </p>\n");
      out.write("\t\t\t\t </div>\n");
      out.write("\t\t\t\t \n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"10\" class=\"all-contents\">\n");
      out.write("\t\t\t\t<div id='image10' class='image'> </div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class=\"content\">\n");
      out.write("\t\t\t\t\t<h2 id=\"book10\"> </h2>\n");
      out.write("\t\t\t\t\t<h3 id=\"author10\"> </h3>\n");
      out.write("\t\t\t\t\t<p id=\"description10\"> </p>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<div class='clear-float'></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t</div>\n");
      out.write("\t\t<script> \n");
      out.write("\t\t\t\n");
      out.write("\t\t\tvar bookname = \"Results for \\\"\" + window.localStorage.getItem('search-words') + \"\\\"\";\n");
      out.write("\t\t\tdocument.getElementById('search-words').innerHTML = bookname;\n");
      out.write("\t\t\tvar i;\n");
      out.write("\t\t\tvar bookname = ['book1', 'book2', 'book3', \n");
      out.write("\t\t\t\t'book4', 'book5', 'book6', 'book7', \n");
      out.write("\t\t\t\t'book8', 'book9', 'book10'];\n");
      out.write("\t\t\tvar authorname = ['author1', 'author2', 'author3', \n");
      out.write("\t\t\t\t'author4', 'author5', 'author6', 'author7', \n");
      out.write("\t\t\t\t'author8', 'author9', 'author10'];\n");
      out.write("\t\t\tvar description = ['description1',  'description2', \n");
      out.write("\t\t\t\t'description3', 'description4', 'description5', \n");
      out.write("\t\t\t\t'description6', 'description7', 'description8', \n");
      out.write("\t\t\t\t'description9', 'description10'];\n");
      out.write("\t\t\tvar image = ['image1', 'image2', 'image3', 'image4', \n");
      out.write("\t\t\t\t'image5', 'image6', 'image7', 'image8',\n");
      out.write("\t\t\t\t'image9', 'image10'];\n");
      out.write("\t\t\tfor (i = 0; i < localStorage.getItem('numItem'); i++)\n");
      out.write("\t\t\t{\n");
      out.write("\t\t\t\tdocument.getElementById(bookname[i]).innerHTML = localStorage.getItem(bookname[i]);\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\tif(localStorage.getItem(authorname[i]) === \"undefined\")\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\tdocument.getElementById(authorname[i]).innerHTML = \"No author is available.\";\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse{\n");
      out.write("\t\t\t\t\tdocument.getElementById(authorname[i]).innerHTML = \"<i>\" + localStorage.getItem(authorname[i]) + \"</i>\";\n");
      out.write("\t\t\t\t}\n");
      out.write("\n");
      out.write("\t\t\t\tif(localStorage.getItem(description[i]) === \"undefined\")\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\tdocument.getElementById(description[i]).innerHTML = \"No summary is available.\";\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse{\n");
      out.write("\t\t\t\t\tdocument.getElementById(description[i]).innerHTML = \"<strong>Summary</strong>: \" + localStorage.getItem(description[i]);\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\tdocument.getElementById(image[i]).innerHTML = \"<img onclick=\\'sendDetail(this)\\' src=\" + localStorage.getItem(image[i]) + \" alt=\\\"Book Cover Image is unavailable\\\" width=\\\"150\\\">\";\n");
      out.write("\t\t\t} \n");
      out.write("\t\t</script>\n");
      out.write("\t</body>\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}

/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/9.0.24
 * Generated at: 2019-11-03 05:14:32 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class register_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("\t<title>Sample Form</title>\n");
      out.write("\t<style type=\"text/css\">\n");
      out.write("\t\tbody{\n");
      out.write("\t\t\tmargin: 0px;\n");
      out.write("\t\t}\n");
      out.write("\n");
      out.write("\t\t#header{\n");
      out.write("\t\t\theight: 120px;\n");
      out.write("\t\t\twidth: 70%;\n");
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
      out.write("\t\t#content{\n");
      out.write("\t\t\twidth: 80%;\n");
      out.write("\t\t\tmargin-right: auto;\n");
      out.write("\t\t\tmargin-left: auto;\n");
      out.write("\t\t\tmargin-top: 50px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t#username, #password, #passwordcopy{\n");
      out.write("\t\t\twidth: 100%;\n");
      out.write("\t\t\theight: 30px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t#register{\n");
      out.write("\t\t\twidth: 100%;\n");
      out.write("\t\t\theight: 40px;\n");
      out.write("\t\t\tfont-size: 20px;\n");
      out.write("\t\t\tmargin-top: 30px;\n");
      out.write("\t\t\tcolor: white;\n");
      out.write("\t\t\tbackground-color: #5D5E60;\n");
      out.write("\t\t\tborder-radius: 10px;\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t</style>\n");
      out.write("\t<script>\n");
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
      out.write("\t\n");
      out.write("\t\t\t\t\t\tif(xhttp.responseText.trim().length > 0) {\n");
      out.write("\t\n");
      out.write("\t\t\t\t\t\twindow.localStorage.setItem('result', JSON.stringify(xhttp.responseText));\n");
      out.write("\t\t\t\t\t\twindow.localStorage.setItem('search-words', document.getElementById('search-bar').value);\n");
      out.write("\t\n");
      out.write("\t\t\t\t\t\twindow.location.href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/SearchResults.jsp\";\n");
      out.write("\t\t\t\t\t}\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse{\n");
      out.write("\t\t\t\t\talert(\"Please provide a valid information for the book that you want to search!\");\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\txhttp.send();\n");
      out.write("\t\t}\n");
      out.write("\t\n");
      out.write("\t\tfunction val(e){\n");
      out.write("\t\t\tvar xhttp = new XMLHttpRequest();\n");
      out.write("\t\t\txhttp.open(\"GET\", \"register_servlet?username=\" + document.registerform.username.value +\n");
      out.write("\t\t\t\t\"&password=\" + document.registerform.password.value + \n");
      out.write("\t\t\t\t\"&passwordcopy=\" + document.registerform.passwordcopy.value, false);\n");
      out.write("\t\t\t\txhttp.send();\n");
      out.write("\t\t\t\tif (xhttp.responseText.trim().length > 0) {\n");
      out.write("\t\t\t\t\tdocument.getElementById(\"errorMsg\").innerHTML = xhttp.responseText;\n");
      out.write("\t\t\t\t\treturn false;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse{\n");
      out.write("\t\t\t\t\t\n");
      out.write("\t\t\t\t\twindow.localStorage.setItem('status', 'succeed');\n");
      out.write("\t\t\t\t\twindow.localStorage.setItem('username', document.registerform.username.value);\n");
      out.write("\t\t\t\t\treturn true;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t}\n");
      out.write("\t\t\n");
      out.write("\t</script>\n");
      out.write("</head>\n");
      out.write("<body>\n");
      out.write("\t<div id=\"header\">\n");
      out.write("\t\t\t<a href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment3/HomePage.jsp\"><img id=\"book-worm\" src=\"images/bookworm.png\"></a>\n");
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
      out.write("\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t<div class='clear-float'></div>\n");
      out.write("\n");
      out.write("\t</div>\n");
      out.write("\t\n");
      out.write("\t<hr> \n");
      out.write("\n");
      out.write("\t<div id=\"content\">\n");
      out.write("\t\t<form name=\"registerform\" method=\"GET\" action=\"HomePage.jsp\" onsubmit=\"return val(event);\">\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div class=\"info\">\n");
      out.write("\t\t\t\t<h3>Username</h3>\n");
      out.write("\t\t\t\t<input id=\"username\" type=\"text\" name=\"username\" /><br /> \n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div class=\"info\">\n");
      out.write("\t\t\t\t <h3>Password</h3>\n");
      out.write("\t\t\t\t <input id=\"password\" type=\"text\" name=\"password\" /><br />\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div class=\"info\">\n");
      out.write("\t\t\t\t <h3>Confirm Password</h3>\n");
      out.write("\t\t\t\t <input id=\"passwordcopy\" type=\"text\" name=\"passwordcopy\" /><br />\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<strong><div id=\"errorMsg\"></div></strong><br />\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t<div id=\"button\">\n");
      out.write("\t\t\t\t<input id=\"register\" type=\"submit\" name=\"submit\" value=\"Register\" />\n");
      out.write("\t\t\t</div>\t\t\n");
      out.write("\t\t</form>\n");
      out.write("\t\n");
      out.write("\t</div>\n");
      out.write("\n");
      out.write("</body>\n");
      out.write("</html>\t");
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

/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/9.0.24
 * Generated at: 2019-10-14 00:06:02 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class HomePage_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("\t<head>\n");
      out.write("\t\t<meta charset=\"UTF-8\">\n");
      out.write("\t\t<title>HomePage</title>\t\n");
      out.write("\t\t\n");
      out.write("\t\t<style type=\"text/css\">\n");
      out.write("\t\t\tbody{\n");
      out.write("\t\t\t\tmargin: 0px;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\th1{\n");
      out.write("\t\t\t\tmargin: 0px;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#header{\n");
      out.write("\t\t\t\theight: 150px;\n");
      out.write("\t\t\t\twidth: auto;\n");
      out.write("\t\t\t\tmargin: 0px;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#book-worm{\n");
      out.write("\t\t\t\theight: 150px;\n");
      out.write("\t\t\t\twidth: auto;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#main{\n");
      out.write("\t\t\t\theight: 550px;\n");
      out.write("\t\t\t\tbackground-image: url(\"images/background.jpg\");\n");
      out.write("\t\t\t\tbackground-size: cover;\n");
      out.write("\t\t\t\tbackground-position: center;\t\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#search{\n");
      out.write("\t\t\t\tpadding-top: 250px;\n");
      out.write("\t\t\t\twidth: 80%;\n");
      out.write("\t\t\t\tmargin-right: auto;\n");
      out.write("\t\t\t\tmargin-left: auto;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t\n");
      out.write("\t\t\th1{\n");
      out.write("\t\t\t\tcolor: white;\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#search-bar{\n");
      out.write("\t\t\t\twidth: 100%;\n");
      out.write("\t\t\t\theight: 35px;\n");
      out.write("\t\t\t\tfont-size: 20px;\n");
      out.write("\t\t\t\tborder-radius: 7px;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#button{\n");
      out.write("\t\t\t\twidth: 80%;\n");
      out.write("\t\t\t\tmargin: 30px auto;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#search-button{\n");
      out.write("\t\t\t\theight: 40px;\n");
      out.write("\t\t\t\twidth: 70px;\n");
      out.write("\t\t\t\tfont-size: 32px;\n");
      out.write("\t\t\t\tfloat: right;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t.radio{\n");
      out.write("\t\t\t\tcolor: white;\n");
      out.write("\t\t\t\tfont-size: 17px;\n");
      out.write("\t\t\t\tmargin-right: 10%;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\t\n");
      out.write("\t\t\t#choice{\n");
      out.write("\t\t\t\tmargin: 30px auto;\n");
      out.write("\t\t\t\twidth: 80%;\n");
      out.write("\t\t\t\ttext-align: center;\n");
      out.write("\t\t\t}\n");
      out.write("\t\t</style>\n");
      out.write("\t\t\n");
      out.write("\t\t<script>\n");
      out.write("\t\n");
      out.write("\t\t\tfunction validate(e) {\n");
      out.write("\t\t\t\te.preventDefault();\n");
      out.write("\t\t\t\tvar xhttp = new XMLHttpRequest();\n");
      out.write("\t\t\t\tvar appKey = \"AIzaSyBny4rBlMQ0ITH2ltQhJzQZQm3sdsZ2nNY\";\n");
      out.write("\t\t\t\tvar requestUrl = \"https://www.googleapis.com/books/v1/volumes?q=\" \n");
      out.write("\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\tif(document.getElementById(\"radio1\").checked)\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=intitle:\" \n");
      out.write("\t\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse if(document.getElementById(\"radio2\").checked)\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=isbn:\" \n");
      out.write("\t\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse if(document.getElementById(\"radio3\").checked)\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=inauthor:\" \n");
      out.write("\t\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\telse if(document.getElementById(\"radio4\").checked)\n");
      out.write("\t\t\t\t{\n");
      out.write("\t\t\t\t\trequestUrl = \"https://www.googleapis.com/books/v1/volumes?q=inpublisher:\" \n");
      out.write("\t\t\t\t\t\t+ document.getElementById('search-bar').value \n");
      out.write("\t\t\t\t\t\t+ \"&key=\"\n");
      out.write("\t\t\t\t\t\t+ appKey;\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\t\t\n");
      out.write("\t\t\t\txhttp.open(\"GET\", requestUrl, false);\n");
      out.write("\t\t\t\txhttp.onload = function(){\n");
      out.write("\t\t\t\t\tconst temp = JSON.parse(xhttp.responseText);\n");
      out.write("\t\t\t\t\tvar numItem = temp['totalItems'];\n");
      out.write("\t\t\t\t\t\n");
      out.write("\t\t\t\t\tif(this.status === 200 && document.getElementById('search-bar').value != \"\" && numItem != 0)\n");
      out.write("\t\t\t\t\t{\n");
      out.write("\n");
      out.write(" \t\t\t\t\t\tif(xhttp.responseText.trim().length > 0) {\n");
      out.write("\n");
      out.write("\t\t\t\t\t\t\twindow.localStorage.setItem('result', JSON.stringify(xhttp.responseText));\n");
      out.write("\t\t\t\t\t\t\twindow.localStorage.setItem('search-words', document.getElementById('search-bar').value);\n");
      out.write("\n");
      out.write("\t\t\t\t\t\t\twindow.location.href=\"http://localhost:8080/xiaoyanq_CSCI201L_Assignment2/SearchResults.jsp\";\n");
      out.write("\t\t\t\t\t\t}\n");
      out.write("\t\t\t\t\t}\n");
      out.write("\t\t\t\t\telse{\n");
      out.write("\t\t\t\t\t\talert(\"Please provide a valid information for the book that you want to search!\");\n");
      out.write("\t\t\t\t\t}\n");
      out.write("\t\t\t\t}\n");
      out.write("\t\t\t\txhttp.send();\n");
      out.write("\t\t\t}\n");
      out.write("\t\t\n");
      out.write("\t\t</script>\n");
      out.write("\t</head>\n");
      out.write("\t<body>\n");
      out.write("\t\t<div id=\"header\"> \n");
      out.write("\t\t\t<img id=\"book-worm\" src=\"images/bookworm.png\">\n");
      out.write("\t\t</div>\n");
      out.write("\t\n");
      out.write("\t\t<div id=\"main\">\n");
      out.write("\t\t\t<div id=\"search-section\">\n");
      out.write("\t\t\t\t\n");
      out.write("\t\t\t\t<form name=\"myform\" method=\"get\" onsubmit=\"return validate(event);\">\n");
      out.write("\t\t\t\t\t<div id=\"search\">\n");
      out.write("\t\t\t\t\t\t<h1>BookWorm: Just a Mini Program...Happy Days!</h1>\n");
      out.write("\t\t\t\t\t\t<input id=\"search-bar\" type=\"text\" name=\"search-bar\" placeholder=\" Search for your favorite book!\">\n");
      out.write("\t\t\t\t\t</div>\n");
      out.write("\t\t\t\t\t\n");
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
      out.write("\t\t\t\t\t<div id=\"button\">\n");
      out.write("\t\t\t\t\t\t<input type=\"submit\" name=\"submit\" value=\"Search!\" id=\"search-button\">\n");
      out.write("\t\t\t\t\t</div>\n");
      out.write("\t\t\t\t</form>\n");
      out.write("\t\t\t</div>\n");
      out.write("\t\t</div>\n");
      out.write("\t\n");
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

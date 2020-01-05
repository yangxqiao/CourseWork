package xiaoyanq_CSCI201L_Assignment3;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class profile_remove
 */
@WebServlet("/profile_remove")
public class profile_remove extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String bookname = request.getParameter("bookname");
		String username = request.getParameter("username");
		
		System.out.println(bookname);
		System.out.println(username);
		
		DBManager checker = new DBManager();
		checker.deleteBook(username, bookname);
		System.out.println("delete");	
	}
}

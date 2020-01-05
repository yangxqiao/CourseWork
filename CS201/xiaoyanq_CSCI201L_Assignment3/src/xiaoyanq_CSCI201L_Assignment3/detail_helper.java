package xiaoyanq_CSCI201L_Assignment3;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class detail_helper
 */
@WebServlet("/detail_helper")
public class detail_helper extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String bookname = request.getParameter("bookname");
		String username = request.getParameter("username");
		String status = request.getParameter("status");
		
		PrintWriter output = response.getWriter();
		
		System.out.println(bookname);
		System.out.println(username);
		System.out.println(status);
		
		if(status == null || status.contentEquals("failed"))
		{
			output.println("Favorite");
		}
		else {
			DBManager checker = new DBManager();
			boolean exist = checker.checkBook(username, bookname);
			if(!exist)
			{
				output.println("Favorite");
			}
			else {
				output.println("Remove");
			}
		}		
	}
}

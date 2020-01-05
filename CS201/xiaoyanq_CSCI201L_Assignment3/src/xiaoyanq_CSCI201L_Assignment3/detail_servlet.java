package xiaoyanq_CSCI201L_Assignment3;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class detail_servlet
 */
@WebServlet("/detail_servlet")
public class detail_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String bookname = request.getParameter("bookname");
		String authorname = request.getParameter("authorname");
		String publisher = request.getParameter("publisher");
		if(publisher == null)
		{
			publisher = " ";
		}
		String publishdate = request.getParameter("publishdate");
		if(publishdate == null)
		{
			publishdate = " ";
		}
		String ISBN = request.getParameter("ISBN");
		if(ISBN == null)
		{
			ISBN = " ";
		}
		String description = request.getParameter("description");
		if(description == null)
		{
			description = " ";
		}
		String username = request.getParameter("username");
		String status = request.getParameter("status");
		String image = request.getParameter("image");
		String rating = request.getParameter("rating");
		
		PrintWriter output = response.getWriter();
		
		System.out.println(bookname);
		System.out.println(authorname);
		System.out.println(publisher);
		System.out.println(publishdate);
		System.out.println(ISBN);
		System.out.println(description);
		System.out.println(username);
		System.out.println(status);
		System.out.println(image);
		
		if(status == null || status.contentEquals("failed"))
		{
			output.println("Please login or register first!");
		}
		else {
			DBManager checker = new DBManager();
			boolean exist = checker.checkBook(username, bookname);
			if(!exist)
			{
				System.out.println("add");
				output.println("Remove");
				checker.addBook(username, bookname, authorname, publisher, publishdate, ISBN, description, image, rating);
			}
			else {
				System.out.println("delete");
				output.println("Favorite");
				checker.deleteBook(username, bookname);
			}
		}		
	}
}

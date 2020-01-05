import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class my_servlet
 */
@WebServlet("/my_servlet")
public class my_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
     
	protected void service(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException {

		String fname = request.getParameter("fname");
		String lname = request.getParameter("lname");
		String email = request.getParameter("email");
		System.out.println("fname = " + fname);
		System.out.println("lname = " + lname);
		System.out.println("email = " + email);
		
		String next = "/invalidAnswer.jsp";
		if (fname != null && fname.equals("Xiaoyang") && lname != null && lname.equals("Qiao")) 
		{
			next = "/validAnswer.jsp";
		} 
		else
		{
			request.setAttribute("errorMsg", "Please enter valid input");

		}
		RequestDispatcher dispatch = getServletContext().getRequestDispatcher(next);
		dispatch.forward(request,response);
	}
}
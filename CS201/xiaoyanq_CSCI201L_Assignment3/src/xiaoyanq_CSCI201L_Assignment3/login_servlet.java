package xiaoyanq_CSCI201L_Assignment3;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class login_servlet
 */
@WebServlet(name="login_servlet", urlPatterns= {"/login_servlet"})
public class login_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
		PrintWriter output = response.getWriter();
		
		System.out.println(username);
		System.out.println(password);
		
		DBManager checker = new DBManager();
		boolean found = checker.checkUserPassword(username, password);
		if(!found)
		{
			boolean nameExist = checker.searchUser(username);
			if(nameExist)
			{
				output.println("Invalid password.");
			}
			else {
				output.println("This username does not exist.");
			}
		}
	}

}

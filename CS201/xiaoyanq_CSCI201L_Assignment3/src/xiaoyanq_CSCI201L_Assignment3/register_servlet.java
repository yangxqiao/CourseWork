package xiaoyanq_CSCI201L_Assignment3;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


/**
 * Servlet implementation class register_servlet
 */
@WebServlet("/register_servlet")
public class register_servlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String passwordcopy = request.getParameter("passwordcopy");
		
		PrintWriter output = response.getWriter();
		
		System.out.println(username);
		System.out.println(password);
		System.out.println(passwordcopy);
		
		if(username.contentEquals("") )
		{
			output.println("Please provide valid username.");
		}
		else
		{
			if(password.contentEquals(""))
			{
				output.println("Please provide valid password.");
			}
			else {
				if(!password.equals(passwordcopy))
				{
					output.println("The passwords do not match.");
				}
				else {
					DBManager checker = new DBManager();
					boolean found = checker.searchUser(username);
					if(found)
					{
						output.println("This username is already taken.");
					}
					else {
						checker.addUser(username, passwordcopy);
					}
				}
			}
		}
	}

}

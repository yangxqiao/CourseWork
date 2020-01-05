import Database.Database;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.*;


@WebServlet(name="LoginServlet", urlPatterns={"/LoginServlet"})
public class LoginServlet extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("in login servlet");
		Database database = new Database();
		String errmsg1 = "";
		String errmsg2 = "";
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		if (username.trim().length() == 0 || password.trim().length() == 0) {
			errmsg1 = "Please fill out all fields.";
		} else {
			if (!database.userExist(username)) {
				errmsg1 = "This user does not exist. ";
			} else if (!database.authenticate(username, password)) {
				errmsg2 = "Incorrect password. ";
			}
		}
		String errmsg = errmsg1 + errmsg2;
		if(!errmsg.trim().contentEquals("")) {
			request.setAttribute("error",errmsg); 
			  RequestDispatcher dispatch = getServletContext().getRequestDispatcher("/LoginPage.jsp"); 
			  try {
				dispatch.forward(request, response); 
			}catch(IOException e) {
				e.printStackTrace(); 
			}catch(ServletException e) { 
				e.printStackTrace(); 
			}
		}
		else { // Successful
			System.out.println("log in success");
			HttpSession session = request.getSession();
			session.setAttribute("username", username);
			response.sendRedirect("Homepage.jsp");			
			return;			
		}
	}
	
}

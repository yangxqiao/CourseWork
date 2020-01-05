import Database.Database;
import Database.DatabaseOperator1;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.*;


@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	
	public RegisterServlet() {
        super();
        // TODO Auto-generated constructor stub
    }
	
	
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		DatabaseOperator1 database = new DatabaseOperator1();
		String errmsg = "";
		boolean login = false;
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String confirm = request.getParameter("confirm");
		String next = "";
		if(username != "" && password != "" && confirm != "") {
			if(!password.equals(confirm)) {
				errmsg = "The passwords do not match!!! ";
			}
			else if (database.userExist(username)) {
				errmsg = "This username is already taken!!! ";
			}
			else {
				login = true;
				database.addUser(username, password);
			}
		}
		HttpSession session = request.getSession();
		
		if(!login){
			session.setAttribute("login", "false");
			session.setAttribute("errMsg", errmsg);
			next = "/RegisterPage.jsp";
		}
		else {
			session.setAttribute("login", "true");
			session.setAttribute("username", username);
			next = "/Homepage.jsp";
		}
		try {
			System.out.println("next is : " + next);
    		request.getRequestDispatcher(next).forward(request,response);
    	}catch(IOException e) {
    		e.printStackTrace();
    	}catch(ServletException e) {
    		e.printStackTrace();
    	}
		
	}
	
}

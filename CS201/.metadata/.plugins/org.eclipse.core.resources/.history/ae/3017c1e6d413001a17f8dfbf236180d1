

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class SearchServlet
 */
@WebServlet("/SearchServlet")
public class SearchServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SearchServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String input = request.getParameter("search-bar");
		String choice = request.getParameter("radio-button");
		String errmsg = "";
		if(input==null || input.trim()=="") { //input field empty
			//alert the user to enter something
			errmsg = "Please enter something";
			request.setAttribute("error",errmsg);
			
			//but how to return to the page where it came from?
			RequestDispatcher dispatch = getServletContext().getRequestDispatcher("/Homepage.jsp"); 
			try {
				dispatch.forward(request, response);
			}catch(IOException e) {
				e.printStackTrace();
			}catch(ServletException e) {
				e.printStackTrace();
			}
		}
		else {
			if(choice==null || choice.trim().contentEquals("Course")) { //default to search by course
				request.setAttribute("resultsby","Course");
			}
			else if(choice.trim().contentEquals("Professor")) {//search by professor
				request.setAttribute("resultsby","Professor");
			}
			RequestDispatcher dispatch = getServletContext().getRequestDispatcher("/searchresults.jsp"); 
			try {
				dispatch.forward(request, response);
			}catch(IOException e) {
				e.printStackTrace();
			}catch(ServletException e) {
				e.printStackTrace();
			}
		}
		
		
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}

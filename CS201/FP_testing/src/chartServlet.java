import Database.Database;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.*;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.*;
import javax.websocket.Session;


@WebServlet(name="chartServlet", urlPatterns={"/chartServlet"})

public class chartServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
		
		protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			Database database = new Database();
			String term = request.getParameter("term");
			String course = request.getParameter("course");
			System.out.println(term);
			System.out.println(course);
			
//			ArrayList<String> listProfessor = database.get_All_Professor_Given_Term_And_Course(term, course);
//			ArrayList<Double> listGPA = database.get_All_GPA_Given_Term_And_Course(term, course);
			
			ArrayList<String> listProfessor = new ArrayList<String>();
			listProfessor.add("Mark Redekopp");
			listProfessor.add("Olivera Grujic");
			listProfessor.add("Jeffrey Miller");
			listProfessor.add("Andrew Goodney");
			listProfessor.add("Average");
			
			for(Integer i = 0; i < listProfessor.size(); i++)
			{
				String tempString = listProfessor.get(i);
				listProfessor.set(i, "'" + tempString + "'");
			}
			
			ArrayList<Double> listGPA = new ArrayList<Double>();
			listGPA.add(4.0);
			listGPA.add(2.5);
			listGPA.add(3.0);
			listGPA.add(3.4);
			listGPA.add(3.2);
			
			HttpSession session = request.getSession();
			session.setAttribute("listProfessor", listProfessor);
			session.setAttribute("listGPA", listGPA);	

		}	
}

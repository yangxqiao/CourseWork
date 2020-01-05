import Database.Database;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import com.google.gson.*;

@WebServlet(name="chartServlet", urlPatterns={"/chartServlet"})

public class chartServlet extends HttpServlet{
	private static final long serialVersionUID = 1L;
		
		protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			System.out.println("in chartServlet");
			Database database = new Database();
			String term = request.getParameter("term");
			String[] termsplit = term.split("\\s+");
			String termNumber = termsplit[0];
			if(termsplit[1].contentEquals("Spring")) {
				termNumber+="1";
			}else if(termsplit[1].contentEquals("Summer")) {
				termNumber+="2";
			}else termNumber+="3";
			
			String course = request.getParameter("course");
			System.out.println(termNumber);
			System.out.println(course);
			
			ArrayList<String> listProfessor = database.get_All_Professor_Given_Term_And_Course(termNumber, course);
			ArrayList<Double> listGPA = database.get_All_GPA_Given_Term_And_Course(termNumber, course);
			
			for(Integer i = 0; i < listProfessor.size(); i++)
			{
				String tempString = listProfessor.get(i);
				listProfessor.set(i, "'" + tempString + "'");
			}
			
			PrintWriter outPrintWriter = response.getWriter();
			
			String outstring = "";
			for(Integer i = 0; i < listProfessor.size(); i++)
			{
				outstring += listProfessor.get(i)+",";
				System.out.println(listProfessor.get(i));
			}
			if(outstring.length()!=0) {
				outstring = outstring.substring(0,outstring.length()-1);
				outstring +="|";
			}
			for(Integer i = 0; i < listGPA.size(); i++)
			{
				outstring += listGPA.get(i)+",";
				System.out.println(listGPA.get(i));
			}
			if(outstring.length()!=0) {
				outstring = outstring.substring(0,outstring.length()-1);
			}
			outPrintWriter.print(outstring);
			outPrintWriter.flush();
			outPrintWriter.close();
		}	
}

import Database.*;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//import javax.servlet.http.Httprequest;

/**
 * Servlet implementation class UploadServlet
 */
@WebServlet("/UploadServlet")
public class UploadServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UploadServlet() {
        super();
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String course = request.getParameter("course");
		String term = request.getParameter("term");
		String professor = request.getParameter("professor");
		String gpa = request.getParameter("gpa");
		String recommend = request.getParameter("recommend");
		String challenging = request.getParameter("challenging");
//		Httprequest request = request.getrequest();
		String err = null;
		
		if(gpa == "") {
			//request.setAttribute("error", "Please enter your GPA.");
			err = "Please enter your GPA.";
		}
		else if(recommend == null) {
//			request.setAttribute("error", "Do you recommend this professor?");
			err = "Do you recommend this professor?";
		}
		else if(challenging == null) {
//			request.setAttribute("error", "Do you think this course with this professor is challenging?");
			err = "Do you think this course with this professor is challenging?"; 
		}
		else {
			//connect to database and upload the data
			Database db = new Database();
			boolean upload = db.upload(course, term, professor, gpa, recommend, challenging);
			//request.setAttribute("upload", upload);
			if(upload)
			{
//				request.setAttribute("error", "Congrats! You successfully upload your GPA!");
			}
			else {
//				request.setAttribute("error", "Upload fail. Please try again.");
				err= "Upload fail. Please try again.";
			}
		}
		if(err!=null) {
			request.setAttribute("error",err);
			System.out.println("err:"+err);
		}
		else{System.out.println("no err");}
		//direct back to upload page
		try {
			System.out.println("reached dispatch");
    		request.getRequestDispatcher("/Upload.jsp").forward(request,response);
    	}catch(IOException e) {
    		e.printStackTrace();
    	}catch(ServletException e) {
    		e.printStackTrace();
    	}
	}

}

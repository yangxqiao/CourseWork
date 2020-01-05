import Database.*;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
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
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String course = request.getParameter("course");
		String term = request.getParameter("term");
		String professor = request.getParameter("professor");
		String gpa = request.getParameter("gpa");
		String recommend = request.getParameter("recommend");
		String challenging = request.getParameter("challenging");
		HttpSession session = request.getSession();
		String err = "";
		PrintWriter out = response.getWriter();
		if (session.getAttribute("username") == null) {
			err = "Please log in first.";
		} else {

			if (gpa == "") {
				err = "Please enter your GPA.";
			} else if (recommend == null || recommend.trim().length() == 0) {
				err = "Do you recommend this professor?";
			} else if (challenging == null || challenging.trim().length() == 0) {
				err = "Do you think this course with this professor is challenging?";
			} else {
				// connect to database and upload the data
				Database db = new Database();
				boolean upload = db.upload(course, term, professor, gpa, recommend, challenging);
				session.setAttribute("upload", upload);
				if (upload) {
				} else {
					err = "Upload fail. Please try again.";
				}
			}
			request.setAttribute("error", err);
			System.out.println("err:" + err);

		}
		out.print(err);
		out.flush();
		out.close();
	}

}

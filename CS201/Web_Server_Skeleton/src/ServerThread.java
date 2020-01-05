import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;


public class ServerThread extends Thread{
	// to do --> private variables for the server thread 
	
	private BufferedReader input;
	private PrintStream output;
	private Socket socket;
	
	
	public ServerThread(Socket s) {
		try {
			// to do --> store them somewhere, you will need them later 
			this.input = new BufferedReader(new InputStreamReader(s.getInputStream()));
			this.output = new PrintStream(new BufferedOutputStream(s.getOutputStream()));
			this.socket = s;
			
			this.start();
			// to do --> complete the implementation for the constructor
		
		} catch (IOException ioe) {
			System.out.println("ioe in ServerThread constructor: " + ioe.getMessage());
		}
	}

	// to do --> what method are we missing? Implement the missing method 
	
	
	public void run() {
		String header = "";
		String filename = "";
		
		try {
			header = input.readLine();
			
			if(!header.equals(""))
			{
				filename = header.substring(header.indexOf("/"), header.indexOf("HTTP/1.1")).trim();
			}
			
			
			System.out.println("Header: " + header);
			
			String filepath = new File("").getAbsolutePath() + "/" + filename;
			
			String filetype = "";
			
			switch(filename.substring(filename.lastIndexOf("."), filename.length())) {
			case ".jpg":
			case ".jpeg":
				filetype = "image/jpeg";
				break;
			case ".png":
				filetype = "image/png";
				break;
			case ".html":
				filetype = "text/html";
				break;
			case ".css":
				filetype = "text/css";
				break;
			case ".js":
				filetype = "text/js";
				break;
			}
		
			String responseHeader = "HTTP/1.1 200 OK\r\n" + "Content-Type:" + filetype + "\r\n\r\n";
		
		
			byte[] file = Files.readAllBytes(Paths.get(filepath));
			
			this.output.print(responseHeader);
			this.output.write(file);
			
			
		}
		catch(IOException ioe)
		{
			String responseHTML = "<html> <body> <h1> Error a404 File Not Found </h1> </body> </html>";
			String responseHeader = "HTTP/1.1 404 Not  Found\r\n" + "Content-Type: text/html" + "\r\n\r\n" + responseHTML;
			this.output.print(responseHeader);
		}
		
		finally {
			this.output.close();
		}
		
	}
	
	
	
}

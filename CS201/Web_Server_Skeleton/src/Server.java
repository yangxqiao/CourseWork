import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;



public class Server {
	// to do --> data structure to hold server threads 
	// thread-safe data structure
	
	private Vector<ServerThread> serverThreads;
	
	public Server(int port) throws IOException {
		// to do --> implement your constructor
		ServerSocket ss = new ServerSocket(port);
		System.out.println("Binding to port " + port);	
		serverThreads = new Vector<ServerThread>();
		
					
		while(true)
		{
			Socket connection = ss.accept(); // blocking
			// unless we received message from ServerSocket, nothing followed will happen
			System.out.println("Received connection from: " + connection.getInetAddress());
			ServerThread st = new ServerThread(connection);
			serverThreads.add(st);
		}
	
		
	}
	
	public static void main(String [] args) {
		// to do --> implement your main()
		try {
		Server server = new Server(4322);		
		}

		catch(IOException ioe)
		{
			System.out.println("ioe in Server constructor: " + ioe.getMessage());
		}
	}
}

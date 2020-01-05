package chatroom;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class ServerThread extends Thread {

	private PrintWriter pw;
	private BufferedReader br;
	private ChatRoom cr;
	private Lock lock;
	private Condition condition;
	boolean firstClient, endOfTurn;
	public ServerThread(Socket s, ChatRoom cr, Lock lock, Condition condition, boolean firstClient) {
		try {
			this.cr = cr;
			this.lock = lock;
			this.condition = condition;
			this.firstClient = firstClient;
			pw = new PrintWriter(s.getOutputStream());
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			this.start();
		} catch (IOException ioe) {
			System.out.println("ioe in ServerThread constructor: " + ioe.getMessage());
		}
	}

	public void sendMessage(String message) {
		pw.println(message);
		pw.flush();
	}
	
	public void run() {
		try {
			while(true) {
				endOfTurn = false;
				lock.lock();
				
				if(!firstClient) {
					condition.await();
				} else {
					firstClient = false;
				}
				
				while(!endOfTurn) {
					String line = br.readLine();
					
					if(line.contains("END_OF_MESSAGE")) {
						sendMessage("Wait again until it is your turn to send a message.");
						cr.signalNextClient(this);
						endOfTurn = true;
						break;
						
					}
					cr.broadcast(line, this);
				}
				lock.unlock();
				
			}
		} catch (IOException ioe) {
			System.out.println("ioe in ServerThread.run(): " + ioe.getMessage());
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

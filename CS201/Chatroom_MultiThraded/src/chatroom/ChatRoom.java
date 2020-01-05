package chatroom;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ChatRoom {

	private Vector<ServerThread> serverThreads;
	private Vector<Lock> locks;
	private Vector<Condition> conditions;
	boolean first = true;

	public ChatRoom(int port) {
		try {
			System.out.println("Binding to port " + port);
			ServerSocket ss = new ServerSocket(port);
			System.out.println("Bound to port " + port);
			serverThreads = new Vector<ServerThread>();
			locks = new Vector<Lock>();
			conditions = new Vector<Condition>();
			
			while(true) {
				Socket s = ss.accept(); // blocking
				System.out.println("Connection from: " + s.getInetAddress());
				
				Lock lock = new ReentrantLock();
				Condition condition = lock.newCondition();

				ServerThread st = new ServerThread(s, this, lock, condition, first);
				if(first) {
					first = false;
				}
				serverThreads.add(st);
				locks.add(lock);
				conditions.add(condition);
			}
		} catch (IOException ioe) {
			System.out.println("ioe in ChatRoom constructor: " + ioe.getMessage());
		}
	}
	
	public void broadcast(String message, ServerThread st) {
		if (message != null) {
			System.out.println(message);
			for(ServerThread threads : serverThreads) {
				if (st != threads) {
					threads.sendMessage(message);
				}
			}
		}
	}
	
	public void signalNextClient(ServerThread st) {
		int index = -1;
		for(int i = 0; i<serverThreads.size(); i++) {
			if(serverThreads.get(i).equals(st)) {
				index = i;
			}
		}
		// next client
		index++;
		//if you've reached the end of the vector, loop back to the first one
		if(index == serverThreads.size()) {
			index = 0;
		}
		locks.get(index).lock();
		conditions.get(index).signal();
		locks.get(index).unlock();
	}
	
	public static void main(String [] args) {
		ChatRoom cr = new ChatRoom(6789);
	}
}

package xiaoyanq_CSCI201L_Lab9;
import thead.MessageQueue;
import thead.Util;

public class Messenger extends Thread {
	private MessageQueue mq;
	
	public Messenger(MessageQueue mq) {
		this.mq = mq;
	}
	
	public void run() {
		for(int i = 0; i < 20; i++)
		{
			String msg = "Hello world #" + String.valueOf(i);
			mq.addMessage(msg);
			System.out.println(Util.getCurrentTime() + " Message send: " + msg);
			
			try {
				Thread.sleep((long)(Math.random() * 1000));
			}
			catch(InterruptedException e){
				System.out.println(e.getStackTrace());
			}
		}

	}
}


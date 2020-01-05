package Subscriber;
import thead.MessageQueue;
import thead.Util;

public class subscriber extends Thread{
	private MessageQueue mq;
	
	public subscriber(MessageQueue mq) {
		this.mq = mq;
	}
	
	public void run() {
		int numberMsgRead = 0;
		while(numberMsgRead < 20)
		{
			String msg = mq.getMessage();
			if(msg.length() != 0)
			{
				numberMsgRead++;
				System.out.println(Util.getCurrentTime() + " Message received: " + msg);
			}
			else {
				System.out.println(Util.getCurrentTime() + " No message received.");
			}
			
			try {
				Thread.sleep((long)(Math.random() * 1000));
			}
			catch(InterruptedException e){
				System.out.println(e.getStackTrace());
			}
		}
	}
}

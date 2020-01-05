import thead.MessageQueue;
import xiaoyanq_CSCI201L_Lab9.Messenger;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import Subscriber.subscriber;


public class MessageTest {
	
	public static void main(String[] args) {
		for(int i = 0; i < 2; i++)
		{	
			MessageQueue msg = new MessageQueue();
			Messenger talker = new Messenger(msg);
			subscriber listener = new subscriber(msg);
			
			
			ExecutorService executor = Executors.newFixedThreadPool(2);
			executor.execute(talker);
			executor.execute(listener);
			
			executor.shutdown();
			
			while(!executor.isTerminated())
			{
				Thread.yield();
			}
			System.out.println("******************************************");
		}
	}
}

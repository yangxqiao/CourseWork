package gameRoom;

import java.util.Random;
import java.util.Vector;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class GameRoom {
	public Vector<ServerGameThread> all_players;
	public Vector<Lock> locks;
	public Vector<Condition> conditions;
	public Vector<String> secretWords;
	private Integer totalNum;
	private String gameName;
	private String secretWord;
	private boolean gameOver;
	public Server sr;
	public Integer numGuesses = 7;
	public String currMessage = "";
	public boolean is_playing = false;
	
	public GameRoom(ServerGameThread player1, Integer totalNum, String gameName, Vector<String> secretWords, Server sr) {
		all_players = new Vector<ServerGameThread>();
		locks = new Vector<Lock>();
		conditions = new Vector<Condition>();
		
	    this.secretWords = new Vector<String>();
		this.sr = sr;
		this.all_players.add(player1);
		this.totalNum = totalNum;
		this.gameName = gameName;
		this.gameOver = false;
		this.secretWords = secretWords;
		
		Random r = new Random();
		Integer index = r.nextInt(secretWords.size()-1);
		secretWord = secretWords.elementAt(index);
		
		Integer length = secretWord.length();
		for(Integer i = 0; i < length; i++)
		{
			currMessage += "_";
		}
		
		locks.add(player1.lock);
		conditions.add(player1.condition);
		if(totalNum != 1)
		{
			player1.sendMessage("Waiting for " + String.valueOf(playerDiff()) + " other user to join in...");
		}
	}
	
	public Integer indexOfPlayer(ServerGameThread st)
	{
		return this.all_players.indexOf(st);
	}
	
	// return true if the player is added successfully
	public boolean addPlayer(ServerGameThread player) {
		
		if(all_players.size() < totalNum)
		{
			for(ServerGameThread threads : all_players)
			{
				if(threads != player)
				{

					threads.sendMessage("User " + player.username + " is in the game.");
					threads.sendMessage(player.username + "'s Record:");
					threads.sendMessage("--------------");
					threads.sendMessage("Wins - " + sr.getWinNum(player.username));
					threads.sendMessage("Loses - " + sr.getLoseNum(player.username));
					threads.sendMessage("\n");
					
					player.sendMessage("User " + threads.username + " is in the game.");
					player.sendMessage(threads.username + "'s Record:");
					player.sendMessage("--------------");
					player.sendMessage("Wins - " + sr.getWinNum(threads.username));
					player.sendMessage("Loses - " + sr.getLoseNum(threads.username));
					player.sendMessage("\n");
				}
			}
			
			all_players.add(player);
			locks.add(player.lock);
			conditions.add(player.condition);
			
			if(!isFull())
			{
				Integer diff = playerDiff();
				for(ServerGameThread threads : all_players)
				{
					threads.sendMessage("Waiting for " + String.valueOf(diff) + " other user to join in...");
				}
			}
			return true;
		}
		return false;
	}
	
	public Vector<ServerGameThread> getAllPlayers() {
		return all_players;
	}
	
	public String getGameName() {
		return gameName;
	}
	
	public Integer totalPlayer() {
		return totalNum;
	}
	
	public Integer currPlayer() {
		return all_players.size();
	}
	
	// return true is the room is full
	public boolean isFull() {
		return totalNum == all_players.size();
	}
	
	public Integer playerDiff()
	{
		Integer diff = totalNum - all_players.size();
		return diff;
	}
	
//	public void setSecretWord(String secretword) {
//		secretWord = secretword;
//	}
	
	public String getSecretWord() {
		return secretWord;
	}
}
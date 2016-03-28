package ru.java.command.shell;

import java.lang.reflect.InvocationTargetException;
import java.util.Scanner;

import ru.java.command.entity.CommandFactory;
import ru.java.command.entity.IStorage;

public class CommandShellExec {
	private static CommandShellExec INSTANCE = new CommandShellExec();
	private static IStorage storage;
	private CommandShellExec(){
	}
	public void exec(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException{
		if(args.length!=0)
			commandHandler(args);
			ioCommandHandler(); 
	}
	public static CommandShellExec getInstance(IStorage stor){
		storage = stor;
		return INSTANCE;
	}
	private void ioCommandHandler() throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException{
		Scanner sc = new Scanner(System.in);
		String[] args;
		do
        {
	        //System.out.print("CSHELL::>");
	        String strCommand = sc.nextLine();
	        args = strCommand.split(" ", 100); 
	        //System.out.println(strCommand);
	        //for(String str:args){System.out.println("COMMAND: "+str);}
	        CommandFactory.getInstance(storage).getCommand(args).execute();
	    }while(args[0].equals("exit")!=true);
	}
	private void commandHandler(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException{
		CommandFactory.getInstance(storage).getCommand(args).execute();
	}
}

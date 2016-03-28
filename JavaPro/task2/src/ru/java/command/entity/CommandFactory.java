package ru.java.command.entity;

import java.lang.reflect.InvocationTargetException;
import java.util.List;

import ru.java.command.Arguments;
import ru.java.command.ICommand;
import ru.java.command.noname;

public class CommandFactory {
	private static CommandFactory INSTANCE = new CommandFactory();
	private static IStorage storage=null;
	private CommandFactory(){}
	public static CommandFactory getInstance(IStorage stor){
        storage = stor; 
		return INSTANCE;
	}
	public ICommand getCommand(String[] args) throws InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException
	{
		if(args.length==0) return new noname(null);
		ICommand iComm=null;
		try{
		String className = storage.getCommandClassName(args[0]);
		iComm = (ICommand) Class.forName(className).getConstructor(Arguments.class).newInstance(new Arguments(args));
		}catch(ClassNotFoundException e){
			iComm = new noname(null);
		}
		return iComm;
	}
	
}

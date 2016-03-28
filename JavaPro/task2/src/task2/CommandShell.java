package task2;

import java.io.File;
import java.lang.reflect.InvocationTargetException;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

import ru.java.command.entity.IStorage;
import ru.java.command.entity.ShellCommand;
import ru.java.command.entity.ShellCommands;
import ru.java.command.entity.XMLStorage;
import ru.java.command.shell.CommandShellExec;

public class CommandShell {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//System.out.println("Hello World!");
		IStorage storage = new XMLStorage(); 
		try {
			CommandShellExec.getInstance(storage).exec(args);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (NoSuchMethodException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		/*
		    ShellCommand cmd1 = new ShellCommand(1, "CMD1");
		    ShellCommand cmd2 = new ShellCommand(2, "CMD2");
		    ShellCommand cmd3 = new ShellCommand(3, "CMD3");
		    ShellCommand cmd4 = new ShellCommand(4, "CMD4");
		    ShellCommand cmd5 = new ShellCommand(5, "CMD5");
	        
		    ShellCommands commands = new ShellCommands();
		    commands.getCommands().add(cmd1);
		    commands.getCommands().add(cmd2);
		    commands.getCommands().add(cmd3);
		    commands.getCommands().add(cmd4);
		    commands.getCommands().add(cmd5);


	        try {

	            File file = new File("D:\\BelHard\\Java\\JavaProject\\JavaJSP\\task2\\command.xml");
	            JAXBContext jaxbContext = JAXBContext.newInstance(ShellCommands.class);
	            Marshaller jaxbMarshaller = jaxbContext.createMarshaller();

	            jaxbMarshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
	            jaxbMarshaller.marshal(commands, file);
	            jaxbMarshaller.marshal(commands, System.out);
	            
	            Unmarshaller um = jaxbContext.createUnmarshaller();
	            ShellCommands el2 = (ShellCommands) um.unmarshal(file);
	            System.out.println(el2.getCommands().size());
	            for(ShellCommand cmd: el2.getCommands()){
	            	System.out.println(cmd.getId()+" "+cmd.getName());
	            }
	             

	        } catch (JAXBException e) {
	            e.printStackTrace();
	        }

           */
	}

}

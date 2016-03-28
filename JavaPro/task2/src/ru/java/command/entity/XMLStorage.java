package ru.java.command.entity;

import java.io.File;
import java.io.IOException;
import java.util.Hashtable;
import java.util.Map;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

public class XMLStorage implements IStorage {
	private Map<String,String> mCommands=null; 
	public XMLStorage(){
		mCommands = new Hashtable<String,String>();
		save();
	}
	public String getCommandClassName(String name){
		if(mCommands.containsKey(name)==true)
		{
			return mCommands.get(name);
		}else{
			refresh();
			if(mCommands.containsKey(name)==true)
				return mCommands.get(name);
		}
		return new String();
	}
	
	public void refresh() {
		// TODO Auto-generated method stub
		String strPath = new File(".").getAbsolutePath()+"command.xml";
    	strPath = strPath.replaceAll(".command.xml", "command.xml");
		File file = new File(strPath);
        JAXBContext jaxbContext;
         try {
  	      jaxbContext = JAXBContext.newInstance(ShellCommands.class);
  	      Unmarshaller um = jaxbContext.createUnmarshaller();
  	      ShellCommands sCommand = (ShellCommands)um.unmarshal(file);
  	      for(ShellCommand cmd:sCommand.getCommands()){
  	    	mCommands.put(cmd.getName(), cmd.getClassName());
  	      }
         }
		 catch(Exception e)
		 {
			 e.printStackTrace();
		 }
	}
	public void save() {
		// TODO Auto-generated method stub
		 ShellCommand cmd1 = new ShellCommand(1, "ps","ru.java.command.ps");
		 ShellCommand cmd2 = new ShellCommand(2, "ls","ru.java.command.ls");
		 ShellCommand cmd3 = new ShellCommand(3, "pwd","ru.java.command.pwd");
		 ShellCommands commands = new ShellCommands();
		 commands.getCommands().add(cmd1);
		 commands.getCommands().add(cmd2);
		 commands.getCommands().add(cmd3);
		 try {
		  String strPath = new File(".").getAbsolutePath()+"command.xml";
		  strPath = strPath.replaceAll(".command.xml", "command.xml");
		  File file = new File(strPath);
          JAXBContext jaxbContext;
 		  jaxbContext = JAXBContext.newInstance(ShellCommands.class);
          Marshaller jaxbMarshaller;
		  jaxbMarshaller = jaxbContext.createMarshaller();
          jaxbMarshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
          jaxbMarshaller.marshal(commands, file);
          jaxbMarshaller.marshal(commands, System.out);
		 }
		 catch(Exception e)
		 {
			 e.printStackTrace();
		 }
	}

}

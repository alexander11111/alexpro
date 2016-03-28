package ru.java.command;

import java.io.File;

public class ls extends Command {
	public ls(Arguments args){
		super(args);
	}
	@Override
	protected void specExecute() {
		// TODO Auto-generated method stub
		super.specExecute();
		getFileList(".");
	}
	private void getFileList(String folderName){
	    File folder = new File(folderName);
	    for(File file: folder.listFiles()){
	    	if(file.isDirectory()==false)
	    	System.out.println("ls out::>"+file.getName());
	    }
	}

}

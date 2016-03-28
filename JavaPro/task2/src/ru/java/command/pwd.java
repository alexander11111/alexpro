package ru.java.command;

import java.io.File;

public class pwd extends Command {
	public pwd(Arguments args){
		super(args);
	}
	@Override
	protected void specExecute() {
		// TODO Auto-generated method stub
		super.specExecute();
		getPath();
	}
	private void getPath(){
		//System.out.println("pwd out::>"+);
		System.out.println("pwd out::>"+new File(".").getAbsolutePath());
	}

}

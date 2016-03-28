package ru.java.command;

public class Arguments {
	private String[] args;
    public Arguments(String[] args){
    	   this.args = args;
    }
	public String[] getArgs() {
		return args;
	}
	public void setArgs(String[] args) {
		this.args = args;
	}
}

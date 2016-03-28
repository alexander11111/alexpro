package ru.java.command;

public abstract class Command extends Thread implements ICommand {
	protected Arguments args;
	protected Command(Arguments args){
		this.args = args; 
	}
	@Override
	public void execute() {
		// TODO Auto-generated method stub
		start();
	}
    @Override
    public synchronized void run() {
    	// TODO Auto-generated method stub
    	specExecute();
    } 
    protected void specExecute(){
    	if(args!=null)
    	for(String str:args.getArgs()){System.out.println(this.getName()+" execute::>"+str);}
    }
}

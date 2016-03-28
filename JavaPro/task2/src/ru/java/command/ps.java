package ru.java.command;

import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.jutils.jprocesses.JProcesses;
import org.jutils.jprocesses.model.ProcessInfo;

public class ps extends Command {
	public ps(Arguments args){
		super(args);
	}
	@Override
	protected void specExecute() {
		// TODO Auto-generated method stub
		super.specExecute();
		getProcess();
	}
	private void getProcess(){
		String str = getProcessName();
		List<ProcessInfo> processesList = JProcesses.getProcessList();
	    for (final ProcessInfo processInfo : processesList) {
	    	//System.out.println("ps execute::>pattern name: "+str+" "+processInfo.getName()+" "+processInfo.getName().indexOf(str,0));
	    	if((str=="")||(processInfo.getName().indexOf(str)!=-1))
	    	{
	        System.out.println("ps Process PID: " + processInfo.getPid());
	        System.out.println("ps Process Name: " + processInfo.getName());
	        System.out.println("ps Process Time: " + processInfo.getTime());
	        System.out.println("ps User: " + processInfo.getUser());
	        System.out.println("ps Virtual Memory: " + processInfo.getVirtualMemory());
	        System.out.println("ps Physical Memory: " + processInfo.getPhysicalMemory());
	        System.out.println("ps CPU usage: " + processInfo.getCpuUsage());
	        System.out.println("ps Start Time: " + processInfo.getStartTime());
	        System.out.println("ps Priority: " + processInfo.getPriority());
	        System.out.println("ps Full command: " + processInfo.getCommand());
	        System.out.println("------------------");
	    	}
	    }
	}
	private String getProcessName(){
		for(String str:args.getArgs())
		{
		 Pattern p = Pattern.compile("(pname=\")(.+)\"");
		 Matcher m = p.matcher(str);
		 if(m.find()==true)
		 {
	       return m.group().replaceAll("pname=", "").replaceAll("\"", "");	
		   //System.out.println("ps execute::>pattern name: "+strName);
		 }
		}
		return "";
	} 
}

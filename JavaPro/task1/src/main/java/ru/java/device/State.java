package ru.java.device;

public class State {
	private TOGGLESTATE toggleState;
	private String notify;
	public State(){
		resetState();
	}
	public State(TOGGLESTATE toggleState,String notify){
	    this.toggleState = toggleState;	
	    this.notify = notify;
	
	}
	public void resetState(){
		toggleState = TOGGLESTATE.OFF;
		notify = "null state";
	}
	
	public TOGGLESTATE getToggleState() {
		return toggleState;
	}
	public void setToggleState(TOGGLESTATE toggleState) {
		this.toggleState = toggleState;
	}
	public String getNotify() {
		return notify;
	}
	public void setNotify(String notify) {
		this.notify = notify;
	}
	
}

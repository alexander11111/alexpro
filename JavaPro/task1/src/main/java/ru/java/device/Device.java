package ru.java.device;

public abstract class Device implements IDevice {
	private State state;
	public Device(State st){
		state = st; 
	}
	@Override
	public State turn() {
		return toggle();
	}
	protected void start(){
		System.out.println(state.getNotify());
	}
	protected void stop(){
		System.out.println(state.getNotify());
	}
	protected State toggle(){
		if(state.getToggleState()==TOGGLESTATE.OFF){
			state.setToggleState(TOGGLESTATE.ON);
			state.setNotify(this.getClass().getName()+" "+": I am turned on!");
			start();
		}else
			if(state.getToggleState()==TOGGLESTATE.ON){
				state.setToggleState(TOGGLESTATE.OFF);
				state.setNotify(this.getClass().getName()+" "+": I am turned off!");
				stop();
			}
		return state;
	}
}

package ie.globalcom;

import ru.java.device.Device;
import ru.java.device.State;

public class Toster extends Device {
	public Toster(State st){
		super(st);
	}
	@Override
	protected void start() {
		super.start();
		//Start Process 
	}
	@Override
	protected void stop() {
		super.stop();
		//Stop Process
	}
}

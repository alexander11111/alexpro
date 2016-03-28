package ru.java.device;

import java.lang.reflect.InvocationTargetException;

import ru.java.store.IStorage;

public class DeviceDriver {
	private static final DeviceDriver INSTANCE = new DeviceDriver();
	private DeviceDriver(){}
	private static DeviceFactory devFactory=null;
	public static DeviceDriver getInstance(IStorage storage)
	{
		devFactory = DeviceFactory.getInstance().setStorage(storage);
		return INSTANCE;
	} 
	public State turn(String name) throws InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException, ClassNotFoundException{
		return devFactory.getInstance().getDevice(name).turn();
	}
	
}

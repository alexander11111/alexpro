package ru.java.device;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Properties;

import ru.java.service.SettingsDB;
import ru.java.store.IStorage;
import ru.java.store.classes;

public class DeviceFactory {
	 private static final DeviceFactory INSTANCE = new DeviceFactory();
	 private IStorage storage;
     private Map<String,IDevice> deviceList = null; 
     private DeviceFactory(){
    	 deviceList = new Hashtable<String,IDevice>(); 
     }
     private void refresh() throws InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException, ClassNotFoundException
     {
    	 List<classes> list = storage.getAllClass();
    	 for(classes cl:list){
    		 if(deviceList.containsKey(cl.getClassname())==false)
    		 {
				IDevice iDev = (IDevice) Class.forName(cl.getClassname()).getConstructor(State.class).newInstance(new State());
     			deviceList.put(cl.getClassname(), iDev);
    		 }
    	 }
     }
     public static DeviceFactory getInstance(){return INSTANCE;}
	 public DeviceFactory setStorage(IStorage storage) {
		this.storage = storage;
		return this;
	 }
	 public IDevice getDevice(String name) throws InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, NoSuchMethodException, SecurityException, ClassNotFoundException {
		 classes className = storage.getClassName(name);
		 if (className==null) throw new ClassNotFoundException("Illegal Operation!");
		 if(deviceList.containsKey(className.getClassname())==true){
		    return deviceList.get(className.getClassname()); 	 
		 }else
		 {
		    refresh();
		    if(deviceList.containsKey(className.getClassname())==true){
			    return deviceList.get(className.getClassname());
		    }
		 }
		 return null;
	 }
}

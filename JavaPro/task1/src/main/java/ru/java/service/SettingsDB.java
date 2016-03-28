package ru.java.service;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

public class SettingsDB {
	private static final SettingsDB INSTANCE = new SettingsDB();
	private final Properties properties = new Properties();
	private SettingsDB() {
		try {
			properties.load(new FileInputStream(this.getClass().getClassLoader().getResource("taskconfig.properties").getFile()));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	public static SettingsDB getInstance(){return INSTANCE;}
	public String value(String key){return this.properties.getProperty(key);}
	

}

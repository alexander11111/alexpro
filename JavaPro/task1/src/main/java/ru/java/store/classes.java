package ru.java.store;

public class classes {
	private int id;
    private String classname;
    private boolean state;
    public classes(int id,String classname){
    	this.id = id;
    	this.classname = classname;
    	this.state = false;
    	
    }
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getClassname() {
		return classname;
	}
	public void setClassname(String classname) {
		this.classname = classname;
	}
	public boolean isState() {
		return state;
	}
	public void setState(boolean state) {
		this.state = state;
	}
}

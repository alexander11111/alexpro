package ru.java.datamodel;

import java.io.Serializable;

import com.fasterxml.jackson.annotation.JsonProperty;

public class RemoteCommandData implements Serializable  {
	//@JsonProperty("operation")
	public String operation;

	public RemoteCommandData() {
	}
	
	public RemoteCommandData(String operation) {
		this.operation = operation;
	}

	public String getOperation() {
		return operation;
	}

	public void setOperation(String operation) {
		this.operation = operation;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "{operation:"+operation+"}";
	}
}
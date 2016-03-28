package ru.java.command.entity;

import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;

@XmlRootElement
@XmlAccessorType(XmlAccessType.NONE)
public class ShellCommand {

    // обязательно должен быть конструктор без параметров!!
    public ShellCommand() {
    }

    public ShellCommand(int id, String name, String className) {
        this.id = id;
        this.name = name;
        this.className = className;
    }
    
    @XmlAttribute(name = "id", required = true)
    private int id;
    
    @XmlElement(required = true)
    private String name;
    
    @XmlElement(required = true)
    private String className;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

	public String getClassName() {
		return className;
	}

	public void setClassName(String className) {
		this.className = className;
	}
}

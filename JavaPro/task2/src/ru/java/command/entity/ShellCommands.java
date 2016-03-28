package ru.java.command.entity;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
@XmlAccessorType(XmlAccessType.NONE)
public class ShellCommands {

    @XmlElement(name="commands")
    private List<ShellCommand> commands = new ArrayList<ShellCommand>();

	public List<ShellCommand> getCommands() {
		return commands;
	}

	public void setCommands(List<ShellCommand> commands) {
		this.commands = commands;
	}





  
}

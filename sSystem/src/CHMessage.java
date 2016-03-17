package src;
public class CHMessage
{
	public CHMessage(){
		System.out.println("(CHMessage::>Create");
		m_sbyInfo = new byte[150];
	}
    short m_swLen;
    short m_swObjID;
	byte m_sbyFrom;
    byte m_sbyFor;
    byte m_sbyType;
    byte m_sbyTypeIntID;
    byte m_sbyIntID;
    byte m_sbyServerID;
    byte m_sbyDirID;
    byte m_sbyInfo[];
};	


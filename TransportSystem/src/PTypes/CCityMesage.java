package PTypes;

import java.util.Date;


public class CCityMesage {
	public int ID;
	public int codeID;
	public String strName;
	public int X;
	public int Y;
	public Date depDate;
	public Date arrDate;
	public boolean isAir;
	public boolean isAut;
	public boolean isTrain;
	public boolean isWath;
	
	public int getID(){return ID;};
	public String getName(){return strName;};
	public int getX(){return X;};
	public int getY(){return Y;};
	public boolean getAir(){return isAir;};
	public boolean getAut(){return isAut;};
	public boolean getTrain(){return isTrain;};
	public boolean getWath(){return isWath;};
	
	public void setID(int val){ID = val;};
	public void setName(String val){strName = val;};
	public void setX(int val){X = val;};
	public void setY(int val){Y = val;};
	public void setAir(boolean val){isAir = val;};
	public void setAut(boolean val){isAut = val;};
	public void setTrain(boolean val){isTrain = val;};
	public void setWath(boolean val){isWath = val;};
}

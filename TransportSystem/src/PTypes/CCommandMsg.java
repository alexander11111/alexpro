package PTypes;

public class CCommandMsg {
	 public CCommandMsg(){
		 pCM = new CCityMesage();
	 }
	 public int cargoID;
	 public int cargoTypeID;
     public int depCity;
     public int arrCity;
     public CCityMesage pCM;
}

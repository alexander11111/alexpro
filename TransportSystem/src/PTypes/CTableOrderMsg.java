package PTypes;

public class CTableOrderMsg {
	 public int ID;
	 public String strName;
	 public String strLicNumber;
	 public String strLicenseNo;
	 public String getInfo(){
		 return "ID: "+ID+" Name: "+strName+" LicCH: "+strLicNumber+" LicenseNo: "+strLicenseNo;
	 }
}

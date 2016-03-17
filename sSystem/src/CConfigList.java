package src;
//import java.io.BufferedReader;
//import java.io.FileReader;
import com.siemens.icm.io.file.FileConnection;
import javax.microedition.io.Connector;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.Vector;
public class CConfigList {
	  private Vector mConfig;
	  public CConfigList(String strConf){
		  mConfig = new Vector();
		  LoadFromFile(strConf);
		  System.out.println("CPhoneBook::>Create");
	  }
      public void addItem(CConfigItem pI){
    	  mConfig.addElement(pI);
      }
      public CConfigItem getItem(int i){
    	  if(i<mConfig.size())
    		  return (CConfigItem)(mConfig.elementAt(i)); else
    			  return null;
      }
      public int Size0(){
    	  return mConfig.size();
      }
       public void LoadFromFile(String strName){
    	  System.out.println("CPhoneBook::>LoadFromFile "+strName);
    	  try{
    		FileConnection objFileConnection =
    		(FileConnection)Connector.open(strName);
    		DataInputStream objDataInputStream =
    		objFileConnection.openDataInputStream();
    		byte[] data = new byte[objDataInputStream.available()];
    		if (objDataInputStream.available() > -1)
			{
			 objDataInputStream.read(data, 0, objDataInputStream.available());
			 ParceString(new String(data));
			}
			objDataInputStream.close();
    	  }catch (IOException e) 
    	  { 
    		System.out.println("CPhoneBook::>IOException!!!: "+e.getMessage());
          }
      }
      private void ParceString(String str)
      {
    		 int nPos = str.indexOf("::");
			 int nPos1 = str.indexOf("::",2);
			 int i=0,j=0;
			 String s[] = new String[5];
		     while (nPos1!=-1) 
		     {
		      String strF = str.substring(nPos+2,nPos1-0);
		      nPos = str.indexOf("::",nPos+2);
		      nPos1 = str.indexOf("::",nPos1+1);
		      if (strF.compareTo("\r\n")!=0)
		      { 
		       s[i] = strF;
		       if (i==4) 
		       {
		     	addItem(new CConfigItem(s[0],s[1],s[2],s[3],s[4]));
		    	i=0;
		       }else  i++;
		      }
		     }
      }
      public boolean GetLoops(int ID,Vector nList){
    	  boolean res = false;
    	  try{
    		  //System.out.println("("+ID+")GetLoops="+Size0());  
    	  for(int i=0;i<Size0();i++)
    	  {
    		  CConfigItem pI = getItem(i);
    		  
    		  int nID = Integer.parseInt(pI.strLoop);
    		  //System.out.println("("+ID+")GetLoops="+nID+" Type:"+pI.strType);
    		  if(nID==ID)
    		  {
    		   if ((pI.strType.equalsIgnoreCase("Loop")==true)||(pI.strType.equalsIgnoreCase("User")==true)){
    			  //System.out.println("("+ID+")GetLoops="+pI.strType);  
    		 	  nList.addElement(new CConfigItem(pI));
    		 	  res = true;
    		   }
    		  }
    	  }
    	  return res;
    	  }catch(Exception e){
    		  return false;
    	  }
      }
      public boolean GetAdmins(Vector nList){
    	  boolean res = false;
    	  try{
    	  for(int i=0;i<Size0();i++)
    	  {
    		  CConfigItem pI = getItem(i);
    		   if ((pI.strType.equalsIgnoreCase("Admin")==true)){
    			   //System.out.println("("+pI.strLoop+")GetAdmins="+pI.strType);  
    		 	  nList.addElement(new CConfigItem(pI));
    		 	  res = true;
    		   }
    	  }
    	  return res;
    	  }catch(Exception e){
    		  return false;
    	  }   	  
      }
      
}

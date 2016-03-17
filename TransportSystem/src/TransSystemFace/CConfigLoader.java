package TransSystemFace;

import PDataBase.CDBDriver;
import PDataBase.CDataBase;
import PTableOrder.CTableOrders;
import PTypes.CTableOrderMsg;

public class CConfigLoader {
	   private CDataBase pDB;
	   private CDBDriver drDB;
	   private CTableOrders pTO;
	   public CConfigLoader(String strUrl,String strUserName,String strPassword,String strDriver){
		   connectDB(strUrl,strUserName,strPassword,strDriver);
		   CreateSystem();
	   }
	   private void connectDB(String strUrl,String strUserName,String strPassword,String strDriver){
		   pDB  = new CDataBase(strUrl,strUserName,strPassword,strDriver);
		   if (pDB.ConnectToDB()==true){
			   drDB = new CDBDriver(pDB.getConnection()); 
		   }
	   }
	   private void CreateSystem(){
		   drDB.createTransSystem();
		   CTableOrderMsg pTbl = new CTableOrderMsg();
		   if (drDB.getTableOrder(pTbl)==true){
			   pTO = new CTableOrders(pTbl);
			   pTO.connectToDB(drDB);
			   pTO.prepareSystem();
		   }
	   }
	   public CTableOrders getSystem(){
		   return pTO;
	   }
	   public void close(){
		   drDB.close();
	   }

}

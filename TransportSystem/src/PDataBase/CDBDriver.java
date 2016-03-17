package PDataBase;


import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Date;
import java.util.HashMap;
import java.util.Vector;

import PCity.CCity;
import PTableOrder.CTrips;
import PTransport.CTransportCompany;
import PTypes.CCargoMsg;
import PTypes.CCityMesage;
import PTypes.CPassengerMsg;
import PTypes.CTableOrderMsg;
import PTypes.CTransCompanyMsg;
import PTypes.CTransportMsg;
import PTypes.CTripsMsg;

public class CDBDriver {
	   private CReadWriter rw;
	   public  ResultSet  rs;
	   public CDBDriver(Connection cn){
		   rw = new CReadWriter(cn);
	   }
	   /*
	    	 public int ID;
	 public String strName;
	 public String strLicNumber;
	 public String strLicenseNo;
	    */
	   public void close(){
		   rw.closeRW();
	   }
  	   public void createTransSystem(){
  		 rw.Write("DROP TABLE TRANSSSYST");
  		 
  		 rw.Write("CREATE TABLE TRANSSSYST("
  		 		+ "ID INT PRIMARY KEY,"
  		 		+ "strName VARCHAR(255),"
  		 		+ "strLicNumber VARCHAR(100),"
  		 		+ "strLicenseNo VARCHAR(100)"
  		 		+ ");");  
  		 
  		 rw.Write("INSERT INTO TRANSSSYST VALUES("
  		 		+ "0,"
  		 		+ "'My Transport System',"
  		 		+ "'CH:¹ AB43-56V',"
  		 		+ "'LS:¹ 4332-34C'"
  		 		+ ");");
  	   }
  	   public void createCityTBL(){
         rw.Write("DROP TABLE CITYS");

  		 rw.Write("CREATE TABLE CITYS("
  		 		+ "ID INT PRIMARY KEY,"
  		 		+ "codeID INT ,"
  		 		+ "strName VARCHAR(255),"
  		 		+ "X INT ,"
  		 		+ "Y INT ,"
  		 		+ "isAir BOOL,"
  		 		+ "isAut BOOL,"
  		 		+ "isTrain BOOL,"
  		 		+ "isWath BOOL,"
  		 		+ ");");  
  		 
         rw.Write("INSERT INTO CITYS VALUES(0,0,'Minsk'  ,0  ,0  ,true,true,true,false);");
         rw.Write("INSERT INTO CITYS VALUES(1,1,'Gomel'  ,10 ,20 ,true,true,true,false);");
         rw.Write("INSERT INTO CITYS VALUES(2,2,'Vitebsk',20 ,40 ,false,true,true,true);");
         rw.Write("INSERT INTO CITYS VALUES(3,3,'Grodno' ,30 ,100,false,true,true,false);");
         rw.Write("INSERT INTO CITYS VALUES(4,4,'Mogilev',50 ,70 ,false,true,true,true);");
         rw.Write("INSERT INTO CITYS VALUES(5,5,'Moskva' ,230,450,true,true,true,false);");
         rw.Write("INSERT INTO CITYS VALUES(6,6,'S-Petersburg' ,430,650,true,true,true,true);");
         rw.Write("INSERT INTO CITYS VALUES(7,7,'Brussel' ,530,750,true,true,true,false);");
         rw.Write("INSERT INTO CITYS VALUES(8,8,'Madrid' ,660,880,true,true,true,true);");
         rw.Write("INSERT INTO CITYS VALUES(9,9,'Costa-Rica' ,1660,1180,true,true,false,true);");
	   
  	   }
       public void addCity(String strName,int nX,int nY,boolean nIsAir,boolean nIsAut,boolean nIsTra,boolean nIsWat){
    	   int nID = getMaxCityID();
    	   if(nID!=0) nID++;
    	   rw.Write("INSERT INTO CITYS VALUES("
    	   		+ nID+","
    	   		+ nID+","
    	   		+ "'"+strName+"',"
    	   		+ nX+","
    	   		+ nY+","
    	   		+ nIsAir+","
    	   		+ nIsAut+","
    	   		+ nIsTra+","
    	   		+ nIsWat
    	   		+ ");");
       }
  	   public void createTransCopmanyTBL(){
         rw.Write("DROP TABLE TRANSCOMPS");

    	 rw.Write("CREATE TABLE TRANSCOMPS("
    		 		+ "ID INT PRIMARY KEY,"
    		 		+ "nTransCoID INT ,"
    		 		+ "strName VARCHAR(255),"
    		 		+ "strLicNo VARCHAR(255),"
    		 		+ ");");  
    		 
          rw.Write("INSERT INTO TRANSCOMPS VALUES(0,0,'LTD MinTrans'   ,'LC-435/43BV');");
          rw.Write("INSERT INTO TRANSCOMPS VALUES(1,1,'LTD TransAeroCo','LC-565/34CD');");
          rw.Write("INSERT INTO TRANSCOMPS VALUES(2,2,'LTD AeroMax'    ,'LC-233/56JK');");
  	   }
  	   public void createTransTBL(){

          rw.Write("DROP TABLE TRANSS");

      	  rw.Write("CREATE TABLE TRANSS("
      		 		+ "ID INT PRIMARY KEY,"
      		 		+ "nTransCoID INT ,"
      		 		+ "nTransID INT ,"
      		 		+ "Type INT ,"
      		 		+ "nPortID INT ,"
      		 		+ "strNumber VARCHAR(255),"
      		 		+ "strName VARCHAR(255),"
      		 		+ "costKilo DOUBLE,"
      		 		+ "costKilogKm DOUBLE,"
      		 		+ "speed DOUBLE,"
      		 		+ "cargoCapacity DOUBLE,"
      		 		+ "pasgrCapacity INT ,"
      		 		+ ");");  
      		 
          rw.Write("INSERT INTO TRANSS VALUES(0,0,0,0,1,'AB 23-45MR'   ,'MAN-3245',30,130,90,1000,50);");
          rw.Write("INSERT INTO TRANSS VALUES(1,0,1,1,1,'CG 43-22NR'   ,'MAZ-5453',25,30,80,3000,0);");
          rw.Write("INSERT INTO TRANSS VALUES(2,0,2,2,2,'TR 456/C'     ,'RYR 344C',10,40,80,600000,0);");
          rw.Write("INSERT INTO TRANSS VALUES(3,0,3,3,2,'TR 457/C'     ,'RYR 344P',12,30,100,100,500);");
          rw.Write("INSERT INTO TRANSS VALUES(4,0,4,4,0,'AI MR710'     ,'BOENG-747C',100,300,700,80000,0);");
          rw.Write("INSERT INTO TRANSS VALUES(5,0,5,5,0,'AI MR711'     ,'BOENG-747P',90,240,700,100,300);");
          rw.Write("INSERT INTO TRANSS VALUES(6,0,6,6,3,'WT CP544'     ,'COSTA CONCORDIA',15,230,40,200000,1000);");

          rw.Write("INSERT INTO TRANSS VALUES(7,1,7,0,1,'AB 33-76MR'   ,'MAN-3245',30,240,90,1000,50);");
          rw.Write("INSERT INTO TRANSS VALUES(8,1,8,0,1,'AB 43-86MR'   ,'MERCEDES-314',50,280,90,100,10);");
          rw.Write("INSERT INTO TRANSS VALUES(9,1,9,0,1,'AB 87-11MR'   ,'VW-330d',50,220,90,100,25);");

          rw.Write("INSERT INTO TRANSS VALUES(10,2,10,5,0,'AI MR713'   ,'EMBRAER',120,530,900,100,200);");
          rw.Write("INSERT INTO TRANSS VALUES(11,2,11,5,0,'AI MR714'   ,'AN-224',300,830,850,250000,20);");
          rw.Write("INSERT INTO TRANSS VALUES(12,2,12,6,3,'WT CP200'   ,'TITAN',30,130,40,100000,300);");
          
          rw.Write("INSERT INTO TRANSS VALUES(13,0,13,1,1,'CG 65-89NR' ,'VOLVO-440',25,250,80,30000,0);");
          rw.Write("INSERT INTO TRANSS VALUES(14,0,14,0,1,'AB 64-35MR' ,'Ford Transit',60,230,80,90,10);");
          rw.Write("INSERT INTO TRANSS VALUES(15,0,15,0,1,'FB 54-32FR' ,'Ford Escort',300,750,80,150,5);");
          rw.Write("INSERT INTO TRANSS VALUES(16,0,16,0,1,'GB 46-35RR' ,'Mercedes E320',400,830,80,130,10);");
          rw.Write("INSERT INTO TRANSS VALUES(17,0,17,0,1,'AH 44-33HR' ,'MAZ A5432',330,330,80,120,50);");
          rw.Write("INSERT INTO TRANSS VALUES(18,0,18,0,1,'AR 94-35GR' ,'MAN Z454-FN',60,630,80,130,55);");

  	   }
  	   public void createTripsTBL(){
  	        rw.Write("DROP TABLE TRIPSS");

  	    	rw.Write("CREATE TABLE TRIPSS("
  	    		 		+ "ID INT PRIMARY KEY,"
  	    		 		+ "codeID INT ,"
  	    		 		+ "TypeID INT ,"
  	    		 		+ "strNumber VARCHAR(255),"
  	    		 		+ "strName VARCHAR(255),"
  	    		 		+ "depDate DATETIME,"
  	    		 		+ "arrDate DATETIME,"
  	    		 		+ "depCityID INT ,"
  	    		 		+ "arrCityID INT ,"
  	    		 		+ "nTransID INT ,"
  	    		 		+ ");");  

  	    	rw.Write("INSERT INTO TRIPSS VALUES(0,0,0,'TR100200','Minsk-Grodno','2014-09-13 8:15:00','2014-09-13 13:20:00',0,3,8);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(1,1,0,'TR100201','Minsk-Grodno','2014-09-13 8:15:00','2014-09-13 13:20:00',0,3,14);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(2,2,2,'TR100202','Minsk-Grodno','2014-09-13 8:15:00','2014-09-13 13:20:00',0,3,2);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(3,3,0,'TR100203','Minsk-Vitebsk','2014-09-13 8:15:00','2014-09-13 13:20:00',0,2,8);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(4,4,0,'TR100204','Minsk-Vitebsk','2014-09-13 8:15:00','2014-09-13 13:20:00',0,2,14);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(5,5,1,'TR100205','Minsk-Moskva','2014-09-13 8:15:00','2014-09-13 13:20:00',0,5,1);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(6,6,1,'TR100206','Grodno-S-Petersburg','2014-09-13 8:15:00','2014-09-13 13:20:00',3,6,13);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(7,7,0,'TR100207','Moskva-Brussel','2014-09-13 8:15:00','2014-09-13 13:20:00',5,7,14);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(8,8,0,'TR100208','Madrid-Brussel','2014-09-13 8:15:00','2014-09-13 13:20:00',7,8,15);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(9,9,4,'TR100209','Costa-Rica-Madrid','2014-09-13 8:15:00','2014-09-13 13:20:00',9,8,4);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(10,10,0,'TR100210','Moskva-Madrid','2014-09-13 8:15:00','2014-09-13 13:20:00',8,8,16);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(11,11,0,'TR100211','S-Petersburg-Minsk','2014-09-13 8:15:00','2014-09-13 13:20:00',6,0,17);");
  	    	rw.Write("INSERT INTO TRIPSS VALUES(12,12,0,'TR100212','Grodno-S-Petersburg','2014-09-13 8:15:00','2014-09-13 13:20:00',3,6,17);");
  	    	  	   }
  	    public void createCargoTBL(){
  	       rw.Write("DROP TABLE CARGOS");

      	   rw.Write("CREATE TABLE CARGOS("
      		 		+ "ID INT PRIMARY KEY,"
      		 		+ "cargoID INT ,"
      		 		+ "cargoTypeID INT ,"
      		 		+ "strOwnerName VARCHAR(255),"
      		 		+ "strName VARCHAR(255),"
      		 		+ "volume DOUBLE,"
      		 		+ "dense DOUBLE,"
      		 		+ "Money DOUBLE,"
      		 		+ ");");  
      		 
           rw.Write("INSERT INTO CARGOS VALUES(0,0,0,'LTD Doneck Ugol','coal',30000,1.200,16000);");
           rw.Write("INSERT INTO CARGOS VALUES(1,1,0,'LTD Granit'     ,'granite',100,2.200,2500000);");
           rw.Write("INSERT INTO CARGOS VALUES(2,2,0,'TNK CLAYD'      ,'claydite',440,1.100,3500000);");
           rw.Write("INSERT INTO CARGOS VALUES(3,3,0,'BELCEMENT'      ,'cement',500,2.100,5500000);");
           rw.Write("INSERT INTO CARGOS VALUES(4,4,0,'BELASFALN'      ,'asphalt',1000,2.300,12500000);");
           rw.Write("INSERT INTO CARGOS VALUES(5,5,0,'Belarus Neft'   ,'benzine',2300,0.780,129500000);");
           rw.Write("INSERT INTO CARGOS VALUES(6,6,0,'Gsprom Neft'    ,'kerosine',700,0.790,459500000);");
           rw.Write("INSERT INTO CARGOS VALUES(7,7,0,'RNK'            ,'bitum',3100,0.850,929500000);");
           rw.Write("INSERT INTO CARGOS VALUES(8,8,0,'TNK BP'         ,'petroleum',1400,0.900,8929500000);");
           rw.Write("INSERT INTO CARGOS VALUES(9,9,0,'TNK BP'         ,'diesel',250,0.780,12900000);");
    		   
  	   }
  	   public void createPassTBL(){
  	       rw.Write("DROP TABLE PASNGS");

      	   rw.Write("CREATE TABLE PASNGS("
      		 		+ "ID INT PRIMARY KEY,"
      		 		+ "cargoID INT ,"
      		 		+ "cargoTypeID INT ,"
      		 		+ "Money DOUBLE,"
      		 		+ "sImya VARCHAR(255),"
      		 		+ "sFam VARCHAR(255),"
      		 		+ "sOtch VARCHAR(255),"
      		 		+ ");");  
      		 
           rw.Write("INSERT INTO PASNGS VALUES(0,0,1,3000,'Virtanen','Toiv','Niemi');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(1,1,1,250000,'Rantanen','Virtan','Laakso');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(2,2,1,50000,'Jokinen','Jok','Kallio');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(3,3,1,70000,'Karjalainen','Ahon','Nurmi');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(4,4,1,30000,'Ahonen','Virtan','Koski');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(5,5,1,3000000,'Toivonen','Rant','Saari');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(6,6,1,240000,'Halone1','Karjal1','Virt1');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(7,7,1,15000,'Halone2','Karjal2','Virt2');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(8,8,1,7000,'Halone3','Karjal3','Virt3');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(9,9,1,5000,'Halone4','Karjal4','Virt4');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(10,10,1,2000,'Halone5','Karjal5','Virt5');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(11,11,1,12000,'Halone6','Karjal6','Virt6');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(12,12,1,43000,'Halone7','Karjal7','Virt7');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(13,13,1,12000,'Halone8','Karjal8','Virt8');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(14,14,1,12000,'Halone9','Karjal9','Virt9');");  		   
           rw.Write("INSERT INTO PASNGS VALUES(15,15,1,5000,'Halone10','Karjal10','Virt10');");  		   
  	   }
  
  	   public boolean loadCity(int ID,HashMap<Integer,CCityMesage> pTbl){
 		    if (ID==-1) rs = rw.Read("SELECT * FROM CITYS");else
 		    if (ID!=-1) rs = rw.Read("SELECT * FROM CITYS WHERE cargoID="+ID);
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CCityMesage pT = new CCityMesage();
					pT.ID      = rs.getInt("ID");
					pT.codeID  = rs.getInt("codeID");
					pT.strName = rs.getString("strName");
					pT.X       = rs.getInt("X");
					pT.Y       = rs.getInt("Y");
					pT.isAir   = rs.getBoolean("isAir");
					pT.isAut   = rs.getBoolean("isAut");
					pT.isTrain = rs.getBoolean("isTrain");
					pT.isWath  = rs.getBoolean("isWath");
					pTbl.put(pT.codeID,pT);
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;   		   
  	   }
  	   public boolean loadTransCopmany(Vector<CTransCompanyMsg> pTbl){
 		    rs = rw.Read("SELECT * FROM TRANSCOMPS");
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CTransCompanyMsg pT = new CTransCompanyMsg();
					pT.ID        = rs.getInt("ID");
					pT.nTransCoID= rs.getInt("nTransCoID");
					pT.strName   = rs.getString("strName");
					pT.strLicNo  = rs.getString("strLicNo");
					pTbl.add(pT);
				    res = true;
				}
				for(CTransCompanyMsg pT:pTbl)
				{
					HashMap<Integer,CTransportMsg> pTTbl = new HashMap<Integer,CTransportMsg>();
				    loadTransport(pT.nTransCoID,pTTbl);
				    pT.pTrans = pTTbl;	 
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;   		   
  	   }
  	   public boolean loadTransport(int nTransCo,HashMap<Integer,CTransportMsg> pTbl){
  		    if (nTransCo!=-1) rs = rw.Read("SELECT * FROM TRANSS WHERE nTransCoID="+nTransCo); else
  		                      rs = rw.Read("SELECT * FROM TRANSS");
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CTransportMsg pT = new CTransportMsg();
					pT.ID            = rs.getInt("ID");
					pT.nTransCoID    = rs.getInt("nTransCoID");
					pT.nTransID      = rs.getInt("nTransID");
					pT.Type          = rs.getInt("Type");
					pT.nPortID       = rs.getInt("nPortID");
					pT.strNumber     = rs.getString("strNumber");
					pT.strName       = rs.getString("strName");
					pT.costKilo      = rs.getDouble("costKilo");
					pT.costKilogKm   = rs.getDouble("costKilogKm");
					pT.speed         = rs.getDouble("speed");
					pT.cargoCapacity = rs.getDouble("cargoCapacity");
					pT.pasgrCapacity = rs.getInt("pasgrCapacity");
					pTbl.put(pT.nTransID,pT);
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;   		   
	   }
  	   public boolean loadTrips(Vector<CTripsMsg> pTbl){
  		    rs = rw.Read("SELECT * FROM TRIPSS");
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CTripsMsg pT = new CTripsMsg();
					pT.ID        = rs.getInt("ID");
					pT.codeID    = rs.getInt("codeID");
					pT.TypeID      = rs.getInt("TypeID");
					pT.strNumber = rs.getString("strNumber");
					pT.strName   = rs.getString("strName");
					pT.depDate   = rs.getTime("depDate");
					pT.arrDate   = rs.getTime("arrDate");
					pT.depCityID = rs.getInt("depCityID");
					pT.arrCityID = rs.getInt("arrCityID");
					pT.nTransID  = rs.getInt("nTransID");
					pTbl.add(pT);
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;  
  	   }
  	   ///////////////////////
  	   public boolean loadCargos(Vector<CCargoMsg> pTbl){
		    rs = rw.Read("SELECT * FROM CARGOS");
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CCargoMsg pT = new CCargoMsg();
					pT.ID           = rs.getInt("ID");
					pT.cargoID      = rs.getInt("cargoID");
					pT.cargoTypeID  = rs.getInt("cargoTypeID");
					pT.strOwnerName = rs.getString("strOwnerName");
					pT.strName      = rs.getString("strName");
					pT.volume       = rs.getDouble("volume");
					pT.dense        = rs.getDouble("dense");
					pT.Money        = rs.getDouble("Money");
					pTbl.add(pT);
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;  
	   }
  	   public boolean loadPassengers(Vector<CPassengerMsg> pTbl){
		    rs = rw.Read("SELECT * FROM PASNGS");
		    boolean res = false;
		    if (pTbl==null) return false;
		    try {
		    	pTbl.clear();
				while(rs.next())
				{
					CPassengerMsg pT = new CPassengerMsg();
					pT.ID         = rs.getInt("ID");
					pT.cargoID    = rs.getInt("cargoID");
					pT.cargoTypeID= rs.getInt("cargoTypeID");
					pT.Money      = rs.getDouble("Money");
					pT.sImya      = rs.getString("sImya");
					pT.sFam       = rs.getString("sFam");
					pT.sOtch      = rs.getString("sOtch");
					pTbl.add(pT);
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;  
	   }
 	   
  	   
  	   public boolean getTableOrder(CTableOrderMsg pTbl){
  		    rs = rw.Read("SELECT * FROM TRANSSSYST");
  		    boolean res = false;
  		    if (pTbl==null) return false;
		    try {
				while(rs.next())
				{
					pTbl.ID           = rs.getInt("ID");
					pTbl.strName      = rs.getString("strName");
					pTbl.strLicNumber = rs.getString("strLicNumber");
					pTbl.strLicenseNo = rs.getString("strLicenseNo");
				    res = true;
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return res;
  	   }
  	   public int getMaxCityID(){
		    rs = rw.Read("SELECT max(ID) as nID FROM CITYS");
		    try {
				while(rs.next())
				{
					return rs.getInt("nID");
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    return 0;
	   }
}

package PTableOrder;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import CConstant.CConst;
import PCity.CCity;
import PDataBase.CDBDriver;
import PTransport.CATAirPlane;
import PTransport.CAirTrans;
import PTransport.CGTAuto;
import PTransport.CGTTrainCar;
import PTransport.CTransportCompany;
import PTransport.CWTShip;
import PTransport.IFTransport;
import PTransported.CCargo;
import PTransported.CPassenger;
import PTransported.IFTransported;
import PTypes.CCargoMsg;
import PTypes.CCityMesage;
import PTypes.CCommandMsg;
import PTypes.COrderMessage;
import PTypes.CPassengerMsg;
import PTypes.CTableOrderMsg;
import PTypes.CTransCompanyMsg;
import PTypes.CTransportMsg;
import PTypes.CTripsMsg;

public class CTableOrders {
	 private CCommandMsg pCmd;
	 private CTableOrderMsg pTbl;
     
     private HashMap<Integer,CCityMesage> mCityMsg;
     private Vector<CTransCompanyMsg> mTransMsg;
     private Vector<CTripsMsg> mTripsMsg;
     private Vector<CCargoMsg> mCargoMsg;
     private Vector<CPassengerMsg> mPassgMsg;

     private Vector<CCity> mCityMap;
     private Vector<CTransportCompany> mTrancComp;
     private HashMap<Integer,CTrips> mTrips;
     private Vector<CCustomOrder> mOrders;
     private HashMap<Integer,CCargo> mTransdCarg;
     private HashMap<Integer,CPassenger> mTransdMan;
     
     private HashMap<String, CCustomOrder> mCargo;
     private HashMap<String, CCustomOrder> mPass;
     
     
     private CDBDriver pDB;

     public CTableOrders(CTableOrderMsg pTbl){
    	 this.pTbl = pTbl;
    	 initMessageCont();
    	 initSysCont();
    	 CConst.trace("CTableOrders::>Create."+pTbl.getInfo());
     }
     public void connectToDB(CDBDriver pDB){
    	 this.pDB = pDB;
     }
     public void prepareSystem(){
    	 createTable();
    	 loadTable();
    	 loadSystem();
     }
     public void updateSystem(){
    	 loadTable();
    	 loadSystem();
     }    
     private void initSysCont(){
    	 mCityMap   = new Vector<CCity>();
    	 mTrancComp = new Vector<CTransportCompany>();
    	 mTrips     = new HashMap<Integer,CTrips>();
    	 mOrders    = new Vector<CCustomOrder>();
    	 mTransdCarg= new HashMap<Integer,CCargo>();
    	 mTransdMan = new HashMap<Integer,CPassenger>();
    	 mCargo     = new HashMap<String, CCustomOrder>();
    	 mPass      = new HashMap<String, CCustomOrder>();
     }
     private void initMessageCont(){
    	 mCityMsg  = new HashMap<Integer,CCityMesage>();
    	 mTransMsg = new Vector<CTransCompanyMsg>();
    	 mTripsMsg = new Vector<CTripsMsg>();
    	 mCargoMsg = new Vector<CCargoMsg>();
    	 mPassgMsg = new Vector<CPassengerMsg>();
    	 pCmd      = new CCommandMsg();    	 
     }
     private void updateCity(){
    	 mCityMap.clear();
    	 mCityMsg.clear();
    	 pDB.loadCity(-1,mCityMsg);
    	 createCity();
     }
     private void createTable(){
    	 pDB.createCityTBL();
    	 pDB.createTransCopmanyTBL();
    	 pDB.createTransTBL();
    	 pDB.createCargoTBL();
    	 pDB.createPassTBL();
    	 pDB.createTripsTBL();    	 
     }
     private void loadTable(){
    	 pDB.loadCity(-1,mCityMsg);
    	 pDB.loadTransCopmany(mTransMsg);
    	 pDB.loadTrips(mTripsMsg);
    	 pDB.loadCargos(mCargoMsg);
    	 pDB.loadPassengers(mPassgMsg);   	 
     }
     private void loadSystem(){
    	 createCity();
    	 createTransCompany();
    	 createTrips();
    	 createTransported();
      }
     
     private void createCity(){

    	 for (Map.Entry<Integer,CCityMesage> entry : mCityMsg.entrySet())
  		 mCityMap.add(new CCity(entry.getValue())); 
     }
     private void createTransCompany(){
    	 try{
    	 for(CTransCompanyMsg pT:mTransMsg){
    		 CTransportCompany pTC = new CTransportCompany(pT);
    		 mTrancComp.add(pTC);
    		 for (Map.Entry<Integer,CTransportMsg> entry : pT.pTrans.entrySet())
    		 {
    			 CTransportMsg pTR = entry.getValue();
        		 if (pTR.nPortID==CConst.AIRPORT)    pTC.addTransport(new CATAirPlane(pTR)); 
           		 if (pTR.nPortID==CConst.AUTOPORT)   pTC.addTransport(new CGTAuto(pTR));
           		 if (pTR.nPortID==CConst.TRAINPORT)  pTC.addTransport(new CGTTrainCar(pTR));
           		 if (pTR.nPortID==CConst.WATERRPORT) pTC.addTransport(new CWTShip(pTR));
    		 }
    	 }
	     }catch(Exception e){
		  System.out.println("CTableOrders::>createTransCompany Exception!!! "+e.getMessage());
	     }
     }
     private void createTransported(){
    	 createCargos();
    	 createPassengers();
     }
     private void createCargos(){
    	 for(CCargoMsg pT:mCargoMsg)
    	 mTransdCarg.put(pT.cargoID,new CCargo(pT));
     }
     private void createPassengers(){
    	 for(CPassengerMsg pT:mPassgMsg)
   		 mTransdMan.put(pT.cargoID,new CPassenger(pT));
     }
     private void createTrips(){
    	 try{
    	 //Vector<CTransportMsg> mTR = new Vector<CTransportMsg>();
    	 CTransportMsg pTM;
    	 for(CTripsMsg pT:mTripsMsg){
    		 CCityMesage pDC = mCityMsg.get(pT.depCityID);
    		 CCityMesage pAC = mCityMsg.get(pT.arrCityID);
    		 pDC.depDate = pT.depDate;
    		 pAC.arrDate = pT.arrDate;
    		 if (((pTM = getTrans(pT.nTransID))!=null)&&(pDC!=null)&&(pAC!=null)){
    		  if (pTM.nPortID==CConst.AIRPORT)    mTrips.put(pT.codeID,new CTrips(pT,new CATAirPlane(pTM),new CRoute(pDC,pAC))); 
       		  if (pTM.nPortID==CConst.AUTOPORT)   mTrips.put(pT.codeID,new CTrips(pT,new CGTAuto(pTM)    ,new CRoute(pDC,pAC)));
       		  if (pTM.nPortID==CConst.TRAINPORT)  mTrips.put(pT.codeID,new CTrips(pT,new CGTTrainCar(pTM),new CRoute(pDC,pAC)));
       		  if (pTM.nPortID==CConst.WATERRPORT) mTrips.put(pT.codeID,new CTrips(pT,new CWTShip(pTM),new CRoute(pDC,pAC)));
    		 }
    	 }
    	 }catch(Exception e){
    		 System.out.println("CTableOrders::>createTrips Exception!!! "+e.getMessage());
    	 }
     }
     private CTransportMsg getTrans(int ID){
		 CTransportMsg pTM = null;
		 for(CTransCompanyMsg pTC:mTransMsg){
			 pTM = pTC.getTrans(ID);
			 if (pTM!=null) break;
		 }	 
		 return pTM;
     }
     public boolean setManToTrips(int nCargoID,int nTripsID){
    	 //Поместить человека на рейс и выдать Документ
    	 //Документ поместить в индивидуальны заказ и отслеживать его выполнение
    	 boolean res = true;
    	 try{
    	    CPassenger pPR = mTransdMan.get(nCargoID);
    	    CTrips pTR = mTrips.get(nTripsID);
    	    String strKey = pTR.getTripsNo()+"/"+pPR.getCargoID()+"/"+pPR.getCargoTypeID();
    	    if (mPass.containsKey(strKey)==false){
    	    CCustomOrder pCO = pTR.load(pPR);
    	     if (pCO!=null)
    	     {
    	    	if (pCO.getIntState()==CConst.CONOPLACE) {pCO.getStringState();return false;}
    	    	if (pCO.getIntState()==CConst.COLOWMONEY)pCO.getStringState();else
    	            mPass.put(strKey, pCO); 
    	     }
    	    } else System.out.println("("+strKey+")(ERR AREADY EX)!!!");
  	     }catch(Exception e){
  	    	res = false;//System.out.println("CTableOrders::>setManToTrips Exception!!! "+e.getMessage());
  	     }
    	 return res;
     }
     public boolean setCargoToTrips(boolean blFullLoad,int nCargoID,int nTripsID){
    	 //Поместить груз на рейс и выдать документ
    	 //Документ поместить в индивидуальны заказ и отслеживать его выполнение 
       	 boolean res = true;
    	 try{
    	    CCargo pPR = mTransdCarg.get(nCargoID);
    	    CTrips pTR = mTrips.get(nTripsID);
    	    String strKey = pTR.getTripsNo()+"/"+pPR.getCargoID()+"/"+pPR.getCargoTypeID();
    	    if (mPass.containsKey(strKey)==false){
    	    CCustomOrder pCO = pTR.load(pPR);
    	     if (pCO!=null)
    	     {
    	    	if (pCO.getIntState()==CConst.CONOPLACE){pCO.getStringState();return false;}
    	    	if (pCO.getIntState()==CConst.COLOWMONEY)pCO.getStringState();else{
    	            mPass.put(strKey, pCO);
    	            if (blFullLoad==true) return false;
    	    	}
    	     }
    	    } else System.out.println("("+strKey+")(ERR AREADY EX)!!!");
  	     }catch(Exception e){
  	    	res = false;//System.out.println("CTableOrders::>setManToTrips Exception!!! "+e.getMessage());
  	     }
    	 return res;
     }
    
     public CCommandMsg getCommand(){
    	 //Этот метод снимает все пременные с формы перед выполнением команды
    	 pCmd.cargoID     = 0;
    	 pCmd.cargoTypeID = 0;
    	 pCmd.depCity     = 0;
    	 pCmd.arrCity     = 3;
    	 return pCmd;
     }
     public void setDepCityPID(){
    	 //При выборе города отправления заполить чекбоксы портов
     }
     public void setArrCityPID(){
    	//При выборе города прибытия заполить чекбоксы портов
     }
     public void loadCityToCB(){
    	 //После добавления города обновить два комбобокса с городами отпр и приб
     }
     public void setCommand(CCommandMsg pCmd){
    	 this.pCmd = pCmd; 
     }
     public boolean createOrder(COrderMessage pOM){
    	 
    	 return true;
     }
     //Здесь будут обрабатываться команды основной формы апплета
     public boolean exeqAddCargoToTrips(){
    	 //Попытка оформить заказ(заказы) на рейс(рейсы) на перевозку груза
    	 //Сигнал о посадке приходит в каждый индивидуальный заказ
    	 return true;
     }
     public boolean exeqGetPrepareInfo(){
    	 //Получить информацию от перевозчиков отн возможности по деньгам скорости цены времени перевозки 
    	 //Информацию вывести в список
    	 return true;
     }
     public boolean exeqAddNewCity(){
    	 //Добавить новый пункт в базу
    	 //Город добавлен вывести в список 
    	 return true;
     }
     public boolean exeqTrips(){
    	 //Послать рейс в конечную точку(при этом сигналы 
    	 // об отправлении и прибытии должны прити в каждый индивидуальный заказ)
    	 // Сигналы перенаправить в список
    	 return true;
     }
     public void getCityTBL(int nCityID){
    	 for (CCity pT : mCityMap){
    		 if (nCityID==-1) CConst.trace(pT.getCityInfo()); else
    		 {
    			 if(nCityID==pT.getID()) CConst.trace(pT.getCityInfo());
    		 }
    	 }
     }
     public void getPassTBL(int nPassID){
    	 if (nPassID==-1)
    	 for (Map.Entry<Integer,CPassenger> entry : mTransdMan.entrySet())
    		 CConst.trace(entry.getValue().getCargoParam()); 
    	 if (nPassID!=-1)
    		 CConst.trace(mTransdMan.get(nPassID).getCargoParam());
     }
     public void getCargoTBL(int nCargID){
    	 if (nCargID==-1)
    	 for (Map.Entry<Integer,CCargo> entry : mTransdCarg.entrySet())
    		 CConst.trace(entry.getValue().getCargoParam()); 
    	 if (nCargID!=-1)
    		 CConst.trace(mTransdCarg.get(nCargID).getCargoParam());
     }
     public void getTransportTBL(int nTranID){
    	 for(CTransportCompany pTC:mTrancComp)
    		 CConst.trace(pTC.getCompanyInfo());
     }
     public void getTripsTBL(int nTripsType,int nTripsID){
    	 //nTripsType = 0;
    	 //nTripsID = 9;
    	 if (nTripsID==-1){
    	  for (Map.Entry<Integer,CTrips> entry : mTrips.entrySet())
    	  {
    		 if(nTripsType==-1)
    		 CConst.trace(entry.getValue().getTripsInfo());else
      			 if (entry.getValue().checkCatroType(nTripsType))
    				 CConst.trace(entry.getValue().getTripsInfo());
    	  }
    	 } else{
    	  for (Map.Entry<Integer,CTrips> entry : mTrips.entrySet())
       	  {
       		 if(nTripsType!=-1){
       			if(nTripsID==entry.getValue().getID())
       		    CConst.trace(entry.getValue().getTripsInfo());
       		 } else{
         			 if (entry.getValue().checkCatroType(nTripsType))
         			 if(nTripsID==entry.getValue().getID())
       				 CConst.trace(entry.getValue().getTripsInfo());
       		       }
       		 }    		 
    	 }
     }
     public void getTripsByDir(int nTripsType,int nDepID,int nArrID){
    	 for (Map.Entry<Integer,CTrips> entry : mTrips.entrySet())
    	 {
    		 CTrips pT = entry.getValue();
    		 if((pT.getDepCityID()==nDepID)&&(pT.getArrCityID()==nArrID))
    		 {
    			 if(nTripsType==-1)
    			 CConst.trace(pT.getTripsInfo());else
    			 {
    				 if (pT.checkCatroType(nTripsType)) 
    					 CConst.trace(pT.getTripsInfo());
    			 }
    		 }
    	 }
     }
     public void getAlternateForPassByTransp(int nPassengerID,int nTripsID){
    	 CTrips pT = mTrips.get(nTripsID);
    	 CPassenger pP = mTransdMan.get(nPassengerID);
    	 for(CTransportCompany pTC:mTrancComp){
    		 Vector<IFTransport> pVC = pTC.getCont();
    		 for(IFTransport pTV:pVC){
    			 CCustomOrder pCO = pT.getCheckDocument(pP, pTV);
    			 CConst.trace(pCO.getShortInfo());
    		 }
    	 }
     }
     public void getAlternateForCargByTransp(int nCargoID,int nTripsID){
    	 CTrips pT = mTrips.get(nTripsID);
    	 CCargo pP = mTransdCarg.get(nCargoID);
    	 for(CTransportCompany pTC:mTrancComp){
    		 Vector<IFTransport> pVC = pTC.getCont();
    		 for(IFTransport pTV:pVC){
    			 CCustomOrder pCO = pT.getCheckDocument(pP, pTV);
    			 CConst.trace(pCO.getShortInfo());
    		 }
    	 }
     }
     public void loadPass(int nPassengerID,int nTripsID){
    	setManToTrips(nPassengerID,nTripsID);
     }
     public void loadCargo(int nCargoID,int nTripsID){
    	setCargoToTrips(false,nCargoID,nTripsID);
     }
     public void depTrips(int nTripsID){
    	CTrips pTR = mTrips.get(nTripsID);
		pTR.departures();
     }
     public void arrTrips(int nTripsID){
    	CTrips pTR = mTrips.get(nTripsID);
		pTR.arrival();
		mPass.clear();
     }
     public void loadAllPassAndGo(int nTripsID){
    	 for(CPassengerMsg pT:mPassgMsg)
    	 {
    		 if (setManToTrips(pT.cargoID,nTripsID)==false){
    			 CTrips pTR = mTrips.get(nTripsID);
    			 pTR.departures();
    			 pTR.arrival();
    			 mPass.clear();
    			 break;
    		 }
    	 }    	 
     }
     public void loadAllCargoAndGo(int nTripsID){
    	 CTrips pTR = mTrips.get(nTripsID);
    	 for(CCargoMsg pT:mCargoMsg)
    	 {
    		 CCargo pPR = mTransdCarg.get(pT.cargoID);
    		 boolean blColumn = pTR.checkColumn(pPR);
    		 int nCount = pTR.getTripsCount(pPR);
    		 if (blColumn==true)
    			 nCount = pTR.getTripsCount(pPR); else
    				 nCount = 1;
    		 
    		 for(int i=0;i<nCount;i++)
    		 {
    		  if (setCargoToTrips(blColumn,pT.cargoID,nTripsID)==false)
    		  {
    			 pTR.departures();
    			 pTR.arrival();
    			 mPass.clear();
    			 if(blColumn!=true) return;
    		  }
    		 }
    	 }
		 pTR.departures();
		 pTR.arrival();
		 mPass.clear();
     }
     public void addCity(String strName,int nX,int nY,int nIsAir,int nIsAut,int nIsTra,int nIsWat){
    	 boolean isAir=false;
    	 boolean isAut=false;
    	 boolean isTra=false;
    	 boolean isWat=false;
    	 if(nIsAir!=0)isAir=true;
    	 if(nIsAut!=0)isAut=true;
    	 if(nIsTra!=0)isTra=true;
    	 if(nIsWat!=0)isWat=true;
    	 pDB.addCity(strName,nX,nY,isAir,isAut,isTra,isWat);
    	 updateCity();
     }
}

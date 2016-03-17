package src;
public class CAdmin {
     private int nID;
     private CConfigItem pI;
     private CLoopHandler pLHand;
     public CAdmin(CConfigItem pI,CLoopHandler pLHand){
    	 this.pI = pI; 
    	 this.pLHand = pLHand;
    	 System.out.println("("+pI.strLoop+")CAdmin::>Create. :"+pI.strPhone+" OpenMsg:"+pI.strMsgOpen+" CloseMsg:"+pI.strMsgClose);
     }
	   public int getID(){
		   return -1;
	   } 
     public boolean EventHandler(String strPhone,String strMessage){
    	 boolean res = false;
    	 //System.out.println("("+pI.strLoop+")CAdmin::>EventHandler. Phone:"+pI.strPhone+" OpenMsg:"+pI.strMsgOpen+" CloseMsg:"+pI.strMsgClose);
    	 //System.out.println("("+pI.strLoop+")CAdmin::>EventHandler. Phone:"+strPhone+" Msg:"+strMessage);
    	 //if (strPhone.equalsIgnoreCase(pI.strPhone)==true){
    	 if (pI.strPhone.indexOf(strPhone)>=0){
    		 //if (strMessage.indexOf(pI.strLoop)>=0)
    		 //{
       			 //if (strMessage.equalsIgnoreCase(pI.strMsgOpen)==true) 
    			 if (strMessage.indexOf(pI.strMsgOpen)>=0)
    				 pLHand.openLoop(); else
       			 //if (strMessage.equalsIgnoreCase(pI.strMsgClose)==true) 
    			 if (strMessage.indexOf(pI.strMsgClose)>=0)
    				 pLHand.closeLoop();
    		 //}
    	 }
    	 return res;
     }
}

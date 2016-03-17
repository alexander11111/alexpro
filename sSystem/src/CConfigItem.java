package src;

public class CConfigItem {
	 public CConfigItem(String str){
		 
	 }
	 public CConfigItem(String sType,String sLoop,String sPhone,String sMsgOpen,String sMsgClose){
		 strType     = sType;
		 strLoop     = sLoop;
		 strPhone    = sPhone;
		 strMsgOpen  = sMsgOpen;
		 strMsgClose = sMsgClose;
		 System.out.println("CPhoneItem::>Create. Type:"+strType+" Loop:"+strLoop+" Phone:'"+strPhone+"' Msg Open: '"+sMsgOpen+"' Msg Close: '"+sMsgClose);
	 }
	 public CConfigItem(CConfigItem pI){
		 this.strType     = pI.strType;
		 this.strLoop     = pI.strLoop;
		 this.strPhone    = pI.strPhone;
		 this.strMsgOpen  = pI.strMsgOpen;
		 this.strMsgClose = pI.strMsgClose;
	 }
	 public int getID(){
		 int res = 0;
		 try{
			 res = Integer.parseInt(strLoop);
			 return res;
		 }catch(Exception e){
			return 0; 
		 }
	 }
	 public int getOpenTime(){
		 int res = 0;
		 try{
			 res = Integer.parseInt(strPhone);
			 return res;
		 }catch(Exception e){
			return 0; 
		 }
	 }
	 public int getCloseTime(){
		 int res = 0;
		 try{
			 res = Integer.parseInt(strMsgOpen);
			 return res;
		 }catch(Exception e){
			return 0; 
		 }
	 }
	 public int getPinID(){
	     return getID();
	 }
	 public String strType;
	 public String strLoop;
     public String strPhone;
     public String strMsgOpen;
     public String strMsgClose;
}

package CConstant;

public class CConst {
	public static final int AIRPORT    = 0;
	public static final int AUTOPORT   = 1;
	public static final int TRAINPORT  = 2;
	public static final int WATERRPORT = 3;
	
	public static final int ISCARGO = 0;
	public static final int ISMAN   = 1;
	
	public static final int COFREE       = 0;
	public static final int COINDEPPOINT = 1;
	public static final int COINROAD     = 2;
	public static final int COINARRPOINT = 3;
	public static final int COLOWMONEY   = 4;
	public static final int CONOPLACE    = 5;
	public static final int CODEPARTURES = 6;
	
	public static final int CLOAD        = 0;
	public static final int CUNLOAD      = 1;
	
	public static final int AUTOP   = 0;
	public static final int AUTOC   = 1;
	public static final int TRAIC   = 2;
	public static final int TRAIP   = 3;
	public static final int AIRC    = 4;
	public static final int AIRP    = 5;
	public static final int WATP    = 6;
	public static final int WATC    = 7;
    
	public static String getCaroStrID(int nID){
		if(nID==AUTOP) return "AUTOP";
		if(nID==AUTOC) return "AUTOC";
		if(nID==TRAIC) return "TRAIC";
		if(nID==TRAIP) return "TRAIP";
		if(nID==AIRC) return "AIRC";
		if(nID==AIRP) return "AIRP";
		if(nID==WATP) return "WATP";
		if(nID==WATC) return "WATC";
		return "UNC";
	}
	public static boolean chechCgType(int nType){
  	  return ((nType==CConst.AUTOC)||
  			  (nType==CConst.AIRC)||
  			  (nType==CConst.WATC));
    }
    public static boolean chechPsType(int nType){
  	  return ((nType==CConst.AUTOP)||
  			  (nType==CConst.AIRP)||
  			  (nType==CConst.WATC));
    }
	
	
	public static void trace(String str){
		System.out.println(str);
	}
}

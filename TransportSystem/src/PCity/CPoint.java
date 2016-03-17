package PCity;

public class CPoint {
     private int nX;
     private int nY;
     public CPoint(int nX,int nY){
    	 this.nX = nX;
    	 this.nY = nY;
     }
     public CPoint(CPoint pP){
    	 this.nX = pP.nX;
    	 this.nY = pP.nY;
     }
     public int getX(){
    	 return nX;
     }
     public int getY(){
    	 return nY;
     }
     public boolean equals(CPoint pP){
    		 return ((nX==pP.getX())&&(nY==pP.getY()));
     }
     public String getPointInfo(){
    	 return "X: "+nX+" "+" Y: "+nY; 
     }
}
